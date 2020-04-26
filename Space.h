/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 03/10/2019
 * Description: Space class header file.
***************************************************************/
#include "Waiter.h"
#include "Guest.h"

#include <string>
#include <vector> 

#ifndef SPACE_H
#define SPACE_H

class Space
{
	protected:
		Space *top;
		Space *right;
		Space *bottom;
		Space *left;
		
		std::vector <Guest> party1;
		std::vector <Guest> party2;
		std::vector <Guest> party3;
		std::vector <Guest> party4;

		bool party1Seated;
		bool party2Seated;
		bool party3Seated;
		bool party4Seated;
		bool occupied;
		bool ordered;
		bool eating;

		std::string party1Name;
		std::string party2Name;
		std::string party3Name;
		std::string party4Name;
		std::string name;

	public:
		//Constructor
		Space();

		//Destructor
		virtual ~Space() = 0;

		//Getters
		std::string getName();
		Space *getTop();
		Space *getLeft();
		Space *getRight();
		Space *getBottom();
		std::vector <Guest> getParty1();
		std::string getParty1Name();
		std::string getParty2Name();
		std::string getParty3Name();
		std::string getParty4Name();
		
		//Setters
		void setName(std::string);
		void setTop(Space *);
		void setLeft(Space *);
		void setRight(Space *);
		void setBottom(Space *);
		void setParty1(std::vector <Guest> &);
		void setParty1Name(std::string);
		void setParty2Name(std::string);
		void setParty3Name(std::string);
		void setParty4Name(std::string);

		//Methods
		virtual void home(Waiter &) = 0;
		bool isOccupied();
		bool isEating();
		bool partiesSeated();
};
#endif
