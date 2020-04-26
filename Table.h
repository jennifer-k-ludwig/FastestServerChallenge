/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 03/10/2019
 * Description: Table class header file.
***************************************************************/
#include "Space.h"
#include "Guest.h"
#include "Waiter.h"

#include <vector>
#include <string>

#ifndef TABLE_H
#define TABLE_H

class Table : public Space
{
	public:
		//Constructor
		Table();	

		//Destructor
		~Table();

		//Methods
		void home(Waiter &);
		std::string translateOrder(Order);
};
#endif

