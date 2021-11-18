#pragma once
#include"Residency_Profile.h"
#include"Doubly_Linked_List.h"
#include<string>
using namespace std;
class Admission_Profile : public Residency_Profile
{
private:
	bool Confirmation_Status;
	Doubly_Linked_List<string> TTBS;
public:
	Admission_Profile();
	Admission_Profile(const string& , const CDate& , const string& , const string& , const string& _Race, const CDate&, Doubly_Linked_List<string>,bool=false );
	Admission_Profile(const Admission_Profile&);
	~Admission_Profile();
	void Add_Infor(const string&);
	Doubly_Linked_List<string> Get_TTBS();
	//void Set_Room();
	void Set_Confirmation_Status(bool);
	bool Get_Confirmation_Status();
};

