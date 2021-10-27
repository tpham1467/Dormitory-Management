#pragma once
#include<fstream>
using namespace std;
#include<string>
#include<iostream>
#include"console.h"
void Introduction()
{
	ifstream input;
	input.open("introduction.txt", ios::in);
	int line = 0;
	while (!input.eof())
	{
		
		string data;
		getline(input, data);
		Outstring(60, line++, 11, 0, data);

	}
}
void Xoa_o(int x,int y,int x2,int y2)
{
	for (int i = x; i <= x2; i++)
	{
		for (int j = y; j <= y2; j++)
		{
			Outchar(i, j, 0, 0, ' ');
		}
	}
}
void Khoi_tao()
{
	/*SetWindowSize(210, 60);
	SetScreenBufferSize(200, 50);*/
	DisableResizeWindow();
}
void danh_sach_Menu_chinh()
{
	Outstring(15, 16, 11, 0, "Quan Li Sinh Vien");
	Outstring(17, 19, 11, 0, "Quan Li Phong");
	Outstring(17, 22, 11, 0, "Quan Li Ho So");
	Outstring(14, 25, 11, 0, "Quan Li The Ra Vao");
	Outstring(19, 28, 11, 0, "Thong Ke");
}
void huong_dan()
{
	for (int i = 0; i < 45; i++)
	{
		for(int j=0;j<3;j++)
		Outchar(i, j, 11, 0, (char)219);
	}
	Outstring(15,1 , 0,11, "Huong Dan");
	Outstring(3, 3, 11, 0, "Mui Ten Len Xuong :De Dieu Khien");
	Outstring(3, 4, 11, 0, "Nut Enter         :De Chon");
	Outstring(3, 5, 11, 0, "Nut Esc           :De Tro Lai");
}
void khung_chon()
{
	for (int i = 3; i < 42; i++)
	{
		Outchar(i, 12, 11, 0, (char)219);
	}
	for (int i = 3; i < 42; i++)
	{
		Outchar(i, 36, 11, 0, (char)219);
	}
	for (int i = 12; i < 36; i++)
	{
		Outchar(3, i, 11, 0, (char)219);
	}
	for (int i = 12; i < 36; i++)
	{
		Outchar(41, i, 11, 0, (char)219);
	}
	Outstring(21, 13, 5, 0, "Menu");
}
void khung()
{
	for (int i = 0; i <175 ; i++)
	{
		Outchar(i, 38, 15, 0, (char)219);
	}
	for (int i = 0; i < 39; i++)
	{
		Outchar(45, i, 15, 0, (char)219);
	}
	for (int i = 0; i <45; i++)
	{
		Outchar(i,10, 15, 0, (char)219);
	}
	for (int i = 46; i < 175; i++)
	{
		Outchar(i, 7, 15, 0, (char)254);
	}
}
int chon(int a[])
{
	
}
void Menu_chinh()
{
	Khoi_tao();
	Introduction();
	khung();
	khung_chon();
	huong_dan();
	danh_sach_Menu_chinh();
	//Xoa_o(4,13,40,35); xoa danh scah menu
	Cursor(false);

}

