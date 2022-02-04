#include "LinkedList.h"
#include "Menu.h"

Node* Head = new Node;

int main()
{
    menu();
    fileFunctions::writeToFile(Head);
}