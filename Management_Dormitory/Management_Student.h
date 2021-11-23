#pragma once
#include"Student.h"
#include"Doubly_Linked_List.h"
#include"Khoi_tao.h"
class Management_Student
{
private:
	Doubly_Linked_List<Student> Database;
	static int N_S;
public:
	Management_Student();
	~Management_Student();
	void Add_Student(const Student&);
	void Delete_Student(Student& _student);
	Doubly_Linked_List<Student> Find_Student(string);
	void Update_Info(Node<Student>* , const Student&);
	Doubly_Linked_List<Student>& Get_List_Student();
	Node<Student> *Index_off(string);
	void Write_File();
	void Read_File();
	void Menu_Student();
	void Menu_update(Student&);
};



