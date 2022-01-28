#include "NodeInsert.h"

void prependNode(Node*& Head, int userDay, int userMonth, int userYear)
{
    Node* newNode = new Node{ userDay, userMonth, userYear, NULL, Head };
    newNode->next = Head;
    Head->prev = newNode;

    Head = newNode;
}

void appendNode(Node* Head, int userDay, int userMonth, int userYear)
{
    Node* newNode = new Node{ userDay, userMonth, userYear };

    Node* temp = new Node;
    temp = Head;
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