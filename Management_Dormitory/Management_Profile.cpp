#include "Management_Profile.h"
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
//Doubly_Linked_List< Admission_Profile> Management_Profile::Find_Admission_Profile(string data)
//{
//
//}
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