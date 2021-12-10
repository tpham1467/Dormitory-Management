#include "Residency_Profile.h"
#define Price_D 3000; 
Residency_Profile::Residency_Profile(const string& _Profile_Code, const CDate& _Registration_Date, const string& _id, const string& _Native_lace, const string& _Race, const CDate& _Expiration_Date)
	: Profile_Code(_Profile_Code), Registration_Date(_Registration_Date), ID(_id), Native_lace(_Native_lace), Race(_Race),Expiration_Date(_Expiration_Date)

{

}
Residency_Profile::Residency_Profile()
{

}
Residency_Profile::Residency_Profile(const Residency_Profile& rp)
{
	this->Profile_Code = rp.Profile_Code;
	this->Registration_Date = rp.Registration_Date;
	this->ID = rp.ID;
	this->Native_lace = rp.Native_lace;
	this->Race = rp.Race;
	this->Expiration_Date = rp.Expiration_Date;
}
Residency_Profile::~Residency_Profile()
{

}
string Residency_Profile::Get_Profile_Code()
{
	return this->Profile_Code;
}
void Residency_Profile::Set_Profile_Code(const string& _Profile_Code)
{
	this->Profile_Code = _Profile_Code;
}
CDate Residency_Profile::Get_Registration_Date()
{
	return this->Registration_Date;
}
void Residency_Profile::Set_Registration_Date(const CDate& _Registration_Date)
{
	this->Registration_Date = _Registration_Date;
}
string Residency_Profile::Get_ID()
{
	return  this->ID;
}
void Residency_Profile::Set_ID(const string& _ID)
{

}
string Residency_Profile::Get_Native_lace()
{
	return this->Native_lace;
}
void Residency_Profile::Set_Native_lace(const string& _Native_lace)
{
	this->Native_lace = _Native_lace;
}
string Residency_Profile::Get_Race()
{
	return this->Race;
}
void Residency_Profile::Set_Race(const string& _Race)
{
	this->Race = _Race;
}
CDate Residency_Profile::Get_Expiration_Date()
{
	return this->Expiration_Date;
}
void Residency_Profile::Set_Expiration_Date(const CDate& _Expiration_Date)
{
	this->Expiration_Date = _Expiration_Date;
}
int  Residency_Profile::Pay()
{
	 CDate _time = this->Get_Expiration_Date().Get_time();
	 int day = Expiration_Date -_time;
	 if (_time > this->Expiration_Date) return -day * Price_D;
     return day * Price_D;
}
void Residency_Profile::Extend()
{
	this->Expiration_Date.operator+(6);
}
Node<Student>* Residency_Profile::Get_Student(Management_Student& Data_Student)
{
	Node<Student>* p = Data_Student.Get_List_Student().Get_P_Head();
	while (p != nullptr)
	{
		if (p->Get_Data().Get_Profile_Code() == this->Profile_Code) return p;
		p = p->Get_Next();
	}
	return nullptr;

}