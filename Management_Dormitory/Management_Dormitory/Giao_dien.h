#pragma once
#include<fstream>
using namespace std;
#include<string>
#include<iostream>
#include"console.h"
#include"Khoi_tao.h"
#include<windows.h>
#include<conio.h>
void Menu_Student();
void Menu_Room();
void Menu_Profile();
void Menu_Card();
void Menu_chinh();

void Menu_Student()
{
	Hien_thi_danh_sach(arr_Student, 4);
	int a = bat_su_kien(arr_Student, 4);
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
	default:
	{
		Xoa_o(4, 14, 39, 35);
		Menu_chinh();
		break; }

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
		Menu_chinh();
		break; }

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
		Menu_chinh();
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
		Menu_chinh();
		break; }

	}
}
void Menu_chinh()
{
	Khoi_tao();
	Hien_thi_danh_sach(arr_1, 4);
	int a=bat_su_kien(arr_1,4);
	switch (a)
	{
	case 0:
	{
		Xoa_o(4, 14, 39, 35);
		Menu_Student();
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
	default:
	{

		break; }

	}
	

}

