#include "Management_Student.h"
#include"Date_of_Birth.h"
#include <fstream>
#include <string>
using namespace std;
int Management_Student::N_S=0;
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
        input>>this->N_S;
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
            Date_of_Birth dt;
            // dt.Day=(int)_d_of_b[0]+(int)_d_of_b[1]-96;
            // dt.Month=(int)_d_of_b[3]+(int)_d_of_b[4]-96;
            // dt.Year=(int)_d_of_b[6]+(int)_d_of_b[7]+(int)_d_of_b[8]+(int)_d_of_b[9]-96;
            Student _Student(name,Phone_number,Room_Code,Profile_Code,Gender,Student_Code,Email,dt,Address);
            this->Database.InsertAtHead(_Student);
            cout<<this->Database.Get_P_Head()->Get_Data().Get_Name()<<" "<<this->Database.Get_P_Head()->Get_Data().Get_Address();
        }
        
    }
}

Management_Student::~Management_Student()
{
    this->Database.~Doubly_Linked_List();
}
void Management_Student::Add_Student(const Student& _Student)
{
    this->Database.InsertAtTail(_Student);
    Management_Student::N_S++;
}