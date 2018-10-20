#include "Controller.h"
#include "GameRender.h"
#include "Game.h"
#include "Ball.h"
#include <iostream>

Controller::Controller()
{
}


Controller::~Controller()
{
}

void Controller::update()
{
	if (Game::getObject(1)->getPosition().x<0)
	{
		player2Score++;
		((Ball*)Game::getObject(1))->restart();

		Sleep(2000);
	}
	else if (Game::getObject(1)->getPosition().x > 640)
	{
		player1Score++;
		((Ball*)Game::getObject(1))->restart();

		Sleep(2000);
	}

	if (player1Score >= scoreToWin)
	{
		std::cout << "You've Won the game" << std::endl;
		std::cout << "Game ending in 3 seconds" << std::endl;
		Sleep(3000);

		Game::end();
	}
	else if (player2Score >= scoreToWin)
	{
		std::cout << "You've Lost the game" << std::endl;
		std::cout << "Game ending in 3 seconds" << std::endl;
		Sleep(3000);

		Game::end();
	}
}

void Controller::draw()
{
	for (int i = 0; i < player1Score; i++)
	{
		GameRender::drawRectangle(4, 4 + (16*i), 8, 8 + (16*i));
	}

	for (int i = 0; i < player2Score; i++)
	{
		GameRender::drawRectangle(640-8, 4 + (16 * i), 640-4, 8 + (16 * i));
	}
}