#pragma once
#include<string>
#include"Doubly_Linked_List.h"
#include"Management_Student.h"
#include"Student.h"
#include"Date.h"
#include<vector>
using namespace std;
class Room
{
private:
    string Room_Code;
    int Number_Students;
    bool condition_of_facilities;
    CDate Han_Dong_Tien_Phi_Sinh_Hoat;
public:
    Room(const string&,const int&,const bool&,const CDate&);
    Room();
   // Room(const Room&);
    ~Room();
    Doubly_Linked_List<Student> Get_List_Student(Management_Student&);
    //condition of facilities
    const bool& Get_COF();
    void Set_COF(const bool&);
    //Han_Dong_Tien_Phi Sinh Hoat
    CDate& Get_HDTPSH();
    void Set_HDTPNSH(const CDate&);
    //Number Student
    const int& Get_NS();
    void Set_NS(const int&);
    // Room_code;
    const string& Get_Room_code();
   /* void Add_Student(Management_Student&,const string&);
    void Delete_Student(Management_Student&,const string&);*/
};


