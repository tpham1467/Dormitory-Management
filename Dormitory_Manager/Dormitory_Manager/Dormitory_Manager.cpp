// Dormitory_Manager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"Doubly_Linked_List.h"
#include"Person.h"
int main()
{
    Doubly_Linked_List<Person> db;
    Person a1("pham van a", 11, true);
    Person a2("pham van b", 12, true);
    Person a3("pham van c", 13, true);
    db.InsertAtHead(a1);
    db.InsertAtTail(a2);
    db.InsertAtHead(a2);
    db.InsertAtHead(a3);
    db.InsertAtTail(a3);
    //db.DeleteAtHead();
    //db.DeleteAtTail();
    db.Delete_indexoff(db.Get_P_Head());


    Node<Person>* p = db.Get_P_Head();
    while (p != nullptr)
    {
        p->Get_Data().ShowInfo();
        p = p->Get_Next();
        cout << endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
