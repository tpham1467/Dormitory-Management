#pragma once
#include"Management_Room.h"
#include"Management_Student.h"
#include"Management_Profile.h"
#include"Thong_Ke.h"
class Management
{
private:
	Management_Student  Data_Student;
	Mamagement_Room Data_Room;
	Management_Profile Data_Profile;
	Thong_Ke tk;
public:
	Management();
	~Management();
	void Menu_chinh();

};

