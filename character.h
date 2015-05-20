#include <string>
#include <iostream>
#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;

class Character
{
protected:
	string name;	//name of character
        int armor;	//holds armor value
        int strength;	//holds strength value
        bool alive;	//character is alive or dead
	int damage;	//holds damage value
	int attack_dice;	//attack dice sides
	int defend_dice;	//defense dice sides
	int attack_total;	//total for attack roll
	int defend_total;	//total for defense roll
	bool achilles_cut;	//is achilles cut
public:
        Character();	//constructor
	int getArmor();		//return armor value
	int getStrength();	//return strength value
	string getAlive();	//return alive
	void setAlive();	//change alive variable
	string getName();	//return character's name
	void setAchilles();	//change value of achilles_cut
	virtual int attack() = 0;	//virtual function
	virtual int defend() = 0;	//virtual function
	//virtual function
	virtual void setStrength(int attack_roll, int defend_roll) = 0;
};
#endif