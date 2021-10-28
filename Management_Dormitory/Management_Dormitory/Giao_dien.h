#pragma once
#include<fstream>
using namespace std;
#include<string>
#include<iostream>
#include"console.h"
#include"Khoi_tao.h"
#include"Management_Student.h"
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<vector>

void Menu_Student( Management_Student& Database);
void Menu_Room();
void Menu_Profile();
void Menu_Card();
void Menu_chinh( Management_Student& Database);
void Menu_find_Student( Management_Student& Database);
void Menu_find_Studen_silde( Management_Student& Database,int n,int flag=false);

void Menu_find_Studen_silde(Management_Student& Database, int n, int flag)
{
	if (n == 0) {

		Hcn(50, 20, 100, 22);
		Hcn(103, 20, 113, 22);
		Outstring(103, 21, 0, 103, "Tim Kiem");
		setBackgroundColor(0);
		setColor(15);
		gotoXY(52, 21);

		if (flag == true)
		{
			Cursor(true);
			string data;
			getline(cin, data);
			Cursor(false);
			vector<Student> _data_find =Database.Find_Student(data);
			cout << _data_find.size();
			if (_data_find.size() == 0)
			{
				cout << "khong ci";
			}
			else if (_data_find.size() >= 10)
				Ve_luoi_nhieu(_data_find);
			else {

				Xoa_o(48, 10, 170, 36, 0);
				Ve_luoi(_data_find.size() , 6, _data_find, 0);
				_getch();
			}
			
		}
	}
	else
	{
		if (flag == false)
		{

			vector<Student> list_kt;
			Node<Student>* p = Database.Get_List_Student().Get_P_Head();
			for (; p!=nullptr;)
			{
				list_kt.push_back(p->Get_Data());
				p = p->Get_Next();
			}
			if(list_kt.size()<10)
			Ve_luoi(list_kt.size()-1, 6, list_kt,0);
			else 
				Ve_luoi(10, 6, list_kt, 0);
		}
		else
		{
			vector<Student> list_kt;
			Node<Student>* p = Database.Get_List_Student().Get_P_Head();
			for (; p!=nullptr; )
			{
				list_kt.push_back(p->Get_Data());
				p = p->Get_Next();
			}
			Ve_luoi_nhieu(list_kt);
		}
	}
}
void Menu_find_Student( Management_Student& Database)
{
		Hien_thi_danh_sach(arr_find, 1);
		int i=0;
		char key;
		int n = 1;
		Outstring(arr_find[i].first.first - 2, arr_find[i].first.second, 2, 0, ">>");
		Outstring(arr_find[i].first.first, arr_find[i].first.second, 2, 0, arr_find[i].second);
		Menu_find_Studen_silde(Database, 0);
		while (true)
		{
			key = _getch();
			Outstring(arr_find[i].first.first - 2, arr_find[i].first.second, 2, 0, "  ");
			Outstring(arr_find[i].first.first, arr_find[i].first.second, 11, 0, arr_find[i].second);
			if (key == 72)
			{
				if (i == 0) i = n;
				else i--;
			}
			else if (key == 80)
			{
				if (i == n) i = 0;
				else i++;

			}
			else if (key == 13)
			{
				Menu_find_Studen_silde(Database, i,true);
			}
			else if (key == 27)
			{
				Xoa_o(4, 14, 39, 35, 0);
				Xoa_o(48, 10, 170, 36, 0);
				Menu_Student(Database);
				break;
			}
			Xoa_o(48, 10, 170, 36, 0);
			Outstring(arr_find[i].first.first - 2, arr_find[i].first.second, 2, 0, ">>");
			Outstring(arr_find[i].first.first, arr_find[i].first.second, 2, 0, arr_find[i].second);
			Menu_find_Studen_silde(Database, i);
		}
		Xoa_o(48, 10, 170, 36, 0);
		
	
}
void Menu_Student( Management_Student& Database)
{
	Hien_thi_danh_sach(arr_Student, 4);
	int a = bat_su_kien(arr_Student, 4);
	switch (a)
	{
	case 0:
	{
		Xoa_o(4, 14, 39, 35,0);
		break;
	}
	case 1:
	{
		Xoa_o(48, 10, 170, 36, 0);
		Xoa_o(4, 14, 39, 35, 0);
		Menu_find_Student(Database);
		break;
	}
	case 2:
	{
		
		break;
	}
	case 3:
	{
		
		break;
	}
	case 4:
	{
	
		break;
	}
	default:
	{
		Xoa_o(4, 14, 39, 35);
		Menu_chinh(Database);
		break; }

	}
	Xoa_o(4, 14, 39, 35, 0);
}
void Menu_Room()
{
	Hien_thi_danh_sach(arr_Room, 3);
	int a = bat_su_kien(arr_Room, 3);
	switch (a)
	{
	case 0:
	{
		Xoa_o(4, 14, 39, 35);
		//Menu_Student();
		break;
	}
	case 1:
	{
		//Menu_Room();
		break;
	}
	case 2:
	{
		//Menu_Profile();
		break;
	}
	case 3:
	{
		//Menu_Card();
		break;
	}
	default:
	{
		Xoa_o(4, 14, 39, 35);
		//Menu_chinh();
		break;
	}

	}
}
void Menu_Profile()
{
	Hien_thi_danh_sach(arr_Profile, 5);
	int a = bat_su_kien(arr_Profile, 5);
	switch (a)
	{
	case 0:
	{
		Xoa_o(4, 14, 39, 35);
		//Menu_Student();
		break;
	}
	case 1:
	{
		//Menu_Room();
		break;
	}
	case 2:
	{
		//Menu_Profile();
		break;
	}
	case 3:
	{
		//Menu_Card();
		break;
	}
	case 4:
	{
		//Menu_Tk();
		break;
	}
	case 5:
	{
		break;
	}
	default:
	{
		Xoa_o(4, 14, 39, 35);
		//Menu_chinh();*/
		break; }

	}
}
void Menu_Card()
{
	Hien_thi_danh_sach(arr_Card, 3);
	int a = bat_su_kien(arr_Card, 3);
	switch (a)
	{
	case 0:
	{
		Xoa_o(4, 14, 39, 35);
		//Menu_Student();
		break;
	}
	case 1:
	{
		//Menu_Room();
		break;
	}
	case 2:
	{
		//Menu_Profile();
		break;
	}
	case 3:
	{
		//Menu_Card();
		break;
	}
	default:
	{
		Xoa_o(4, 14, 39, 35);
		//Menu_chinh();*/
		break; }

	}
}
void Menu_chinh( Management_Student& Database)
{
	Khoi_tao();
	Cursor(false);
	while (1)
	{

		Hien_thi_danh_sach(arr_1, 5);
		int a = bat_su_kien(arr_1, 5);
		switch (a)
		{
		case 0:
		{
			Xoa_o(4, 14, 39, 35);
		/*	Xoa_o(48, 10, 170, 36, 14);
			Line(48, 20, 170, 20,14,false);
			Line(100, 10, 100,36 , 14);
			Confict_line(48, 20, 170,20, 100, 10, 100, 36, 14);*/
			Menu_Student(Database);
			break;
		}
		case 1:
		{
			Xoa_o(4, 14, 39, 35);
			Menu_Room();
			break;
		}
		case 2:
		{
			Xoa_o(4, 14, 39, 35);
			Menu_Profile();
			break;
		}
		case 3:
		{
			Xoa_o(4, 14, 39, 35);
			Menu_Card();
			break;
		}
		case 4:
		{
			//Menu_Tk();
			break;
		}
		case 5:
		{
			Xoa_o(0, 0, 175, 40);
			exit(0);
		}
		default:
		{

			break; 
		}

		}
	}
}

