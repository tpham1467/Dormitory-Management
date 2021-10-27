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
	void Add_Student(const Student&);
	void Delete_Student(const Student&);
	const Student& Find_Student(const Student&);
	void Update_Info();
	void Get_List_Student();
	Node<Student> *Index_off(string);

};



