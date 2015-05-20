/********************************************************************
 * Program Filename: main.cpp
 * Author: Adam Smith
 * Date: 05/10/2015
 * Description: This is a fantasy battle game. The user is able to 
 * 		choose to do battle between 5 characters: Goblin, 
 * 		The Shadow, Blue Men, Barbarian and Goblin. The program
 * 		allows the user to choose the attacker and defender 
 * 		for each round. The program then simulates dice rolls
 * 		for each of the attackers and defenders and based off
 * 		those rolls it calulates the damage. The user is able
 * 		to view the damage incurred after each round.
 * Input: The user is asked for input from a main menu. The user will
 * 	be able to select to play another round, list the characteres, 
 * 	or quit.
 * Output: The program will output a main menu to the user to select
 * 	from. When selecting to play a round, the program will present
 * 	the user with a secondary menu to select the attackers and 
 * 	defenders. If the user enters someting incorrectly the program
 * 	will inform the user and ask them to try again. Once the input
 * 	is correct, the program will output the simulation of the game, 
 * 	informing the user of the rolls for each character and the 
 * 	results of those rolls. The user will also have the option 
 * 	after each round to list the characters and get their status
 * 	which will print all the characters to the screen. 
 *******************************************************************/
#include <iostream> 
#include <string>
#include <cstdlib>
#include "character.h"
#include "barbarian.h"
#include "goblin.h"
#include "reptile.h"
#include "bluemen.h"
#include "shadow.h"

using namespace std;

int main()
{
	const int NUM_PLAYERS = 5;	//defines size of an array

	//create Barbarian
	Character *pBar;		//pointer to a Character object
	Barbarian gameBarbarian;	//create Barbarian object
	pBar = &gameBarbarian;		//pointer to Barbarian
	
	//create Goblin
	Character *pGob;		//pointer to a Character object
	Goblin gameGoblin;		//create Goblin object
	pGob = &gameGoblin;		//pointer to Goblin
	
	//create Reptile
	Character *pRep;		//pointer to a Character object
	Reptile gameReptile;		//create Reptile object
	pRep = &gameReptile;		//pointer to Reptile

	//create Blue Men
	Character *pBlue;		//pointer to a Character Object
	BlueMen gameBlueMen;		//create Blue Men object
	pBlue = &gameBlueMen;		//pointer to BlueMen

	//create Shadow
	Character *pShad;		//pointer to a Character Object
	Shadow gameShadow;		//create Shadow object
	pShad = &gameShadow;		//poiter to Shadow

	string menuSelect;		//store main menu selection
	string attack;			//store attack selection
	string defend;			//store defense selection
	int attack_num;			//character position in the array
	int defend_num;			//character position in the array
	int attack_roll;		//attacker roll total
	int defend_roll;		//defender roll total
	
	//array to hold pointers to character objects	
	Character *players[NUM_PLAYERS] = {pBar, pBlue, pRep, pShad, pGob};

	cout << endl;
	cout << "Welcome to the game!" << endl << endl;

	do
	{
		//output to the user and instructions
		cout << ">>>>>>>>>> Main Menu <<<<<<<<<<" << endl;
		cout << "[1] Play New Round" << endl;
		cout << "[2] Display Characters" << endl;
		cout << "[3] Quit" << endl << endl;
	
		cout << "Please enter your selection: ";
		cin >> menuSelect;
		cout << endl;

		//check for user input
		if (menuSelect.at(0) == '1')
		{
			do
			{	
				//menu to select characters
				cout << "[0] Barbarian" << endl;
				cout << "[1] Blue Men" << endl;
				cout << "[2] Reptile People" << endl;
				cout << "[3] The Shadow" << endl;
				cout << "[4] Goblin" << endl << endl;
				cout << "Choose an attacker: ";
				cin >> attack;
				cout << endl;
					
				//check for user input
				if (attack.at(0) > '4')
				{
					cout << "Not a valid selection" << endl;
				}
			
				else
				{
					//convert string entered to an int
					attack_num = atoi(attack.c_str());
				}

				//check if user selection is alive
				if (players[attack_num]->getAlive() == "dead")
				{
					cout << players[attack_num]->getName();
					cout << " is dead" << endl << endl;
				}
			}
			while (attack.at(0) > '4' || players[attack_num]->getAlive() == "dead");

			do
			{
				//instructions to user
				cout << "Choose a defender: ";
				cin >> defend;
				cout << endl;
				
				//check user input
				if (defend.at(0) > '4')
				{
					cout << "Not a valid selection" << endl;
				}
			
				else
				{
					//convert string to int
					defend_num = atoi(defend.c_str());
				}

				//check if player is alive
				if (players[defend_num]->getAlive() == "dead")
				{
					cout << players[defend_num]->getName();
					cout << " is dead" << endl << endl;
				}
			}
			while (defend.at(0) > '4' || players[defend_num]->getAlive() == "dead");
		
			//limit fights to only other characters
			if (attack_num == defend_num)
			{
				cout << "Cannot have a character fight itself";
				cout << endl << endl;
			}
			
			else
			{	
				//announce the match
				cout << ">> " << players[attack_num]->getName();
				cout << " vs. " << players[defend_num]->getName();
				cout << " <<" << endl;

				//call attack and defense functions
				attack_roll = players[attack_num]->attack();
				defend_roll = players[defend_num]->defend();
				players[defend_num]->setStrength(attack_roll, defend_roll);

				//check for Goblin damage
				if (attack_roll == 12 && attack_num == 4)
				{	
					players[defend_num]->setAchilles();
				}
			
				//keep playing if defender lived through battle
				if (players[defend_num]->getStrength() > 0)
				{
					//reverse attacker and defender
					cout << ">> " << "Counter Attack";
					cout << " <<" << endl;
					attack_roll = players[defend_num]->attack();
					defend_roll = players[attack_num]->defend();
					players[attack_num]->setStrength(attack_roll, defend_roll);

					//check if player is alive
					if (players[attack_num]->getStrength() < 1)
					{
						cout << players[attack_num]->getName();
						cout << " is dead" << endl << endl;
						players[attack_num]->setAlive();
					}
					
					//check for Goblin damage
					if (attack_roll == 12 && defend_num == 4)
					{
						players[attack_num]->setAchilles();
					}
				}
				//check if player is alive
				else if (players[defend_num]->getStrength() < 1)
				{
					cout << players[defend_num]->getName();
					cout << " is dead" << endl << endl;
					players[defend_num]->setAlive();
				}
			}
		}

		//show characters
		else if (menuSelect.at(0) == '2')
		{
			cout << "Barbarian" << endl;
			cout << "Armor: " << gameBarbarian.getArmor() << endl;
			cout << "Strength: ";
			cout << gameBarbarian.getStrength() << endl;
			cout << "Status: ";
			cout << gameBarbarian.getAlive() << endl << endl;
	
			cout << "Goblin" << endl;
			cout << "Armor: " << gameGoblin.getArmor() << endl;
			cout << "Strength: ";
			cout << gameGoblin.getStrength() << endl;
			cout << "Status: ";
			cout << gameGoblin.getAlive() << endl << endl;
	
			cout << "Reptile" << endl;
			cout << "Armor: " << gameReptile.getArmor() << endl;
			cout << "Strength: ";
			cout << gameReptile.getStrength() << endl;
			cout << "Status: ";
			cout << gameReptile.getAlive() << endl << endl;
	
			cout << "Blue Men" << endl;
			cout << "Armor: " << gameBlueMen.getArmor() << endl;
			cout << "Strength: ";
			cout << gameBlueMen.getStrength() << endl;
			cout << "Status: ";
			cout << gameBlueMen.getAlive() << endl << endl;	
	
			cout << "The Shadow" << endl;
			cout << "Armor: " << gameShadow.getArmor() << endl;
			cout << "Strength: ";
			cout << gameShadow.getStrength() << endl;
			cout << "Status: ";
			cout << gameShadow.getAlive() << endl << endl;	
	
		}

		//user selects to quit
		else if (menuSelect.at(0) != '1' && menuSelect.at(0) > '3')
		{
			cout << "Not a valid selection" << endl;
		}
	}
	while(menuSelect.at(0) != '3');

	return 0;
}


