#pragma once
#ifndef CPUFUNC_H
#define CPUFUNC_H
class useCPU
{
public:
	void adding(int* c, const int* a, const int* b, unsigned int size);
	double ConvertImageToGrayCpu(unsigned char* imageRGBA, int width, int height);
	double ConvertImageToRedCPU(unsigned char* imageRGBA, int width, int height);
	double ConvertImageToGreenCPU(unsigned char* imageRGBA, int width, int height);
	double ConvertImageToBlueCPU(unsigned char* imageRGBA, int width, int height);
	double ConvertImageInvCPU(unsigned char* imageRGBA, int width, int height);
};
#endif