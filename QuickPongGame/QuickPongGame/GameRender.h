#pragma once
#include "Image.h"

class GameRender
{
public:
	GameRender();
	~GameRender();

	static void setImage(Image* img);
	static void drawRectangle(int x, int y, int x2, int y2);

	static void setDrawColor(int color);
	static int getDrawColor();

private:
	static Image * currentImage;
	static int drawColor;
};

