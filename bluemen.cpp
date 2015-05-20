#include <iostream>
#include <cstdlib>
#include <ctime>
#include "character.h"
#include "bluemen.h"

using namespace std;

/********************************************************************
 * Function: BlueMen constructor
 * Description: Initializes all the variables of the BlueMen class.
 * Parameters: None
 *******************************************************************/
BlueMen::BlueMen()
{
	name = "Blue Men";
	armor = 3;
	strength = 12;
	alive = true;
	damage = 0;
	attack_dice = 10;
	defend_dice = 6;
	roll1 = 0;
	roll2 = 0;
	roll3 = 0;
	achilles_cut = false;
	attack_total = 0;
	defend_total = 0;
	
	srand(time(0));
}

/********************************************************************
 * Function: attack()
 * Description: Calculates the total of dice rolled on an attack roll 
 * 		and returns the results to main
 * Parameters: None
 *******************************************************************/
int BlueMen::attack()
{
	roll1 = (rand() % attack_dice + 1);
	roll2 = (rand() % attack_dice + 1);
	attack_total = roll1 + roll2;
	cout << "Blue Men roll a " << roll1 << " and a ";
	cout << roll2 << "." << endl;

	if (achilles_cut == true)
	{
		cout << "The injury from the Goblin has halved the ";
		cout << "Blue Men's roll." << endl;
		attack_total = attack_total / 2;
		cout << "new attack total " << attack_total << endl;
	}
	return attack_total;
}

/********************************************************************
 * Function: defend()
 * Description: Calculates the total of the dice rolled for defense
 * 		and returns the results to main
 * Parameters: None
 *******************************************************************/
int BlueMen::defend()
{
	roll1 = (rand() % defend_dice + 1);
	roll2 = (rand() % defend_dice + 1);
	roll3 = (rand() % defend_dice + 1);
	defend_total = roll1 + roll2 + roll3;
	cout << "Blue Men roll a " << roll1 << " a " << roll2;
	cout << " and a " << roll3 << endl;

	return defend_total;
}

/********************************************************************
 * Function: strength()
 * Description: Takes in the total attack and defense roll and 
 * 		calculates the damage. Then if necessary, changes
 * 		the strength points. 
 * Parameters: ints for attack total and defense total
 *******************************************************************/
void BlueMen::setStrength(int attack_roll, int defend_roll)
{
	damage = (attack_roll - defend_roll) - armor;

	if (damage > 0)
	{
		strength = (strength - damage);
		cout << "Damage to Blue Men" << endl << endl;
	}
	else if (damage < 1)
	{
		cout << "No damage to Blue Men" << endl << endl;
	}
}

