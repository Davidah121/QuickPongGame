#include "Vec2.h"



Vec2::Vec2()
{
}

Vec2::Vec2(double x, double y)
{
	this->x = x;
	this->y = y;
}


Vec2::~Vec2()
{
}

double Vec2::getX()
{
	return x;
}

double Vec2::getY()
{
	return y;
}

void Vec2::setX(double x)
{
	this->x = x;
}

void Vec2::setY(double y)
{
	this->y = y;
}