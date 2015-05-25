#include <iostream>
#include "lineup.h"
#include "loserStack.h"

using namespace std;
/*******************************************************************
 * Function: List() constructor
 * Description: Initializes the head pointer to NULL
 * Parameters: none
 *******************************************************************/
Lineup::Lineup()
{
	head = NULL;
}

/*******************************************************************
 * Function: getNode()
 * Description: this function returns the head pointer in order for 
 * 		the object it points to be to accessed in the list
 * Parameters: none
 ******************************************************************/
Node *Lineup::getNode()
{
	return head;
}	

/********************************************************************
 * Function: addBack()
 * Description: Takes in an int, creates a new node with the int, 
		and adds the node to the back of the list
 * Parameters: Takes in an integer value
 *******************************************************************/
void Lineup::addBack(Character *ptrPlayer)
{
	if (head == NULL)
	{
		head = new Node(ptrPlayer);
	}
	else
	{
		Node *ptrNode = head;
		while (ptrNode->next != NULL)
		{
			ptrNode = ptrNode->next;
			
		}
		ptrNode->next = new Node(ptrPlayer);
	}
}

/********************************************************************
 * Function: addFront()
 * Description: Takes in an int, creates a new Node with int value, 
		then adds the node to the front of the list
 * Parameters: Takes in an integer value
********************************************************************/
void Lineup::addFront(Character *ptrPlayer)
{
	if (head == NULL)
	{
		head = new Node(ptrPlayer);
	}
	else
	{
		head = new Node(ptrPlayer, head);	
	}
}	
/********************************************************************
 * Function: List() destructor
 * Description: destroys the list
 * Parameters: none
 *******************************************************************/
Lineup::~Lineup()
{
	Node *ptrNode = head;	//begin at head of list
	while (ptrNode != NULL)
	{
		Node *garbage = ptrNode;
		ptrNode = ptrNode->next;
		delete garbage;
	}
}

/********************************************************************
 * Function: print()
 * Description: transverses the list printing the value at each node
 * Parameters: none
 *******************************************************************/
void Lineup::print() const
{	
	Node *ptrNode = head;	//begin at head of list
	while (ptrNode)
	{
		cout << ptrNode->ptrPlayer->getType() << ": ";
		cout << ptrNode->ptrPlayer->getName() << " " << endl;
		ptrNode = ptrNode->next;
	}
}

/********************************************************************
 * printStatus()
 *******************************************************************/
void Lineup::printStatus() const
{
	Node *ptrNode = head; //begin at head of list
	while (ptrNode)
	{
		cout << ptrNode->ptrPlayer->getType() << endl;
		cout << "Name: " << ptrNode->ptrPlayer->getName() << endl;
		cout << "Strength: " << ptrNode->ptrPlayer->getStrength();
		cout << endl << endl;
		ptrNode = ptrNode->next;
	}
}

/********************************************************************
 * Function: checkLineup()
 * Description: looks through lineup to see how many nodes are left
 * Parameters: none
 *******************************************************************/
int Lineup::checkLineup()
{
	Node *ptrNode = head;	//begin at head of list
	int nodesLeft = 0;
	
	while (ptrNode)
	{
		ptrNode = ptrNode->next;
		nodesLeft++;
	}
	
	return nodesLeft;
}
/**************************************************************
 * Function: removeFront()
 * Description: Removes and element from the front of the list
		and updates remaining pointers
 * Parameters: none
 * Output: returns and integer value
**************************************************************/
void Lineup::removeFront(LoserStack *ptrLosers)
{
	Node *ptrNode;

		Character *ptrCharacter;	//new pointer to character
		ptrCharacter = head->ptrPlayer;	//store character in pointer
		ptrNode = head;			//copy head to node pointer
		head = head->next;		//point head to next pointer
		delete ptrNode;			//delete first node

	if (ptrCharacter->getAlive() == "living")
	{
                Node *ptrNewNode = head;	//create new node
                while (ptrNewNode->next != NULL)
                {
                        ptrNewNode = ptrNewNode->next;

                }
		//assign character to new node at the back
                ptrNewNode->next = new Node(ptrCharacter);	
	}
	
	else if (ptrCharacter->getAlive() == "dead")
	{
		ptrLosers->addFront(ptrCharacter);
	}
}

