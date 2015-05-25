#include <iostream>
#include <cstdlib>
#include <ctime>
#include "character.h"
#include "barbarian.h"

using namespace std;

/********************************************************************
 * Function: Barbarian constructor
 * Description: Initializes all member variables of the barbarian
 * 		class
 * Parameters: None
 *******************************************************************/
Barbarian::Barbarian(string name) : Character(name)
{
	type = "Barbarian";
	armor = 0;
	strength = 12;
	alive = true;
	damage = 0;
	attack_dice = 6;
	defend_dice = 6;
	roll1 = 0;
	roll2 = 0;
	achilles_cut = false;
	attack_total = 0;
	defend_total = 0;
	srand(time(0));
}

/********************************************************************
 * Function: attack()
 * Description: Calculates the Barbarians attack roll and returns the
 * 		total back to main
 * Parameters: None
 *******************************************************************/
int Barbarian::attack()
{
	roll1 = (rand() % attack_dice + 1);
	roll2 = (rand() % attack_dice + 1);
	attack_total = roll1 + roll2;
	cout << "Barbarian rolls a " << roll1 << " and a ";
	cout << roll2 << "." << endl;
	
	if (achilles_cut == true)
	{
		cout << "The injury from the Goblin has halved the ";
		cout << "Barbarian's roll" << endl;
		attack_total = attack_total / 2;
	}

	return attack_total;
}
	
/********************************************************************
 * Function: defend()
 * Description: Calculates the defense roll of the barbarian class
 * 		and returns the results back to main
 * Parameters: None
 *******************************************************************/
int Barbarian::defend()
{
	roll1 = (rand() % defend_dice + 1);
	roll2 = (rand() % defend_dice + 1);
	defend_total = roll1 + roll2;
	cout << "Barbarian rolls a " << roll1 << " and a ";
	cout << roll2 << "." << endl;

	return defend_total;
}	

/********************************************************************
 * Function: strength()
 * Description: Takes in the total attack and defense rolls and 
 * 		calculates the damage incurred then changes the 
 * 		the strength points.
 * Parameters: int for attack total and defense total
 *******************************************************************/
int Barbarian::setStrength(int attack_roll, int defend_roll)
{
	damage = (attack_roll - defend_roll) - armor;

	if (damage > 0)
	{
		strength = (strength - damage);
		cout << "Damage to Barbarian" << endl << endl;
		return 1;
	}
	else if (damage < 1)
	{
		cout << "No damage to Barbarian" << endl << endl;
		return 0;
	}
}

/********************************************************************
 * Function :adjustStrength()
 * Description: adjust barbarian strength by 1 if they have lost strength
 * Parameters: none
 *******************************************************************/
void Barbarian::adjustStrength()
{
	if (strength < 12)
	{
		strength = strength + 1;
		cout << "Barbarian has recovered some strength." << endl << endl;
	}
	
	else
	{
		cout << "Barbarian remains at full strength." << endl << endl;
	}
}
