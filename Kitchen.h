/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 03/10/2019
 * Description: Kitchen class header file.
***************************************************************/
#include "Space.h"
#include "Guest.h"
#include "Waiter.h"

#include <vector>

#ifndef KITCHEN_H
#define KITCHEN_H

class Kitchen : public Space
{
	private:
		bool busy;

	public:
		//Constructor
		Kitchen();

		//Destructor
		~Kitchen();

		//Methods
		void home(Waiter &);
};
#endif

