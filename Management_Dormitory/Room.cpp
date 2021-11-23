#include "Room.h"
Room::Room(const string &_Room_code, const int &_Number_Student, const bool &COF, const CDate &HDTPNSH)
    : Room_Code(_Room_code), Number_Students(_Number_Student), condition_of_facilities(COF), Han_Dong_Tien_Phi_Sinh_Hoat(HDTPNSH)
{
}
Room::Room()
{

}
Room::~Room()
{
}
//condition of facilities
const bool &Room::Get_COF()
{
    return this->condition_of_facilities;
}
void Room::Set_COF(const bool &COF)
{
    this->condition_of_facilities = COF;
}
//Han_Dong_Tien_Phi Sinh Hoat
CDate &Room::Get_HDTPSH()
{
    return this->Han_Dong_Tien_Phi_Sinh_Hoat;
}
void Room::Set_HDTPNSH(const CDate &HDTPSH)
{
    this->Han_Dong_Tien_Phi_Sinh_Hoat = HDTPSH;
}
//Number Student
const int &Room::Get_NS()
{
    return this->Number_Students;
}
void Room::Set_NS(const int &NS)
{
    this->Number_Students = NS;
}
//Room_code
const string &Room::Get_Room_code()
{
    return this->Room_Code;
}
Doubly_Linked_List<Student>& Room::Get_List_Student(Management_Student &Data)
{
    Node<Student> *p = Data.Get_List_Student().Get_P_Head();
    Doubly_Linked_List<Student> List;
    while (p != nullptr)
    {
        if (p->Get_Data().Get_Room_Code() == this->Room_Code)
            List.InsertAtTail(p->Get_Data());
        p = p->Get_Next();
    }
    return List;
}
// void Room::Add_Student(Management_Student &,  const string &_Studen_code)
// {

// }
//void Room::Delete_Student(Management_Student &Data, const string &_Studen_code)
//{
//    Data.Delete_Student(Data.Index_off(_Studen_code)->Get_Data());
//    this->Number_Students--;
//}