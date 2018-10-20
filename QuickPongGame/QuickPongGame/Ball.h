#pragma once
#include "GameObject.h"
class Ball : public GameObject
{
public:
	Ball();
	~Ball();

	void update();
	void draw();

	void restart();

private:
	Vec2 direction = Vec2(0,0);
};

