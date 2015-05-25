#include <stddef.h>
#include "character.h"
#ifndef NODE_H
#define NODE_H

struct Node
{
	Character *ptrPlayer;
        Node *next;
	Node *previous;
        Node(Character *ptrPlayer, Node *next1 = NULL)
        {
		this->ptrPlayer = ptrPlayer;
                next = next1;
        }
};
#endif
