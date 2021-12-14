#pragma once
#include"Student.h"
#include"Doubly_Linked_List.h"
#include"Khoi_tao.h"
class Management_Student
{
private:
	Doubly_Linked_List<Student> Database;
public:
	Management_Student();
	~Management_Student();
	void Add_Student(const Student&);
	void Delete_Student(Student& _student);
	Doubly_Linked_List<Student> Find_Student(string);
	void Update_DataBase(Node<Student>*);
	Doubly_Linked_List<Student>& Get_List_Student();
	Node<Student> *Index_off(string);
	Node<Student>* Move_Room();
	void Write_File();
	void Read_File();
	void Export_File_Excel();
	void Menu_Student(bool=true);
	void Draw_a_Page(int , int , Doubly_Linked_List<Student>&, int);
	int Move_Page(Doubly_Linked_List<Student>& , bool& , bool&);
	void Draw_Object(Doubly_Linked_List<Student>&, int, int, int);
	void Draw_Info_Object();
	void Update();
	void Updata_Info(int);
	void Doi_Mau(int,int);
	void SelectionSort(Node<Student>* ,bool Compfunc(Student, Student));
	void Sort(Node<Student>*);
};



