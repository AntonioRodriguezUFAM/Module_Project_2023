
#ifndef GPUFUNC_H
#define GPUFUNC_H



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