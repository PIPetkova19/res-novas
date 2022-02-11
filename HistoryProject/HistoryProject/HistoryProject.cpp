#include "LinkedList.h"
#include "Menu.h"

Node* Head = new Node;
string userName;

int main()
{  
    userName = userInfo();
    system("cls");
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    menu();
}