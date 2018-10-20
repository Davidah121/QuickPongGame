#include "Game.h"
#include <iostream>
#include "Paddle1.h"
#include "Ball.h"
#include "Paddle2.h"
#include "Controller.h"

int Game::FPS = 0;
int Game::FPSCOUNT = 0;
Window* Game::gameWindow;
std::vector<GameObject*> Game::objectList = std::vector<GameObject*>();

AABB Game::screenBox = AABB(0, 640, 64, 416);

Game::Game()
{
}

Game::~Game()
{
}

void Game::init()
{
	addObject(new Paddle1());
	addObject(new Ball());
	addObject(new Paddle2());
	addObject(new Controller());
}

void Game::end()
{
	for(int i=0; i<objectList.size(); i++)
		objectList.pop_back();

	gameWindow->close();
}

void Game::update()
{
	for (int i = 0; i < objectList.size(); i++)
	{
		objectList[i]->update();
	}
}

void Game::render()
{
	Image img = Image(640, 480);

	img.setAllPixels(0x00000000);

	GameRender::setImage(&img);

	for (int i = 0; i < objectList.size(); i++)
	{
		objectList[i]->draw();
	}

	gameWindow->setWindowPixels(&img);
}

void Game::run()
{
	gameWindow = new Window(640, 480);

	Window::setStaticWindow(gameWindow);

	long startTime = 0;
	long endTime = 0;
	long totalTime = 0;

	init();

	while (gameWindow->windowExists())
	{
		startTime = System::getTimeNano();

		update();
		render();

		Input::updateKeys();
		gameWindow->processMessages();

		endTime = System::getTimeNano();

		while ((endTime - startTime) < (SECOND_IN_NANO/FPSLIMIT))
		{
			endTime = System::getTimeNano();
		}

		FPSCOUNT++;
		totalTime += (endTime - startTime);

		if (totalTime >= SECOND_IN_NANO)
		{
			FPS = FPSCOUNT;
			FPSCOUNT = 0;
			totalTime = 0;

			std::cout << "FPS: " << FPS << std::endl;
		}

	}
}

void Game::addObject(GameObject* obj)
{
	objectList.push_back(obj);
}

GameObject * Game::getObject(int location)
{
	if (location >= 0 && location < objectList.size())
		return objectList[location];
	else
		return nullptr;
}

int Game::getObjectListSize()
{
	return objectList.size();
}

AABB Game::getScreenBox()
{
	return screenBox;
}
