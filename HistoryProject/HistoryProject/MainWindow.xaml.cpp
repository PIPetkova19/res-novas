#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::HistoryProject::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    int userDay, userMonth, userYear;
    Node* Head = new Node;

    void MainWindow::Button_Add(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        txtEvent().Text(to_hstring(Head->year));
    }

    void MainWindow::AssignValues() 
    {
        userDay = stoi(to_string(txtDay().Text()));
        userMonth = stoi(to_string(txtMonth().Text()));
        userYear = stoi(to_string(txtYear().Text()));
    }

    void MainWindow::prependNode(Node*& Head)
    {
        AssignValues();
        Node* newNode = new Node{ userDay, userMonth, userYear, NULL, Head };
        newNode->next = Head;
        Head->prev = newNode;

        Head = newNode;
    }

    void MainWindow::appendNode(Node* Head)
    {
        AssignValues();
        Node* newNode = new Node{ userDay, userMonth, userYear };

        Node* temp = new Node;
        temp = Head;
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
}
