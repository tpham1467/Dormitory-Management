#include "Management_Profile.h"
#include <algorithm>
#include<sstream>
Management_Profile::Management_Profile()
{
	
}
Management_Profile:: ~Management_Profile()
{

}
Doubly_Linked_List<Admission_Profile> Management_Profile::Get_Data_AP()
{
	return this->Data_AP;
}
Doubly_Linked_List<Residency_Profile> Management_Profile::Get_Data_RP()
{
	return this->Data_RP;
}
void Management_Profile::Add_Admission_Profile(const Admission_Profile& ap)
{
	Data_AP.InsertAtTail(ap);
}
void Management_Profile::Add_Residency_Profile(const Residency_Profile& rp)
{
	Data_RP.InsertAtTail(rp);
}
void Management_Profile::Extend(string  _profile_code)
{
	Node<Residency_Profile>* p = Indexoff(_profile_code, 1);
	p->Get_Data().Extend();
}
Doubly_Linked_List< Admission_Profile> Management_Profile::Find_Admission_Profile(string data,Management_Student& Database_Student)
{
    stringstream _data(data);
    Doubly_Linked_List<string> _data_Token;
    Doubly_Linked_List<Admission_Profile> data_AP;
    string token;
    while (_data >> token) {

        _data_Token.InsertAtTail(token);
    }
    //find
    Node<Admission_Profile>* p = this->Data_AP.Get_P_Head();
    while (p != nullptr)
    {

        bool check = false;
        Node<string>* pp = _data_Token.Get_P_Head();
        while (pp != nullptr && check == false)
        {
			token = pp->Get_Data();
			string _profile_code = p->Get_Data().Get_Profile_Code();
			if (_profile_code.find(token) >= 0 || _profile_code.find(token) <= _profile_code.length())
			{
				data_AP.InsertAtTail(p->Get_Data());
				check = true;
			}
			if (check == true) break;
			if (check == false)
			{
				Doubly_Linked_List<Student> data_Student = Database_Student.Find_Student(token);
				if (data_Student.Get_Lenght() != 0)
				{
					Node<Student>* p1 = data_Student.Get_P_Head();
					while (p1 != nullptr)
					{
						Node<Admission_Profile>* p2 = Indexoff(p->Get_Data().Get_Profile_Code());
						data_AP.InsertAtTail(p2->Get_Data());
					}
					check = true;
				}
			}
			pp = pp->Get_Next();
        }
		
        p = p->Get_Next();
    }
	return data_AP;
}
//Doubly_Linked_List< Residency_Profile> Management_Profile::Find_Residency_Profile(string data)
//{
//
//}
int  Management_Profile::Pay(string _profile_code)
{
	Node<Residency_Profile>* p = Indexoff(_profile_code, 1);
	Delete_RP(_profile_code);
	return p->Get_Data().Pay();
}
void Management_Profile::Confirm(string  _profile_code)
{
	Node<Admission_Profile>* p = Indexoff(_profile_code);
	p->Get_Data().Set_Confirmation_Status(true);
}
void Management_Profile::Update_Admission_Profile(string _profile_code)
{

}
void Management_Profile::Update_Residency_Profile(string  _profile_code)
{

}
Node<Residency_Profile> * Management_Profile::Indexoff(string _profile_code, int i)
{
	Node<Residency_Profile>* p = this->Data_RP.Get_P_Head();
	while (p != nullptr)
	{
		if (p->Get_Data().Get_Profile_Code() == _profile_code) return p;
		p = p->Get_Next();
	}
	return nullptr;
}
Node<Admission_Profile>* Management_Profile::Indexoff(string _profile_code)
{
	Node< Admission_Profile>* p = this->Data_AP.Get_P_Head();
	while (p!=nullptr)
	{
		if (p->Get_Data().Get_Profile_Code() == _profile_code) return p;
		p = p->Get_Next();
	}
	return nullptr;
}
void Management_Profile::Delete_RP(string _profile_code)
{
	Node<Residency_Profile>* p = Indexoff(_profile_code,1);
	this->Data_RP.Delete_indexoff(p);
}
void Management_Profile::Delete_AP(string _profile_code)
{
	Node<Admission_Profile>* p = Indexoff(_profile_code);


}
