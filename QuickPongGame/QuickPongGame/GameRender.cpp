#include "GameRender.h"
#include "MathExt.h"
#include <iostream>

Image* GameRender::currentImage = nullptr;
int GameRender::drawColor = 0;

GameRender::GameRender()
{
}


GameRender::~GameRender()
{
}

void GameRender::setImage(Image* img)
{
	currentImage = img;
}

void GameRender::drawRectangle(int x, int y, int x2, int y2)
{
	if (currentImage != nullptr)
	{
		int** pixels = currentImage->getPixelData();

		int minX = MathExt::clamp(MathExt::min(x, x2), 0, currentImage->getWidth());
		int maxX = MathExt::clamp(MathExt::max(x, x2), 0, currentImage->getWidth());

		int minY = MathExt::clamp(MathExt::min(y, y2), 0, currentImage->getHeight());
		int maxY = MathExt::clamp(MathExt::max(y, y2), 0, currentImage->getHeight());

		for (int i2 = minY; i2 < maxY; i2++)
		{
			for (int i = minX; i < maxX; i++)
			{
				pixels[i2][i] = drawColor;
			}
		}
	}
}

void GameRender::setDrawColor(int color)
{
	drawColor = color;
}

int GameRender::getDrawColor()
{
	return drawColor;
}
