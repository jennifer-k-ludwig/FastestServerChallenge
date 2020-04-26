/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 03/10/2019
 * Description: Party class header file.
***************************************************************/
#include <string>

#ifndef GUEST_H
#define GUEST_H

enum Order { Pizza, Pasta, Fish };

struct Guest
{
	std::string name;
	Order order;
	Guest(std::string nameIn, Order orderIn)
	{
		name = nameIn;
		order = orderIn;
	}	
};

#endif

