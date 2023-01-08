// CPU Filters

#include "Filter_Cpu.h"
#include <stdio.h>
#include "include/stb_image.h"
#include "include/stb_image_write.h"
#include <iostream>
#include <string>
#include <cassert>
#include <chrono>
#include <ctime>

using namespace std::chrono;

// Create Pixel Data Structure
struct Pixel
{
	unsigned char red, green, blue, alpha;
};

// Convert Image to Gray at CPU

 double useCPU::ConvertImageToGrayCpu(unsigned char* imageRGBA, int width, int height) {
	// Start Timers
	auto start = std::chrono::steady_clock::now();

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			/*  Color to Grayscale Equation
			 Ylinear = 0.2126RLinear + 0.7152GLiners +0.0722BLiners */
			Pixel* ptrPixel = (Pixel*)&imageRGBA[y * width * 4 + 4 * x];
			unsigned char pixelValue = (unsigned char)(ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel->blue * 0.0722f);

			//float pixelValue = ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel-> blue * 0.0722f;
			//unsigned char pixelValue = pixelValue;
			ptrPixel->red = pixelValue;
			ptrPixel->green = pixelValue;
			ptrPixel->blue = pixelValue;
			ptrPixel->alpha = 255;

		}
	}
	// Stop Timer
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	auto Duration_ms = duration_cast<microseconds> (elapsed_seconds);
	double timecpu= Duration_ms.count();

	// Time of execution
	return timecpu;
}
 // Convert Image to Red at CPU
 double useCPU::ConvertImageToRedCPU(unsigned char* imageRGBA, int width, int height) {
	 // Start Timers
	 auto start = std::chrono::steady_clock::now();


	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			/*  Color to Grayscale Equation
			 Ylinear = 0.2126RLinear + 0.7152GLiners +0.0722BLiners */
			Pixel* ptrPixel = (Pixel*)&imageRGBA[y * width * 4 + 4 * x];
			unsigned char pixelValue = (unsigned char)(ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel->blue * 0.0722f);

			//float pixelValue = ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel-> blue * 0.0722f;
			//unsigned char pixelValue = pixelValue;
			ptrPixel->red = ptrPixel->red * 1;
			ptrPixel->green = ptrPixel->green * 0.5f;
			ptrPixel->blue = ptrPixel->blue * 0.5f;
			ptrPixel->alpha = 255;

		}
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	auto Duration_ms = duration_cast<microseconds> (elapsed_seconds);
	double timecpu = Duration_ms.count();

	// Time of execution
	return timecpu;

}
 // Convert Image to Green at CPU
 double useCPU::ConvertImageToGreenCPU(unsigned char* imageRGBA, int width, int height) {
	 // Start Timers
	 auto start = std::chrono::steady_clock::now();

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			/*  Color to Grayscale Equation
			 Ylinear = 0.2126RLinear + 0.7152GLiners +0.0722BLiners */
			Pixel* ptrPixel = (Pixel*)&imageRGBA[y * width * 4 + 4 * x];
			unsigned char pixelValue = (unsigned char)(ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel->blue * 0.0722f);

			//float pixelValue = ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel-> blue * 0.0722f;
			//unsigned char pixelValue = pixelValue;
			ptrPixel->red = ptrPixel->red * 0.5f;
			ptrPixel->green = ptrPixel->green * 1;
			ptrPixel->blue = ptrPixel->blue * 0.5f;
			ptrPixel->alpha = 255;

		}
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	auto Duration_ms = duration_cast<microseconds> (elapsed_seconds);
	double timecpu = Duration_ms.count();

	// Time of execution
	return timecpu;
}
 // Convert Image to Blue at CPU
 double useCPU::ConvertImageToBlueCPU(unsigned char* imageRGBA, int width, int height) {
	 // Start Timers
	 auto start = std::chrono::steady_clock::now();

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			/*  Color to Grayscale Equation
			 Ylinear = 0.2126RLinear + 0.7152GLiners +0.0722BLiners */
			Pixel* ptrPixel = (Pixel*)&imageRGBA[y * width * 4 + 4 * x];
			unsigned char pixelValue = (unsigned char)(ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel->blue * 0.0722f);

			//float pixelValue = ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel-> blue * 0.0722f;
			//unsigned char pixelValue = pixelValue;
			ptrPixel->red = ptrPixel->red * 0.5f;
			ptrPixel->green = ptrPixel->green * 0.5f;
			ptrPixel->blue = ptrPixel->blue * 1;
			ptrPixel->alpha = 255;

		}
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	auto Duration_ms = duration_cast<microseconds> (elapsed_seconds);
	double timecpu = Duration_ms.count();

	// Time of execution
	return timecpu;
}
 // Convert Image to Inverte at CPU
 double useCPU::ConvertImageInvCPU(unsigned char* imageRGBA, int width, int height) {
	 // Start Timers
	 auto start = std::chrono::steady_clock::now();

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			/*  Color to Grayscale Equation
			 Ylinear = 0.2126RLinear + 0.7152GLiners +0.0722BLiners */
			Pixel* ptrPixel = (Pixel*)&imageRGBA[y * width * 4 + 4 * x];
			unsigned char pixelValue = (unsigned char)(ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel->blue * 0.0722f);

			//float pixelValue = ptrPixel->red * 0.2126f + ptrPixel->green * 0.7152f + ptrPixel-> blue * 0.0722f;
			//unsigned char pixelValue = pixelValue;
			ptrPixel->red = ptrPixel->red * -1 + 255;
			ptrPixel->green = ptrPixel->green * -1 + 255;
			ptrPixel->blue = ptrPixel->blue * -1 + 255;
			ptrPixel->alpha = 255;

		}
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	auto Duration_ms = duration_cast<microseconds> (elapsed_seconds);
	double timecpu = Duration_ms.count();
	// Time of execution
	return timecpu;

}





