#include "LinkedList.h"
#include "Menu.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void linkedList::prependNode(Node*& Head, string userTitle, int userDay, int userMonth, int userYear)
{
	if (Head->title == "" && Head->day == 0 && Head->month == 0 && Head->year == 0)
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
	if (Head->title == "" && Head->day == 0 && Head->month == 0 && Head->year == 0)
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

	cout << " Enter event's Year:" << endl << "   > ";
	userYear = checkYear();
	cout << endl;

	cout << " Enter event's Month:" << endl << "   > ";
	userMonth = checkMonth();
	cout << endl;

	cout << " Enter event's Day:" << endl << "   > ";
	userDay = checkDay(userMonth, userYear);
	cout << endl;


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

	if (temp != NULL && temp->title == keyTitle && temp->day == keyDay && temp->month == keyMonth && temp->year == keyYear)
	{
		Head = temp->next;
		delete temp;
		return;
	}
	else
	{
		while (temp != NULL && temp->title != keyTitle && temp->day != keyDay && temp->month != keyMonth && temp->year != keyYear)
		{
			temp = temp->next;
			counter++;
		}

		if (temp == NULL)
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

void linkedList::modifyNode(Node*& Head)
{
	string keyTitle;
	cin >> keyTitle;
	int keyDay, keyMonth, keyYear;
	cin >> keyDay >> keyMonth >> keyYear;

	modifyGivenNode(Head, keyTitle, keyDay, keyMonth, keyYear);
}

void linkedList::modifyGivenNode(Node*& Head, string keyTitle, int keyDay, int keyMonth, int keyYear)
{
	Node* temp = Head;

	while (temp != NULL && temp->title != keyTitle && temp->day != keyDay && temp->month != keyMonth && temp->year != keyYear)
	{
		temp = temp->next;
	}

	if (temp != NULL)
	{
		temp->title = keyTitle;
		temp->day = keyDay;
		temp->month = keyMonth;
		temp->year = keyYear;
	}
}

void linkedList::printNodes(Node* Head)
{
	while (Head != NULL)
	{
		cout << Head->title << " - " << Head->day << "/" << Head->month << "/" << Head->year << endl;
		Head = Head->next;
	}
}

//Checks if the date exists
int checkDay(int userMonth, int userYear)
{
	int userDay;
	cin >> userDay;
	while (true) {
		//Checks if a year is leap or not (the first 2 lines)
		if (((userYear % 4 != 0) && (userYear % 100 != 0) && (userYear % 400 != 0) && (userMonth == 2) && (userDay > 28))
			|| ((userYear % 4 == 0) && (userYear % 100 != 0) && (userYear % 400 != 0) && (userMonth == 2) && (userDay > 29))
			|| (userMonth == 1) && (userDay > 31)
			|| (userMonth == 3) && (userDay > 31)
			|| (userMonth == 4) && (userDay > 30)
			|| (userMonth == 5) && (userDay > 31)
			|| (userMonth == 6) && (userDay > 30)
			|| (userMonth == 7) && (userDay > 31)
			|| (userMonth == 8) && (userDay > 31)
			|| (userMonth == 9) && (userDay > 30)
			|| (userMonth == 10) && (userDay > 31)
			|| (userMonth == 11) && (userDay > 30)
			|| (userMonth == 12) && (userDay > 31)
			|| (userDay < 1))
		{
			//Change the color to gray
			SetConsoleTextAttribute(console, 8);
			cout << endl << "        Incorrect input" << endl << "        > ";
			cin >> userDay;
			//Change to default color
			SetConsoleTextAttribute(console, 15);
		}
		else {
			break;
		}
	}
	return userDay;

}

//Checks if the date exists
int checkYear()
{
	int userYear;
	cin >> userYear;
	while (true) {
		if (userYear > 2022 || (userYear < 1))
		{
			//Change the color to gray
			SetConsoleTextAttribute(console, 8);
			cout << endl << "        Incorrect input" << endl << "        > ";
			cin >> userYear;
			//Change to default color
			SetConsoleTextAttribute(console, 15);
		}
		else {
			break;
		}
	}
	return userYear;
}

//Checks if the date exists
int checkMonth()
{
	int userMonth;
	cin >> userMonth;
	while (true) {
		if (userMonth > 12 || (userMonth < 1))
		{
			//Change the color to gray
			SetConsoleTextAttribute(console, 8);
			cout << endl << "        Incorrect input" << endl << "        > ";
			cin >> userMonth;
			//Change to default color
			SetConsoleTextAttribute(console, 15);
		}
		else {
			break;
		}
	}
	return userMonth;
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