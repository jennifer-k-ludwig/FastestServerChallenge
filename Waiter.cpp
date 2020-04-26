/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 03/10/2019
 * Description: Waiter class implementation file.
***************************************************************/
#include "Waiter.h"
#include "Guest.h"

#include <vector>
#include <string>

//Setters
void Waiter::setWaitersParty(std::vector <Guest> &partyIn)
{
	party = partyIn;
}

void Waiter::setWaitersPartyName(std::string name)
{
	partyName = name;
}

void Waiter::setOrders(std::vector <Order> &ordersIn)
{
	orders = ordersIn;
}

//Getters
std::vector <Guest> & Waiter::getWaitersParty()
{
	return party;
}
std::string Waiter::getWaitersPartyName()
{
	return partyName;
}

std::vector <Order> Waiter::getOrders()
{
	return orders;
}

//Methods
bool Waiter::hasOrders()
{
	return !orders.empty();
}

void Waiter::clearOrders()
{
	orders.clear();
}

void Waiter::clearParty()
{
	party.clear();
}
