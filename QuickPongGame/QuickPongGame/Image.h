#pragma once
class Image
{
public:
	Image(int width, int height);
	Image(const Image& img);
	~Image();

	int** getPixelData();
	int getWidth();
	int getHeight();

	int getPixel(int x, int y);
	void setPixel(int x, int y, int color);
	void setAllPixels(int color);

private:
	int** pixels = nullptr;
	int width = 0;
	int height = 0;
};

