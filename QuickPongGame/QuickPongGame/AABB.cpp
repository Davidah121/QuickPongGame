#include "AABB.h"
#include <iostream>


AABB::AABB()
{
}

AABB::AABB(int leftBound, int rightBound, int topBound, int bottomBound)
{
	this->leftBound = leftBound;
	this->rightBound = rightBound;
	this->topBound = topBound;
	this->bottomBound = bottomBound;
}

AABB::AABB(const AABB & other)
{
	this->x = other.x;
	this->y = other.y;
	this->leftBound = other.leftBound;
	this->rightBound = other.rightBound;
	this->topBound = other.topBound;
	this->bottomBound = other.bottomBound;

}


AABB::~AABB()
{
}

int AABB::getLeftBound()
{
	return leftBound;
}

int AABB::getRightBound()
{
	return rightBound;
}

int AABB::getTopBound()
{
	return topBound;
}

int AABB::getBottomBound()
{
	return bottomBound;
}

int AABB::getX()
{
	return x;
}

int AABB::getY()
{
	return y;
}

void AABB::setX(int xVal)
{
	x = xVal;
}

void AABB::setY(int yVal)
{
	y = yVal;
}

void AABB::setLeftBound(int value)
{
	leftBound = value;
}

void AABB::setRightBound(int value)
{
	rightBound = value;
}

void AABB::setTopBound(int value)
{
	topBound = value;
}

void AABB::setBottomBound(int value)
{
	bottomBound = value;
}

bool AABB::isColliding(AABB box1, AABB box2)
{

	if ((box1.getLeftBound() + box1.getX()) <= (box2.getRightBound() + box2.getX())
		&& (box1.getRightBound() + box1.getX()) >= (box2.getLeftBound() + box2.getX()))
	{
		if ((box1.getTopBound() + box1.getY()) <= (box2.getBottomBound() + box2.getY())
			&& (box1.getBottomBound() + box1.getY()) >= (box2.getTopBound() + box2.getY()))
		{
			return true;
		}

	}
	
	return false;
}
