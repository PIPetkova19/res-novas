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

void linkedList::addBetween(Node*& Head, string userTitle, int userDay, int userMonth, int userYear)
{
	Node* temp = Head;
	if (Head->title == "" && Head->day == 0 && Head->month == 0 && Head->year == 0)
	{
		Head->title = userTitle;
		Head->day = userDay;
		Head->month = userMonth;
		Head->year = userYear;
		return;
	}

	Node* newNode = new Node{ userTitle, userDay, userMonth, userYear};

	if (temp->next != NULL)
		while (checkFunctions::checkBigger(temp, newNode))
		{
			if (temp->next == NULL)
				break;
			temp = temp->next;
		}

	if (!checkFunctions::checkBigger(newNode, temp))
	{
		linkedList::prependNode(Head, userTitle, userDay, userMonth, userYear);
		return;
	}

	Node* tempAddress = temp->next;
	temp->next = newNode;
	newNode->next = tempAddress;
	temp->next->prev = newNode;
	newNode->prev = temp;
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

	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

	cout << setw(115) << "Enter event's Title:" << endl << setw(100) << "   > ";
	cin.ignore();
	getline(cin, userTitle);
	cout << endl;

	cout << setw(114) << "Enter event's Year:" << endl << setw(100) << "   > ";
	userYear = checkFunctions::checkYear();
	cout << endl;

	cout << setw(115) << "Enter event's Month:" << endl << setw(100) << "   > ";
	userMonth = checkFunctions::checkMonth();
	cout << endl;

	cout << setw(113) << "Enter event's Day:" << endl << setw(100) << "   > ";
	userDay = checkFunctions::checkDay(userMonth, userYear);

	Node* temp = Head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	Node* newNode = new Node{ userTitle, userDay, userMonth, userYear };

	if (checkFunctions::checkBigger(newNode, temp))
	{
		linkedList::appendNode(Head, userTitle, userDay, userMonth, userYear);
	}
	else
	{
		linkedList::addBetween(Head, userTitle, userDay, userMonth, userYear);
	}

	fileFunctions::writeToFile(Head);
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
	fileFunctions::writeToFile(Head);
}

void linkedList::modifyNode(Node*& Head)
{
	string keyTitle;
	cin >> keyTitle;
	int keyDay, keyMonth, keyYear;
	cin >> keyDay >> keyMonth >> keyYear;

	modifyGivenNode(Head, keyTitle, keyDay, keyMonth, keyYear);
	fileFunctions::writeToFile(Head);
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
	fileFunctions::writeToFile(Head);
}

//Checks if the date exists
int checkFunctions::checkDay(int userMonth, int userYear)
{
	string userDay;

	while (true) {
		//Check if the day is invalid of if there is a char
		try {
			cin >> userDay;
			//Checks if a year is leap or not (the first 2 lines)
			if (((userYear % 4 != 0) && (userYear % 100 != 0) && (userYear % 400 != 0) && (userMonth == 2) && (stoi(userDay) > 28))
				|| ((userYear % 4 == 0) && (userYear % 100 != 0) && (userYear % 400 != 0) && (userMonth == 2) && (stoi(userDay) > 29))
				|| (userMonth == 1) && (stoi(userDay) > 31)
				|| (userMonth == 3) && (stoi(userDay) > 31)
				|| (userMonth == 4) && (stoi(userDay) > 30)
				|| (userMonth == 5) && (stoi(userDay) > 31)
				|| (userMonth == 6) && (stoi(userDay) > 30)
				|| (userMonth == 7) && (stoi(userDay) > 31)
				|| (userMonth == 8) && (stoi(userDay) > 31)
				|| (userMonth == 9) && (stoi(userDay) > 30)
				|| (userMonth == 10) && (stoi(userDay) > 31)
				|| (userMonth == 11) && (stoi(userDay) > 30)
				|| (userMonth == 12) && (stoi(userDay) > 31)
				|| (stoi(userDay) < 1)
				|| ((userDay >= "A") && (userDay <= "z")))
			{
				throw 1;
			}

			else {
				break;
			}
		}

		catch (...)
		{
			//Change the color to gray
			colorText(8);
			cout << endl << setw(117) << "Incorrect input" << endl << setw(108) << "   > ";
			//Change to default color
			colorText(15);
		}
	}
	return stoi(userDay);
}

//Checks if the date exists
int checkFunctions::checkYear()
{
	string userYear;
	
	//Check if the year is invalid of if there is a char
	while (true) {
		try {
			cin >> userYear;
			if (((userYear >= "A") && (userYear <= "z")) || (stoi(userYear) > 2022 || stoi(userYear) < 1))
			{
				throw 1;
			}

			else {
				break;
			}
		}

		catch (...)
		{
			//Change the color to gray
			colorText(8);
			cout << endl << setw(117) << "Incorrect input" << endl << setw(108) << "   > ";
			//Change to default color
			colorText(15);
			
		}
	}
	return stoi(userYear);
}

//Checks if the date exists
int checkFunctions::checkMonth()
{
	string userMonth;
	while (true) {
		//Check if the month is invalid of if there is a char
		try {
			cin >> userMonth;
			if (stoi(userMonth) > 12 || stoi(userMonth) < 1 || ((userMonth >= "A") && (userMonth <= "z")))
			{
				throw 1;
			}

			else {
				break;
			}
		}

		catch (...)
		{
			//Change the color to gray
			colorText(8);
			cout << endl << setw(117) << "Incorrect input" << endl << setw(108) << "   > ";
			//Change to default color
			colorText(15);
		
		}
	}
	return stoi(userMonth);
}

bool checkFunctions::checkBigger(Node*& firstNode, Node*& secondNode)
{
	if (firstNode->year > secondNode->year)
		return true;
	else if (firstNode->year < secondNode->year)
		return false;
	else
		if (firstNode->month > secondNode->month)
			return true;
		else if (firstNode->month < secondNode->month)
			return false;
		else
			if (firstNode->day > secondNode->day)
				return true;
			else if (firstNode->day < secondNode->day)
				return false;
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