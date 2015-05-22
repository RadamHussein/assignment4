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
string playerSelect(string input);

//function prototype
void showMenu();

using namespace std;

int main()
{
	int numPlayers;		//holds number of players
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

		checkInput = playerSelect(menuSelect);

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

		checkInput = playerSelect(menuSelect);
	}

	cout << endl;

	do
        {
		showMenu();	//display the menu
                cout << "Please choose Team 2's starting player from the main";
                cout << " menu: ";
                cin >> menuSelect;
                cout << endl;

                checkInput = playerSelect(menuSelect);

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

                checkInput = playerSelect(menuSelect);
                cout << endl;
        }


	return 0;
}

/********************************************************************
 * playerSelect()
 *******************************************************************/
string playerSelect(string input)
{
	string player;
	string playerName;

	if (input.at(0) == '0')
	{
		cout << "You've chosen Barbaian" << endl;
		cout << "Name your Barbarian: ";
		cin >> playerName;
		Barbarian newBarbarian(playerName);
		player = "Barbarian";
		
		return player;		
	}	

	else if (input.at(0) == '1')
	{
		cout << "You've chosen Blue Men" << endl;
		cout << "Name your Blue Men clan: " << endl;
		cin >> playerName;
		BlueMen newBlueMen(playerName);
		player = "Blue Men";
		return player;
	}

	else if (input.at(0) == '2')
	{
		cout << "You've chosen Reptile People" << endl;
		cout << "Name your Reptile People: " << endl;
		cin >> playerName;
		Reptile newReptile(playerName);
		player = "Reptile People";
		return player;	
	}

	else if (input.at(0) == '3')
	{
		cout << "You've chosen The Shadow" << endl;
		cout << "Enter a name for The Shadow: " << endl;
		cin >> playerName;
		Shadow newShadow(playerName);
		player = "The Shadow";
		return player;
	}

	else if (input.at(0) == '4')
	{
		cout << "You've chosen the Goblin" << endl;
		cout << "Enter a name for your Goblin: " << endl;
		cin >> playerName;
		Goblin newGoblin(playerName);
		player = "Goblin";
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
