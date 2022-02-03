#include "LinkedList.h"

void linkedList::prependNode(Node*& Head, string userTitle, int userDay, int userMonth, int userYear)
{
	Node* newNode = new Node{ userTitle, userDay, userMonth, userYear, NULL, Head };
	Head = newNode;
}

void linkedList::appendNode(Node*& Head, string userTitle, int userDay, int userMonth, int userYear)
{
	Node* newNode = new Node{ userTitle, userDay, userMonth, userYear, NULL, NULL };

	Node* temp = Head;
	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->next = newNode;
			newNode->prev = temp;
			return;
		}
		temp = temp->next;
	}
}

void linkedList::printNodes(Node* Head)
{
	while (Head != NULL)
	{
		cout << Head->title << " - " << Head->day << "/" << Head->month << "/" << Head->year << endl;
		Head = Head->next;
	}
}