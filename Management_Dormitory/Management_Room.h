#pragma once
#include"Room.h"
#include"Management_Student.h"
#include"Doubly_Linked_List.h"
class Mamagement_Room
{
private:
    Doubly_Linked_List<Room> DataBase;
public:
    Mamagement_Room();
    ~Mamagement_Room();
    void Read_File();
    const Doubly_Linked_List<Room> Get_List_Room();
    Doubly_Linked_List<Room> Find_Room(const string&,Management_Student&);
    const Room Get_Room(string&);
    /*void Confirm_Repair();
    void Payment();*/
   /* void Write_File();  */

};


