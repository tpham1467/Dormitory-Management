#include "Management.h"
Management::Management()
{	
	this->Data_Room.Read_File();
	this->Data_Student.Read_File();
}
Management::~Management()
{
	this->Data_Room.~Mamagement_Room();
	this->Data_Student.Write_File();
	this->Data_Student.~Management_Student();
}