#pragma once
#include"Management_Room.h"
#include"Management_Student.h"
#include"Management_Profile.h"
class Management
{
private:
	Management_Student  Data_Student;
	Mamagement_Room Data_Room;
	Management_Profile Data_Profile;
public:
	Management();
	~Management();
	void Menu_chinh();

};

