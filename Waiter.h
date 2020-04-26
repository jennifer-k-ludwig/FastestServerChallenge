/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 03/10/2019
 * Description: Waiter class header file.
***************************************************************/
#include "Guest.h"

#include <vector>
#include <string>

#ifndef WAITER_H
#define WAITER_H

class Waiter
{
	private:
		std::vector <Guest> party;
		std::string partyName;
		std::vector <Order> orders;

	public:
		//Setters
		void setWaitersParty(std::vector <Guest> &);
		void setWaitersPartyName(std::string);
		void setOrders(std::vector <Order> &);

		//Getters
		std::vector <Guest> & getWaitersParty();
		std::string getWaitersPartyName();
		std::vector <Order> getOrders();

		//Methods
		bool hasOrders();
		void clearOrders();
		void clearParty();
};
#endif

