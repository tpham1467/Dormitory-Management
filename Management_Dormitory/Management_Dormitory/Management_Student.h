#pragma once
#include"Student.h"
#include"Doubly_Linked_List.h"
#include<vector>
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
	vector<Student> Find_Student(string);
	void Update_Info();
	Doubly_Linked_List<Student>& Get_List_Student();
	Node<Student> *Index_off(string);

};



