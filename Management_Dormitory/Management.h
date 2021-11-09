#pragma once
#include"Management_Room.h"
#include"Management_Student.h"
class Management
{
private:
	Management_Student  Data_Student;
	Mamagement_Room Data_Room;
public:
	Management();
	~Management();
	/*friend void Menu_chinh(Management&);*/

};

