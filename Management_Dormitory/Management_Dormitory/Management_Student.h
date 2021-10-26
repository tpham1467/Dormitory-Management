#pragma once
#include"Student.h"
#include"Doubly_Linked_List.h"
class Management_Student
{
private:
	Doubly_Linked_List<Student> Database;
	static int N_S;
public:
	Management_Student();
	~Management_Student();
};



