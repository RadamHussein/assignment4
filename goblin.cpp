#include <iostream>
#include <cstdlib>
#include <ctime>
#include "character.h"
#include "goblin.h"

using namespace std;

/********************************************************************
 * Function: Goblin constructor
 * Description: Initializes member variables for objects of the 
 * 		Goblin class
 * Parameters: None
 *******************************************************************/
Goblin::Goblin(string name) : Character(name)
{
	type = "Goblin";
	armor = 3;
	strength = 8;
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
 * Description: Totals the attack rolls for the Goblin class and 
 * 		returns the results to main.
 * Parameters: None
 *******************************************************************/
int Goblin::attack()
{
        roll1 = (rand() % attack_dice + 1);
        roll2 = (rand() % attack_dice + 1);
        attack_total = roll1 + roll2;
        cout << "Goblin rolls a " << roll1 << " and a ";
        cout << roll2 << "." << endl;

	if (attack_total == 12)
	{
		cout << "The Goblin has cut your achilles! ";
		cout << "Your attack rolls will be halved." << endl;
	}
        return attack_total;
}

/********************************************************************
 * Function: defend()
 * Description: Totals the defense rolls for the Goblin class and
 * 		returns the results to main
 * Parameters: None
 *******************************************************************/
int Goblin::defend()
{
        roll1 = (rand() % defend_dice + 1);
        defend_total = roll1;
        cout << "Goblin rolls a " << roll1 << "." << endl;

        return defend_total;
}

/********************************************************************
 * Function: strength()
 * Description: Takes the total attack and total defense rolls and 
 * 		calculates the damage. Then changes the strength
 * 		points if necessary.
 * Parameters: Ints for attack total and defense total 
 *******************************************************************/
int Goblin::setStrength(int attack_roll, int defend_roll)
{
        damage = (attack_roll - defend_roll) - armor;

        if (damage > 0)
        {
                strength = (strength - damage);
                cout << "Damage to Goblin" << endl << endl;
		return 1;
        }
        else if (damage < 1)
        {
                cout << "No damage to Goblin" << endl << endl;
		return 0;
        }
}

/********************************************************************
 * Function: adjustStrength()
 * Description: Adjust Goblins strength by 1 if it is less than 8
 * Parameters: none
 *******************************************************************/
void Goblin::adjustStrength()
{
        if (strength < 8)
        {
                strength = strength + 1;
                cout << "Goblin has recovered some strength." << endl << endl;
        }

	else
	{
		cout << "Goblin remains at full strength." << endl << endl;
	}
}


