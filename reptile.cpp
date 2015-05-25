#include <iostream>
#include <cstdlib>
#include <ctime>
#include "character.h"
#include "reptile.h"

using namespace std;

/********************************************************************
 * Function: Reptile constructor
 * Description: Constructor to initialize member variables of the 
 * 		Reptile class
 * Paramters: None
 *******************************************************************/
Reptile::Reptile(string name) : Character(name)
{
	type = "Reptile People";
	armor = 7;
	strength = 18;
	alive = true;
	damage = 0;
	attack_dice = 6;
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
 * Description: Totals the attack rolls for the Reptile class and
 * 		returns the value to main
 * Parameters: None
 *******************************************************************/
int Reptile::attack()
{
        roll1 = (rand() % attack_dice + 1);
        roll2 = (rand() % attack_dice + 1);
	roll3 = (rand() % attack_dice + 1);
        attack_total = roll1 + roll2 + roll3;
        cout << "Reptile People roll a " << roll1 << " a ";
        cout << roll2 << " and a " << roll3 << endl;
        

	if (achilles_cut == true)
	{
		cout << "The injury from the Goblin has halved the ";
		cout << "Reptile People's roll." << endl;
		attack_total = attack_total / 2;
	}
        return attack_total;
}

/********************************************************************
 * Function: defend()
 * Description: Totals the defense rolls for the Reptile class and 
 * 		returns the results to main
 * Parameters: None
 *******************************************************************/
int Reptile::defend()
{       
        roll1 = (rand() % defend_dice + 1);
        defend_total = roll1;
        cout << "Reptile People roll a " << roll1 << "." << endl;
    

        return defend_total;
}

/********************************************************************
 * Function: setStrength()
 * Description: Takes the total attack roll and the total defense roll
 * 		and calculates the damage. Then changes the strength
 * 		points if necessary. 
 * Parameters: ints for attack total and defense total. 
 *******************************************************************/
int Reptile::setStrength(int attack_roll, int defend_roll)
{
        damage = (attack_roll - defend_roll) - armor;
        
        if (damage > 0)
        {
                strength = (strength - damage);
                cout << "Damage to Reptile People" << endl << endl;
		return 1;
        }
        else if (damage < 1)
        {
                cout << "No damage to Reptile People" << endl << endl;
		return 0;
        }
}

/********************************************************************
 * Function: adjustStrength()
 * Description: Adjust Reptile People's strength by 1 if it is less 
 * 		than 18. 
 * Parameters: none
 *******************************************************************/
void Reptile::adjustStrength()
{
        if (strength < 18)
        {
                strength = strength + 1;
                cout << "The Reptile Poeple have recovered some strength." << endl << endl;
        }
	
	else
	{
		cout << "The Reptile People remain at full strength." << endl << endl;
	}
}

