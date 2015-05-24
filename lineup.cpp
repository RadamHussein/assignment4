#include <iostream>
#include "lineup.h"

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
 * getNode()
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
	cout << "hello from addBack()" << endl;

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

/**************************************************************
 * Function: removeFront()
 * Description: Removes and element from the front of the list
		and updates remaining pointers
 * Parameters: none
 * Output: returns and integer value
**************************************************************/
/*
int Lineup::removeFront()
{
	Node *ptrNode;

	if (!head)
	{
		return 0;
	}
	
	else
	{	
		int value = head->value;	//store val to return
		ptrNode = head;
		head = head->next;
		delete ptrNode;
		return value;
	}
}
*/
/**************************************************************
 * Function: removeBack()
 * Description: removes an element from the back of the list
 * Parameters: none
 * Output: returns and integer value
**************************************************************/
/*
int Lineup::removeBack()
{
	Node *ptrNode, *previousPtrNode;

	//check if list is empty
	if (!head)
	{
		return 0;
	}
	
	else 
	{
		Node *previousPtrNode = head;
		Node *ptrNode = head->next;

		//iterate through list skipping middle values
		while (ptrNode->next != NULL)
		{
			previousPtrNode = ptrNode;
			ptrNode = ptrNode->next;
		}

		//create variable to return 
		int nodeVal = ptrNode->value;
		delete ptrNode;
		previousPtrNode->next = NULL;
		return nodeVal;
	}
}*/
