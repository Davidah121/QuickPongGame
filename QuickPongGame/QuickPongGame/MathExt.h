#pragma once

#undef min
#undef max

class MathExt
{
public:
	MathExt();
	~MathExt();

	static int clamp(int value, int min, int max);
	static double clamp(double value, double min, double max);

	static int min(int value, int value2);
	static int max(int value, int value2);

	static int min(int* values, int size);
	static int max(int* values, int size);
};

