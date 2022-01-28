#include "PrintNodes.h"

void printNodes(Node* Head)
{
    while (Head != NULL)
    {
        string dayTemp = to_string(Head->day);
        string monthTemp = to_string(Head->month);
        string yearTemp = to_string(Head->year);

        if (Head->day < 10)
            dayTemp = "0" + to_string(Head->day);

        if (Head->month < 10)
            monthTemp = "0" + to_string(Head->month);

        cout << dayTemp << " / " << monthTemp << " / " << Head->year << endl;
        Head = Head->next;
    }
}