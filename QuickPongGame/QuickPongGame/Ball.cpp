#include "Ball.h"
#include "GameRender.h"
#include "Game.h"
#include "MathExt.h"

Ball::Ball()
{
	position.x = 320;
	position.y = 240;

	box = AABB(-8, 8, -8, 8);
	box.setX(position.x);
	box.setY(position.y);

	direction.x = 2;
}


Ball::~Ball()
{
}

void Ball::update()
{
	GameObject* otherObject = nullptr;
	bool collision = false;
	int yDis = 0;

	
	for (int i = 0; i < Game::getObjectListSize(); i++)
	{
		otherObject = Game::getObject(i);
		if (otherObject != this)
		{
			if (AABB::isColliding(box, otherObject->getBoundingBox()))
			{
				collision = true;
				break;
			}
		}
	}


	if (collision == true)
	{
		yDis = -(otherObject->getPosition().y - this->position.y)/4;
		
		direction = Vec2(-direction.x*1.5, yDis);
		/*
		if (yDis > 0)
			direction = Vec2(-direction.x, 1);
		else if (yDis < 0)
			direction = Vec2(-direction.x, -1);
		else
			direction = Vec2(-direction.x, 0);
		*/
	}
	
	
	if (position.y <= 8 || position.y >= 472)
	{
		direction.y = -direction.y;
	}

	direction.x = MathExt::clamp(direction.x, -16.0, 16.0);

	position.x += direction.x;
	position.y += direction.y;

	box.setX(position.x);
	box.setY(position.y);

}

void Ball::draw()
{
	GameRender::setDrawColor(0xFFFFFFFF);
	GameRender::drawRectangle(position.x + box.getLeftBound(), position.y + box.getTopBound(), position.x + box.getRightBound(), position.y + box.getBottomBound());
}

void Ball::restart()
{
	if (direction.x > 0)
		direction.x = -2;
	else
		direction.x = 2;

	direction.y = 0;
	position.x = 320;
	position.y = 240;
	box.setX(position.x);
	box.setY(position.y);
}
