#include "Paddle2.h"
#include "Game.h"


Paddle2::Paddle2()
{
	position.x = 640 - 32;
	position.y = 320;
	box.setX(position.x);
	box.setY(position.y);
}


Paddle2::~Paddle2()
{
}

void Paddle2::update()
{

	position.x = 640-32;

	box.setX(position.x);
	box.setY(position.y);

	if (Input::getKeyDown((VK_UP)))
	{
		box.setY(position.y - 8);

		if (AABB::isColliding(box, Game::getScreenBox()))
		{
			position.y -= 8;
		}
		else
			box.setY(position.y);
	}
	else if (Input::getKeyDown(VK_DOWN))
	{
		box.setY(position.y + 8);

		if (AABB::isColliding(box, Game::getScreenBox()))
			position.y += 8;
		else
			box.setY(position.y);
	}
}