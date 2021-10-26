#include "Student.h"
#include"Date_of_Birth.h"
Student::Student()
{
}

Student::Student(const string &_name, const string &_Phone_number, const string &_Room_Code, const string &_Profile_Code, const int &_Gender, const string &_Student_Code, const string &_Email, const Date_of_Birth &_D_of_b, const string &_Address)
    : name(_name), Phone_number(_Phone_number), Room_Code(_Room_Code), Profile_Code(_Profile_Code), Gender(_Gender), Student_Code(_Student_Code), Email(_Email), Address(_Address)
{
    this->d_of_b.Day = _D_of_b.Day;
    this->d_of_b.Month = _D_of_b.Month;
    this->d_of_b.Year = _D_of_b.Year;
}
// Student::Student(const Student& _Student)
// {

// }
Student::~Student()
{
}
//name
void Student::Set_Name(const string &_name)
{
    this->name = _name;
}
const string &Student::Get_Name()
{
    return this->name;
}
//phone Number
void Student::Set_Phone_number(const string &_Phone_number)
{
    this->Phone_number = _Phone_number;
}
const string &Student::Get_Phone_number()
{
    return this->Phone_number;
}
//profile code
void Student::Set_Profile_Code(const string &_Profile_code)
{
    this->Profile_Code = _Profile_code;
}
const string &Student::Get_Profile_Code()
{
    return this->Profile_Code;
}
// room code
void Student::Set_Room_Code(const string &_Room_code)
{
    this->Room_Code = _Room_code;
}
const string &Student::Get_Room_Code()
{
    return this->Room_Code;
}
//Gender
void Student::Set_Gender(const int &_gender)
{
    this->Gender = _gender;
}
const int &Student::Get_Gender()
{
    return this->Gender;
}
//Email
void Student::Set_Email(const string &_Email)
{
    this->Email = _Email;
}
const string &Student::Get_Email()
{
    return this->Email;
}
//Date_of_Birth
void Student::Set_Date_of_Birth(const Date_of_Birth &_D_of_b)
{
    this->d_of_b.Day = _D_of_b.Day;
    this->d_of_b.Month = _D_of_b.Month;
    this->d_of_b.Year = _D_of_b.Year;
}
const Date_of_Birth& Student::Get_Date_of_Birth()
{
    return this->d_of_b;
}
// Student
/*
void Student::Set_Student_Code(const string& _Student_code)
{
    this->Student_Code = _Student_code;
}
const string &Student::Get_Student_Code()
{
    return this->Student_Code;
} 
*/
//Address
void Student::Set_Address(const string &_Address)
{
    this->Address = _Address;
}
const string &Student::Get_Address()
{
    return this->Address;
}