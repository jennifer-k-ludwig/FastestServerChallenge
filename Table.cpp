/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 03/10/2019
 * Description: Table class implementation file.
***************************************************************/
#include "Table.h"
#include "Guest.h"
#include "Waiter.h"

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

//Constructor
Table::Table()
{
	setParty1Name("        ");
}

//Destructor
Table::~Table() {}

//Methods
//void home(Waiter &) - performs all actions of the Table derived Space class.
void Table::home(Waiter &waiter)
{
	//If table is occupied, not ordered, and the waiter is not currently carrying orders,
	//Luigi will take their orders
	if (occupied && !ordered && !waiter.hasOrders())
	{
		std::cout << std::left << std::setw(15) << "Luigi" << ": Hello! My name is Luigi and I will be your server tonight. May I take your order?\n";
		
		std::vector <Order> orders;
		for (unsigned int i = 0; i < party1.size(); i++)
		{
			Guest current = party1.at(i);
			std::cout << std::left << std::setw(15) << current.name << ": I would like the " << translateOrder(current.order) << ".\n";
			orders.push_back(current.order);
		}
		waiter.setOrders(orders);
		ordered = true;
	}
	//If the table is served and eating
	else if (eating)
	{
		std::cout << "This party is already served and eating.\n";
	}
	//If the table has ordered, and is waiting for food
	else if (ordered)
	{
		std::cout << "Luigi: ";
		for (unsigned int i = 0; i < party1.size(); i++)
		{
			Guest current = party1.at(i);
			if (i < (party1.size() - 2))
			{
				std::cout << current.name << ", here is your " << translateOrder(current.order) << ",\n";
			}
			else if (i < (party1.size() - 1))
			{
				std::cout << current.name << ", here is your " << translateOrder(current.order) << ", and\n";
			}
			else
			{
				std::cout << current.name << ", here is your " << translateOrder(current.order) << ".\n";
			}
			
		}
		waiter.clearOrders();
		eating = true;
	}
	//If the waiter is currently storing orders, can only take one order at a time
	else if (waiter.hasOrders())
	{
		std::cout << "Luigi can only take one party's orders at a time!\n";
		std::cout << "Take the orders to the kitchen and deliver them before\n";
		std::cout << "taking new orders.\n";
	}
	//If there is no party at the table yet
	else
	{
		std::cout << getName() << " is unoccupied. Please seat a party here.\n";
	}
}

//string translateOrder(Order) - translates order from enum to string
std::string Table::translateOrder(Order order)
{
	switch (order)
	{
		case 0: return "Pizza";
			break;
		case 1: return "Pasta";
			break;
		case 2: return "Fish";
			break;
	}
	return "";
}
