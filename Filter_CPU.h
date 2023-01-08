#pragma once
#ifndef CPUFUNC_H
#define CPUFUNC_H
class useCPU
{
public:
	void adding(int* c, const int* a, const int* b, unsigned int size);
	double ConvertImageToGrayCpu(unsigned char* imageRGBA, int width, int height);
	inline auto ConvertImageToRed(unsigned char* imageRGBA, int width, int height);
	inline auto ConvertImageToGreen(unsigned char* imageRGBA, int width, int height);
	inline auto ConvertImageToBlue(unsigned char* imageRGBA, int width, int height);
	inline auto ConvertImageInv(unsigned char* imageRGBA, int width, int height);
};
#endif