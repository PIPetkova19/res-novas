#include "Menu.h"
#include "LinkedList.h"


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void dynamicMenu(Node* Head);
void removeMenu(Node* Head);

void menu()
{
	string sentances[4] = { "ADD ELEMENT" , "DELETE ELEMENT", "MODIFY ELEMENT", "REVIEW LIST" };
	int arrow = 0;

	bool choose = true;

	while (choose)
	{
		SetConsoleTextAttribute(hConsole, 2);

		cout << endl;
		cout << "    dMP dMP dMP dMMMMMP dMP    .aMMMb  .aMMMb  dMMMMMMMMb  dMMMMMP" << endl;
		cout << "   dMP dMP dMP dMP     dMP    dMP VMP dMP dMP dMP dMP dMP dMP      " << endl;
		cout << "  dMP dMP dMP dMMMP   dMP    dMP     dMP dMP dMP dMP dMP dMMMP     " << endl;
		cout << " dMP.dMP.dMP dMP     dMP    dMP.aMP dMP.aMP dMP dMP dMP dMP        " << endl;
		cout << " VMMMPVMMP  dMMMMMP dMMMMMP VMMMP   VMMMP  dMP dMP dMP dMMMMMP" << endl;
		cout << endl;


		SetConsoleTextAttribute(hConsole, 8);

		cout << " Use the UP and DOWN arrows to move and Space to select:" << endl;
		cout << "" << endl;

		if (arrow == 0)
		{
			SetConsoleTextAttribute(hConsole, 15);
			cout << " -->" << '\t' << sentances[0] << "\t<--" << endl;
			cout << '\t' << sentances[1] << endl;
			cout << '\t' << sentances[2] << endl << endl;
			cout << '\t' << sentances[3] << endl;
		}

		if (arrow == 1)
		{
			SetConsoleTextAttribute(hConsole, 15);
			cout << '\t' << sentances[0] << endl;
			cout << " -->" << '\t' << sentances[1] << "\t<--" << endl;
			cout << '\t' << sentances[2] << endl << endl;
			cout << '\t' << sentances[3] << endl;
		}

		if (arrow == 2)
		{
			SetConsoleTextAttribute(hConsole, 15);
			cout << '\t' << sentances[0] << endl;
			cout << '\t' << sentances[1] << endl;
			cout << " -->" << '\t' << sentances[2] << "\t<--" << endl << endl;
			cout << '\t' << sentances[3] << endl;
		}

		if (arrow == 3)
		{
			SetConsoleTextAttribute(hConsole, 15);
			cout << '\t' << sentances[0] << endl;
			cout << '\t' << sentances[1] << endl;
			cout << '\t' << sentances[2] << endl << endl;
			cout << " -->" << '\t' << sentances[3] << "\t<--" << endl;
		}

		system("pause>nul");

		if (GetAsyncKeyState(VK_UP))
		{
			if (arrow == 0)
			{
				Beep(220, 50);
			}
			else
			{
				Beep(440, 50);
				arrow--;
			}
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (arrow == 3)
			{
				Beep(220, 50);
			}
			else
			{
				arrow++;
				Beep(440, 50);
			}
		}

		if (GetAsyncKeyState(VK_SPACE))
		{
			if (arrow == 0)
			{
				Beep(440, 100);
				Beep(493, 100);
				Beep(523, 150);

				system("cls");

				linkedList::addNode(Head);

				choose = false;
			}
			else if (arrow == 1)
			{
				system("cls");

				removeMenu(Head);

				choose = false;
			}
			else if (arrow == 2)
			{
				choose = false;
			}
			else if (arrow == 3)
			{
				choose = false;

				system("cls");

				dynamicMenu(Head);

				menu();
			}
		}
		system("cls");
	}
}

void removeMenu(Node* Head)
{
	int eventsCounter = 0;

	Node* tempCounter = Head;

	while (tempCounter != NULL)
	{
		tempCounter = tempCounter->next;
		eventsCounter++;
	}

	int arrow = 0;

	Node* tempSelect = Head;

	while (true)
	{
		Node* temp = Head;

		for (int j = 0; j < arrow; j++)
		{
			cout << '\t' << temp->title << "-" << temp->day << "/" << temp->month << "/" << temp->year << endl;

			temp = temp->next;
		}

		cout << " " << " -->" << '\t' << temp->title << "-" << temp->day << "/" << temp->month << "/" << temp->year << "\t<--" << endl;

		temp = temp->next;

		for (int j = arrow + 1; j < eventsCounter; j++)
		{
			cout << '\t' << temp->title << "-" << temp->day << "/" << temp->month << "/" << temp->year << endl;

			temp = temp->next;
		}

		system("pause>nul");

		if (GetAsyncKeyState(VK_UP))
		{
			if (arrow == 0)
			{
				Beep(220, 50);
			}
			else
			{
				Beep(440, 50);
				arrow--;
				tempSelect = tempSelect->prev;
			}
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (arrow == eventsCounter - 1)
			{
				Beep(220, 50);
			}
			else
			{
				Beep(440, 50);
				arrow++;
				tempSelect = tempSelect->next;
			}
		}

		if (GetAsyncKeyState(VK_SPACE))
		{
			linkedList::removeNode(tempSelect);
			break;
		}

		system("cls");
	}

	system("cls");
}

void dynamicMenu(Node* Head)
{
	int eventsCounter = 0;

	Node* tempCounter = Head;

	while (tempCounter != NULL)
	{
		tempCounter = tempCounter->next;
		eventsCounter++;
	}

	int arrow = 0;

	while (true)
	{
		Node* temp = Head;

		for (int j = 0; j < arrow; j++)
		{
			cout << '\t' << temp->title << "-" << temp->day << "/" << temp->month << "/" << temp->year << endl;

			temp = temp->next;
		}

		cout << " " << " -->" << '\t' << temp->title << "-" << temp->day << "/" << temp->month << "/" << temp->year << "\t<--" << endl;

		temp = temp->next;

		for (int j = arrow + 1; j < eventsCounter; j++)
		{
			cout << '\t' << temp->title << "-" << temp->day << "/" << temp->month << "/" << temp->year << endl;

			temp = temp->next;
		}

		system("pause>nul");

		if (GetAsyncKeyState(VK_UP))
		{
			if (arrow == 0)
			{
				Beep(220, 50);
			}
			else
			{
				Beep(440, 50);
				arrow--;
			}
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (arrow == eventsCounter - 1)
			{
				Beep(220, 50);
			}
			else
			{
				Beep(440, 50);
				arrow++;
			}
		}

		if (GetAsyncKeyState(VK_SPACE))
		{
			break;
		}

		system("cls");
	}

	system("cls");
}

void load()
{
	cout << endl << " ";

	for (int r = 1; r <= 5; r++)
	{
		SetConsoleTextAttribute(hConsole, 2);
		Beep(220, 200);
		std::cout << (char)219u << " ";
	}

	SetConsoleTextAttribute(hConsole, 15);

	cout << endl << endl << " ALL DONE. PRESS ENTER TO CONTINUE";

	system("pause>nul");

	system("cls");

	menu();
}