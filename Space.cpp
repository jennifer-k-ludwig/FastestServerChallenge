/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 03/10/2019
 * Description: Space class implementation file.
***************************************************************/
#include "Space.h"
#include "Guest.h"

#include <iostream>
#include <string>
#include <vector>

//Constructor
Space::Space()
{
	top = nullptr;
	right = nullptr;
	bottom = nullptr;
	left = nullptr;
	name = "";
	party1Seated = false;
	party2Seated = false;
	party3Seated = false;
	party4Seated = false;
	occupied = false;
	eating = false;
	party1Name = "Party #1";
	party2Name = "Party #2";
	party3Name = "Party #3";
	party4Name = "Party #4";
	ordered = false;
}

//Destructor
Space::~Space() {}

//Setters
void Space::setName(std::string nameIn)
{
	name = nameIn;
}

void Space::setTop(Space *topIn)
{
	top = topIn;
}

void Space::setLeft(Space * leftIn)
{
	left = leftIn;
}

void Space::setRight(Space * rightIn)
{
	right = rightIn;
}

void Space::setBottom(Space *bottomIn)
{
	bottom = bottomIn;
}

void Space::setParty1(std::vector <Guest> &party1In)
{
	party1 = party1In;
	occupied = true;
}

void Space::setParty1Name(std::string nameIn)
{
	party1Name = nameIn;
}

void Space::setParty2Name(std::string nameIn)
{
	party2Name = nameIn;
}

void Space::setParty3Name(std::string nameIn)
{
	party3Name = nameIn;
}

void Space::setParty4Name(std::string nameIn)
{
	party4Name = nameIn;
}


//Getters
std::string Space::getName()
{
	return name;
}

Space * Space::getTop()
{
	return top;
}

Space * Space::getLeft()
{
	return left;
}

Space * Space::getRight()
{
	return right;
}

Space * Space::getBottom()
{
	return bottom;
}

std::vector <Guest> Space::getParty1()
{
	return party1;
}

std::string Space::getParty1Name()
{
	return party1Name;
}

std::string Space::getParty2Name()
{
	return party2Name;
}

std::string Space::getParty3Name()
{
	return party3Name;
}

std::string Space::getParty4Name()
{
	return party4Name;
}
		
//Methods
bool Space::isOccupied()
{ return occupied; }

bool Space::isEating()
{ return eating; }

//bool partiesSeated() - returns whether all parties are seated
bool Space::partiesSeated()
{
	return (party1Seated && party2Seated && party3Seated && party4Seated);
}
