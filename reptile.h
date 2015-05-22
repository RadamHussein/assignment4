#include "character.h"
#ifndef REPTILE_H
#define REPTILE_H

class Reptile : public Character
{
private:
	int roll1;	//holds first roll
	int roll2;	//holds second roll
	int roll3;	//holds third roll
public:
	Reptile(string name);	//constructor	
	int attack();	//attack function
	int defend();	//defense function
	//strength function
	void setStrength(int attack_roll, int defend_roll);

};
#endif

