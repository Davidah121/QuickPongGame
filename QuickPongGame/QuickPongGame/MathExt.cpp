#include "MathExt.h"



MathExt::MathExt()
{
}


MathExt::~MathExt()
{
}

int MathExt::min(int value, int value2)
{
	return (value>value2) ? value2 : value;
}

int MathExt::max(int value, int value2)
{
	return (value>value2) ? value : value2;
}

int MathExt::min(int * values, int size)
{
	int tempMin = values[0];
	for (int i = 0; i < size; i++)
	{
		tempMin = (tempMin < values[i]) ? tempMin : values[i];
	}
	return tempMin;
}

int MathExt::max(int * values, int size)
{
	int tempMax = values[0];
	for (int i = 0; i < size; i++)
	{
		tempMax = (tempMax > values[i]) ? tempMax : values[i];
	}
	return tempMax;
}

int MathExt::clamp(int value, int min, int max)
{
	if (value > max)
		return max;

	if (value < min)
		return min;

	return value;
}

double MathExt::clamp(double value, double min, double max)
{
	if (value > max)
		return max;

	if (value < min)
		return min;

	return value;
}
