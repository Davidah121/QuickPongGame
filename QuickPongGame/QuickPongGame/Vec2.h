#pragma once
class Vec2
{
public:
	Vec2();
	Vec2(double x, double y);
	~Vec2();

	double x = 0;
	double y = 0;

	double getX();
	double getY();

	void setX(double x);
	void setY(double y);

};

