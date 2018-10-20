#pragma once
class Vec3
{
public:
	Vec3();
	Vec3(double x, double y, double z);
	~Vec3();

	void setX(double x);
	void setY(double y);
	void setZ(double z);

	double getX();
	double getY();
	double getZ();

	double x = 0;
	double y = 0;
	double z = 0;
};

