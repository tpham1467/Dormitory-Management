#pragma once
#include"Admission_Profile.h"
#include"Management_Student.h"
#include"Management_Room.h"
class Management_Profile
{
private:
	Doubly_Linked_List<Admission_Profile> Data_AP;
	Doubly_Linked_List<Residency_Profile> Data_RP;
public:
	Management_Profile();
	~Management_Profile();
	Doubly_Linked_List<Admission_Profile>& Get_Data_AP();
	Doubly_Linked_List<Residency_Profile>& Get_Data_RP();
	void Add_Admission_Profile(const Admission_Profile&);
	void Add_Residency_Profile(const Residency_Profile&);
	void Extend(string,int);
	Doubly_Linked_List< Admission_Profile> Find_Admission_Profile(string, Management_Student&);
	Doubly_Linked_List< Residency_Profile> Find_Residency_Profile(string, Management_Student&);
	int  Pay(string, Management_Student&);
	void Update_Admission_Profile(string, const  Admission_Profile&);
	void Update_Residency_Profile(string, const  Residency_Profile&);
	Node<Residency_Profile>* Indexoff(string,int);
	Node<Admission_Profile>* Indexoff(string);
	void Delete_RP(string, Management_Student&, Mamagement_Room&);
	void Delete_AP(string);
	void Set_Room(Management_Student& , Mamagement_Room& );
	void Menu(Management_Student&, Mamagement_Room&);
	void Read_File();
	void Write_File();
	//RP
	void Menu_RP(Management_Student&, Mamagement_Room&);
	void Draw_a_Page_RP(int, Doubly_Linked_List<Residency_Profile>, int, Management_Student&);
	int Move_Page_RP(Doubly_Linked_List<Residency_Profile>, bool&, bool&,Management_Student&);
	void Draw_Object_RP(Residency_Profile, int, int, int, Management_Student&);
	void Draw_Info_Object_RP(Management_Student&);
	void Update_RP(Management_Student&, Mamagement_Room&);
	void Doi_Mau(int , int , Management_Student&);
	void Update_Info(int, Management_Student&, Mamagement_Room&);
	//AP
	void Menu_AP(Management_Student&, Mamagement_Room&);
	int Move_Page_AP(Doubly_Linked_List<Admission_Profile>, bool&, bool&, Management_Student&);
	void Draw_Info_Object_AP();
	void Update_AP(Management_Student&, Mamagement_Room&);
	void Doi_Mau_AP(int, int, Management_Student&);
	void Update_Info_AP(int, Management_Student&, Mamagement_Room&);
	//
	void Add_Profile(Management_Student& );
	void Export_File_Excel(bool);
};

