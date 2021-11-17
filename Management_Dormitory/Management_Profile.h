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
	void Add_Admission_Profile();
	void Add_Residency_Profile();

};

