#include "Management_Student.h"
#include"Date_of_Birth.h"
#include <fstream>
#include <string>
using namespace std;
Management_Student::Management_Student()
{
    ifstream input;
    input.open("Student.txt", ios::in);
    if (!input.is_open())
    {
        //throw "Unable to open file Student";
       cout<<1;
    }
    else
    {
        int n;
        input>>n;
        int i=0;
        input.ignore();
        while (!input.eof())
        {
            string name;
            string Phone_number;
            string Profile_Code;
            string Room_Code;
            int Gender;
            string Email;
            string Student_Code;
            Date_of_Birth d_of_b;
            string _d_of_b;
            string Address;
            int _day,_month,_year;
            getline(input, name, '-');
            getline(input, Phone_number, '-');
            getline(input, Profile_Code, '-');
            getline(input, Room_Code, '-');
            input >> Gender;
            input.ignore();
            getline(input, Email, '-');
            getline(input, Student_Code, '-');
            getline(input, _d_of_b, '-');
            getline(input, Address, '.');
            // cout<<name<<endl<<Phone_number<<endl<<Room_Code<<endl<<
            // Profile_Code<<
            // endl<<Gender<<endl<<Email<<endl<<Student_Code<<endl<<
            // Address<<endl<<_d_of_b;
            i++;
            if(i==n)
            {
              break;  
            }
            Date_of_Birth dt;
            Student _Student(name,Phone_number,Room_Code,Profile_Code,Gender,Student_Code,Email,dt,Address);
            this->Database.InsertAtHead(_Student);
            cout<<this->Database.Get_P_Head()->Get_Data().Get_Name();
        }
        
    }
}

Management_Student::~Management_Student()
{
    this->Database.~Doubly_Linked_List();
}