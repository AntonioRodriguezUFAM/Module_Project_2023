#pragma once
#ifndef GPUFUNC_H
#define GPUFUNC_H

//Load Images
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "include/stb_image.h"
// Write Images
#include "include/stb_image_write.h"


class useGPU
{
public:
	void adding(int* c, const int* a, const int* b, unsigned int size);
	//double ImageToGrayGpu(unsigned char* imageRGBA, int width, int height);
	int ImageToGrayGpu(unsigned char* imageRGBA, int width, int height);

	double ImageToRedGpu(unsigned char* imageRGBA, int width, int height);
	double ImageToGreenGpu(unsigned char* imageRGBA, int width, int height);
	double ImageToBlueGpu(unsigned char* imageRGBA, int width, int height);
	double ImageToInvGpu(unsigned char* imageRGBA, int width, int height);
};
#endif