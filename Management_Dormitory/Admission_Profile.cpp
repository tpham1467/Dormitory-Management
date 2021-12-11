#include "Admission_Profile.h"
Admission_Profile::Admission_Profile(const string& _Profile_Code, const CDate& _Registration_Date, const string& _id, const string& _Native_lace, const string& _Race, const CDate& _Expiration_Date,Doubly_Linked_List<string> _TTBS,bool _Confirmation_Status)
:Residency_Profile(_Profile_Code, _Registration_Date, _id, _Native_lace, _Race, _Expiration_Date),TTBS(_TTBS),Confirmation_Status(_Confirmation_Status)
{

}
Admission_Profile::Admission_Profile()
{
}
Admission_Profile::Admission_Profile(const Admission_Profile& ap)
{
	this->Profile_Code = ap.Profile_Code;
	this->Registration_Date = ap.Registration_Date;
	this->ID = ap.ID;
	this->Native_lace = ap.Native_lace;
	this->Race = ap.Race;
	this->Expiration_Date = ap.Expiration_Date;
	this->TTBS = ap.TTBS;
	this->Confirmation_Status = ap.Confirmation_Status;
}
Admission_Profile::~Admission_Profile()
{
	this->TTBS.~Doubly_Linked_List();
}
void Admission_Profile::Add_Infor(Node<string>* p)
{
	this->TTBS.Delete_indexoff(p);
}
Doubly_Linked_List<string>& Admission_Profile::Get_TTBS()
{
	return this->TTBS;
}
void Admission_Profile::Set_Confirmation_Status(bool cf)
{
	this->Confirmation_Status = cf;
}
bool Admission_Profile::Get_Confirmation_Status()
{
	return this->Confirmation_Status;
}
Admission_Profile& Admission_Profile::operator=(const Admission_Profile& ap)
{
	this->Profile_Code = ap.Profile_Code;
	this->Registration_Date = ap.Registration_Date;
	this->ID = ap.ID;
	this->Native_lace = ap.Native_lace;
	this->Race = ap.Race;
	this->Expiration_Date = ap.Expiration_Date;
	this->TTBS = ap.TTBS;
	this->Confirmation_Status = ap.Confirmation_Status;
	return *this;
}