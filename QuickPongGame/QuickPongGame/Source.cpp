#include <iostream>
#include "Game.h"

/*
	Title:
		PONG

	Purpose:
		A simple game that can be developed in one to two days
		Gives additional experience and is in preparation of GameJam

	Method:
		Uses the Windows API to render the pixels to a window.

	Total Estimated Time Spent:
		7.5 hrs.
*/

/*
	The Game is incappible of renderering text so dots are used to represent
	score.

	When the game ends, it displays in the Console Window and ends the game.

	The game is a 2 player game and uses the W, S keys for player one and
	up, down arrow keys for player 2.

	This is not indicative of the other projects that I have done in terms
	of completion, code management, ease of use and understanding, or quality.

	The game stuffers from a stuttering issue do to a lack of frame buffering
	or any real way of vertical synchronization.
*/


void main()
{
	Game::run();

	system("pause");
}