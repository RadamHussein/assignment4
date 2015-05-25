/********************************************************************
 * Filename: tournament.cpp
 * Author: Adam Smith
 * Date: 05/24/2015
 * Description:  This program is a fantasy fighting game. It will 
 * 		run a tournament between between a number of players
 * 		on two teams. The number of players is specified by the
 * 		user. The program will run battles between opposing
 * 		characters on the list. If a character is killed they 
 * 		will be removed from their teams lineup and placed in 
 * 		the front of a loser list. If a player scores damage on 
 * 		another player, and the attacker is not at full strength
 * 		they will receive one additional strength point. The 
 * 		team's lineups will rotate after each round of play. Once
 * 		a team is left with only 1 player, the game is over and
 * 		the opposing team wins. 
 * Input: The user will input the number of players each team will have,
 * 	the type of creatures that each player on each team will be, and
 * 	the name of each creatures. 
 * Output: The program outputs instructions to the user. It will print
 * 	the lineup before each new round and print the status of the
 * 	players after each round. If a player scores damage, the program
 * 	will output it. If a player gains strength points, this will also
 * 	be output to the user. The program will declare who is the winner
 * 	and the loser at the end of the game. 
 ********************************************************************/

#include <iostream> 
#include <string>
#include <cstdlib>
#include "lineup.h"
#include "loserStack.h"
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
	int hit;		//stores a value if a player is damaged
	string menuSelect;	//store menu selection
	string checkInput;	//checks string returned by function

	Lineup Team1;	//create team 1 list object
	Lineup Team2;	//create team 2 list object
	LoserStack Losers;	//create a loser list object
	LoserStack *ptrLosers;	//create a pointer to a loser object
	ptrLosers = &Losers;	//assign Losers object to loser pointer

	//Instructions to the user
	cout << endl << endl;
	cout << "Welcome to the tournament!" << endl;

	do 
	{
		cout << "How many players should each side have? ";
		cin >> numPlayers;
		cout << endl;
	
		if (numPlayers < 2)
		{
			cout << "You must have at least 2 players on each team." << endl;
		}
	}
	while (numPlayers < 2);

	//instructions to the user
	cout << "Each team will start out with " << numPlayers;
	cout << " players." << endl;
	cout << "Now let's pick the players for Team 1." << endl;
	cout << endl;

	//set the size of lineups for each team
	int lineup1 = numPlayers;
	int lineup2 = numPlayers;

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

	//loop to input players
	for (int x = 1; x < numPlayers; x++)
	{
		cout << "You have " << numPlayers - x;
		cout << " players left to choose." << endl << endl;
		showMenu();	//display the menu
		cout << "Please choose your next player: ";
		cin >> menuSelect;
		cout << endl << endl;

		checkInput = playerSelect(menuSelect, teamNum1, Team1, Team2);
	}

	cout << endl;

	//loop to check for valid input
	do
        {
		showMenu();	//display the menu
                cout << "Please choose Team 2's starting player from the main";
                cout << " menu: ";
                cin >> menuSelect;
                cout << endl << endl;

                checkInput = playerSelect(menuSelect, teamNum2, Team1, Team2);

        }
        while (checkInput.at(0) == '0');

	//loop to choose players
        for (int x = 1; x < numPlayers; x++)
        {
                cout << "You have " << numPlayers - x;
                cout << " players left to choose." << endl << endl;
		showMenu();	//display the menu
                cout << "Please choose your next player: ";
                getline (cin, menuSelect);
                cout << endl << endl;

                checkInput = playerSelect(menuSelect, teamNum2, Team1, Team2);
                cout << endl;
        }

	//print lineups
	cout << "Team 1 lineup: " << endl;
	Team1.print();
	cout << endl;

	cout << "Team 2 lineup: " << endl;
	Team2.print();
	cout << endl;

	int x = 0;	//counter variable

	//loop for battle
	do
	{
	cout << ">>>>>>>>> Round " << x + 1  << " <<<<<<<<<" << endl;
	cout << "Matchup: " << Team1.getNode()->ptrPlayer->getName();
	cout << " vs. " << Team2.getNode()->ptrPlayer->getName() << endl;
	
	//Team 1 attacks, Team 2 defends
	attack_roll = Team1.getNode()->ptrPlayer->attack();
	defense_roll = Team2.getNode()->ptrPlayer->defend();
	hit = Team2.getNode()->ptrPlayer->setStrength(attack_roll, defense_roll);

	//add strength point if player scored damage
	if (hit == 1)
	{
		Team1.getNode()->ptrPlayer->adjustStrength();
	}

	//check for Goblin damage
	if (attack_roll == 12 && Team1.getNode()->ptrPlayer->getType() == "Goblin")
        {
                Team2.getNode()->ptrPlayer->setAchilles();
        }

	//check if Team 2's character died in attack
	if (Team2.getNode()->ptrPlayer->getStrength() < 1)
	{
		cout << Team2.getNode()->ptrPlayer->getName();
		cout << " the " << Team2.getNode()->ptrPlayer->getType();
		cout << " is dead " << endl << endl;
		Team2.getNode()->ptrPlayer->setAlive();
	
		//add remove function to remove dead player
		Team2.removeFront(ptrLosers);

		//check for enough players to continue
		lineup1 = Team1.checkLineup();
        	lineup2 = Team2.checkLineup();

		if (lineup1 ==1 || lineup2 == 1)
		{
			break;
		}
	}

	else
	{
		//Team 2 attacks, Team 1 defends
		cout << "Team 2 return attack: " << endl;
		attack_roll = Team2.getNode()->ptrPlayer->attack();
		defense_roll = Team1.getNode()->ptrPlayer->defend();
		hit = Team1.getNode()->ptrPlayer->setStrength(attack_roll, defense_roll);
		
		//add strength if player scored damage
		if (hit == 1)
		{
			Team2.getNode()->ptrPlayer->adjustStrength();
		}
	
		//check for Goblin damage
		if (attack_roll == 12 && Team2.getNode()->ptrPlayer->getType() == "Goblin")
        	{
                	Team1.getNode()->ptrPlayer->setAchilles();
        	}	
	
		//Check if Team 1's character died in attack
		if (Team1.getNode()->ptrPlayer->getStrength() < 1)
		{
			cout << Team1.getNode()->ptrPlayer->getName();
			cout << " the ";
			cout << Team1.getNode()->ptrPlayer->getType();
			cout << " is dead " << endl << endl;
			Team1.getNode()->ptrPlayer->setAlive();

		}

	}

	//print teams
	cout << "Team 1 Player status after round:" << endl;
	Team1.printStatus();
	cout << endl << endl;
	cout << "Team 2 Player status after round:" << endl;
	Team2.printStatus();
	cout << endl << endl;

	cout << ">>> Team 1 lineup <<< " << endl;
	Team1.removeFront(ptrLosers);
	Team1.print();
	cout << endl << endl;

	cout << ">>> Team 2 lineup <<< " << endl;
	Team2.removeFront(ptrLosers);
	Team2.print();
	cout << endl << endl;
	
	cout << ">>> Loser List <<< " << endl;
	Losers.print();
	cout << endl << endl;

	//check the number of players in each team
	lineup1 = Team1.checkLineup();
        lineup2 = Team2.checkLineup();

	//end loop if someone has lost
         if (lineup1 == 1 || lineup2 == 1)
         {
         	break;
         }

	x++;
	}
	while (lineup1 != 1 && lineup2 != 1);

	//check which side has won
	if (lineup1 == 1)
	{
		cout << "Team 1 has lost the tournament.";
		cout << " Team 2 is the winner!" << endl << endl;
	}

	else if (lineup2 == 1)
	{
		cout << "Team 2 has lost the tournament.";
		cout << " Team 1 is the winner!" << endl << endl;
	}

	//print final lineup
	cout << "Team 1 lineup: " << endl;
        Team1.print();
        cout << endl << endl;

        cout << "Team 2 lineup: " << endl;
        Team2.print();
        cout << endl << endl;

	return 0;
}

/********************************************************************
 * Function: playerSelect()
 * Description: This function determines which creatures are being
 * 		selected from the menu by the user and creates
 * 		new creature objects.
 * Parameters: accepts a string for the menu input, and pointers to
 * 		which teams that the player will be sent to. 
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
		cout << endl;
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
		cout << endl;
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
		cout << endl;
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
		cout << endl;
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
		cout << endl;
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
 * Function: showMenu()
 * Description: This function prints the main menu for the character
 * 		selection
 * Parameters: none
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
