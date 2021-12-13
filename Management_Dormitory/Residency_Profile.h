#pragma once
#include"Date.h"
#include<string>
#include"Management_Student.h"
using namespace std;
class Residency_Profile
{

protected:
	string Profile_Code;
	CDate Registration_Date;
	string ID;
	string Native_lace;
	string Race;
	CDate Expiration_Date;
public:

	Residency_Profile();
	Residency_Profile(const string&, const CDate&, const string&, const string&, const string&, const CDate&);
	Residency_Profile(const Residency_Profile&);
	~Residency_Profile();
	string Get_Profile_Code();
	void Set_Profile_Code(const string&);
	CDate Get_Registration_Date();
	void Set_Registration_Date(const CDate&);
	string Get_ID();
	void Set_ID(const string&);
	string Get_Native_lace();
	void Set_Native_lace(const string&);
	string Get_Race();
	void Set_Race(const string&);
	CDate Get_Expiration_Date();
	void Set_Expiration_Date(const CDate&);
	void Extend();
	int  Pay();
	Node<Student>* Get_Student(Management_Student&);
};

