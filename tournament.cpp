#include <iostream> 
#include <string>
#include <cstdlib>
#include "lineup.h"
#include "character.h"
#include "barbarian.h"
#include "goblin.h"
#include "reptile.h"
#include "bluemen.h"
#include "shadow.h"

//function prototype
string playerSelect(string input, int &teamNum, Lineup &Team1, Lineup &Team2);

//function prototype
void showMenu();

using namespace std;

int main()
{
	int numPlayers;		//holds number of players
	int teamNum1 = 1;	//number for team 1
	int teamNum2 = 2;	//number for team 2
	int attack_roll;	//attacker roll total	
	int defense_roll;	//defender roll total
	string menuSelect;	//store menu selection
	string checkInput;	//checks string returned by function

	Lineup Team1;	//create team 1 list object
	Lineup Team2;	//create team 2 list object

	//Instructions to the user
	cout << endl << endl;
	cout << "Welcome to the tournament!" << endl;
	cout << "How many players should each side have? ";
	cin >> numPlayers;
	cout << endl;
	cout << "Each team will start out with " << numPlayers;
	cout << " players." << endl;
	cout << "Now let's pick the players for Team 1." << endl;
	cout << endl;

	//get team 1 input
	do
	{
		showMenu();	//display the menu
		cout << "Please choose Team 1's starting player from the main";
		cout << " menu: ";
		cin >> menuSelect;
		cout << endl;

		checkInput = playerSelect(menuSelect, teamNum1, Team1, Team2);

	}
	while (checkInput.at(0) == '0');

	for (int x = 1; x < numPlayers; x++)
	{
		cout << "You have " << numPlayers - x;
		cout << " players left to choose." << endl << endl;
		showMenu();	//display the menu
		cout << "Please choose your next player: ";
		cin >> menuSelect;
		cout << endl;

		checkInput = playerSelect(menuSelect, teamNum1, Team1, Team2);
	}

	cout << endl;

	do
        {
		showMenu();	//display the menu
                cout << "Please choose Team 2's starting player from the main";
                cout << " menu: ";
                cin >> menuSelect;
                cout << endl;

                checkInput = playerSelect(menuSelect, teamNum2, Team1, Team2);

        }
        while (checkInput.at(0) == '0');

        for (int x = 1; x < numPlayers; x++)
        {
                cout << "You have " << numPlayers - x;
                cout << " players left to choose." << endl << endl;
		showMenu();	//display the menu
                cout << "Please choose your next player: ";
                cin >> menuSelect;
                cout << endl;

                checkInput = playerSelect(menuSelect, teamNum2, Team1, Team2);
                cout << endl;
        }

	cout << "Team 1 is: " << endl;
	Team1.print();
	cout << endl;

	cout << "Team 2 is: " << endl;
	Team2.print();
	cout << endl;

	cout << "Team 1 will attack first." << endl;
	
	attack_roll = Team1.getNode()->ptrPlayer->attack();
	defense_roll = Team2.getNode()->ptrPlayer->defend();
	//Team2.getNode->ptrPlayer->setStrength(attack_roll, defense_roll);


	return 0;
}

/********************************************************************
 * playerSelect()
 *******************************************************************/
string playerSelect(string input, int &teamNum, Lineup &Team1, Lineup &Team2)
{
	string player;
	string playerName;

	if (input.at(0) == '0')
	{
		cout << "You've chosen Barbaian" << endl;
		cout << "Name your Barbarian: ";
		cin >> playerName;
		cin.ignore();
		Character *ptrBarbarian = new Barbarian(playerName);
		player = "Barbarian";
		
		if (teamNum == 1)
		{
			Team1.addBack(ptrBarbarian);
		}
		
		else if (teamNum == 2)
		{
			Team2.addBack(ptrBarbarian);
		}
		return player;		
	}	

	else if (input.at(0) == '1')
	{
		cout << "You've chosen Blue Men" << endl;
		cout << "Name your Blue Men clan: " << endl;
		cin >> playerName;
		cin.ignore();
		Character *ptrBlueMen = new BlueMen(playerName);
		player = "Blue Men";

		if (teamNum == 1)
		{
			Team1.addBack(ptrBlueMen);
		}

		else if (teamNum == 2)
		{
			Team2.addBack(ptrBlueMen);
		}
		return player;
	}

	else if (input.at(0) == '2')
	{
		cout << "You've chosen Reptile People" << endl;
		cout << "Name your Reptile People: " << endl;
		cin >> playerName;
		cin.ignore();
		Character *ptrReptile = new Reptile(playerName);
		player = "Reptile People";
	
		if (teamNum == 1)
		{
			Team1.addBack(ptrReptile);
		}
	
		else if (teamNum ==2)
		{
			Team2.addBack(ptrReptile);
		}
		return player;	
	}

	else if (input.at(0) == '3')
	{
		cout << "You've chosen The Shadow" << endl;
		cout << "Enter a name for The Shadow: " << endl;
		cin >> playerName;
		cin.ignore();
		Character *ptrShadow = new Shadow(playerName);
		player = "The Shadow";

		if (teamNum == 1)
		{
			Team1.addBack(ptrShadow);
		}

		else if (teamNum == 2)
		{
			Team2.addBack(ptrShadow);
		}
		return player;
	}

	else if (input.at(0) == '4')
	{
		cout << "You've chosen the Goblin" << endl;
		cout << "Enter a name for your Goblin: " << endl;
		cin >> playerName;
		cin.ignore();
		Character *ptrGoblin = new Goblin(playerName);
		player = "Goblin";

		if (teamNum == 1)
		{
			Team1.addBack(ptrGoblin);
		}

		else if (teamNum == 2)
		{
			Team2.addBack(ptrGoblin);
		}
		return player;
	}

	else
	{
		cout << "Invalid input. Please try again" << endl;
		player = "0";
		return player;
	}
}

/********************************************************************
 * showMenu()
 *******************************************************************/
void showMenu()
{
	cout << ">>>>>>>>>> Main Menu <<<<<<<<<<" << endl;
        cout << "[0] Barbarian" << endl;
        cout << "[1] Blue Men" << endl;
        cout << "[2] Reptile People" << endl;
        cout << "[3] The Shadow" << endl;
        cout << "[4] Goblin" << endl << endl;
}
