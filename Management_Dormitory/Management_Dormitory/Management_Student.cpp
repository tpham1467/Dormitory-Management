#include "Management_Student.h"
#include "Date_of_Birth.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int Management_Student::N_S = 0;
Management_Student::Management_Student()
{
    ifstream input;
    input.open("Student.txt", ios::in);
    if (!input.is_open())
    {
        //throw "Unable to open file Student";
        cout << 1;
    }
    else
    {
        int n;
        input >> this->N_S;
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
            int _day, _month, _year;
            input.ignore();
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
            Student _Student(name, Phone_number, Room_Code, Profile_Code, Gender, Student_Code, Email, _d_of_b, Address);
            this->Database.InsertAtTail(_Student);
            //cout << this->Database.Get_P_Head()->Get_Data().Get_Name() << " " << this->Database.Get_P_Head()->Get_Data().Get_Address();
        }
    }
}

Management_Student::~Management_Student()
{
    this->Database.~Doubly_Linked_List();
}
void Management_Student::Add_Student(const Student &_Student)
{
    this->Database.InsertAtTail(_Student);
    Management_Student::N_S++;
}
vector<Student> Management_Student::Find_Student(string data)
{
    stringstream _data(data);
    Doubly_Linked_List<string> _data_Token;
    vector<Student> data_Student;
    string token;
    while (_data >> token){

        _data_Token.InsertAtTail(token);
    }
    //find
    Node<Student> *p = this->Database.Get_P_Head();
    while (p != nullptr)
    {
      
         bool check = false;
         Node<string> *pp=_data_Token.Get_P_Head();
        while (pp!=nullptr&&check==false)
        {
            string name = p->Get_Data().Get_Name();
            transform(name.begin(), name.end(), name.begin(), toupper);
            string Phone_Number = p->Get_Data().Get_Phone_number();
            transform(Phone_Number.begin(), Phone_Number.end(), Phone_Number.begin(), toupper);
            string Email = p->Get_Data().Get_Email();
            transform(Email.begin(), Email.end(), Email.begin(), toupper);
            string Student_code = p->Get_Data().Get_Student_Code();
            transform(Student_code.begin(), Student_code.end(), Student_code.begin(), toupper);
            token = pp->Get_Data();
            transform(token.begin(), token.end(), token.begin(), toupper);
            int index =name.find(token)-1;
            int size_token = token.size();
            if (name.find(token) >= 0 && name.find(token) <= name.length())
            {   
                if (index==-1||(index + size_token+1)==name.size())
                {
     
                        data_Student.push_back(p->Get_Data());
                         check = true;
                }
                else if (name.at(index) == ' ' && name.at(index + size_token+1) == ' ')
                {
                    data_Student.push_back(p->Get_Data());
                    check = true;
                }
            }
            if (check == false && Phone_Number.find(token) >= 0 && Phone_Number.find(token) <= Email.length())
            {
                data_Student.push_back(p->Get_Data());
                check = true;
            }
            if (check == false && Email.find(token) >= 0 && Email.find(token) <= Email.length())
            {
                data_Student.push_back(p->Get_Data());
                check = true;
            }
            if (check == false && Student_code.find(token) >= 0 && Student_code.find(token) <= Student_code.length())
            {
                data_Student.push_back(p->Get_Data());
                check = true;
            }
            pp=pp->Get_Next();
            
        }
        p = p->Get_Next(); 
    }
    return data_Student;
}
Doubly_Linked_List<Student>&  Management_Student::Get_List_Student()
{
    return this->Database;
}
void Management_Student::Delete_Student( Student& _student)
{

    this->Database.Delete_indexoff(Index_off(_student.Get_Student_Code()));
}
Node<Student>* Management_Student::Index_off(string _student_code)
{
    Node<Student>* p = this->Database.Get_P_Head();
    while (p != nullptr)
    {
        if (p->Get_Data().Get_Student_Code() == _student_code) return p;
        p = p->Get_Next();
    }
}
//void Management_Student::Update_Info(Node<Student>* p)
//{
//    
//}