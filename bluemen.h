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
        BlueMen(string name);	//constructor
	int attack();	//attack function
	int defend();	//defense function
	//strength function
	int setStrength(int attack_roll, int defend_roll);
	void adjustStrength();
};
#endif

