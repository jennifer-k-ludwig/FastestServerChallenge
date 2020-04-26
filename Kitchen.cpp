/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 03/10/2019
 * Description: Kitchen class header file.
***************************************************************/
#include "Kitchen.h"
#include "Guest.h"

#include <vector>
#include <iostream>
#include <iomanip>

//Constructor
Kitchen::Kitchen()
{
	busy = false;
}

//Destructor
Kitchen::~Kitchen() {}

//Methods
//void home(Waiter &) - performs all actions of the Kitchen derived class.
void Kitchen::home(Waiter &waiter)
{
	//If the kitchen is not preparing other orders, and the waiter is storing orders,
	//the kitchen will prepare the orders
	if (!busy && waiter.hasOrders())
	{
		std::cout << std::left << std::setw(10) << "Head Chef" << ": Hello, Luigi! What can I prepare for you?\n";
		std::vector <Order> orders = waiter.getOrders();
		int pizza = 0, pasta = 0, fish = 0;
		for (unsigned int i = 0; i < orders.size(); i++)
		{
			if (orders.at(i) == 0)
				pizza++;
			else if (orders.at(i) == 1)
				pasta++;
			else
				fish++;
		}
		std::cout << std::left << std::setw(10) << "Luigi" << ": Hi, Chef! Can I get " << pizza << " pizzas, " 
		<< pasta << " pasta plates, and " << fish << " fish plates?\n";
		std::cout<< std::left << std::setw(10) << "Head Chef" << ": Of course! Coming right up!\n";
		std::cout << "(time passes)\n";
		std::cout << std::left << std::setw(10)<< "Head Chef" << ": Here you go! (passes Luigi the plates)\n";
		std::cout << std::left << std::setw(10)<< "Luigi" << ": Thanks, Chef!\n";
	}
	//If Luigi goes to the kitchen without orders
	else if (!waiter.hasOrders())
	{
		std::cout << "Luigi has no orders to bring to the kitchen.\n";
		std::cout << "Seat a party and take orders before visiting the kitchen.\n";
	}
	//If the kitchen is busy
	else
	{
		std::cout << "The kitchen is busy preparing other orders.\n";
	}
}
