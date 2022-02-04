#include "LinkedList.h"
#include "Menu.h"

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

	cout << " Enter event's Title:" << endl << "   > ";

	cin >> userTitle;

	cout << endl;

	cout << " Enter event's Day:" << endl << "   > ";

	cin >> userDay;

	cout << endl;

	cout << " Enter event's Month:" << endl << "   > ";

	cin >> userMonth;

	cout << endl;

	cout << " Enter event's Year:" << endl << "   > ";

	cin >> userYear;

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

	load();
}

void linkedList::removeGivenNode(Node*& Head, string keyTitle, int keyDay, int keyMonth, int keyYear)
{
	Node* temp = Head;
	int counter = 0;

	if(temp != NULL && temp->title == keyTitle && temp->day == keyDay && temp->month == keyMonth && temp->year == keyYear)
	{
		Head = temp->next;
		delete temp;
		return;
	}
	else
	{
		while(temp != NULL && temp->title != keyTitle && temp->day != keyDay &&temp->month != keyMonth && temp->year != keyYear)
		{
			temp = temp->next;
			counter++;
		}

		if(temp == NULL)
			return;
		
		if (!counter)
		{
			Head = Head->next;
			delete temp;
			return;
		}
		delete temp;
	}
}

void linkedList::removeNode(Node*& Head)
{
	string keyTitle;
	int keyDay, keyMonth, keyYear;

	getline(cin, keyTitle, '\n');
	cin >> keyDay >> keyMonth >> keyYear;

	linkedList::removeGivenNode(Head, keyTitle, keyDay, keyMonth, keyYear);
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