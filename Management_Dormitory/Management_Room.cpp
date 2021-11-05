#include"Management_Room.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
bool flag = false;
void Mamagement_Room::Read_File()
{
    ifstream input;
    input.open("Room.csv", ios::in);
    if (!input.is_open())
    {
        //throw "Unable to open file Student";
        cout << 1;
    }
    else
    {
        int n; char z;
        input >> n >> z;
        while (!input.eof())
        {
            string Room_Code;
            int Number_Student;
            int COF;
            input.ignore();
            string Han_Dong_Tien_Phi_Sinh_Hoat;
            getline(input, Room_Code, ',');
            input >> Number_Student>>z;
            input >> COF>>z;
           input.ignore();
            getline(input, Han_Dong_Tien_Phi_Sinh_Hoat, ',');
            Room _Room(Room_Code, Number_Student, (COF == 1) ? true : false, Han_Dong_Tien_Phi_Sinh_Hoat);
            this->DataBase.InsertAtHead(_Room);
            cout << _Room.Get_Room_code() << " " << _Room.Get_NS() << " " << _Room.Get_COF() << " " << _Room.Get_HDTPSH() << endl;
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
const Doubly_Linked_List<Room> Mamagement_Room::Get_List_Room()
{
	return this->DataBase;
}
vector<Room> Mamagement_Room::Find_Room(const string& data,Management_Student& DataBase_Student)
{
    stringstream _data(data);
    Doubly_Linked_List<string> _data_Token;
    vector<Room> data_Room;
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
                data_Room.push_back(_room);
            }
            else
            {
                flag = false;
            }
            pp = pp->Get_Next();
        }
     
   

    if (data_Room.size() == 0)
    {
        Node<string>* pp = _data_Token.Get_P_Head();
        vector<string> List_rCode;
        while (pp != nullptr)
        {
             token = pp->Get_Data();
            vector<Student> _Data_Student = DataBase_Student.Find_Student(token);
            if (_Data_Student.size() != 0)
            {
                while (_Data_Student.size() != 0)
                {
                    Student _s = _Data_Student.back();
                    string rCode = _s.Get_Room_Code();
                    cout << _s.Get_Name() << _s.Get_Room_Code() << endl;
                    List_rCode.push_back(rCode);
                    _Data_Student.pop_back();
                }
            }
            pp = pp->Get_Next();
        }
        sort(begin(List_rCode), end(List_rCode));
        List_rCode.erase(unique(begin(List_rCode), end(List_rCode)), end(List_rCode));
        while (List_rCode.size() != 0)
        {
            data_Room.push_back(Mamagement_Room::Get_Room(List_rCode.back()));
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
    Node<Room>* p = this->DataBase.Get_P_Head();
    while (p != nullptr)
    {
        transform(_Room_code.begin(), _Room_code.end(), _Room_code.begin(), toupper);
        string Room_Code_2 = p->Get_Data().Get_Room_code();
        transform(Room_Code_2.begin(), Room_Code_2.end(), Room_Code_2.begin(), toupper);
        if (_Room_code == Room_Code_2) return p->Get_Data();
        p = p->Get_Next();
    }
    flag = true;
    return Room(" ", 0, 0, " ");
}