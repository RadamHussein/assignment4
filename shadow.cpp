#include <iostream>
#include <cstdlib>
#include <ctime>
#include "character.h"
#include "shadow.h"

using namespace std;

/********************************************************************
 * Function: Shadow constructor
 * Description: Initializes member variables of the Shadow class.
 * Parameters: None
 *******************************************************************/
Shadow::Shadow(string name) : Character(name)
{
	type = "The Shadow";
	armor = 0;
	strength = 12;
	alive = true;
	damage = 0;
	attack_dice = 10;
	defend_dice = 6;
	roll1 = 0;
	roll2 = 0;
	coinflip = 0;
	achilles_cut = false;
	attack_total = 0;
	defend_total = 0;
	srand(time(0));
}

/********************************************************************
 * Function: attack()
 * Descriptioin: Totals the attack rolls for the Shadow class and
 * 		returns the results to main
 * Parameters: None
 *******************************************************************/
int Shadow::attack()
{
        roll1 = (rand() % attack_dice + 1);
        roll2 = (rand() % attack_dice + 1);
        attack_total = roll1 + roll2;
        cout << "The Shadow rolls a " << roll1 << " and a ";
        cout << roll2 << "." << endl;
     

	if (achilles_cut == true)
	{
		cout << "The injury from the Goblin has halved The ";
		cout << "Shadow's roll." << endl;
		attack_total = attack_total / 2;
	}
        return attack_total;
}

/********************************************************************
 * Function: defend()
 * Description: Totals the defense roll for the shadow class and 
 * 		returns the results to main. Also flips a coin to 
 * 		generate a random 50% chance that the shadow could
 * 		have been missed. 
 * Parameters: None
 *******************************************************************/
int Shadow::defend()
{
	coinflip = (rand() % 2);

	if (coinflip == 0)
	{
		cout << "The Shadow has deceived! ";
		cout << "You have not seen the shadow." << endl;
	
		//set defend total to the highest possible attack total	
		defend_total = 20;
		return defend_total;
	}
	
	else
	{ 
        	roll1 = (rand() % defend_dice + 1);
        	defend_total = roll1;
        	cout << "The Shadow rolls a " << roll1 << ".";
	        cout << endl;

        	return defend_total;
	}
}

/********************************************************************
 * Function: strength()
 * Description: Takes in the attack total and defense total and 
 * 		calculates the damage. Then changes the value in 
 * 		strength if necessary.
 * Parameters: ints for attack total and defense total 
 *******************************************************************/
int Shadow::setStrength(int attack_roll, int defend_roll)
{
        damage = (attack_roll - defend_roll) - armor;
       
        if (damage > 0)
        {
                strength = (strength - damage);
                cout << "Damage to The Shadow" << endl << endl;
		return 1;
        }
        else if (damage < 1)
        {
                cout << "No damage to The Shadow" << endl << endl;
		return 0;
        }
}

/*********************************************************************
 * Function: adjustStrength()
 * Description: adjust strength by 1 if it is less than 12
 * Parameters: none
 *******************************************************************/
void Shadow::adjustStrength()
{
        if (strength < 12)
        {
                strength = strength + 1;
                cout << "The Shadow has recovered some strength." << endl << endl;
        }

	else 
	{
		cout << "The Shadow remains at full strength." << endl << endl;
	}
}

