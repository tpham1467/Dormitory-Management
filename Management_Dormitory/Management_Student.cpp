#include "Management_Student.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include"Date.h"
using namespace std;
int Management_Student::N_S = 0;
Student _student_section;
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
    if (output.is_open()) cout << "";
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
    }
    else
    {
       /* input >> this->N_S;*/
        while (!input.eof())
        {
            string name_1;
            string Phone_number;
            string Profile_Code;
            string Room_Code;
            int Gender;
            string Email;
            string Student_Code;
            string _d_of_b;
            string Address;
            getline(input, name_1, '-');
            getline(input, Phone_number, '-');
            getline(input, Profile_Code, '-');
            getline(input, Room_Code, '-');
            input >> Gender;
            input.ignore();
            getline(input, Email, '-');
            getline(input, Student_Code, '-');
            getline(input, _d_of_b, '-');
            getline(input, Address, '.');
            input.ignore();
            CDate _d;
            _d = _d.To_CDate(_d_of_b);
            Student _Student(name_1, Phone_number, Room_Code, Profile_Code, Gender, Student_Code, Email, _d, Address);
            this->Database.InsertAtTail(_Student);
        }
        this->Database.DeleteAtTail();

        input.close();
    }
}
void Management_Student::Menu_Student()
{
    //bool check_del = true;
    int index = 0;
    while (1)
    {
    ds:
        bool update = false;
        bool find = false;
        index = Move_Page(this->Database, update, find);

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
            Xoa_o(46, 9, 170, 36, 0);
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
                index = Move_Page(_data_find, update, find);
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
            Management_Student::Draw_Info_Object();
            Xoa_o(46, 9, 170, 36, 0);
        }

    }
}
void Management_Student::Menu_update(Student& _student_section)
{
    Outstring(100, 30, 2, 0, "Hoan Tat");
    Hcn(60, 29, 150, 31);
    string data;
    getline(cin, data);
}
void Management_Student::Update_Info(Node<Student>* p,const Student& _student)
{
    this->Database.replace(p, _student);
}
void Management_Student::Draw_a_Page(int y, int color, Doubly_Linked_List<Student>& Database, int j)
{
    if (j == -1) {


        Xoa_o(48, 10, 170, 12, 15);
        Xoa_o(48, 13, 170, 13 + 1, 6);
        Outstring(50, 11, 0, 15, "Ma Sinh Vien");
        Outstring(84, 11, 0, 15, "Ho Va Ten");
        Outstring(112, 11, 0, 15, "Gioi Tinh");
        Outstring(140, 11, 0, 15, "Dia Chi");
        Line(68, 13, 68, 13 + 1, 6);
        Line(68, 10, 68, 12, 15);
        Line(108, 13, 108, 13 + 1, 6);
        Line(108, 10, 108, 12, 15);
        Line(125, 13, 125, 13 + 1, 6);
        Line(125, 10, 125, 12, 15);
        return;
    }
    else
    {
        Xoa_o(48, 10, 170, 12, 15);
        Xoa_o(48, 13, 170, 13 + 2 * y, 6);
        Outstring(50, 11, 0, 15, "Ma Sinh Vien");
        Outstring(84, 11, 0, 15, "Ho Va Ten");
        Outstring(112, 11, 0, 15, "Gioi Tinh");
        Outstring(140, 11, 0, 15, "Dia Chi");
    }
    int i;

    for (i = 15; i < 13 + 2 * y; i += 2)
    {

        Outstring(51, i - 1, 0, 6, Database[j].Get_Student_Code());

        Outstring(72, i - 1, 0, 6, Database[j].Get_Name());
        Outstring(111, i - 1, 0, 6, (Database[j].Get_Gender() == 1) ? "Nam" : "Nu");
        Outstring(128, i - 1, 0, 6, Database[j].Get_Address());

        Line(48, i, 170, i, 6, false);
        j++;
    }
    Outstring(51, i - 1, 0, 6, Database[j].Get_Student_Code());
    Outstring(72, i - 1, 0, 6, Database[j].Get_Name());
    Outstring(111, i - 1, 0, 6, (Database[j].Get_Gender() == 1) ? "Nam" : "Nu");
    Outstring(128, i - 1, 0, 6, Database[j].Get_Address());

    Line(68, 13, 68, 13 + 2 * y, 6);
    Line(68, 10, 68, 12, 15);
    Line(108, 13, 108, 13 + 2 * y, 6);
    Line(108, 10, 108, 12, 15);
    Line(125, 13, 125, 13 + 2 * y, 6);
    Line(125, 10, 125, 12, 15);
    for (int i = 15; i < 13 + 2 * y; i += 2)
    {

        Confict_line(48, i, 170, i, 68, 13, 68, 13 + 2 * y, 6);
        Confict_line(48, i, 170, i, 125, 13, 125, 13 + 2 * y, 6);
        Confict_line(48, i, 170, i, 108, 13, 108, 13 + 2 * y, 6);

    }
}
void Management_Student::Draw_Object(Doubly_Linked_List<Student>& Database, int index , int color, int i)
{
    Outstring(51, (index - i) * 2 + 14, color, 6, Database[index].Get_Student_Code());
    Outstring(72, (index - i) * 2 + 14, color, 6, Database[index].Get_Name());
    Outstring(111, (index - i) * 2 + 14, color, 6, (Database[index].Get_Gender() == 1) ? "Nam" : "Nu");
    Outstring(128, (index - i) * 2 + 14, color, 6, Database[index].Get_Address());
}
void Management_Student::Draw_Info_Object()
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
<<<<<<< HEAD
    _getch();
}
int Management_Student::Move_Page(Doubly_Linked_List<Student>& Database, bool& update, bool& find)
{
    int lenght = Database.Get_Lenght();
    int so_lan = (int)(lenght / 10) + 1;
    int i = 0, j = 1; int z = 0; ; int dem = 0; bool check = false;
    Xoa_o(48, 10, 170, 35, 0);
    bool Firt = false;
    if (so_lan == 1)
    {
        Draw_a_Page(lenght, 6, Database, 0);
        Draw_Object(Database, 0, 4, i);
        Firt = true;
    }
    else
    {
        Draw_a_Page(10, 6, Database, 0);
        Outstring(101, 13 + 2 * 10 + 1, 2, 0, "<<");
        Outint(103, 13 + 2 * 10 + 1, 1, 0, j);
        Outstring(104, 13 + 2 * 10 + 1, 2, 0, ">>");
        Draw_Object(Database, 0, 4, i);
        Firt = true;
    }
    while (1)
    {
        char key = _getch();
        switch (key)
        {
        case 77:
        {
            if (j == so_lan) i = i;
            else {
                i += 10;
                j++;
                dem = i;
                check = true;
            }
            break;
        }
        case 75:
        {
            if (i == 0) break;
            else
            {
                i -= 10;
                j--;
                dem = i;
                check = true;
            }
            break;
        }
        case 72:
        {
            if (dem == i) break;
            else {
                Draw_Object(Database, dem, 0, i);
                dem += -1;
                check = false;
                Draw_Object(Database, dem, 4, i);
            }
            break;
        }
        case 80:
        {
            if (dem == i + 9 || dem == lenght - 1) break;
            else
            {
                Draw_Object(Database, dem, 0, i);
                dem += 1;
                Draw_Object(Database, dem, 4, i);
                check = false;
            }

            break;
        }
        case 13:
        {

            return dem;
            break;
        }
        case 27:
        {
            return -1;
            break;
        }
        case 85:
        {
            update = true;
            return dem;
        }
        case 117:
        {
            update = true;
            return dem;
        }
        case 70:
        {
            find = true;
            return dem;
        }
        case 102:
        {
            find = true;
            return dem;
        }
        }
        if (Firt == true && check == true)
        {
            Xoa_o(48, 10, 170, 35, 0);
            if (j == so_lan || lenght < 10)
            {
                if (lenght < 10)
                {
                    Draw_a_Page(lenght, 6, Database, i);
                    Draw_Object(Database, lenght, 4, i);
                    z = lenght;
                }
                else
                {
                    if (lenght - (so_lan - 1) * 10 == 0)
                    {
                        z = 1;
                        Draw_a_Page(lenght - (so_lan - 1) * 10, 6, Database, -1);
                    }
                    else
                    {
                        Draw_a_Page(lenght - (so_lan - 1) * 10, 6, Database, i);
                        Draw_Object(Database, dem, 4, i);
                        z = lenght - (so_lan - 1) * 10;
                    }
                }

            }
            else
            {
                Draw_a_Page(10, 6, Database, i);
                Draw_Object(Database, dem, 4, i);
                z = 10;
            }
            Outstring(101, 13 + 2 * z + 1, 2, 0, "<<");
            Outint(103, 13 + 2 * z + 1, 1, 0, j);
            Outstring((j > 9) ? 105 : 104, 13 + 2 * z + 1, 2, 0, ">>");

        }
    }
=======
    Outstring(100, 30, 2, 0, "Hoan Tat");
    Hcn(60, 29, 150, 31);
    string data;
    getline(cin, data);
}
void Management_Student::Update_Info(Node<Student>* p,const Student& _student)
{
    this->Database.replace(p, _student);
>>>>>>> 719b41b9401dc152faff1cb55369e2c10e7f101d
}