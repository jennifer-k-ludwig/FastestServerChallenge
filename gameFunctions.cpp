/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 03/10/2019
 * Description: Game functions implementation file for server challenge. 
***************************************************************/

#include <algorithm>
#include <string>
#include <iostream>


#include "gameFunctions.h"

/***************************************************************
 * Function Name: bool isInteger
 * Parameters: std::string
 * Description: Returns false string is empty, returns true if
 * 		string length is 1 and the first char of string
 * 		is a digit, returns false if first char of 
 * 		string is - and the second char is not a digit,
 * 		and checks if the rest of the string is a digit.
 * Source: Phi Luu
***************************************************************/

bool isInteger(std::string s)
{
	if (s.empty())
		return false;

	if (s.length() == 1 && isdigit(s[0]))
		return true;

	if (s[0] != '-' && !isdigit(s[0]))
		return false;

	return (std::all_of(s.begin() + 1, s.end(), ::isdigit));
}


/***************************************************************
 * Function Name: void clearScreen
 * Parameters: None
 * Description: Clears screen by inserting 100 lines.
***************************************************************/

void clearScreen()
{
	std::cout << std::string(100, '\n');
}


