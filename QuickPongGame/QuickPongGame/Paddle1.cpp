#include "Paddle1.h"
#include "Input.h"
#include "Game.h"
#include <iostream>

Paddle1::Paddle1()
{
	position.x = 32;
	position.y = 128;

	box = AABB(-6, 6, -32, 32);
	box.setX(position.x);
	box.setY(position.y);
}


Paddle1::~Paddle1()
{
}

void Paddle1::update()
{
	position.x = 32;
	
	box.setX(position.x);
	box.setY(position.y);

	if (Input::getKeyDown('W'))
	{
		box.setY(position.y - 8);

		if (AABB::isColliding(box, Game::getScreenBox()))
		{
			position.y -= 8;
		}
		else
			box.setY(position.y);
	}
	else if (Input::getKeyDown('S'))
	{
		box.setY(position.y + 8);

		if (AABB::isColliding(box, Game::getScreenBox()))
			position.y += 8;
		else
			box.setY(position.y);
	}
}

void Paddle1::draw()
{

	GameRender::setDrawColor(0xFFFFFFFF);
	GameRender::drawRectangle(position.x + box.getLeftBound(), position.y + box.getTopBound(), position.x + box.getRightBound(), position.y + box.getBottomBound());
}