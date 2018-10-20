#pragma once
#include "GameObject.h"
class Controller :
	public GameObject
{
public:
	Controller();
	~Controller();

	void update();
	void draw();

private:
	int player1Score = 0;
	int player2Score = 0;

	int scoreToWin = 5;

	void restart();
};

