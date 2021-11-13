#pragma once
#include"Profile.h"
#include"Doubly_Linked_List.h"
#include<string>
using namespace std;
class Admission_Profile : public Student_Profile
{
private:
	bool Confirmation_Status;
	Doubly_Linked_List<string> TTBS;
public:
	Admission_Profile();
	~Admission_Profile();
	Add_Infor();
	Set_Room();
};

