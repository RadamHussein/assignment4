#include <string>
#include <iostream>
#include "character.h"

using namespace std;

/********************************************************************
 * Function: Character constructor
 * Description: Initializes Objects of the Character class
 * 		Does not initialize all variables since Character 
 * 		is an abstract class
 * Parameters: None
 *******************************************************************/
Character::Character(string name)
{
	alive = true;
	this->name = name;
}

/********************************************************************
 * Function: getArmor()
 * Description: Returns the armor value from an object of the 
 * 		Character class
 * Parameters: None
 *******************************************************************/
int Character::getArmor()
{
	return armor;
}

/********************************************************************
 * Function: getStrenght()
 * Descriptioin: Returns the strength value from an object of the 
 * 		Character class
 * Parameters: None
 *******************************************************************/
int Character::getStrength()
{
	return strength;
}

/********************************************************************
 * Function: getAlive()
 * Description: Returns a string based on the bool value alive to 
 * 		indicate if a player is living or dead.
 * Parameters: None
 *******************************************************************/
string Character::getAlive()
{
	string living = "living";
	string dead = "dead";

	if (alive == true)
	{
		return living;
	}
	
	else if (alive == false)
	{
		return dead;
	}
}

/********************************************************************
 * Function: getName()
 * Description: Returns the string holding the name of the player
 * 		for a Character object
 * Parameters: None
 *******************************************************************/
string Character::getName()
{
	return name;
}

/********************************************************************
 * Function: setAlive()
 * Descriptioin: Changes the value of alive bool when a player has 
 * 		run out of strength points
 * Parameters: None
 *******************************************************************/
void Character::setAlive()
{
	alive = false;
}

/********************************************************************
 * Function: setAchilles()
 * Description: Changes the value of the acchilles_cut bool when 
 * 		a Goblin rolls a 12 on its attack roll
 * Paramters: None
 *******************************************************************/
void Character::setAchilles()
{
	achilles_cut = true;
}
