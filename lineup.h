#include "node.h"

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
	//int removeFront();
	//int removeBack();
	void print() const;
};
