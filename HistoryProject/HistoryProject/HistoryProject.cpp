#include "LinkedList.h"
#include "Menu.h"

int main()
{
    Node* Head = new Node{ "Birthday", 15, 11, 2005, NULL, NULL };
    
    menu();

    fileFunctions::writeToFile(Head);
}