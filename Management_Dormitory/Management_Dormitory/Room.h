#pragma once
#include<string>
#include"Doubly_Linked_List.h"
#include"Student.h"
using namespace std;

class Room
{
private:
    string Room_Code;
    Doubly_Linked_List<Student> database;
    static int Number_Students;
    bool condition_of_facilities;
public:
    Room();
    Room(const Room&);
    ~Room();
};


