#pragma once

#include <iostream>
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

namespace linkedList
{
	void prependNode(Node*&, string, int, int, int);
	void appendNode(Node*&, string, int, int, int);
	void printNodes(Node*);
}

namespace fileFunctions
{
	void writeToFile(Node*);
}