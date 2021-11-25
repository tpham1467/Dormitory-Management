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
    Doubly_Linked_List<Room> Get_List_Room();
    Doubly_Linked_List<Room> Find_Room(const string&,Management_Student&);
    const Room Get_Room(string&);
    /*void Confirm_Repair();
    void Payment();*/
    void Write_File();  
<<<<<<< HEAD
    void Menu(Management_Student&);
=======
    void Menu();
>>>>>>> 719b41b9401dc152faff1cb55369e2c10e7f101d
    void Draw_a_Page(int, Doubly_Linked_List<Room>&,int);
    int Move_Page(Doubly_Linked_List<Room>&, bool& , bool&);
    void Draw_Object(Doubly_Linked_List<Room>& , int, int , int);
    void Draw_Info_Object(Management_Student&);
};


