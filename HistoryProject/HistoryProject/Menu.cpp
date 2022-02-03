#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void menu()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

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
				choose = false;
			}
			else if (arrow == 1)
			{
				choose = false;
			}
			else if (arrow == 2)
			{
				choose = false;
			}
			else if (arrow == 3)
			{
				choose = false;
			}
		}
		system("cls");
	}
}

int main()
{
	menu();
}