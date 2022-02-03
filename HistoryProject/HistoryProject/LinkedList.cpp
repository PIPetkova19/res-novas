#include "LinkedList.h"

void linkedList::prependNode(Node*& Head, string userTitle, int userDay, int userMonth, int userYear)
{
	if(Head->title == "" && Head->day == 0 && Head->month == 0 && Head->year == 0)
	{
		Head->title = userTitle;
		Head->day = userDay;
		Head->month = userMonth;
		Head->year = userYear;
		return;
	}
	Node* newNode = new Node{ userTitle, userDay, userMonth, userYear, NULL, Head };
	Head = newNode;
}

void linkedList::appendNode(Node*& Head, string userTitle, int userDay, int userMonth, int userYear)
{
	if(Head->title == "" && Head->day == 0 && Head->month == 0 && Head->year == 0)
	{
		Head->title = userTitle;
		Head->day = userDay;
		Head->month = userMonth;
		Head->year = userYear;
		return;
	}
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

void linkedList::addNode(Node*& Head)
{
	string userTitle;
	int userDay, userMonth, userYear;

	getline(cin, userTitle, '\n');
	cin >> userDay >> userMonth >> userYear;

	Node* temp = Head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	if (userYear > temp->year)
	{
		linkedList::appendNode(Head, userTitle, userDay, userMonth, userYear);
	}
	else
	{
		linkedList::prependNode(Head, userTitle, userDay, userMonth, userYear);
	}
    fileFunctions::writeToFile(Head);
}

void linkedList::printNodes(Node* Head)
{
	while (Head != NULL)
	{
		cout << Head->title << " - " << Head->day << "/" << Head->month << "/" << Head->year << endl;
		Head = Head->next;
	}
}

void fileFunctions::writeToFile(Node* Head)
{
	ofstream MyFile("dateInfo.txt");

	while (Head != NULL)
	{
		MyFile << Head->title << " - " << Head->day << "/" << Head->month << "/" << Head->year << endl;
		Head = Head->next;
	}
}