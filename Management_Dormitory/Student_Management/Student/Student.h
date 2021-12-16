#pragma once
#include<iostream>
#include"../../Date/Date.h"
using namespace std;
class Student
{
private:
	string name; //
	string Phone_number; //
	string Profile_Code;
	string Room_Code;
	int Gender; //
	string Email;//
	string Student_Code;
	CDate Date_of_Birth;//
	string Address;//

public:
	Student();
	Student(const string&,const string&, const string&,const string&,const int&,const string&,const string&,const CDate&,const string&);
	Student(const Student&);
	~Student();
	//name
	void Set_Name(const string&);
	const string& Get_Name();
	//Phone_number
	void Set_Phone_number(const string&);
	const string& Get_Phone_number();
	//Profile_Code
	void Set_Profile_Code(const string&);
	const string& Get_Profile_Code();
	// room_code
	void Set_Room_Code(const string&);
	const string& Get_Room_Code();
	//gender
	void Set_Gender(const int&);
	const int& Get_Gender();
	//email
	void Set_Email(const string&);
	const string& Get_Email();
	//Student_Code
	void Set_Student_Code(const string&);
	const string& Get_Student_Code();
	//Date_of_Birth
	void Set_Date_of_Birth(const CDate&);
	CDate& Get_Date_of_Birth();
	//address
	void Set_Address(const string&);
	const string& Get_Address();
	/*Student& operator = (const Stdudent&);*/
};

