/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 03/10/2019
 * Description: Main file for server challenge. 
***************************************************************/
#include "Game.h"
#include "gameFunctions.h"

#include <iostream>
#include <algorithm>

int main()
{
	Game game;

	clearScreen();
	std::cout << ":: Fastest Server Challenge ::\n\n";

	std::cout << "It's Saturday night at Mario's Italian Restaurant\n";
	std::cout << "and there are four hungry parties waiting to be seated\n";
	std::cout << "and served.\n\n";

	std::cout << "Luigi, the waiter, must seat each party, take their orders,\n";
	std::cout << "and serve their food before time runs out!\n\n";

	game.runGame();
	
	return 0;
}

