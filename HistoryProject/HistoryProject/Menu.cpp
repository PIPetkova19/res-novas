#include "Menu.h"
#include "LinkedList.h"


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void dynamicMenu(Node* Head);
void removeMenu(Node* Head);

void colorText(int colorSelect)
{
	SetConsoleTextAttribute(hConsole, colorSelect);
}

string userInfo()
{
	string userName;
	cout << "Enter your first name: " << endl;
	cin >> userName;
	return userName;
	system("cls");

}

void menu()
{
	string sentances[4] = { "ADD ELEMENT" , "DELETE ELEMENT", "MODIFY ELEMENT", "REVIEW LIST" };
	int arrow = 0;

	bool choose = true;

	int key;

	while (choose)
	{
		colorText(2);

		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(139) << "    dMP dMP dMP dMMMMMP dMP    .aMMMb  .aMMMb  dMMMMMMMMb  dMMMMMP" << endl;
		cout << setw(140) << "   dMP dMP dMP dMP     dMP    dMP VMP dMP dMP dMP dMP dMP dMP      " << endl;
		cout << setw(140) << "  dMP dMP dMP dMMMP   dMP    dMP     dMP dMP dMP dMP dMP dMMMP     " << endl;
		cout << setw(140) << " dMP.dMP.dMP dMP     dMP    dMP.aMP dMP.aMP dMP dMP dMP dMP        " << endl;
		cout << setw(135) << " VMMMPVMMP  dMMMMMP dMMMMMP VMMMP   VMMMP  dMP dMP dMP dMMMMMP" << endl;
		cout << endl;
		cout << setw(130) <<"HI, " << userName << endl << endl;

		colorText(8);

		cout << setw(132) << " Use the UP and DOWN arrows to move and Space to select:" << endl;
		cout << "" << endl;

		if (arrow == 0)
		{
			colorText(2);
			cout << setw(95) << "-->" << "\t  " << sentances[0] << "\t<--" << endl;
			colorText(15);
			cout << setw(95) << "\t  " << sentances[1] << endl;
			cout << setw(95) << "\t  " << sentances[2] << endl << endl;
			cout << setw(95) << "\t  " << sentances[3] << endl;
		}

		if (arrow == 1)
		{
			colorText(15);
			cout << setw(95) << "\t  " << sentances[0] << endl;
			colorText(2);
			cout << setw(95) << "-->" << "\t  " << sentances[1] << "\t<--" << endl;
			colorText(15);
			cout << setw(95) << "\t  " << sentances[2] << endl << endl;
			cout << setw(95) << "\t  " << sentances[3] << endl;
		}

		if (arrow == 2)
		{
			colorText(15);
			cout << setw(95) << "\t  " << sentances[0] << endl;
			cout << setw(95) << "\t  " << sentances[1] << endl;
			colorText(2);
			cout << setw(95) << "-->" << "\t  " << sentances[2] << "\t<--" << endl << endl;
			colorText(15);
			cout << setw(95) << "\t  " << sentances[3] << endl;
		}

		if (arrow == 3)
		{
			colorText(15);
			cout << setw(95) << "\t  " << sentances[0] << endl;
			cout << setw(95) << "\t  " << sentances[1] << endl;
			cout << setw(95) << "\t  " << sentances[2] << endl << endl;
			colorText(4);
			cout << setw(95) << "-->" << "\t  " << sentances[3] << "\t<--" << endl;
			colorText(15);
		}

		key = _getch();

		if (key == 72)
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
		if (key == 80)
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

		if (key == 32)
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

				menu();

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

	Node* temp = Head;

	int key;

	while (temp != NULL)
	{
		temp = temp->next;
		eventsCounter++;
	}

	int arrow = 0;

	while (true)
	{
		temp = Head;

		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

		colorText(7);
		cout << setw(114) << "PRESS SPACE TO DELETE" << endl << endl;
		colorText(15);

		if (temp->title != "" && temp->day != 0 && temp->month != 0 && temp->year != 0)
		{
			for (int j = 0; j < arrow; j++)
			{
				cout << setw(95) << "\t  " << temp->title << "-" << temp->day << "/" << temp->month << "/" << temp->year << endl;

				temp = temp->next;
			}

			colorText(2);
			cout << setw(95) << "-->" << "\t  " << temp->title << "-" << to_string(temp->day) << "/" << to_string(temp->month) 
				 << "/" << to_string(temp->year) << "\t<--" << endl;
			colorText(15);

			temp = temp->next;

			for (int j = arrow + 1; j < eventsCounter; j++)
			{
				cout << setw(95) << "\t  " << temp->title << "-" << temp->day << "/" << temp->month << "/" << temp->year << endl;

				temp = temp->next;
			}

			colorText(7);
			cout << endl << setw(113) << "PRESS ESC TO GO BACK" << endl << endl;
			colorText(15);
		}
		else
		{
			colorText(4);
			cout << setw(115) << "- THERE ARE NO EVENTS -" << endl << endl;
			cout << setw(113) << "PRESS ESC TO GO BACK" << endl << endl;
			colorText(15);
		}

		key = _getch();

		if (key == 72)
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
		if (key == 80)
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

		if (key == 32)
		{
			linkedList::removeNode(temp);
			break;
		}

		if (key == 27)
		{
			break;
		}

		system("cls");
	}

	system("cls");
}

void dynamicMenu(Node* Head)
{
	int eventsCounter = 0;

	Node* temp = Head;

	int key;

	while (temp != NULL)
	{
		temp = temp->next;
		eventsCounter++;
	}

	int arrow = 0;

	while (true)
	{
		temp = Head;

		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

		colorText(7);
		cout << setw(113) << "PRESS ESC TO GO BACK" << endl << endl;
		colorText(15);

		if (temp->title != "" && temp->day != 0 && temp->month != 0 && temp->year != 0)
		{
			for (int j = 0; j < arrow; j++)
			{
				cout << setw(95) << "\t  " << temp->title << "-" << temp->day << "/" << temp->month << "/" << temp->year << endl;

				temp = temp->next;
			}

			colorText(2);
			cout << setw(95) << "-->" << "\t  " << temp->title << "-" << temp->day << "/" << temp->month << "/" << temp->year << "\t<--" << endl;
			colorText(15);

			temp = temp->next;

			for (int j = arrow + 1; j < eventsCounter; j++)
			{
				cout << setw(95) << "\t  " << temp->title << "-" << temp->day << "/" << temp->month << "/" << temp->year << endl;

				temp = temp->next;
			}
		}
		else
		{
			colorText(4);
			cout << setw(115) << "- THERE ARE NO EVENTS -" << endl << endl;
			colorText(15);
		}

		key = _getch();

		if (key == 72)
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
		if (key == 80)
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

		if (key == 27)
		{
			break;
		}

		system("cls");
	}

	system("cls");
}

void load()
{
	cout << endl << setw(102);

	for (int r = 1; r <= 5; r++)
	{
		colorText(2);
		Beep(220, 200);
		std::cout << (char)219u << " ";
	}

	colorText(15);

	cout << endl << endl << endl << setw(123) << "ALL DONE. PRESS ENTER TO CONTINUE";

	while (true)
	{
		if (_getch() == 13)
		{
			system("cls");

			menu();
		}
	}
}