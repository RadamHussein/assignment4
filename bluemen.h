#include "character.h"
#ifndef BLUEMEN_H
#define BLUEMEN_H

class BlueMen : public Character
{
private:
	int roll1;	//holds first roll
	int roll2;	//holds second roll
	int roll3;	//holds third roll
public:
        BlueMen();	//constructor
	int attack();	//attack function
	int defend();	//defense function
	//strength function
	void setStrength(int attack_roll, int defend_roll);
};
#endif

