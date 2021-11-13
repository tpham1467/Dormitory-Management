#include "Management_Student.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int Management_Student::N_S = 0;
Management_Student::Management_Student()
{
 
}

void Management_Student::Add_Student(const Student &_Student)
{
    this->Database.InsertAtTail(_Student);
    Management_Student::N_S++;
}
Doubly_Linked_List<Student> Management_Student::Find_Student(string data)
{
    stringstream _data(data);
    Doubly_Linked_List<string> _data_Token;
    Doubly_Linked_List<Student> data_Student;
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
                if (index==-1 || (index + size_token + 1) == name.size())
                {

                         if(index==-1)
                         {
                             if (name.at(index + size_token + 1) == ' ')
                             {

                                 data_Student.InsertAtTail(p->Get_Data());
                                 check = true;
                             }
                         }
                         else
                         {
                             if (name.at(index) == ' ')
                             {

                                 data_Student.InsertAtTail(p->Get_Data());
                                 check = true;
                             }
                         }
                        
                }
                else if (name.at(index) == ' ' && name.at(index + size_token+1) == ' ')
                {
                   
                    data_Student.InsertAtTail(p->Get_Data());
                    check = true;
                }
            }
            if (check == false && Phone_Number.find(token) >= 0 && Phone_Number.find(token) <= Phone_Number.length()&& Phone_Number.length()==token.size())
            {
                data_Student.InsertAtTail(p->Get_Data());
                check = true;
            }
           if (check == false && Email.find(token) >= 0 && Email.find(token) <= Email.length()&&token.size()== Email.length())
            {
                data_Student.InsertAtTail(p->Get_Data());
                check = true;
            }
            if (check == false && Student_code.find(token) >= 0 && Student_code.find(token) <= Student_code.length())
            {
                data_Student.InsertAtTail(p->Get_Data());
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

    //this->Database.Delete_indexoff(Index_off(_student.Get_Student_Code()));
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
Management_Student::~Management_Student()
{
    this->Database.~Doubly_Linked_List();
}
void Management_Student::Write_File()
{
    ofstream output;
    output.open("Student.csv", ios::out);
    if (output.is_open()) cout << " mo";
    else cout << "fall";
    Node<Student>* p = this->Database.Get_P_Head();
    this->Database.DeleteAtTail();
    output << "Ho Va Ten," << "So Dien Thoai," << "Ma Ho So," << "Ma Phong," << "Gioi Tinh," << "Email," << "Ma Sinh Vien," << "Ngay Sinh," << "Dia Chi" << endl;
    while (p != nullptr)
    {
        output << p->Get_Data().Get_Name() << ',' << p->Get_Data().Get_Phone_number() << ',' 
       << p->Get_Data().Get_Profile_Code() << ',' << p->Get_Data().Get_Room_Code() << ',' 
       << ((p->Get_Data().Get_Gender() == 1) ? "Nam" : "Nu") << ',' <<p->Get_Data().Get_Email()<<','<< p->Get_Data().Get_Student_Code() << ','
      << p->Get_Data().Get_Date_of_Birth().Get_String() << ',' << p->Get_Data().Get_Address() << endl;
        p = p->Get_Next();
    }
    output.close();
}
void Management_Student::Read_File()
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
            string _d_of_b;
            string Address;
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

            //Student _Student(name, Phone_number, Room_Code, Profile_Code, Gender, Student_Code, Email, _d_of_b, Address);

            //this->Database.InsertAtTail(_Student);



        }
        this->Database.DeleteAtTail();

        input.close();
    }
}
void Management_Student::Menu_Student()
{
    Student _student_section;
    //bool check_del = true;
    int index = 0;
    while (1)
    {
    ds:
        bool update = false;
        bool find = false;
        index = Ve_nhieu_trang_chon(this->Database, update, find);

        if (index == -1)
        {
            Xoa_o(48, 10, 170, 36, 0);
            return;
        }

        else
            _student_section = this->Database.at(index);

        if (update == true)
        {
        updae_info:
            gotoXY(3, 21);
            Management_Student::Menu_update(_student_section);
            //hien thi update
        }
        else if (find == true)
        {
        find:
            gotoXY(3, 21);
            cout << 2;
            Xoa_o(48, 10, 170, 36, 0);
            Hcn(50, 20, 100, 22);
            Hcn(103, 20, 113, 22);
            Outstring(103, 21, 0, 103, "Tim Kiem");
            setBackgroundColor(0);
            setColor(15);
            gotoXY(52, 21);
            Cursor(true);
            string data;
            getline(cin, data);
            Cursor(false);
            Doubly_Linked_List<Student> _data_find = Management_Student::Find_Student(data);
            if (_data_find.Get_Lenght() == 0)
            {
                Not_Found();
            }
            else
            {
                index = Ve_nhieu_trang_chon(_data_find, update, find);
                if (index == -1)
                {
                    goto ds;
                }

                else
                {

                    _student_section = _data_find.at(index);

                }
                if (update == true)
                {
                    goto updae_info;
                }
                else if (find == true)
                {
                    goto find;
                }
                else
                {
                    goto hien_thi;
                }
            }

        }
        else
        {
        hien_thi:
            Management_Student::Menu_update(_student_section);
            Xoa_o(45, 9, 170, 36, 0);
        }

    }
}
void Management_Student::Menu_update(Student& _student_section)
{
    Xoa_o(48, 10, 170, 36, 0);
    Hcn(48, 9, 60, 11);
    Outstring(50, 10, 2, 0, "Ho Va Ten");
    Hcn(63, 9, 112, 11);
    Outstring(120, 10, 2, 0, "Gioi Tinh");
    Hcn(118, 9, 132, 11);
    Hcn(135, 9, 165, 11);
    Outstring(50, 14, 2, 0, "Dia Chi");
    Hcn(48, 13, 58, 15);
    Hcn(61, 13, 112, 15);
    Outstring(120, 14, 2, 0, "Ngay Sinh");
    Hcn(118, 13, 132, 15);
    Hcn(135, 13, 165, 15);
    Outstring(50, 18, 2, 0, "Ma Sinh Vien");
    Hcn(48, 17, 63, 19);
    Hcn(66, 17, 112, 19);
    Outstring(120, 18, 2, 0, "Ma Phong");
    Hcn(118, 17, 130, 19);
    Hcn(133, 17, 165, 19);
    Outstring(50, 22, 2, 0, "Email");
    Hcn(48, 21, 58, 23);
    Hcn(61, 21, 112, 23);
    Outstring(120, 22, 2, 0, "So Dien Thoai");
    Hcn(118, 21, 135, 23);
    Hcn(138, 21, 165, 23);
    Outstring(50, 26, 2, 0, "Ma Ho So");
    Hcn(48, 25, 58, 27);
    Hcn(61, 25, 112, 27);
    Outstring(65, 10, 9, 0, _student_section.Get_Name());
    Outstring(137, 10, 9, 0, (_student_section.Get_Gender() == 0) ? "Nu" : "Nam");
    Outstring(62, 14, 9, 0, _student_section.Get_Address());
    Outstring(137, 14, 9, 0, _student_section.Get_Date_of_Birth().Get_String());
    Outstring(68, 18, 9, 0, _student_section.Get_Student_Code());
    Outstring(135, 18, 9, 0, _student_section.Get_Room_Code());
    Outstring(63, 22, 9, 0, _student_section.Get_Email());
    Outstring(140, 22, 9, 0, _student_section.Get_Phone_number());
    Outstring(63, 26, 9, 0, _student_section.Get_Profile_Code());
    Outstring(100, 30, 2, 0, "Hoan Tat");
    Hcn(60, 29, 150, 31);
    string data;
    getline(cin, data);
}