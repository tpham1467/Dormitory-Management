#pragma once
#include"../Profile_Management/Management_Profile.h"
#include"../Room_Management/Management_Room.h"
#include"../Student_Management/Management_Student.h"
#include"../Thong_Ke/Thong_Ke.h"
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

