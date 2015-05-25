#include "node.h"
#include "loserStack.h"

class Lineup
{
private:
	Node *head;
public:
	//constructor
	Lineup();
	~Lineup();	//destructor
	void addFront(Character *ptrPlayer);
	void addBack(Character *ptrPlayer);
	Node *getNode();
	void removeFront(LoserStack *ptrLosers);
	void print() const;
	void printStatus() const;
	int checkLineup();
};
