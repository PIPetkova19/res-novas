#include "LinkedList.h"
#include "Menu.h"

Node* Head = new Node;

int main()
{
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    menu();
    fileFunctions::writeToFile(Head);
}