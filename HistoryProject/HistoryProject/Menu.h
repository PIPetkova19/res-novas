#pragma once

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <conio.h>
#include "LinkedList.h"

using namespace std;

void menu();
void load();
void colorText(int colorSelect);
string userInfo();
void title();
string selectTheme(Node* Head);