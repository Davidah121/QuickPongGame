#include "Vec3.h"



Vec3::Vec3()
{
}

Vec3::Vec3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


Vec3::~Vec3()
{
}

void Vec3::setX(double x)
{
	this->x = x;
}

void Vec3::setY(double y)
{
	this->y = y;
}

void Vec3::setZ(double z)
{
	this->z = z;
}

double Vec3::getX()
{
	return x;
}

double Vec3::getY()
{
	return y;
}

double Vec3::getZ()
{
	return z;
}
