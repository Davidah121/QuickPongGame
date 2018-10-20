#pragma once
#include "Window.h"
#include "System.h"
#include "Input.h"
#include <vector>
#include "GameObject.h"
#include "AABB.h"

class Game
{
public:
	Game();
	~Game();
	
	static void run();
	static void init();
	static void end();

	static void update();
	static void render();

	static void addObject(GameObject* obj);
	static GameObject* getObject(int location);
	static int getObjectListSize();

	static const int FPSLIMIT = 60;
	static const long SECOND_IN_NANO = 1000000000L;

	static AABB getScreenBox();

private:
	static int FPS;
	static int FPSCOUNT;
	static Window* gameWindow;

	static std::vector<GameObject*> objectList;

	static AABB screenBox;
};

