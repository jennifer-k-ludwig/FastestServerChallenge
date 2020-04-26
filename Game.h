/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 03/10/2019
 * Description: Header file for Game class. 
***************************************************************/
#include "Space.h"
#include "Lobby.h"
#include "Table.h"
#include "Kitchen.h"

#include <iostream>

#ifndef GAME_H
#define GAME_H

class Game
{
	private:
		Space *lobby;
		Space *table1;
		Space *table2;
		Space *table3;
		Space *table4;
		Space *kitchen;
		Space *current;
		Waiter waiter;
		int minutes;
	public:
		//Constructor
		Game();

		//Destructor
		~Game();

		//Methods
		int runGame();
		void printRestaurant();
		void pickTable();
		bool checkServed(int);
};
#endif
