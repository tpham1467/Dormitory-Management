#include"Management_Room.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include"Khoi_tao.h"
bool flag = false;
Room _room_section;
void Mamagement_Room::Read_File()
{
    ifstream input;
    input.open("Room.csv", ios::in);
    if (!input.is_open())
    {
        //throw "Unable to open file Student";
    }
    else
    {
        int n; char z;
        input >> n >> z;
        int i = 0;
        while (n>i)
        {
            string Room_Code;
            int Number_Student;
            int COF;
            input.ignore();
            string Han_Dong_Tien_Phi_Sinh_Hoat;
            getline(input, Room_Code, ',');
            input >> Number_Student>>z;
            input >> COF;
           input.ignore();
            getline(input, Han_Dong_Tien_Phi_Sinh_Hoat, ',');
            CDate _c;
            _c = _c.To_CDate(Han_Dong_Tien_Phi_Sinh_Hoat);
            Room _Room(Room_Code, Number_Student, (COF == 1) ? true : false, _c);
            this->DataBase.InsertAtTail(_Room);
            i++;
          /*  cout << _Room.Get_Room_code() << " " << _Room.Get_NS() << " " << _Room.Get_COF() << " " << _Room.Get_HDTPSH() << endl;*/
        }
        input.close();
    }
 
}
Mamagement_Room::Mamagement_Room()
{
 
}

Mamagement_Room::~Mamagement_Room()
{
	this->DataBase.~Doubly_Linked_List();
}
Doubly_Linked_List<Room> Mamagement_Room::Get_List_Room()
{
	return this->DataBase;
}
Doubly_Linked_List<Room> Mamagement_Room::Find_Room(const string& data,Management_Student& DataBase_Student)
{
    stringstream _data(data);
    Doubly_Linked_List<string> _data_Token;
    Doubly_Linked_List<Room> data_Room;
    string token;
    while (_data >> token) {

        _data_Token.InsertAtTail(token);
    }

        Node<string>* pp = _data_Token.Get_P_Head();
        while (pp != nullptr)
        {
            token = pp->Get_Data();
            Room _room = this->Get_Room(token);
            if (flag == false)
            {
                data_Room.InsertAtTail(_room);
            }
            else
            {
                flag = false;
            }
            pp = pp->Get_Next();
        }
     
   

    if (data_Room.Get_Lenght() == 0)
    {
        Node<string>* pp = _data_Token.Get_P_Head();
        vector<string> List_rCode;
        while (pp != nullptr)
        {
             token = pp->Get_Data();
             Doubly_Linked_List<Student> _Data_Student= DataBase_Student.Find_Student(token);

            
         
                Node<Student>* p = _Data_Student.Get_P_Head();
                while (p!=nullptr){
                
                    cout << p->Get_Data().Get_Name() << p->Get_Data().Get_Room_Code() << endl;
                    List_rCode.push_back(p->Get_Data().Get_Room_Code());
                    p = p->Get_Next();
                }
            
            pp = pp->Get_Next();
        }
        sort(begin(List_rCode), end(List_rCode));
        List_rCode.erase(unique(begin(List_rCode), end(List_rCode)), end(List_rCode));

        while (List_rCode.size() != 0)
        {
            Room _r = this->Get_Room(List_rCode.back());
            cout << _r.Get_Room_code() << 1;
            data_Room.InsertAtTail(_r);

            List_rCode.pop_back();
        }

        return data_Room;
    }
    else
    {

        return data_Room;
    }
}
const Room Mamagement_Room::Get_Room(string& _Room_code)
{   
    transform(_Room_code.begin(), _Room_code.end(), _Room_code.begin(), toupper);
     Node<Room>* p = this->DataBase.Get_P_Head();
     while (p != nullptr)
     {
  
         string Room_Code_2 = p->Get_Data().Get_Room_code();
         transform(Room_Code_2.begin(), Room_Code_2.end(), Room_Code_2.begin(), toupper);
         if (_Room_code == Room_Code_2) return p->Get_Data();
         p = p->Get_Next();
     }
    flag = true;
    return Room(" ", 0, 0, CDate(0,0,0));
}
void Mamagement_Room::Write_File()
{
    ofstream output;
    output.open("Room_Excel.csv", ios::out);
    if (output.is_open()) cout << " mo";
    else cout << "fall";
    Node<Room>* p = this->DataBase.Get_P_Head();
    output << "Ma Phong" << ',' << "So Luong Sinh Vien Trong Phong" << ','
        << "Tinh Trang Sua Chua" << ',' << "Han Dong Tien Nuoc" << ',' << endl;
    while (p != nullptr)
    {
        output << p->Get_Data().Get_Room_code() << ',' << p->Get_Data().Get_NS() << ','
            << p->Get_Data().Get_COF() << ',' << p->Get_Data().Get_HDTPSH().Get_String() << ',' << endl;
        p = p->Get_Next();
    }
    output.close();
}
void Mamagement_Room::Menu()
{
    //Room _stud_section;
    ////bool check_del = true;
    //int index = 0;
    //while (1)
    //{
    //ds:
    //    bool update = false;
    //    bool find = false;
    //    index = Ve_nhieu_trang_chon(this->Database, update, find);

    //    if (index == -1)
    //    {
    //        Xoa_o(48, 10, 170, 36, 0);
    //        return;
    //    }

    //    else
    //        _student_section = this->Database.at(index);

    //    if (update == true)
    //    {
    //    updae_info:
    //        gotoXY(3, 21);
    //        Management_Student::Menu_update(_student_section);
    //        //hien thi update
    //    }
    //    else if (find == true)
    //    {
    //    find:
    //        gotoXY(3, 21);
    //        cout << 2;
    //        Xoa_o(48, 10, 170, 36, 0);
    //        Hcn(50, 20, 100, 22);
    //        Hcn(103, 20, 113, 22);
    //        Outstring(103, 21, 0, 103, "Tim Kiem");
    //        setBackgroundColor(0);
    //        setColor(15);
    //        gotoXY(52, 21);
    //        Cursor(true);
    //        string data;
    //        getline(cin, data);
    //        Cursor(false);
    //        Doubly_Linked_List<Student> _data_find = Management_Student::Find_Student(data);
    //        if (_data_find.Get_Lenght() == 0)
    //        {
    //            Not_Found();
    //        }
    //        else
    //        {
    //            index = Ve_nhieu_trang_chon(_data_find, update, find);
    //            if (index == -1)
    //            {
    //                goto ds;
    //            }

    //            else
    //            {

    //                _student_section = _data_find.at(index);

    //            }
    //            if (update == true)
    //            {
    //                goto updae_info;
    //            }
    //            else if (find == true)
    //            {
    //                goto find;
    //            }
    //            else
    //            {
    //                goto hien_thi;
    //            }
    //        }

    //    }
    //    else
    //    {
    //    hien_thi:
    //        Management_Student::Menu_update(_student_section);
    //        Xoa_o(45, 9, 170, 36, 0);
    //    }

    //}
}
void Mamagement_Room::Draw_a_Page(int y, Doubly_Linked_List<Room>& _Data ,int j)
{
    if (j == -1) {


        Xoa_o(48, 10, 170, 12, 15);
        Xoa_o(48, 13, 170, 13 + 1, 6);
        Outstring(50, 11, 0, 15, "Ma Phong");
        Outstring(72, 11, 0, 15, "So Sinh Vien");
        Outstring(102, 11, 0, 15, "Tinh Trang Sua Chua");
        Outstring(135, 11, 0, 15, "Han Dong Dong Phi Sinh Hoat");
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
        Outstring(50, 11, 0, 15, "Ma Phong");
        Outstring(72, 11, 0, 15, "So Sinh Vien");
        Outstring(102, 11, 0, 15, "Tinh Trang Sua Chua");
        Outstring(135, 11, 0, 15, "Han Dong Dong Phi Sinh Hoat");
    }
    int i;

    for (i = 15; i < 13 + 2 * y; i += 2)
    {

        Outstring(50, i - 1, 0, 6, _Data[j].Get_Room_code());
        Outint(75, i - 1, 0, 6, _Data[j].Get_NS());
        Outstring(102, i - 1, 0, 6, (_Data[j].Get_COF() == true) ? "Da Sua Chua" : "Chua Sua Chua");
        Outstring(137, i - 1, 0, 6, _Data[j].Get_HDTPSH().Get_String());

        Line(48, i, 170, i, 6, false);
        j++;
    }
    Outstring(50, i - 1, 0, 6, _Data[j].Get_Room_code());
    Outint(75, i - 1, 0, 6, _Data[j].Get_NS());
    Outstring(102, i - 1, 0, 6, (_Data[j].Get_COF()==0)?"Da Sua Chua":"Chua Sua Chua");
    Outstring(137, i - 1, 0, 6, _Data[j].Get_HDTPSH().Get_String());

    Line(61, 13, 61, 13 + 2 * y, 6);
    Line(61, 10, 61, 12, 15);
    Line(95, 13, 95, 13 + 2 * y, 6);
    Line(95, 10, 95, 12, 15);
    Line(125, 13, 125, 13 + 2 * y, 6);
    Line(125, 10, 125, 12, 15);
    for (int i = 15; i < 13 + 2 * y; i += 2)
    {

        Confict_line(48, i, 170, i, 61, 13, 61, 13 + 2 * y, 6);
        Confict_line(48, i, 170, i, 95, 13, 95, 13 + 2 * y, 6);
        Confict_line(48, i, 170, i, 125, 13, 125, 13 + 2 * y, 6);

    }
}
int Mamagement_Room::Move_Page(Doubly_Linked_List<Room>& _data, bool& update, bool& find)
{
    int lenght = _data.Get_Lenght();
    int so_lan = (int)(lenght / 10) + 1;
    int i = 0, j = 1; int z = 0; ; int dem = 0; bool check = false;
    Xoa_o(48, 10, 170, 35, 0);
    bool Firt = false;
    if (so_lan == 1)
    {
        Draw_a_Page(lenght,_data, 0);
        Draw_Object(_data, 0, 4, i);
        Firt = true;
    }
    else
    {
        Draw_a_Page(10, _data, 0);
        Outstring(101, 13 + 2 * 10 + 1, 2, 0, "<<");
        Outint(103, 13 + 2 * 10 + 1, 1, 0, j);
        Outstring(104, 13 + 2 * 10 + 1, 2, 0, ">>");
        Draw_Object(_data, 0, 4, i);
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
                Draw_Object(_data, dem, 0, i);
                dem += -1;
                check = false;
                Draw_Object(_data, dem, 4, i);
            }
            break;
        }
        case 80:
        {
            if (dem == i + 9 || dem == lenght - 1) break;
            else
            {
                Draw_Object(_data, dem, 0, i);
                dem += 1;
                Draw_Object(_data, dem, 4, i);
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
                    Draw_a_Page(lenght,_data, i);
                    Draw_Object(_data, lenght, 4, i);
                    z = lenght;
                }
                else
                {
                    if (lenght - (so_lan - 1) * 10 == 0)
                    {
                        z = 1;
                        Draw_a_Page(lenght - (so_lan - 1) * 10,_data, -1);
                    }
                    else
                    {
                        Draw_a_Page(lenght - (so_lan - 1) * 10,_data, i);
                        Draw_Object(_data, dem, 4, i);
                        z = lenght - (so_lan - 1) * 10;
                    }
                }

            }
            else
            {
                Draw_a_Page(10,_data, i);
                Draw_Object(_data, dem, 4, i);
                z = 10;
            }
            Outstring(101, 13 + 2 * z + 1, 2, 0, "<<");
            Outint(103, 13 + 2 * z + 1, 1, 0, j);
            Outstring((j > 9) ? 105 : 104, 13 + 2 * z + 1, 2, 0, ">>");

        }
    }
}
void Mamagement_Room::Draw_Object(Doubly_Linked_List<Room>& _Database, int index, int color, int i)
{
    Outstring(50, (index - i) * 2 + 14, color, 6, "        ");
    Outstring(102, (index - i) * 2 + 14, color, 6, "                  ");
    Outstring(137, (index - i) * 2 + 14, color, 6, "                  ");
    Outstring(50, (index - i) * 2 + 14, color, 6, _Database[index].Get_Room_code());
    Outint(75, (index - i) * 2 + 14, color, 6, _Database[index].Get_NS());
    Outstring(102, (index - i) * 2 + 14, color, 6, ((_Database[index].Get_COF() == true) ? "Da Sua Chua" : "Chua Sua Chua"));
    Outstring(137, (index - i) * 2 + 14, color, 6, _Database[index].Get_HDTPSH().Get_String());
}
void Mamagement_Room::Draw_Info_Object()
{
    Xoa_o(48, 10, 170, 36, 0);
    Hcn(48, 9, 60, 11);
    Outstring(50, 10, 2, 0, "Ma Phong");
    Hcn(63, 9, 112, 11);
    Outstring(120, 10, 2, 0,"So Luong Sinh Vien");
    Hcn(118, 9, 140, 11);
    Hcn(143, 9, 165, 11);
    Outstring(50, 14, 2, 0, "Tinh Trang Sua Chua");
    Hcn(48, 13, 75, 15);
    Hcn(78, 13, 112, 15);
    Outstring(120, 14, 2, 0, "Han Dong Phi Sinh Hoat");
    Hcn(118, 13, 143, 15);
    Hcn(146, 13, 165, 15);
    int x1 = 48, x2 = 118;
    int y = 17;
    //Doubly_Linked_List<Student> = _room_section.Get_List_Student(Data);
    for (int i = 0; i < 0; i++)
    {
        if (i == 2 || i == 4) y += 4;
        if (i % 2 == 0)
        {
            Outstring(50, y+1, 2, 0, "Sinh Vien :");
            Outint(62, y+1, 2, 0, i + 1);
            Hcn(48, y, 65, y+2);
            Hcn(68, y, 112, y+2);
        }
        else
        {
            Outstring(120, y+1, 2, 0, "Sinh Vien :");
            Outint(132, y+1, 2, 0, i + 1);
            Hcn(118, y, 135, y + 2);
            Hcn(138, y, 165, y+2);
        }
    }
    //Outstring(65, 10, 9, 0, R.Get_Name());
    //Outstring(137, 10, 9, 0, (_student_section.Get_Gender() == 0) ? "Nu" : "Nam");
    //Outstring(62, 14, 9, 0, _student_section.Get_Address());
    //Outstring(137, 14, 9, 0, _student_section.Get_Date_of_Birth().Get_String());
    //Outstring(68, 18, 9, 0, _student_section.Get_Student_Code());
    //Outstring(135, 18, 9, 0, _student_section.Get_Room_Code());
    //Outstring(63, 22, 9, 0, _student_section.Get_Email());
    //Outstring(140, 22, 9, 0, _student_section.Get_Phone_number());
    //Outstring(63, 26, 9, 0, _student_section.Get_Profile_Code());
    //Outstring(100, 30, 2, 0, "Hoan Tat");
    //Hcn(60, 29, 150, 31);
}