#include <iostream>
#include<string>
// #include"management_room.h"
//#include"Management_Student.h"
#include"Date.h"
//#include"Doubly_Linked_List.h"
//#include <algorithm>
using namespace std;
int main()
{ 
    CDate ns(02, 2, 2020);
    CDate _time = ns.To_CDate("29/2/2020");
    cout << _time.Get_String() << endl;
    cout<<((_time.validDate()==1)?"True":"false") << endl;
    string _data = ns.Get_String();

    cout << ns.Get_String() << endl;
   // ns.operator+(1);
    // Mamagement_Room data_r;
    // data_r.Read_File();
    // Doubly_Linked_List<Room> data_f = data_r.Find_Room("huy",Data_s);
    // Node<Room> *p = data_f.Get_P_Head();
    // while (p != nullptr)
    // {
    //     cout << p->Get_Data().Get_Room_code()<<endl;
    //     p = p->Get_Next();
    // }
  /*  Doubly_Linked_List<int> data_1;
    data_1.InsertAtTail(1);
    data_1.InsertAtTail(2);
    data_1.InsertAtTail(3);
    data_1.InsertAtTail(4);
    Doubly_Linked_List<int> data_2(data_1);
    Node<int>* p = data_2.Get_P_Head();
    while (p != nullptr)
    {
        cout << p->Get_Data();
        p = p->Get_Next();
    }*/
    /*Doubly_Linked_List<Student> data_1 = Data_s.Get_List_Student();
    cout << data_1.Get_Lenght();
    for(int i=0;i<data_1.Get_Lenght();i++)
    {
        cout << data_1[i].Get_Name()<<endl;
    }*/
    return 0;
}

