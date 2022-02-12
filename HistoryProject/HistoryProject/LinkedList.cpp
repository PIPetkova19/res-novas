#include "LinkedList.h"
#include "Menu.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void linkedList::prependNode(Node* Head, string userTitle, int userDay, int userMonth, int userYear)
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

void linkedList::addBetween(Node* Head, string userTitle, int userDay, int userMonth, int userYear)
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

void linkedList::appendNode(Node* Head, string userTitle, int userDay, int userMonth, int userYear)
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

string inputString(string userTitle)
{
	cin.ignore(INT_MAX, '\n');
	getline(cin, userTitle);
	cout << endl;
	return userTitle;
}


void linkedList::addNode(Node* Head)
{
	string userTitle, userName;
	int userDay, userMonth, userYear;
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

	cout << setw(115) << "Enter event's Title:" << endl << setw(100) << "   > ";
	userTitle = inputString(userTitle);


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
	load();
}

//Remove given node
void linkedList::removeGivenNode(Node* Head, int grayNum)
{
	while (Head->prev != NULL)
	{
		Head = Head->prev;
	}
	Node* temp = Head;
	int tempGrayNum = grayCode::getGrayCode(temp);

	while (temp != NULL && tempGrayNum != grayNum)
	{
		temp = temp->next;
		tempGrayNum = grayCode::getGrayCode(temp);
	}

	if (temp != NULL && tempGrayNum == grayNum)
	{
		Node* tempPrev = temp->prev;
		Head = Head->next;
		temp->title = "";
		temp->day = 0;
		temp->month = 0;
		temp->year = 0;
		if(tempPrev != nullptr)
		{
			tempPrev->next = temp->next;
			if(temp->next != nullptr)
				temp->next->prev = tempPrev;
		}
		return;
	}
}

//Remove a node
void linkedList::removeNode(Node* Head, int grayNum)
{
	linkedList::removeGivenNode(Head, grayNum);
}

//Modify a node
void linkedList::modifyNode(Node* Head, int grayNum)
{
	string keyTitle, keyName;
	int keyDay, keyMonth, keyYear;

	system("cls");

	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

	cout << setw(115) << "Enter event's Title:" << endl << setw(100) << "   > ";
	keyTitle = inputString(keyTitle);


	cout << setw(114) << "Enter event's Year:" << endl << setw(100) << "   > ";
	keyYear = checkFunctions::checkYear();
	cout << endl;

	cout << setw(115) << "Enter event's Month:" << endl << setw(100) << "   > ";
	keyMonth = checkFunctions::checkMonth();
	cout << endl;

	cout << setw(113) << "Enter event's Day:" << endl << setw(100) << "   > ";
	keyDay = checkFunctions::checkDay(keyMonth, keyYear);

	modifyGivenNode(Head, grayNum, keyTitle, keyDay, keyMonth, keyYear);
}

//Modifyes a given node
void linkedList::modifyGivenNode(Node* Head, int grayNum, string keyTitle, int keyDay, int keyMonth, int keyYear)
{
	while (Head->prev != NULL)
	{
		Head = Head->prev;
	}

	Node* temp = Head;
	int tempGrayNum = grayCode::getGrayCode(temp);

	while (temp != NULL && tempGrayNum != grayNum)
	{
		temp = temp->next;
		tempGrayNum = grayCode::getGrayCode(temp);
	}

	if (temp != NULL && tempGrayNum == grayNum)
	{
		temp->title = keyTitle;
		temp->day = keyDay;
		temp->month = keyMonth;
		temp->year = keyYear;
	}
}

//Prints all dates
void linkedList::printNodes(Node* Head)
{
	while (Head != NULL)
	{
		cout << Head->title << " - " << Head->day << "/" << Head->month << "/" << Head->year << endl;
		Head = Head->next;
	}
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

//Checks whick nodes date is more recent
bool checkFunctions::checkBigger(Node* firstNode, Node* secondNode)
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
	return 0;
}

//Convert decimal to binary
long long int grayCode::decToBin(int dec) {
	int bin = 0;
	int counter = 1;

	while (dec) {
		bin += (dec % 2) * counter;
		dec /= 2;
		counter *= 10;
	}
	return bin;
}

//Convert bin to Gray code
long long int  grayCode::binToGraysCode(int dec) {
	long long binary, gray = 0;
	int lastNum = 0, penultimateNum = 0, counter = 0;
	binary = grayCode::decToBin(dec);
	while (binary != 0)
	{
		lastNum = binary % 10;
		binary /= 10;
		penultimateNum = binary % 10;

		//Make XOR of both numbers
		if ((lastNum ^ penultimateNum) != 0) {
			//Pow(10, counter) makes them bigger
			gray += pow(10, counter);
		}
		counter++;
	}
	return gray;
}

//Use gray code as bin and convert it to dec
int grayCode::grayCodeConversion(long long temp) {
	long long num = grayCode::binToGraysCode(temp);
	int sum = 0, i = 0;
	while (num)
	{
		sum += (num % 10) * pow(2, i);
		i++;
		num = num / 10;
	}
	return sum;
}

int grayCode::getGrayCode(Node* Head)
{
	int dateNum = int(Head->title[0]) + Head->day;
	int grayNum = grayCode::grayCodeConversion(dateNum);

	return grayNum;
}

void sorting::swapNodes(Node* firstNode, Node* secondNode)
{
	Node* tempPrev = firstNode->prev;
	Node* tempNext = secondNode->next;

	secondNode->next = firstNode;
	firstNode->prev = secondNode;
	secondNode->prev = tempPrev;
	firstNode->next = tempNext;
}

void sorting::sortIncreasing(Node* Head)
{
	Node* temp = Head;
	Node* tempNext = temp->next;

	while (temp->next != NULL)
	{
		if (checkFunctions::checkBigger(temp, tempNext))
		{
			sorting::swapNodes(temp, tempNext);
		}
		temp = tempNext;
		tempNext = tempNext->next;
	}
}

void sorting::sortDecreasing(Node* Head)
{
	Node* temp = Head;
	Node* tempNext = temp->next;

	while (temp->next != NULL)
	{
		if (!checkFunctions::checkBigger(temp, tempNext))
		{
			sorting::swapNodes(temp, tempNext);
		}
		temp = tempNext;
		tempNext = tempNext->next;
	}
}

void sorting::sortAlphabetical(Node* Head)
{
	Node* temp = Head;
	Node* tempNext = temp->next;

	while (temp->next != NULL)
	{
		if (temp->title[0] < tempNext->title[0])
		{
			sorting::swapNodes(temp, tempNext);
		}
		temp = tempNext;
		tempNext = tempNext->next;
	}
}