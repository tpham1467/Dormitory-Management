#pragma once
#include"Room.h"
#include"Management_Student.h"
#include"Doubly_Linked_List.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include"Khoi_tao.h"
class Mamagement_Room
{
private:
    Doubly_Linked_List<Room> DataBase;
public:
    Mamagement_Room();
    ~Mamagement_Room();
    void Read_File();
    Doubly_Linked_List<Room>& Get_List_Room();
    Doubly_Linked_List<Room> Find_Room(const string&,Management_Student&);
    Node<Room>* Get_Room(string&);
    void Write_File();  
    void Menu(Management_Student&,bool=true);
    void Draw_a_Page(int, Doubly_Linked_List<Room>&,int);
    int Move_Page(Doubly_Linked_List<Room>&, bool& , bool&,bool&);
    void Draw_Object(Doubly_Linked_List<Room>& , int, int , int);
    void Draw_Info_Object(Management_Student&);
    void Update(Management_Student&);
    friend Management_Student;
};


