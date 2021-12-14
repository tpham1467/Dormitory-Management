#include"Management_Room.h"
Room _room_section;
bool Sort_RC_DES(Room r1, Room r2)
{
    if (r1.Get_Room_code() < r2.Get_Room_code()) return true;
    else return false;
}
bool Sort_RC_ASC(Room r1, Room r2)
{
    if (r1.Get_Room_code() > r2.Get_Room_code()) return false;
    else return true;
}
bool Sort_NS_DES(Room r1, Room r2)
{
    if (r1.Get_NS() < r2.Get_NS()) return true;
    else return false;
}
bool Sort_NS_ASC(Room r1, Room r2)
{
    if (r1.Get_NS() > r2.Get_NS()) return false;
    else return true;
}
void Mamagement_Room::Read_File()
{
    ifstream input;
    input.open("Room.txt", ios::in);
    if (!input.is_open())
    {
        //throw "Unable to open file Student";
    }
    else
    {
        char z;
        while (!input.eof())
        {
            string Room_Code;
            int Number_Student;
            int COF;
            string Han_Dong_Tien_Phi_Sinh_Hoat;
            getline(input, Room_Code, ',');
            input >> Number_Student>>z;
            input >> COF;
           input.ignore();
            getline(input, Han_Dong_Tien_Phi_Sinh_Hoat, ',');
            CDate _c;
            _c = _c.To_CDate(Han_Dong_Tien_Phi_Sinh_Hoat);
            Room _Room(Room_Code, Number_Student, (COF == 1) ? true : false, _c);
            if(_Room.Get_Room_code()!="")
            this->DataBase.InsertAtTail(_Room);
            input.ignore();
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
Doubly_Linked_List<Room>& Mamagement_Room::Get_List_Room()
{
	return this->DataBase;
}
Doubly_Linked_List<Room> Mamagement_Room::Find_Room(const string& data,Management_Student& DataBase_Student)
{
    stringstream _data(data);
    Doubly_Linked_List<string> _data_Token;
    Doubly_Linked_List<Room> data_Room;
    string token;
    //tách từ 
    while (_data >> token)
    {

        _data_Token.InsertAtTail(token);
    }

    Node<string>* pp = _data_Token.Get_P_Head();
    // tìm kiếm theo mã phòng
    while (pp != nullptr)
    {
        token = pp->Get_Data();
        Node<Room>* _room = this->Get_Room(token);
        if (_room !=nullptr)
        {
            data_Room.InsertAtTail(_room->Get_Data());
        }
        pp = pp->Get_Next();
    }
    // Tìm Kiếm Theo Tên Sinh Viên
    if (data_Room.Get_Lenght() == 0)
    {
        Node<string>* pp = _data_Token.Get_P_Head();
        vector<string> List_rCode;
        while (pp != nullptr)
        {
             token = pp->Get_Data();
             Doubly_Linked_List<Student> _Data_Student = DataBase_Student.Find_Student(token);
             Node<Student>* p = _Data_Student.Get_P_Head();
             while (p != nullptr)
             {
                 List_rCode.push_back(p->Get_Data().Get_Room_Code());
                 p = p->Get_Next();
             }
            
            pp = pp->Get_Next();
        }
        // Lọc Các Mã Phòng Trùng Nhau
        sort(begin(List_rCode), end(List_rCode));
        List_rCode.erase(unique(begin(List_rCode), end(List_rCode)), end(List_rCode));

        while (List_rCode.size() != 0)
        {
            Node<Room>* _r = this->Get_Room(List_rCode.back());
            if(_r!=nullptr)
            data_Room.InsertAtTail(_r->Get_Data());
            List_rCode.pop_back();
        }

        return data_Room;
    }
    else
    {

        return data_Room;
    }
}
Node<Room>* Mamagement_Room::Get_Room(string& _Room_code)
{  
     transform(_Room_code.begin(), _Room_code.end(), _Room_code.begin(), toupper);
     Node<Room>* p = this->DataBase.Get_P_Head();
     while (p != nullptr)
     {
  
         string Room_Code_2 = p->Get_Data().Get_Room_code();
         transform(Room_Code_2.begin(), Room_Code_2.end(), Room_Code_2.begin(), toupper);
         if (_Room_code == Room_Code_2) return p;
         p = p->Get_Next();
     }
    return nullptr;
}
void Mamagement_Room::Write_File()
{
    ofstream output;
    output.open("Room.txt", ios::out);
    if (output.is_open()) cout << " mo";
    else cout << "fall";
    Node<Room>* p = this->DataBase.Get_P_Head();
    while (p != nullptr)
    {
        if (p->Get_Data().Get_Room_code() != "")
        {
            output << p->Get_Data().Get_Room_code() << ',' << p->Get_Data().Get_NS() << ','
                << p->Get_Data().Get_COF() << ',' << p->Get_Data().Get_HDTPSH().Get_String() << ',' << endl;
        }
        p = p->Get_Next();
    }
    output.close();
}
void Mamagement_Room::Export_File_Excel()
{
    ofstream output = Save_File();
    Node<Room>* p = this->DataBase.Get_P_Head();
    output << "Ma Phong" << ',' << "So Luong Sinh Vien Trong Phong" << ','
        << "Tinh Trang Sua Chua" << ',' << "Han Dong Tien Nuoc" << ',' << endl;
    while (p != nullptr)
    {
        output << p->Get_Data().Get_Room_code() << ',' << p->Get_Data().Get_NS() << ','
            << ((p->Get_Data().Get_COF()==true)?"Da Sua Chua":" Chua Sua Chua") << ',' << p->Get_Data().Get_HDTPSH().Get_String() << ',' << endl;
        p = p->Get_Next();
    }
    output.close();
}
void Mamagement_Room::Move_Room(Management_Student& data_student)
{
 Sinh_Vien_Chua_co_phong:
    Outstring(90, 37, 0, 103, "Chon Sinh Vien Can Chuyen Phong");
    Node<Student>* p = data_student.Move_Room();
    if (p->Get_Data().Get_Room_Code() == "NULL")
    {
        Sinh_Vien_chua_Phong();
        goto Sinh_Vien_Chua_co_phong;
    }
room_full:
    Outstring(90, 37, 0, 103, "      Chon Phong Chuyen Den    ");
    Menu(data_student, false);
    string rc = _room_section.Get_Room_code();
    if (_room_section.Get_NS() == 6 || _room_section.Get_Room_code() == p->Get_Data().Get_Room_Code())
    {
        Room_Full();
        goto room_full;
    }
    Delete_Student(p->Get_Data().Get_Room_Code());
    p->Get_Data().Set_Room_Code(rc);
    Node<Room>* p1 = Get_Room(rc);
    p1->Get_Data().Set_NS(p1->Get_Data().Get_NS() + 1);
    Outstring(90, 37, 0, 0, "Chon Sinh Vien Can Chuyen Phong");
    Add_Success(0);
}
void Mamagement_Room::Add_Room()
{
    string room_code;
    bool check = true;
    while (check)
    {
        int ma_room = rand() % (90 - 65 + 1) + 65;
        room_code = char(ma_room);
        ma_room = rand() % (50 - 1 + 1) + 1;
        if (ma_room < 10) room_code = room_code + '0' + to_string(ma_room);
        else room_code = room_code + to_string(ma_room);
        Node<Room>* p = this->DataBase.Get_P_Head();
        while (p!=nullptr)
        {
            if (p->Get_Data().Get_Room_code() == room_code) break;
            p = p->Get_Next();
            check = false;
        }
    }
    CDate d;
    d = d.Get_time();
    Room _Room(room_code, 0, false, d);
    this->DataBase.InsertAtTail(_Room);
}
void Mamagement_Room::Menu(Management_Student& data_student,bool flag)
{
    int index = 0;
    while (1)
    {
    ds:
        bool update = false;
        bool find = false;
        bool change = false;
        index = Move_Page(this->DataBase, update, find, change);

        if (index == -1)
        {
            Xoa_o(48, 10, 170, 36, 0);
            return;
        }
        if (index == -2)
        {
            Export_File_Excel();
             _getch();
        }
        if (index == -3)
        {
            Sort(DataBase.Get_P_Head());
            Sap_Xep_Xong();
            Hien_thi_danh_sach(arr_1, 4);
            goto ds;
        }
        else
            _room_section = this->DataBase.at(index);
        if (update == true)
        {
        updae_info:
            if (flag == false) goto ds;
            gotoXY(3, 21);
            Update(data_student);
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
            Doubly_Linked_List<Room> _data_find = Mamagement_Room::Find_Room(data, data_student);
            if (_data_find.Get_Lenght() == 0)
            {
                Not_Found();
            }
            else
            {
                Sort:
                update = false; find = false; change = false;
                index = Move_Page(_data_find, update, find,change);
                if (index == -1)
                {
                    goto ds;
                }
                if (index == -3)
                {
                    Sort(_data_find.Get_P_Head());
                    Sap_Xep_Xong();
                    Hien_thi_danh_sach(arr_1, 4);
                    goto Sort;
                }
                else
                {

                    _room_section = _data_find.at(index);

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
        else if (change == true)
        {
            if (flag == false) goto ds;
            Xoa_o(4, 14, 39, 35);
            Hien_thi_danh_sach(arr_Menu_r ,1);
            int a = bat_su_kien(arr_Menu_r,1);
            if (a == 0)
            {
                Move_Room(data_student);
            }
            else
            {
                Add_Room();
                Add_Success(1);
            }
            Xoa_o(48, 10, 170, 36, 0);
            Hien_thi_danh_sach(arr_1, 4);
        }
        else
        {
        hien_thi:
            if (flag == false) return;
            Draw_Info_Object(data_student);
            _getch();
            Xoa_o(46, 9, 170, 36, 0);
        }

    }
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
    Node<Room>* p = _Data.Get_Pointer(j);
    for (i = 15; i < 13 + 2 * y; i += 2)
    {

        Outstring(50, i - 1, 0, 6, p->Get_Data().Get_Room_code());
        Outint(75, i - 1, 0, 6, p->Get_Data().Get_NS());
        Outstring(102, i - 1, 0, 6, (p->Get_Data().Get_COF() == true) ? "Da Sua Chua" : "Chua Sua Chua");
        Outstring(137, i - 1, 0, 6, p->Get_Data().Get_HDTPSH().Get_String());

        Line(48, i, 170, i, 6, false);
        p = p->Get_Next();
    }
    Outstring(50, i - 1, 0, 6, p->Get_Data().Get_Room_code());
    Outint(75, i - 1, 0, 6, p->Get_Data().Get_NS());
    Outstring(102, i - 1, 0, 6, (p->Get_Data().Get_COF()==true)?"Da Sua Chua":"Chua Sua Chua");
    Outstring(137, i - 1, 0, 6, p->Get_Data().Get_HDTPSH().Get_String());
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
int Mamagement_Room::Move_Page(Doubly_Linked_List<Room>& _data, bool& update, bool& find,bool& change)
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
        case 109:
        {
            change = true;
            return dem;
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
        case 115:
        {
            return -3;
        }
        case 120:
        {
            return -2;
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
void Mamagement_Room::Draw_Info_Object(Management_Student& _Data)
{
    Xoa_o(48, 10, 170, 36, 0);
    Hcn(48, 9, 60, 11);
    Outstring(50, 10, 2, 0, "Ma Phong");
    Hcn(63, 9, 112, 11);
    Outstring(120, 10, 2, 0, "So Luong Sinh Vien");
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
    Doubly_Linked_List<Student> data = _room_section.Get_List_Student(_Data);
    Node<Student>* p = data.Get_P_Head();
    for (int i = 0; i < data.Get_Lenght(); i++)
    {
        if (i == 2 || i == 4) y += 4;
        if (i % 2 == 0)
        {
            Outstring(50, y + 1, 2, 0, "Sinh Vien :");
            Outint(62, y + 1, 2, 0, i + 1);
            Hcn(48, y, 65, y + 2);
            Hcn(68, y, 112, y + 2);
            Outstring(70, y + 1, 9, 0, p->Get_Data().Get_Name());
        }
        else
        {
            Outstring(120, y + 1, 2, 0, "Sinh Vien :");
            Outint(132, y + 1, 2, 0, i + 1);
            Hcn(118, y, 135, y + 2);
            Hcn(138, y, 165, y + 2);
            Outstring(139, y + 1, 9, 0, p->Get_Data().Get_Name());
        }
        p = p->Get_Next();
    }
    Outstring(64, 10, 9, 0, _room_section.Get_Room_code());
    Outint(147, 10, 9, 0, _room_section.Get_NS());
    Outstring(80, 14, 9, 0, ((_room_section.Get_COF() == true) ? "Da Sua Chua" : "Chua Sua Chua"));
    Outstring(150, 14, 9, 0, _room_section.Get_HDTPSH().Get_String());
    CDate d; d = d.Get_time();
    if (d > _room_section.Get_HDTPSH())
    {
        Outstring(50, 34, 2, 0, "Phong Qua Han Dong Phi Sinh Hoat");
        Hcn(48, 33, 84, 35);
    }
    else
    {
        Xoa_o(47, 33, 84, 35);
    }
    //Hcn(60, 29, 150, 31);
}
void Mamagement_Room::Update(Management_Student& Data_Student)
{
    Quay_lai :
    Draw_Info_Object(Data_Student);
    Outstring(50, 30, 2, 0, "Xac Nhan Sua Chua");
    Hcn(48, 29, 67,31);
    Outstring(120, 30, 2, 0, "Dong Tien Dien Nuoc");
    Hcn(118, 29, 140, 31);
    int i = 1;
    while (1)
    {
        char key = ' ';
        key = _getch();
        if(i==1)
          Outstring(50, 30, 2, 0, "Xac Nhan Sua Chua");
        else 
            Outstring(120, 30, 2, 0, "Dong Tien Dien Nuoc");
        if (key == 75)
        {
            if (i == 2) i--;

        }
        else if (key == 77)
        {
            if (i == 1) i++;

        }
        else if (key == 13)
        {
            if (i == 1)
            {
                if (_room_section.Get_COF() == false)
                {
                    _room_section.Set_COF(true);
                    Confirm(0);
                }
                else
                {
                    Confirm(1);
                    char Key=_getch();
                    if (Key == 'Y' || Key == 'y')
                    {
                        _room_section.Set_COF(false);
                    }
                    Outstring(80, 33, 0, 0, "                                                        ");
                    Outstring(80, 34, 0, 0, "                                                        ");
                }
            }
            else
            {
                Payment_Success(1);
                CDate d;
                d = d.Get_time();
                d.operator+(1);
                _room_section.Set_HDTPNSH(d);
            }
            goto Quay_lai;
        }
        else if (key == 27)
        {
            string rc = _room_section.Get_Room_code();
            Node<Room>* p = Get_Room(rc);
            this->DataBase.replace(p, _room_section);
            break;
        }
        if (i == 1)
            Outstring(50, 30, 4, 0, "Xac Nhan Sua Chua");
        else
            Outstring(120, 30, 4, 0, "Dong Tien Dien Nuoc");
    }
}
void Mamagement_Room::Delete_Student(string Room_Code)
{
    Node<Room>* p = Get_Room(Room_Code);
    p->Get_Data().Set_NS(p->Get_Data().Get_NS() - 1);
}
void Mamagement_Room::Add_Student(string Room_Code)
{
    Node<Room>* p = Get_Room(Room_Code);
    p->Get_Data().Set_NS(p->Get_Data().Get_NS() + 1);
}
Room Mamagement_Room::Get_Room_Section()
{
    return _room_section;
}
void Swap(Node<Room>* p1, Node<Room>* p2)
{
    Room temp = p1->Get_Data();
    p1->Set_Data(p2->Get_Data());
    p2->Set_Data(temp);
}
void Mamagement_Room::SelectionSort(Node<Room>* p, bool Compfunc(Room, Room))
{
    Node<Room>* min;
    while (p->Get_Next() != nullptr)
    {
        min = p;
        Node<Room>* p1 = p->Get_Next();
        while (p1 != nullptr)
        {
            if (Compfunc(p1->Get_Data(), min->Get_Data()))
            {
                min = p1;
            }
            p1 = p1->Get_Next();
        }
        Swap(min, p);
        p = p->Get_Next();
    }
}
void Mamagement_Room::Sort(Node<Room> *p)
{
    Xoa_o(4, 14, 39, 35);
    Hien_thi_danh_sach(list_sort_r, 1);
    int a = bat_su_kien(list_sort_r, 1);
    Xoa_o(4, 14, 39, 35);
    Hien_thi_danh_sach(list_ss, 1);
    int b = bat_su_kien(list_ss, 1);
    Xoa_o(4, 14, 39, 35);
    Dang_sap_xep();
    if (a == 0)
    {
        if (b == 0) SelectionSort(p, Sort_RC_DES);
        else  SelectionSort(p ,Sort_RC_ASC);
    }
    else
    {
        if (b == 0) SelectionSort(p,Sort_NS_DES);
        else  SelectionSort(p, Sort_NS_ASC);
    }
}