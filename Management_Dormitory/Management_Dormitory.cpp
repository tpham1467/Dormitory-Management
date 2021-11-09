#include <iostream>
#include<string>
//#include"Student.h"
 #include"management_room.h"


#include"Menu.h"
#include"Doubly_Linked_List.h"
//#include <algorithm>
using namespace std;
int main()
{ 
    Management_Student Data_s;
    Data_s.Read_File();
    //Menu_chinh(Data_s);
    Mamagement_Room data_r;
    data_r.Read_File();
    Doubly_Linked_List<Room> data_f = data_r.Find_Room("huy",Data_s);
    Node<Room> *p = data_f.Get_P_Head();
    while (p != nullptr)
    {
        cout << p->Get_Data().Get_Room_code()<<endl;
        p = p->Get_Next();
    }
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
    return 0;
}

