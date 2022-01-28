#include "NodeInsert.cpp"
#include "PrintNodes.cpp"

int main()
{
    Node* Head = new Node;

    int userDay, userMonth, userYear;
    cin >> userDay >> userMonth >> userYear;

    Head->day = userDay;
    Head->month = userMonth;
    Head->year = userYear;
    printNodes(Head);

    cin >> userDay >> userMonth >> userYear;
    prependNode(Head, userDay, userMonth, userYear);
    printNodes(Head);

    cin >> userDay >> userMonth >> userYear;
    appendNode(Head, userDay, userMonth, userYear);
    printNodes(Head);
}