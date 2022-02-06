#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Node
{
	string title = "";

	int day = 0;
	int month = 0;
	int year = 0;

	Node* prev = 0;
	Node* next = 0;
};

extern Node* Head;

namespace linkedList
{
	void prependNode(Node*&, string, int, int, int);
	void appendNode(Node*&, string, int, int, int);
	void addNode(Node*&);
	void removeGivenNode(Node*&, string, int, int, int);
	void removeNode(Node*&);
	void modifyNode(Node*&);
	void modifyGivenNode(Node*&, string, int, int, int);
	void printNodes(Node*);
}

int checkMonth();
int checkYear();
int checkDay(int userMonth, int userYear);

namespace fileFunctions
{
	void writeToFile(Node*);
}