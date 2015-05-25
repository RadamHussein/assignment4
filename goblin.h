#include "character.h"
#ifndef GOBLIN_H
#define GOBLIN_H

class Goblin : public Character
{
private: 
	int roll1;	//holds first roll
	int roll2;	//holds second roll
public:
        Goblin(string name);	//constructor
	int attack();	//attack function
	int defend();	//defense function
	//strength function
	int setStrength(int attack_roll, int defend_roll);
	void adjustStrength();
};
#endif
