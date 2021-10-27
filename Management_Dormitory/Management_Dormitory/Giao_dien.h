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

		break; }

	}
	

}

