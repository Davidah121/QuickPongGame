#pragma once
class AABB
{
public:
	AABB();
	AABB(int leftBound, int rightBound, int topBound, int bottomBound);
	AABB(const AABB& other);
	~AABB();

	int getLeftBound();
	int getRightBound();
	int getTopBound();
	int getBottomBound();

	int getX();
	int getY();

	void setX(int xVal);
	void setY(int yVal);

	void setLeftBound(int value);
	void setRightBound(int value);
	void setTopBound(int value);
	void setBottomBound(int value);

	static bool isColliding(AABB box1, AABB box2);

private:
	int leftBound = 0;
	int rightBound = 0;
	int topBound = 0;
	int bottomBound = 0;

	int x = 0;
	int y = 0;
};

