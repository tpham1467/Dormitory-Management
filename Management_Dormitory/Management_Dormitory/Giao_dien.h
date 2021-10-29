#pragma once
#include<fstream>
using namespace std;
#include<string>
#include<iostream>
#include"console.h"
#include"Khoi_tao.h"
#include"Management_Student.h"
#include"Menu_Student.h"
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<vector>

void Menu_Student( Management_Student& Database);
void Menu_Room();
void Menu_Profile();
void Menu_Card();
void Menu_chinh( Management_Student& Database);

void Menu_Student( Management_Student& Database)
{
	while (1)
	{
		Hien_thi_danh_sach(arr_Student, 4);
		int a = bat_su_kien(arr_Student, 4);
		switch (a)
		{
		case 0:
		{
			Xoa_o(4, 14, 39, 35, 0);
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
			Xoa_o(48, 10, 170, 36, 0);
			Xoa_o(4, 14, 39, 35, 0);
			Menu_Delete_Student(Database);
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

