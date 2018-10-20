#pragma once
class Input
{
public:
	Input();
	~Input();

	static bool getKeyPressed(char key);
	static bool getKeyDown(char key);
	static bool getKeyUp(char key);

	static void updateKeys();

	static void setKeyUp(char key);
	static void setKeyPressed(char key);

private:

	static bool keyDown[256];
	static bool keyUp[256];
	static bool keyPressed[256];

};

