#include "Input.h"

bool Input::keyDown[256];
bool Input::keyPressed[256];
bool Input::keyUp[256];

Input::Input()
{
}


Input::~Input()
{
}

bool Input::getKeyPressed(char key)
{
	return keyPressed[key];
}

bool Input::getKeyDown(char key)
{
	return keyDown[key];
}

bool Input::getKeyUp(char key)
{
	return keyUp[key];
}

void Input::setKeyPressed(char key)
{
	keyUp[key] = false;
	keyDown[key] = true;
	keyPressed[key] = true;
}

void Input::setKeyUp(char key)
{
	keyUp[key] = true;
	keyDown[key] = false;
	keyPressed[key] = false;
}

void Input::updateKeys()
{
	for (int i = 0; i < 256; i++)
	{
		keyUp[i] = false;
		keyPressed[i] = false;
	}
}