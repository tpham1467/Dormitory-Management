#pragma once
#include<string>
#include"Student.h"
#include"Date.h"
#include"Doubly_Linked_List.h"
using namespace std;
class Student_Profile
{
protected:
	string Profile_Code;
	CDate Registration_Date;
	string ID;
	string Native_lace;
	string Race;
public:
	Student_Profile();
	~Student_Profile();
	virtual const Student_Profile Get_Info();
	virtual void Set_Info(const Student_Profile&);
};

