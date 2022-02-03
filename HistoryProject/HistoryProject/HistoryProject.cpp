#include "LinkedList.h"
#include "Menu.h"

Node* Head = new Node{ "example", 10, 10, 2000, NULL, NULL };

int main()
{
    
    menu();

    fileFunctions::writeToFile(Head);
}