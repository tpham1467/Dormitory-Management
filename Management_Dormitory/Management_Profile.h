#pragma once
#include"Admission_Profile.h"
class Management_Profile
{
private:
	Doubly_Linked_List<Admission_Profile> Data_AP;
	Doubly_Linked_List<Residency_Profile> Data_RP;
public:
	Management_Profile();
	~Management_Profile();
	Doubly_Linked_List<Admission_Profile> Get_Data_AP();
	Doubly_Linked_List<Residency_Profile> Get_Data_RP();
	void Add_Admission_Profile(const Admission_Profile&);
	void Add_Residency_Profile(const Residency_Profile&);
	void Extend(string);
	Doubly_Linked_List< Admission_Profile> Find_Admission_Profile(string);
	Doubly_Linked_List< Residency_Profile> Find_Residency_Profile(string);
	int  Pay(string);
	void Confirm(string);
	void Update_Admission_Profile(string);
	void Update_Residency_Profile(string);
	Node<Residency_Profile>* Indexoff(string,int);
	Node<Admission_Profile>* Indexoff(string);
	void Delete_RP(string);
	void Delete_AP(string);
	void Set_Room(string);
};

