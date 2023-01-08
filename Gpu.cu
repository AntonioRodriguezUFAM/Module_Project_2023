#include <iostream>
#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>
#include "device_launch_parameters.h"
#include "GpuSolver.h"
#include <stdio.h>
#include "include/stb_image.h"
#include "include/stb_image_write.h"
#include <iostream>
#include <string>
#include <cassert>
#include <chrono>
using namespace std::chrono;

//#define STB_IMAGE_IMPLEMENTATION
// Write Images
//#define STB_IMAGE_WRITE_IMPLEMENTATION

//#define STBIR_INCLUDE_STB_IMAGE_RESIZE_H

//#include "include/stb_image.h"
//#include "include/stb_image_resize.h"
//#include "include/stb_image_write.h"
struct Pixel
{
	unsigned char r, g, b, a;
};

__global__ void AddKernel(int* c, const int* a, const int* b)
{
	int i = threadIdx.x;
	c[i] = a[i] + b[i];
}
__global__ void ConvertImageToGrayGpu(unsigned char* imageRGBA)
{
	uint32_t x = blockIdx.x * blockDim.x + threadIdx.x;
	uint32_t y = blockIdx.y * blockDim.y + threadIdx.y;
	uint32_t idx = y * blockDim.x * gridDim.x + x;

	Pixel* ptrPixel = (Pixel*)&imageRGBA[idx * 4];
	unsigned char pixelValue = (unsigned char)
		(ptrPixel->r * 0.2126f + ptrPixel->g * 0.7152f + ptrPixel->b * 0.0722f);
	ptrPixel->r = pixelValue;
	ptrPixel->g = pixelValue;
	ptrPixel->b = pixelValue;
	ptrPixel->a = 255;
}

__global__ void ConvertImageToRedGpu(unsigned char* imageRGBA)
{
	uint32_t x = blockIdx.x * blockDim.x + threadIdx.x;
	uint32_t y = blockIdx.y * blockDim.y + threadIdx.y;
	uint32_t idx = y * blockDim.x * gridDim.x + x;

	Pixel* ptrPixel = (Pixel*)&imageRGBA[idx * 4];
	unsigned char pixelValue = (unsigned char)
		//	(ptrPixel->r * 0.2126f + ptrPixel->g * 0.7152f + ptrPixel->b * 0.0722f);
		ptrPixel->r = ptrPixel->r * 1;
	ptrPixel->g = ptrPixel->g * 0.5;
	ptrPixel->b = ptrPixel->b * 0.5;
	ptrPixel->a = 255;
}

__global__ void ConvertImageToGreenGpu(unsigned char* imageRGBA)
{
	uint32_t x = blockIdx.x * blockDim.x + threadIdx.x;
	uint32_t y = blockIdx.y * blockDim.y + threadIdx.y;
	uint32_t idx = y * blockDim.x * gridDim.x + x;

	Pixel* ptrPixel = (Pixel*)&imageRGBA[idx * 4];
	unsigned char pixelValue = (unsigned char)
		//	(ptrPixel->r * 0.2126f + ptrPixel->g * 0.7152f + ptrPixel->b * 0.0722f);
		ptrPixel->r = ptrPixel->r * 0.5;
	ptrPixel->g = ptrPixel->g * 1;
	ptrPixel->b = ptrPixel->b * 0.5;
	ptrPixel->a = 255;
}

__global__ void ConvertImageToBlueGpu(unsigned char* imageRGBA)
{
	uint32_t x = blockIdx.x * blockDim.x + threadIdx.x;
	uint32_t y = blockIdx.y * blockDim.y + threadIdx.y;
	uint32_t idx = y * blockDim.x * gridDim.x + x;

	Pixel* ptrPixel = (Pixel*)&imageRGBA[idx * 4];
	unsigned char pixelValue = (unsigned char)
		//	(ptrPixel->r * 0.2126f + ptrPixel->g * 0.7152f + ptrPixel->b * 0.0722f);
		ptrPixel->r = ptrPixel->r * 0.5;
	ptrPixel->g = ptrPixel->g * 0.5;
	ptrPixel->b = ptrPixel->b * 1;
	ptrPixel->a = 255;
}

__global__ void ConvertImageToInvGpu(unsigned char* imageRGBA)
{
	uint32_t x = blockIdx.x * blockDim.x + threadIdx.x;
	uint32_t y = blockIdx.y * blockDim.y + threadIdx.y;
	uint32_t idx = y * blockDim.x * gridDim.x + x;

	Pixel* ptrPixel = (Pixel*)&imageRGBA[idx * 4];
	unsigned char pixelValue = (unsigned char)
		//	(ptrPixel->r * 0.2126f + ptrPixel->g * 0.7152f + ptrPixel->b * 0.0722f);
		ptrPixel->r = ptrPixel->r * -1 + 255;
	ptrPixel->g = ptrPixel->g * -1 + 255;
	ptrPixel->b = ptrPixel->b * -1 + 255;
	ptrPixel->a = 255;
}


using namespace std;
void useGPU::adding(int* c, const int* a, const int* b, unsigned int size) {
	int* dev_a = 0;
	int* dev_b = 0;
	int* dev_c = 0;
	cudaMalloc((void**)&dev_c, size * sizeof(int));
	cudaMalloc((void**)&dev_a, size * sizeof(int));
	cudaMalloc((void**)&dev_b, size * sizeof(int));

	cudaMemcpy(dev_a, a, size * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(dev_b, b, size * sizeof(int), cudaMemcpyHostToDevice);

	cudaDeviceSynchronize();

	AddKernel << <1, size >> > (dev_c, dev_a, dev_b);

	cudaMemcpy(c, dev_c, size * sizeof(int), cudaMemcpyDeviceToHost);

	cudaFree(dev_c);
	cudaFree(dev_a);
	cudaFree(dev_b);
}
int useGPU::ImageToGrayGpu(unsigned char* imageRGBA, int width, int height) {
	unsigned char* ptrImageDataGpu = nullptr;
	assert(cudaMalloc(&ptrImageDataGpu, width * height * 4) == cudaSuccess);
	assert(cudaMemcpy(ptrImageDataGpu, imageRGBA, width * height * 4, cudaMemcpyHostToDevice) == cudaSuccess);

	// Process image on gpu
	dim3 blockSize(20, 20);
	dim3 gridSize(width / blockSize.x, height / blockSize.y);
	//ConvertImageToGrayGpu <<<gridSize, blockSize >>> (ptrImageDataGpu);
	auto start = high_resolution_clock::now();
	ConvertImageToGrayGpu << <gridSize, blockSize >> > (ptrImageDataGpu);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	auto err = cudaGetLastError();

	// Copy data from the gpu
	assert(cudaMemcpy(imageRGBA, ptrImageDataGpu, width * height * 4, cudaMemcpyDeviceToHost) == cudaSuccess);

	cudaFree(ptrImageDataGpu);
	return duration.count();
	// Build output filename
	//std::string fileNameOut = "images/output.jpg";
	//stbi_write_jpg("images/output.jpg", width, height, 3, imageRGBA, 100);
}

int useGPU::ImageToRedGpu(unsigned char* imageRGBA, int width, int height) {
	unsigned char* ptrImageDataGpu = nullptr;
	assert(cudaMalloc(&ptrImageDataGpu, width * height * 4) == cudaSuccess);
	assert(cudaMemcpy(ptrImageDataGpu, imageRGBA, width * height * 4, cudaMemcpyHostToDevice) == cudaSuccess);

	// Process image on gpu
	dim3 blockSize(20, 20);
	dim3 gridSize(width / blockSize.x, height / blockSize.y);
	//ConvertImageToGrayGpu <<<gridSize, blockSize >>> (ptrImageDataGpu);
	auto start = high_resolution_clock::now();
	ConvertImageToRedGpu << <gridSize, blockSize >> > (ptrImageDataGpu);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	auto err = cudaGetLastError();

	// Copy data from the gpu
	assert(cudaMemcpy(imageRGBA, ptrImageDataGpu, width * height * 4, cudaMemcpyDeviceToHost) == cudaSuccess);

	cudaFree(ptrImageDataGpu);
	return duration.count();
	// Build output filename
	//std::string fileNameOut = "images/output.jpg";
	//stbi_write_jpg("images/output.jpg", width, height, 3, imageRGBA, 100);
}

int useGPU::ImageToGreenGpu(unsigned char* imageRGBA, int width, int height) {
	unsigned char* ptrImageDataGpu = nullptr;
	assert(cudaMalloc(&ptrImageDataGpu, width * height * 4) == cudaSuccess);
	assert(cudaMemcpy(ptrImageDataGpu, imageRGBA, width * height * 4, cudaMemcpyHostToDevice) == cudaSuccess);

	// Process image on gpu
	dim3 blockSize(20, 20);
	dim3 gridSize(width / blockSize.x, height / blockSize.y);
	//ConvertImageToGrayGpu <<<gridSize, blockSize >>> (ptrImageDataGpu);
	auto start = high_resolution_clock::now();
	ConvertImageToGreenGpu << <gridSize, blockSize >> > (ptrImageDataGpu);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	auto err = cudaGetLastError();

	// Copy data from the gpu
	assert(cudaMemcpy(imageRGBA, ptrImageDataGpu, width * height * 4, cudaMemcpyDeviceToHost) == cudaSuccess);

	cudaFree(ptrImageDataGpu);
	return duration.count();
	// Build output filename
	//std::string fileNameOut = "images/output.jpg";
	//stbi_write_jpg("images/output.jpg", width, height, 3, imageRGBA, 100);
}

int useGPU::ImageToBlueGpu(unsigned char* imageRGBA, int width, int height) {
	unsigned char* ptrImageDataGpu = nullptr;
	assert(cudaMalloc(&ptrImageDataGpu, width * height * 4) == cudaSuccess);
	assert(cudaMemcpy(ptrImageDataGpu, imageRGBA, width * height * 4, cudaMemcpyHostToDevice) == cudaSuccess);

	// Process image on gpu
	dim3 blockSize(20, 20);
	dim3 gridSize(width / blockSize.x, height / blockSize.y);
	//ConvertImageToGrayGpu <<<gridSize, blockSize >>> (ptrImageDataGpu);
	auto start = high_resolution_clock::now();
	ConvertImageToBlueGpu << <gridSize, blockSize >> > (ptrImageDataGpu);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	auto err = cudaGetLastError();

	// Copy data from the gpu
	assert(cudaMemcpy(imageRGBA, ptrImageDataGpu, width * height * 4, cudaMemcpyDeviceToHost) == cudaSuccess);

	cudaFree(ptrImageDataGpu);
	return duration.count();
	// Build output filename
	//std::string fileNameOut = "images/output.jpg";
	//stbi_write_jpg("images/output.jpg", width, height, 3, imageRGBA, 100);
}

int useGPU::ImageToInvGpu(unsigned char* imageRGBA, int width, int height) {
	unsigned char* ptrImageDataGpu = nullptr;
	assert(cudaMalloc(&ptrImageDataGpu, width * height * 4) == cudaSuccess);
	assert(cudaMemcpy(ptrImageDataGpu, imageRGBA, width * height * 4, cudaMemcpyHostToDevice) == cudaSuccess);

	// Process image on gpu
	dim3 blockSize(20, 20);
	dim3 gridSize(width / blockSize.x, height / blockSize.y);
	//ConvertImageToGrayGpu <<<gridSize, blockSize >>> (ptrImageDataGpu);
	auto start = high_resolution_clock::now();
	ConvertImageToInvGpu << <gridSize, blockSize >> > (ptrImageDataGpu);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	auto err = cudaGetLastError();

	// Copy data from the gpu
	assert(cudaMemcpy(imageRGBA, ptrImageDataGpu, width * height * 4, cudaMemcpyDeviceToHost) == cudaSuccess);

	cudaFree(ptrImageDataGpu);
	return duration.count();
	// Build output filename
	//std::string fileNameOut = "images/output.jpg";
	//stbi_write_jpg("images/output.jpg", width, height, 3, imageRGBA, 100);
}