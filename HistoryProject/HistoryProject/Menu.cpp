#include "Menu.h"
#include "LinkedList.h"


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void dynamicMenu(Node* Head);
void removeMenu(Node*& Head);
void modifyMenu(Node* Head);

// Change text color
void colorText(int colorSelect)
{
	SetConsoleTextAttribute(hConsole, colorSelect);
}

// Set color of theme member
void colorTheme(string theme)
{
	if (theme == "FIRST BG KINGDOM")
	{
		SetConsoleTextAttribute(hConsole, 1);
	}
	if (theme == "SECOND BG KINGDOM")
	{
		SetConsoleTextAttribute(hConsole, 3);
	}
	if (theme == "OTTOMAN RULE")
	{
		SetConsoleTextAttribute(hConsole, 2);
	}
	if (theme == "THIRD BG KINDOM")
	{
		SetConsoleTextAttribute(hConsole, 5);
	}
	if (theme == "COMMUNISUM")
	{
		SetConsoleTextAttribute(hConsole, 4);
	}
	if (theme == "MODERN HISTORY")
	{
		SetConsoleTextAttribute(hConsole, 6);
	}
}

// Display Front-End of the first page
void title()
{
	cout << endl << endl << endl;
	colorText(4);
	cout << setw(55) << "====== = -                             = " << endl;
	cout << setw(55) << "###+++*##*-                            **" << endl;
	cout << setw(104) << "##+     -##=             -+***=:       *#*.     -##:        :##-     :##:  ::             " << endl;
	cout << setw(104) << "##+      +##           :##*==+##*      *###.    -##:         +##     *#*   **             " << endl;
	cout << setw(104) << "##+      *##           ##*    .**=     *####:   -##:         .##=   -##:  :##:            " << endl;
	cout << setw(104) << "##*..::=##*. ==========###-            *#*=##-  -##:          +##   ##*   *##*            " << endl;
	cout << setw(104) << "##*=####+:   ###*********###*=-.       *#* =##- -##:  :==+++=-:##= =##:  -####-  .-=++=:  " << endl;
	cout << setw(104) << "##+  =##*:   ##+          .-=*##+      *#*  -##=-##=*##*++++*#####:##+   ##**## +##*++##*." << endl;
	cout << setw(104) << "##+    =##*: ##+       ..     :##=     *#*   :#######=.       -######-::=##==#####.    *#*" << endl;
	cout << setw(104) << "++=      =##*##+       *#*.   -##=     *#*    .####*.           *#################-       " << endl;
	cout << setw(104) << "           =###*=====  .+##**###=      *#*     .*##-            :###.  =##.  .######+=:   " << endl;
	cout << setw(104) << "            .###+++++    .-==-:        :-:      :##-            :##=   ##+    +##.:-+###+." << endl;
	cout << setw(104) << "             ##+                                 *#*.           *##   =##.    .##=    :*#*" << endl;
	cout << setw(104) << "             ##*---------                         *##=.       -##*.   :-:      =##.    *#*" << endl;
	cout << setw(104) << "             ************                          :*##*++++*##*-               +##*++##* " << endl;
	colorText(15);
	cout << endl;
}

// Input your first name 
string userInfo()
{
	title();
	string userName;
	cout << setw(73) << "PLEASE ENTER YOUR FIRST NAME: " << endl << setw(53) << "> ";
	cin >> userName;
	return userName;
}


// Main menu
void menu()
{
	// Menu options
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
		cout << setw(104) <<"HI, " << userName << endl << endl;

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
				// Play melody when adding new Node
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
				system("cls");

				modifyMenu(Head);

				menu();

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

// Add dynamic menu where you can view and delete elements
void removeMenu(Node*& Head)
{
	int eventsCounter = 0;

	while (Head->prev != NULL)
		Head = Head->prev;
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
		int j = 0;

		if (temp != nullptr && temp->title != "" && temp->day != 0 && temp->month != 0 && temp->year != 0)
		{
			for (j; j < arrow; j++)
			{
				cout << setw(95) << "\t  " << temp->title << " - " << temp->day << "/" << temp->month << "/" << temp->year << endl;

				temp = temp->next;
			}

			colorText(2);
			cout << setw(95) << "-->" << "\t  " << temp->title << " - " << to_string(temp->day) << "/" << to_string(temp->month) 
				 << "/" << to_string(temp->year) << "\t<--" << endl;
			colorText(15);

			temp = temp->next;

			for (j = arrow + 1; j < eventsCounter; j++)
			{
				cout << setw(95) << "\t  " << temp->title << " - " << temp->day << "/" << temp->month << "/" << temp->year << endl;

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
			temp = Head;
			int counter = 0;
			while (counter != arrow)
			{
				temp = temp->next;
				counter++;
			}
			int grayNum = grayCode::getGrayCode(temp);
			Head = linkedList::removeNode(temp, grayNum);
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

// Menu for editing the events
void modifyMenu(Node* Head)
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
		cout << setw(114) << "PRESS SPACE TO MODIFY" << endl << endl;
		colorText(15);
		int j = 0;

		if (temp != nullptr && temp->title != "" && temp->day != 0 && temp->month != 0 && temp->year != 0)
		{
			for (j; j < arrow; j++)
			{
				cout << setw(95) << "\t  " << temp->title << " - " << temp->day << "/" << temp->month << "/" << temp->year << endl;

				temp = temp->next;
			}

			colorText(2);
			cout << setw(95) << "-->" << "\t  " << temp->title << " - " << to_string(temp->day) << "/" << to_string(temp->month)
				<< "/" << to_string(temp->year) << "\t<--" << endl;
			colorText(15);

			temp = temp->next;

			for (j = arrow + 1; j < eventsCounter; j++)
			{
				cout << setw(95) << "\t  " << temp->title << " - " << temp->day << "/" << temp->month << "/" << temp->year << endl;

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
			temp = Head;
			int counter = 0;
			while (counter != arrow)
			{
				temp = temp->next;
				counter++;
			}
			int grayNum = grayCode::getGrayCode(temp);
			linkedList::modifyNode(temp, grayNum);
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

// Add dynamic menu where you can view add elements
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
		if (temp != nullptr)
		{
			while (temp->prev != NULL)
			{
				temp = temp->prev;
			}
		}

		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

		colorText(7);
		cout << setw(113) << "PRESS ESC TO GO BACK" << endl << endl;
		colorText(15);

		if (temp != nullptr && temp->title != "" && temp->day != 0 && temp->month != 0 && temp->year != 0)
		{
			for (int j = 0; j < arrow; j++)
			{
				cout << setw(85) << "\t  ";
				colorTheme(temp->theme);
				cout << temp->theme;
				colorText(15);
				cout << " - " << temp->title << " - " << temp->day << "/" << temp->month << "/" << temp->year << endl;

				temp = temp->next;
			}

			colorText(2);
			cout << setw(85) << "-->" << "\t  ";
			colorTheme(temp->theme);
			cout << temp->theme;
			colorText(2);
			cout << " - " << temp->title << " - " << temp->day << "/" << temp->month << "/" << temp->year << "\t<--" << endl;
			colorText(15);

			temp = temp->next;

			for (int j = arrow + 1; j < eventsCounter; j++)
			{
				cout << setw(85) << "\t  ";
				colorTheme(temp->theme);
				cout << temp->theme;
				colorText(15);
				cout << " - " << temp->title << " - " << temp->day << "/" << temp->month << "/" << temp->year << endl;

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

// Select the theme of the event
string selectTheme(Node* Head)
{
	system("cls");

	// Possible themes
	string themes[6] = { "FIRST BG KINGDOM" , "SECOND BG KINGDOM", "OTTOMAN RULE", "THIRD BG KINDOM", "COMMUNISUM", "MODERN HISTORY" };

	int arrow = 0;

	bool choose = true;

	int key;

	while (choose)
	{
		colorText(8);

		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

		cout << setw(117) << "PLEASE SELECT A THEME" << endl << endl;

		for (int i = 0; i < arrow; i++)
		{
			colorTheme(themes[i]);
			cout << setw(95) << "\t  " << themes[i] << endl;
		}

		colorTheme(themes[arrow]);
		cout << setw(95) << "-->" << "\t  " << themes[arrow] << "\t<--" << endl;

		for (int i = arrow + 1; i < 6; i++)
		{
			colorTheme(themes[i]);
			cout << setw(95) << "\t  " << themes[i] << endl;
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
			if (arrow == 5)
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
			return themes[arrow];
		}

		system("cls");
	}

	return "/";
}

// Display loading screen
void load()
{
	cout << endl << setw(102);

	for (int r = 1; r <= 5; r++)
	{
		colorText(2);
		Beep(220, 200);
		cout << (char)219u << " ";
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