#include "character.h"
#ifndef BARBARIAN_H
#define BARBARIAN_H

class Barbarian : public Character
{
private:
	int roll1;	//number from first roll
	int roll2;	//number from second roll
public:
	Barbarian();	//constructor
	int attack();	//attack function	
	int defend();	//defense function
	//strength function
	void setStrength(int attack_roll, int defend_roll);
	
};
#endif
