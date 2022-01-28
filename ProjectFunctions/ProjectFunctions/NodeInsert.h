#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int day = 0;
    int month = 0;
    int year = 0;

    Node* prev = NULL;
    Node* next = NULL;
};

inline void prependNode(Node*&, int, int, int);
inline void appendNode(Node*, int, int, int);