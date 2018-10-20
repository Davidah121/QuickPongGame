#pragma once
#include "GameObject.h"
#include "GameRender.h"

class Paddle1 : public GameObject
{
public:
	Paddle1();
	~Paddle1();

	void update();
	void draw();

};

