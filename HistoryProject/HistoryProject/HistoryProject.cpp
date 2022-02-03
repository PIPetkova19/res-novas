#include "LinkedList.h"

int main()
{
    Node* Head = new Node{ "Birthday", 15, 11, 2005, NULL, NULL };
    
    linkedList::prependNode(Head, "test1", 10, 10, 2000);

    linkedList::appendNode(Head, "test2", 20, 20, 2000);
    linkedList::printNodes(Head);

    fileFunctions::writeToFile(Head);
}