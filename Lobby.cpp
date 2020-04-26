/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 03/10/2019
 * Description: Lobby class implementation file.
***************************************************************/
#include "Waiter.h"
#include "Space.h"
#include "Guest.h"
#include "Lobby.h"
#include "gameFunctions.h"

#include <vector>
#include <iostream>

//Constructor - initializes parties
Lobby::Lobby()
{
	name = "Lobby";
	//Party 1
	Guest Mayor("Mayor", Pasta);
	Guest Wife("Mayor's Wife", Fish);
	party1.push_back(Mayor);
	party1.push_back(Wife);

	//Party 2
	Guest CollegeKid1("College Kid #1", Pizza);
	Guest CollegeKid2("College Kid #2", Pizza);
	Guest CollegeKid3("College Kid #3", Pizza);
	Guest CollegeKid4("College Kid #4", Pizza);
	Guest CollegeKid5("College Kid #5", Pizza);
	party2.push_back(CollegeKid1);
	party2.push_back(CollegeKid2);
	party2.push_back(CollegeKid3);
	party2.push_back(CollegeKid4);
	party2.push_back(CollegeKid5);
	
	//Party 3
	Guest Mother("Mother", Pasta);
	Guest Father("Father", Fish);
	Guest Child1("Child #1", Pizza);
	Guest Child2("Child #2", Pasta);
	party3.push_back(Mother);
	party3.push_back(Father);
	party3.push_back(Child1);
	party3.push_back(Child2);

	//Party 4
	Guest Professional1("Professional #1", Fish);
	Guest Professional2("Professional #2", Pasta);
	Guest Professional3("Professional #3", Fish);
	party4.push_back(Professional1);
	party4.push_back(Professional2);
	party4.push_back(Professional3);
}		

//Destructor
Lobby::~Lobby() {}

//Methods
//void home(Waiter &) - performs all actions of the Lobby derived class
void Lobby::home(Waiter &waiter)
{
	std::cout << "Which party would you like to seat?\n";
	std::cout << "1. Party 1\n";
	std::cout << "2. Party 2\n";
	std::cout << "3. Party 3\n";
	std::cout << "4. Party 4\n";

	bool charInvalid = true;
	std::string selection = "";

	while (charInvalid)
	{
		std::cout << "Party: ";
		std::getline(std::cin, selection);

		if (isInteger(selection))
		{
			if (std::stoi(selection) == 1)
			{	
				//If party is not already seated
				if (!party1Seated)
				{
					//Set the waiter's party to party1
					waiter.setWaitersParty(party1);
					//Set the waiter's party name
					waiter.setWaitersPartyName(getParty1Name());
					//Set party1seated to true
					party1Seated = true;
					//Set party 1's name to blank for the printout
					setParty1Name("        ");
					charInvalid = false; 
				}
				else
				{
					std::cout << "Party #1 is already seated.\n";
				}
			}
			else if (std::stoi(selection) == 2)
			{	
				if (!party2Seated)
				{
					waiter.setWaitersParty(party2);
					waiter.setWaitersPartyName(getParty2Name());
					party2Seated = true;
					setParty2Name("        ");
					charInvalid = false; 
				}
				else
				{
					std::cout << "Party #2 is already seated.\n";
				}
			}
			else if (stoi(selection) == 3)
			{
				if (!party3Seated)
				{
					waiter.setWaitersParty(party3);
					waiter.setWaitersPartyName(getParty3Name());
					party3Seated = true;
					setParty3Name("        ");
					charInvalid = false; 
				}
				else
				{
					std::cout << "Party #3 is already seated.\n";
				}
			}
			else if (std::stoi(selection) == 4)
			{
				if (!party4Seated)
				{
					waiter.setWaitersParty(party4);
					waiter.setWaitersPartyName(getParty4Name());
					party4Seated = true;
					setParty4Name("        ");
					charInvalid = false; 
				}
				else
				{
					std::cout << "Party #4 is already seated.\n";
				}
			}
		}
	}
	std::cout << std::endl;
}

