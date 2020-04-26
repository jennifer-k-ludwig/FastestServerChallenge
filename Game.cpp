/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 03/10/2019
 * Description: Implementation file for Game class. 
***************************************************************/
#include "Game.h"
#include "Space.h"
#include "Lobby.h"
#include "Table.h"
#include "Kitchen.h"
#include "Waiter.h"
#include "gameFunctions.h"

#include <iostream>

//Constructor
Game::Game()
{
	//Create rooms
	lobby = new Lobby;
	lobby->setName("Lobby");

	table1 = new Table;
	table1->setName("Table #1");

	table2 = new Table;
	table2->setName("Table #2");

	table3 = new Table;
	table3->setName("Table #3");

	table4 = new Table;
	table4->setName("Table #4");

	kitchen = new Kitchen;
	kitchen->setName("Kitchen");

	//Connect spaces
	lobby->setTop(table1);
	lobby->setRight(table3);
	lobby->setLeft(nullptr);
	lobby->setBottom(nullptr);

	table1->setTop(nullptr);
	table1->setRight(table2);
	table1->setLeft(nullptr);
	table1->setBottom(lobby);

	table2->setTop(nullptr);
	table2->setRight(kitchen);
	table2->setLeft(table1);
	table2->setBottom(table3);

	table3->setTop(table2);
	table3->setRight(table4);
	table3->setLeft(lobby);
	table3->setBottom(nullptr);

	table4->setTop(kitchen);
	table4->setRight(nullptr);
	table4->setLeft(table3);
	table4->setBottom(nullptr);

	kitchen->setTop(nullptr);
	kitchen->setRight(nullptr);
	kitchen->setLeft(table2);
	kitchen->setBottom(table4);
}

//Destructor
Game::~Game()
{
	delete lobby;
	delete table1;
	delete table2;
	delete table3;
	delete table4;
	delete kitchen;
}

//Methods
//int runGame() - runs entire game
int Game::runGame()
{
	int minutesPassed = 0;
	minutes = 60;

	while (checkServed(minutes))
	{
		std::cout << "Menu\n";	
		std::cout << "---------------------------------------------------\n";
		std::cout << "Where would you like to go? (or press 'q' to quit)" << std::endl;
		std::cout << "1. Lobby\n";
		std::cout << "2. Table 1\n";
		std::cout << "3. Table 2\n";
		std::cout << "4. Table 3\n";
		std::cout << "5. Table 4\n";
		std::cout << "6. Kitchen\n";
	
		bool charInvalid = true;
		std::string selection = "";

		while (charInvalid)
		{
			std::cout << "Location: ";
			std::getline(std::cin, selection);

			if (isInteger(selection))
			{
				if (std::stoi(selection) == 1)
				{	
					current = lobby;
					printRestaurant();
					if (lobby->partiesSeated())
					{
						std::cout << "All parties seated.\n";
					}
					else
					{
						lobby->home(waiter);
						pickTable();
					}
					charInvalid = false;
				}
				else if (std::stoi(selection) == 2)
				{	
					current = table1;
					printRestaurant();
					table1->home(waiter); 
					charInvalid = false; 
				}
				else if (stoi(selection) == 3)
				{
					current = table2;
					printRestaurant();
					table2->home(waiter);
					charInvalid = false; 
				}
				else if (std::stoi(selection) == 4)
				{
					current = table3;
					printRestaurant();
					table3->home(waiter);
					charInvalid = false; 
				}
				else if (std::stoi(selection) == 5)
				{
					current = table4;
					printRestaurant();
					table4->home(waiter);
					charInvalid = false; 
				}
				else if (std::stoi(selection) == 6)
				{
					current = kitchen;
					printRestaurant();
					kitchen->home(waiter);
					charInvalid = false; 
					minutes -= 5;
					minutesPassed += 5;
				}
			}
			else if (selection[0] == 'q')
				return 0;
		}
		std::cout << std::endl;	
 		minutes--;
		minutesPassed++;
	}
	return 0;
}

//void printRestaurant() - prints layout of restuarant with locations of waiter and parties
void Game::printRestaurant()
{
	std::cout << "\n            Mario's Italian Restaurant\n";
	if (current == lobby)
	{
		std::cout << "|---------------|---------------|---------------|\n";
		std::cout << "|    Table #1   |    Table #2   |    Kitchen    |\n";
		std::cout << "|               |               |               |\n";
		std::cout << "|    " << table1->getParty1Name() << "        " << table2->getParty1Name() << "                   |\n";
		std::cout << "|                                               |\n";
		std::cout << "|               |               |               |\n";
		std::cout << "|               |               |               |\n";
		std::cout << "|------| |------|------| |------|------| |------|\n";
		std::cout << "|    " << lobby->getParty1Name() << "   |               |               |\n";
		std::cout << "|    " << lobby->getParty2Name() << "   |               |               |\n";
		std::cout << "|    " << lobby->getParty3Name() << "                                   |\n";
		std::cout << "|    " << lobby->getParty4Name() << "        " << table3->getParty1Name() << "        " << table4->getParty1Name() << "   |\n";
		std::cout << "|    *Waiter*   |               |               |\n";
		std::cout << "|     Lobby     |    Table #3   |    Table #4   |\n";
		std::cout << "|---------------|---------------|---------------|\n";
	}
	else if (current == table1)
	{
		std::cout << "|---------------|---------------|---------------|\n";
		std::cout << "|    Table #1   |    Table #2   |    Kitchen    |\n";
		std::cout << "|    *Waiter*   |               |               |\n";
		std::cout << "|    " << table1->getParty1Name() << "        " << table2->getParty1Name() << "                   |\n";
		std::cout << "|                                               |\n";
		std::cout << "|               |               |               |\n";
		std::cout << "|               |               |               |\n";
		std::cout << "|------| |------|------| |------|------| |------|\n";
		std::cout << "|    " << lobby->getParty1Name() << "   |               |               |\n";
		std::cout << "|    " << lobby->getParty2Name() << "   |               |               |\n";
		std::cout << "|    " << lobby->getParty3Name() << "                                   |\n";
		std::cout << "|    " << lobby->getParty4Name() << "        " << table3->getParty1Name() << "        " << table4->getParty1Name() << "   |\n";
		std::cout << "|               |               |               |\n";
		std::cout << "|     Lobby     |    Table #3   |    Table #4   |\n";
		std::cout << "|---------------|---------------|---------------|\n";
	}
	else if (current == table2)
	{
		std::cout << "|---------------|---------------|---------------|\n";
		std::cout << "|    Table #1   |    Table #2   |    Kitchen    |\n";
		std::cout << "|               |    *Waiter*   |               |\n";
		std::cout << "|    " << table1->getParty1Name() << "        " << table2->getParty1Name() << "                   |\n";
		std::cout << "|                                               |\n";
		std::cout << "|               |               |               |\n";
		std::cout << "|               |               |               |\n";
		std::cout << "|------| |------|------| |------|------| |------|\n";
		std::cout << "|    " << lobby->getParty1Name() << "   |               |               |\n";
		std::cout << "|    " << lobby->getParty2Name() << "   |               |               |\n";
		std::cout << "|    " << lobby->getParty3Name() << "                                   |\n";
		std::cout << "|    " << lobby->getParty4Name() << "        " << table3->getParty1Name() << "        " << table4->getParty1Name() << "   |\n";
		std::cout << "|               |               |               |\n";
		std::cout << "|     Lobby     |    Table #3   |    Table #4   |\n";
		std::cout << "|---------------|---------------|---------------|\n";
	}
	else if (current == table3)
	{
		std::cout << "|---------------|---------------|---------------|\n";
		std::cout << "|    Table #1   |    Table #2   |    Kitchen    |\n";
		std::cout << "|                                               |\n";
		std::cout << "|    " << table1->getParty1Name() << "        " << table2->getParty1Name() << "                   |\n";
		std::cout << "|                                               |\n";
		std::cout << "|               |               |               |\n";
		std::cout << "|               |               |               |\n";
		std::cout << "|------| |------|------| |------|------| |------|\n";
		std::cout << "|    " << lobby->getParty1Name() << "   |               |               |\n";
		std::cout << "|    " << lobby->getParty2Name() << "   |               |               |\n";
		std::cout << "|    " << lobby->getParty3Name() << "                                   |\n";
		std::cout << "|    " << lobby->getParty4Name() << "        " << table3->getParty1Name() << "        " << table4->getParty1Name() << "   |\n";
		std::cout << "|                    *Waiter*                   |\n";
		std::cout << "|     Lobby     |    Table #3   |    Table #4   |\n";
		std::cout << "|---------------|---------------|---------------|\n";
	}
	else if (current == table4)
	{
		std::cout << "|---------------|---------------|---------------|\n";
		std::cout << "|    Table #1   |    Table #2   |    Kitchen    |\n";
		std::cout << "|                                               |\n";
		std::cout << "|    " << table1->getParty1Name() << "        " << table2->getParty1Name() << "                   |\n";
		std::cout << "|                                               |\n";
		std::cout << "|               |               |               |\n";
		std::cout << "|               |               |               |\n";
		std::cout << "|------| |------|------| |------|------| |------|\n";
		std::cout << "|    " << lobby->getParty1Name() << "   |               |               |\n";
		std::cout << "|    " << lobby->getParty2Name() << "   |               |               |\n";
		std::cout << "|    " << lobby->getParty3Name() << "                                   |\n";
		std::cout << "|    " << lobby->getParty4Name() << "        " << table3->getParty1Name() << "        " << table4->getParty1Name() << "   |\n";
		std::cout << "|                                    *Waiter*   |\n";
		std::cout << "|     Lobby     |    Table #3   |    Table #4   |\n";
		std::cout << "|---------------|---------------|---------------|\n";
	}
	else if (current == kitchen)
	{
		std::cout << "|---------------|---------------|---------------|\n";
		std::cout << "|    Table #1   |    Table #2   |    Kitchen    |\n";
		std::cout << "|                                    *Waiter*   |\n";
		std::cout << "|    " << table1->getParty1Name() << "        " << table2->getParty1Name() << "                   |\n";
		std::cout << "|                                               |\n";
		std::cout << "|               |               |               |\n";
		std::cout << "|               |               |               |\n";
		std::cout << "|------| |------|------| |------|------| |------|\n";
		std::cout << "|    " << lobby->getParty1Name() << "   |               |               |\n";
		std::cout << "|    " << lobby->getParty2Name() << "   |               |               |\n";
		std::cout << "|    " << lobby->getParty3Name() << "                                   |\n";
		std::cout << "|    " << lobby->getParty4Name() << "        " << table3->getParty1Name() << "        " << table4->getParty1Name() << "   |\n";
		std::cout << "|                                               |\n";
		std::cout << "|     Lobby     |    Table #3   |    Table #4   |\n";
		std::cout << "|---------------|---------------|---------------|\n";		
	}		
	std::cout << "Time Remaining: " << minutes << " minutes\n\n";
}

//void pickTable() - waiter's selected party is seated at a table
void Game::pickTable()
{
	std::cout << "Which table would you like to seat " << waiter.getWaitersPartyName() << " at?\n";
	std::cout << "1. Table 1\n";
	std::cout << "2. Table 2\n";
	std::cout << "3. Table 3\n";
	std::cout << "4. Table 4\n";

	bool charInvalid = true;
	std::string selection = "";

	while (charInvalid)
	{
		std::cout << "Table: ";
		std::getline(std::cin, selection);

		if (isInteger(selection))
		{
			if (std::stoi(selection) == 1)
			{	
				//seat party at table
				if (!table1->isOccupied())
				{
					current = table1;
					//get party from waiter and set at table
					table1->setParty1(waiter.getWaitersParty());
					//get party's name from waiter and set at table
					table1->setParty1Name(waiter.getWaitersPartyName());
					printRestaurant();
					std::cout << table1->getParty1Name() << " was seated at Table #1.\n";
					charInvalid = false;
				}
				else
				{
					std::cout << "There is already a party seated at this table.\n\n";
				} 
			}
			else if (std::stoi(selection) == 2)
			{	
				//seat party at table
				if (!table2->isOccupied())
				{
					current = table2;
					table2->setParty1(waiter.getWaitersParty());
					table2->setParty1Name(waiter.getWaitersPartyName());
					printRestaurant();
					std::cout << table2->getParty1Name() << " was seated at Table #2.\n";
					charInvalid = false;
				} 
				else
				{
					std::cout << "There is already a party seated at this table.\n\n";
				}
			}
			else if (stoi(selection) == 3)
			{
				//seat party at table
				if (!table3->isOccupied())
				{
					current = table3;
					table3->setParty1(waiter.getWaitersParty());
					table3->setParty1Name(waiter.getWaitersPartyName());
					printRestaurant();
					std::cout << table3->getParty1Name() << " was seated at Table #3.\n";
					charInvalid = false; 
				}
				else
				{
					std::cout << "There is already a party seated at this table.\n\n";
				}
			}
			else if (std::stoi(selection) == 4)
			{
				//seat party at table
				if (!table4->isOccupied())
				{
					current = table4;
					table4->setParty1(waiter.getWaitersParty());
					table4->setParty1Name(waiter.getWaitersPartyName());
					printRestaurant();
					std::cout << table4->getParty1Name() << " was seated at Table #4.\n";
					charInvalid = false; 
				}
				else
				{
					std::cout << "There is already a party seated at this table.\n\n";
				}
			}	
		}
	}
	//clear the waiter's party and party name
	waiter.clearParty();
	waiter.setWaitersPartyName("");
}

//int checkServed(int) - if all tables are served and eating, the game is over and the player wins
bool Game::checkServed(int minutes)
{
	if (table1->isEating() && table2->isEating() && table3->isEating() && table4->isEating())
	{
		std::cout << "Congratulations! Luigi served all tables in " << minutes << " minutes! You won the game!\n";
		return false;
	}
	else if (minutes <= 0)
	{
		std::cout << "Sorry! You did not serve all parties within an hour. You lost!\n";
		return false;
	}
	return true;
}
