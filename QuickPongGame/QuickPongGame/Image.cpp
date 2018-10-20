#include "Image.h"
#include <iostream>


Image::Image(int width, int height)
{
	this->width = width;
	this->height = height;

	pixels = new int*[height];
	for (int i = 0; i < height; i++)
	{
		pixels[i] = new int[width];
	}
}

Image::Image(const Image& img)
{
	width = img.width;
	height = img.height;

	pixels = new int*[height];
	for (int i = 0; i < height; i++)
	{
		pixels[i] = new int[width];
	}

	for (int i = 0; i < height; i++)
	{
		for (int i2 = 0; i2 < width; i2++)
		{
			pixels[i][i2] = img.pixels[i][i2];
		}
	}
}

Image::~Image()
{
	for (int i = 0; i < height; i++)
	{
		delete[] pixels[i];
	}

	delete[] pixels;
}

int Image::getWidth()
{
	return width;
}

int Image::getHeight()
{
	return height;
}

int Image::getPixel(int x, int y)
{
	if (x >= 0 && x < width)
	{
		if (y >= 0 && y < height)
		{
			return pixels[y][x];
		}
	}
	return 0;
}

int** Image::getPixelData()
{
	return pixels;
}

void Image::setPixel(int x, int y, int color)
{
	if (x >= 0 && x < width)
	{
		if (y >= 0 && y < height)
		{
			pixels[y][x] = color;
		}
	}
}

void Image::setAllPixels(int color)
{
	for (int i = 0; i < height; i++)
	{
		for (int i2 = 0; i2 < width; i2++)
		{
			pixels[i][i2] = color;
		}
	}
}
