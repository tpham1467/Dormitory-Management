#pragma once
#include"Admission_Profile.h"
#include"Management_Student.h"
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
	void Extend(string);
	Doubly_Linked_List< Admission_Profile> Find_Admission_Profile(string, Management_Student);
	Doubly_Linked_List< Residency_Profile> Find_Residency_Profile(string, Management_Student);
	int  Pay(string);
	void Confirm(string);
	void Update_Admission_Profile(string);
	void Update_Residency_Profile(string);
	Node<Residency_Profile>* Indexoff(string,int);
	Node<Admission_Profile>* Indexoff(string);
	void Delete_RP(string);
	void Delete_AP(string);
	void Set_Room(string);
	//
	void Menu(Management_Student);
	void Read_File();
	void Write_File();
	//RP
	void Menu_RP(Management_Student);
	// AP
	void Menu_AP();
	// graphisc
	void Draw_a_Page_RP(int, Doubly_Linked_List<Residency_Profile>, int);
	int Move_Page_RP(Doubly_Linked_List<Residency_Profile>, bool&, bool&);
	void Draw_Object_RP(Doubly_Linked_List<Residency_Profile>&, int, int, int);
	void Draw_Info_Object_RP(Management_Profile&);

	//
	void Draw_a_Page_AP(int, Doubly_Linked_List<Residency_Profile>, int);
	int Move_Page_AP(Doubly_Linked_List<Residency_Profile>, bool&, bool&);
	void Draw_Object_AP(Doubly_Linked_List<Residency_Profile>&, int, int, int);
	void Draw_Info_Object_AP(Management_Profile&);


};

