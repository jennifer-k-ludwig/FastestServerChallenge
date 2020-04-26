/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 03/10/2019
 * Description: Lobby class header file.
***************************************************************/
#include "Space.h"
#include "Guest.h"
#include "Waiter.h"

#include <vector>

#ifndef LOBBY_H
#define LOBBY_H

class Lobby : public Space
{
	public:
		//Constructor
		Lobby();

		//Destructor	
		~Lobby();

		//Methods
		void home(Waiter &);
};
#endif

