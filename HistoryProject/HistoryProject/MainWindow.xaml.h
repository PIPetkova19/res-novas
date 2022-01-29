#pragma once

#include "MainWindow.g.h"

namespace winrt::HistoryProject::implementation
{
    //Declare a doubly linked list
    struct Node
    {
        int day = 0;
        int month = 0; 
        int year = 0;

        Node* prev = NULL;
        Node* next = NULL;
    };

    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void AssignValues();
        void prependNode(Node*&);
        void appendNode(Node*);
    };
}

namespace winrt::HistoryProject::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
