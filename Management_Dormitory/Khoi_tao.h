#pragma once
#include<fstream>
using namespace std;
#include<string>
#include<iostream>
#include"console.h"
#include<windows.h>
#include<conio.h>
#include"Giao_dien.h"
#include"Management_Student.h"
#include<vector>
typedef pair<int, int > ii;
typedef pair<ii, string > list;
list arr_1[6];
list arr_Student[5];
list arr_Room[4];
list arr_Profile[6];
list arr_Card[5];
list arr_find[2];

int bat_su_kien(list arr[], int n);
void Introduction();
void Xoa_o(int x, int y, int x2, int y2,int color=0);
void Hien_thi_danh_sach(list arr[], int n);
void huong_dan();
void khung_chon();
void khung();
void Hcn(int x, int y, int x1, int y1,int color=0);
void Line(int x, int y, int x1, int y1, int color=15, bool thang=true);
void Confict_line(int x, int y, int x1, int y1, int _x, int _y, int _x1, int _y1, int color);
void Ve_mot_trang(int y, int color, vector<Student> Database, int j);
void Ve_nhieu_trang(vector<Student> Database);
int Ve_nhieu_trang_chon(vector<Student> Database);
void To_mau_mot_doi_tuong(vector<Student> Database, int index, int color,int i);
void Not_Found();
//vector<string> update();

void Khoi_tao_cac_danh_sach()
{
	arr_1[0].first.first = 15; arr_1[0].first.second = 16; arr_1[0].second = "Quan Li Sinh Vien";
	arr_1[1].first.first = 17; arr_1[1].first.second = 19; arr_1[1].second = "Quan Li Phong";
	arr_1[2].first.first = 17; arr_1[2].first.second = 22; arr_1[2].second = "Quan Li Ho So";
	arr_1[3].first.first = 14; arr_1[3].first.second = 25; arr_1[3].second = "Quan Li The Ra Vao";
	arr_1[4].first.first = 19; arr_1[4].first.second = 28; arr_1[4].second = "Thong Ke";
	arr_1[5].first.first = 21; arr_1[5].first.second = 31; arr_1[5].second = "Thoat";
	//arr_Student
	arr_Student[0].first.first = 16; arr_Student[0].first.second = 16; arr_Student[0].second = "Them Sinh Vien";
	arr_Student[1].first.first = 14; arr_Student[1].first.second = 19; arr_Student[1].second = "Tim Kiem Sinh Vien";
	arr_Student[2].first.first = 17; arr_Student[2].first.second = 22; arr_Student[2].second = "Xoa Sinh Vien";
	arr_Student[3].first.first = 9; arr_Student[3].first.second = 25; arr_Student[3].second = "Cap nhap thong Tin Sinh Vien";
	arr_Student[4].first.first = 14; arr_Student[4].first.second = 28; arr_Student[4].second = "Hien Thi Danh Sach";
	//Room
	arr_Room[0].first.first = 11; arr_Room[0].first.second = 16; arr_Room[0].second = "Hien Thi Thong Tin Phong";
	arr_Room[1].first.first = 11; arr_Room[1].first.second = 19; arr_Room[1].second = "Thanh Toan Tien Dien Nuoc";
	arr_Room[2].first.first = 16; arr_Room[2].first.second = 22; arr_Room[2].second = "Tim Kiem Phong";
	arr_Room[3].first.first = 15; arr_Room[3].first.second = 25; arr_Room[3].second = "Xac Nhan Sua Chua";
	//Profile
	arr_Profile[0].first.first = 12; arr_Profile[0].first.second = 16; arr_Profile[0].second = "Hien Thi Thong Tin Ho So";
	arr_Profile[1].first.first = 16; arr_Profile[1].first.second = 19; arr_Profile[1].second = "Tim Kiem Ho So";
	arr_Profile[2].first.first = 19; arr_Profile[2].first.second = 22; arr_Profile[2].second = "Xoa Ho So";
	arr_Profile[3].first.first = 16; arr_Profile[3].first.second = 25; arr_Profile[3].second = "Phe Duyet Ho So";
	arr_Profile[4].first.first = 20; arr_Profile[4].first.second = 28; arr_Profile[4].second = "Gia Han";
	arr_Profile[5].first.first = 14; arr_Profile[5].first.second = 31; arr_Profile[5].second = "Chinh Sua Thong Tin";
	//Card
	arr_Card[0].first.first = 9; arr_Card[0].first.second = 16; arr_Card[0].second = "Hien Thi Thong Tin The Ra Vao";
	arr_Card[1].first.first = 14; arr_Card[1].first.second = 19; arr_Card[1].second = "Tim Kiem The Ra Vao";
	arr_Card[2].first.first = 16; arr_Card[2].first.second = 22; arr_Card[2].second = "Xoa The Ra Vao";
	arr_Card[3].first.first = 9; arr_Card[3].first.second = 25; arr_Card[3].second = "Chinh Sua Thong Tin The Ra Vao";
	// Find
	arr_find[0].first.first = 6; arr_find[0].first.second = 16; arr_find[0].second = "Tim Kiem Bang Canh Nhap Thong Tin";
	arr_find[1].first.first = 11; arr_find[1].first.second = 19; arr_find[1].second = "Tim Kiem Trong Danh Sach";
}

int bat_su_kien(list arr[], int n)
{
	int i = 0;
	char key;
	Outstring(arr[i].first.first - 2, arr[i].first.second, 2, 0, ">>");
	Outstring(arr[i].first.first, arr[i].first.second, 2, 0, arr[i].second);
	while (true)
	{
		key = _getch();
		Outstring(arr[i].first.first - 2, arr[i].first.second, 2, 0, "  ");
		Outstring(arr[i].first.first, arr[i].first.second, 11, 0, arr[i].second);
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
			break;
		}
		else if (key == 27)
		{
			return (int)key;
		}
		Outstring(arr[i].first.first - 2, arr[i].first.second, 2, 0, ">>");
		Outstring(arr[i].first.first, arr[i].first.second, 2, 0, arr[i].second);
	}
	return i;
}
void Introduction()
{
	ifstream input;
	input.open("introduction.txt", ios::in);
	int line = 0;
	while (!input.eof())
	{

		string data;
		getline(input, data);
		Outstring(70, line++, 11, 0, data);

	}
	/*for (int i = 0; i < 45; i++)
	{
		Outchar(i, 6, 11, 0, char(254));
	}
	Outstring(4,7,11, 0, "Sinh Vien 1: Pham Van Tien Truong");
	Outstring(4,8, 11, 0, "Sinh Vien 1: Pham Cong Huy");*/
}
void Xoa_o(int x, int y, int x2, int y2,int color)
{
	string _string;
	for (int i = x; i <= x2; i++)
		_string.push_back(' ');
	for (int i = y; i <= y2; i++)
	{
		Outstring(x, i, color, color,_string);
	}
}
void Khoi_tao()
{
	/*SetWindowSize(210, 60);
	SetScreenBufferSize(200, 50);*/
	DisableResizeWindow();
	Khoi_tao_cac_danh_sach();
	Cursor(true);
	Introduction();
	khung();
	khung_chon();
	huong_dan();
}
void Hien_thi_danh_sach(list arr[], int n)
{
	for (int i = 0; i <= n; i++)
	{
		Outstring(arr[i].first.first, arr[i].first.second, 11, 0, arr[i].second);
	}
}
void huong_dan()
{
	for (int i = 0; i < 45; i++)
	{
		for (int j = 0; j < 3; j++)
			Outchar(i, j, 11, 0, (char)219);
	}
	Outstring(15, 1, 0, 11, "Huong Dan");
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
	for (int i = 0; i < 175; i++)
	{
		Outchar(i, 38, 15, 0, (char)219);
	}
	for (int i = 0; i < 39; i++)
	{
		Outchar(45, i, 15, 0, (char)219);
	}
	for (int i = 0; i < 45; i++)
	{
		Outchar(i, 10, 15, 0, (char)219);
	}
	for (int i = 46; i < 175; i++)
	{
		Outchar(i, 7, 15, 0, (char)254);
	}
}
void Hcn(int x, int y, int x1, int y1,int color)
{
	for (int i = x; i <= x1; i++)
	{
		Outchar(i, y, 14, color, (char)196);
		Outchar(i, y1, 14, color, (char)196);
	}
	for (int i = y; i <= y1; i++)
	{
		Outchar(x-1, i, 14, color, (char)179);
		Outchar(x1+1, i, 14, color, (char)179);
	}
	gotoXY(x-1, y); cout << char(218);
	gotoXY(x1+1, y); cout << char(191);
	gotoXY(x-1, y1); cout << char(192);
	gotoXY(x1+1,y1); cout << char(217);
	//Xoa_o(x , y , x1 , y1 ,2);
}
void Line(int x, int y, int x1, int y1, int color,bool thang)
{
	if (thang == true)
	{
		for (int i = y; i <= y1; i++)
		
		Outchar(x1, i, 0, color, (char)179);
	}
	else
	{
		for (int i = x; i <= x1; i++)

			Outchar(i, y1, 0, color, (char)196);
	}
}

void Confict_line(int x, int y, int x1, int y1, int _x, int _y, int _x1, int _y1 ,int color)
{
	float a = (float)((-y1 + y) / (x - x1));
	float b = (float)(y1 - a * x1);
	for (int i = _y; i <= _y1; i++)
	{
		if (a * _x + b - i == 0)
		{
			Outchar(_x, i, 0, color, (char)197);
			break;
		}
	}
}
// ve danh 1 trang
void Ve_mot_trang(int y, int color, vector<Student> Database, int j)
{
	if (j == -1) {


		Xoa_o(48, 10, 170, 12, 15);
		Xoa_o(48, 13, 170, 13 + 1, 6);
		Outstring(50, 11, 0, 15, "Ma Sinh Vien");
		Outstring(84, 11, 0, 15, "Ho Va Ten");
		Outstring(112, 11, 0, 15, "Gioi Tinh");
		Outstring(140, 11, 0, 15, "Dia Chi");
		Line(68, 13, 68, 13 + 1, 6);
		Line(68, 10, 68, 12, 15);
		Line(108, 13, 108, 13 +  1, 6);
		Line(108, 10, 108, 12, 15);
		Line(125, 13, 125, 13 + 1, 6);
		Line(125, 10, 125, 12, 15);
		return;
	}
	else
	{
		Xoa_o(48, 10, 170, 12, 15);
		Xoa_o(48, 13, 170, 13 + 2 * y, 6);
		Outstring(50, 11, 0, 15, "Ma Sinh Vien");
		Outstring(84, 11, 0, 15, "Ho Va Ten");
		Outstring(112, 11, 0, 15, "Gioi Tinh");
		Outstring(140, 11, 0, 15, "Dia Chi");
	}
	int i;

	for (i = 15; i < 13+2*y; i += 2)
	{
		Outstring(51, i-1, 0, 6,Database[j].Get_Student_Code());
		Outstring(72, i - 1, 0, 6, Database[j].Get_Name());
		Outstring(111, i - 1, 0, 6, (Database[j].Get_Gender()==1)?"Nam":"Nu");
		Outstring(128, i - 1, 0, 6, Database[j].Get_Address());
		Line(48, i, 170, i, 6, false);
		j++;
	}
	Outstring(51, i - 1, 0, 6, Database[j].Get_Student_Code());
	Outstring(72, i - 1, 0, 6, Database[j].Get_Name());
	Outstring(111, i - 1, 0, 6, (Database[j].Get_Gender() == 1) ? "Nam" : "Nu");
	Outstring(128, i - 1, 0, 6, Database[j].Get_Address());

	Line(68, 13, 68, 13 + 2 * y,6);
	Line(68, 10, 68, 12, 15);
	Line(108, 13, 108, 13+2*y, 6);
	Line(108, 10, 108, 12, 15);
	Line(125, 13, 125, 13 + 2 * y, 6);
	Line(125, 10, 125, 12, 15);
	for (int i = 15; i < 13 + 2 * y; i += 2)
	{
		
		Confict_line(48, i, 170, i, 68, 13, 68, 13 + 2 * y, 6);
		Confict_line(48, i, 170, i, 125, 13, 125, 13 + 2 * y, 6);
		Confict_line(48, i, 170, i, 108, 13, 108, 13 + 2 * y, 6);
	
	}
	
}
// ve danh nhieu trang
void Ve_nhieu_trang(vector<Student> Database)
{
	int lenght =Database.size();
	int so_lan =(int)(lenght / 10)+1;
	int i = 0,j=1; int z = 0;
	Xoa_o(48, 10, 170, 35, 0);
	bool Firt = false;
	if (so_lan==1)
	{
		Ve_mot_trang(lenght , 6, Database, 0);
		Firt = true;
	}
	else
	{
		Ve_mot_trang(10, 6, Database, 0);
		Outstring(101, 13 + 2 * 10 + 1, 2, 0, "<<");
		Outint(103, 13 + 2 * 10 + 1, 1, 0, j);
		Outstring(104, 13 + 2 * 10 + 1, 2, 0, ">>");
		//gotoXY(114, 13 + 2 * 10 + 2);
		//cout << lenght << " " << so_lan << " " << lenght - (so_lan - 1) * 10;
		Firt = true;
	}
	while (1)
	{
		char key = _getch();
		switch (key)
		{
		case 77:
		{	
			if (j==so_lan) break;
			else {
				i += 10;
				j++;
			}
			break;
		}
		case 75:
		{
			if (i == 0) break;
			else
			{
				i -= 10;
				j--;
			}
			break;
		}
		case 27:
			return;
			break;
		}
		if (Firt == true)
		{
			Xoa_o(48, 10, 170, 35, 0);
			if (j ==so_lan||lenght<10)
			{
				if (lenght < 10)
				{
					Ve_mot_trang(lenght, 6, Database, i);
					z = lenght;
				}
				else
				{
					if (lenght - (so_lan - 1) * 10 == 0)
					{
						z = 1;
						Ve_mot_trang(lenght - (so_lan - 1) * 10, 6, Database, -1);
					}
					else
					{
						Ve_mot_trang(lenght - (so_lan - 1) * 10, 6, Database, i);
						z = lenght - (so_lan - 1) * 10;
					}
				}
		
			}
			else
			{
				Ve_mot_trang(10, 6, Database, i );
				z = 10;
			}
			Outstring(101, 13 + 2 * z + 1, 2, 0, "<<");
			Outint(103, 13 + 2 * z + 1, 1, 0, j);
			Outstring((j > 9) ? 105 : 104, 13 + 2 * z + 1, 2, 0, ">>");
		}
	}
}
void To_mau_mot_doi_tuong(vector<Student> Database, int index,int color,int i)
{
	
		
		Outstring(51, (index-i)* 2 + 14, color, 6, Database[index].Get_Student_Code());
		Outstring(72, (index-i) * 2 + 14, color, 6, Database[index].Get_Name());
		Outstring(111, (index-i) * 2 + 14, color, 6, (Database[index].Get_Gender() == 1) ? "Nam" : "Nu");
		Outstring(128, (index-i) * 2 + 14, color, 6, Database[index].Get_Address());
	
}
int Ve_nhieu_trang_chon(vector<Student> Database)
{
	int lenght = Database.size();
	int so_lan = (int)(lenght / 10) + 1;
	int i = 0, j = 1; int z = 0; ; int dem = 0; bool check = false;
	Xoa_o(48, 10, 170, 35, 0);
	bool Firt = false;
	if (so_lan == 1)
	{
		Ve_mot_trang(lenght, 6, Database, 0);
		To_mau_mot_doi_tuong(Database, 0, 4, i);
		Firt = true;
	}
	else
	{
		Ve_mot_trang(10, 6, Database, 0);
		Outstring(101, 13 + 2 * 10 + 1, 2, 0, "<<");
		Outint(103, 13 + 2 * 10 + 1, 1, 0, j);
		Outstring(104, 13 + 2 * 10 + 1, 2, 0, ">>");
		To_mau_mot_doi_tuong(Database, 0, 4, i);
		Firt = true;
	}
	while (1)
	{
		char key = _getch();
		switch (key)
		{
		case 77:
		{
			if (j == so_lan) i = i;
			else {
				i += 10;
				j++;
				dem = i;
				check = true;
			}
			break;
		}
		case 75:
		{
			if (i == 0) break;
			else
			{
				i -= 10;
				j--;
				dem = i;
				check = true;
			}
			break;
		}
		case 72:
		{
			if (dem == i) break;
			else {
				To_mau_mot_doi_tuong(Database, dem, 0, i);
				dem += -1;
				check = false;
				To_mau_mot_doi_tuong(Database, dem, 4, i);
			}
			break;
		}
		case 80:
		{
			if (dem == i + 9 || dem == lenght - 1) break;
			else
			{
				To_mau_mot_doi_tuong(Database, dem, 0, i);
				dem += 1;
				To_mau_mot_doi_tuong(Database, dem, 4, i);
				check = false;
			}

			break;
		}
		case 13:
		{

			return dem;
			break;
		}
		case 27:
		{
			return -1;
			break;
		}
		}
		if (Firt == true && check == true)
		{
			Xoa_o(48, 10, 170, 35, 0);
			if (j == so_lan || lenght < 10)
			{
				if (lenght < 10)
				{
					Ve_mot_trang(lenght, 6, Database, i);
					To_mau_mot_doi_tuong(Database, lenght, 4, i);
					z = lenght;
				}
				else
				{
					if (lenght - (so_lan - 1) * 10 == 0)
					{
						z = 1;
						Ve_mot_trang(lenght - (so_lan - 1) * 10, 6, Database, -1);
					}
					else
					{
						Ve_mot_trang(lenght - (so_lan - 1) * 10, 6, Database, i);
						To_mau_mot_doi_tuong(Database, dem, 4, i);
						z = lenght - (so_lan - 1) * 10;
					}
				}

			}
			else
			{
				Ve_mot_trang(10, 6, Database, i);
				To_mau_mot_doi_tuong(Database, dem, 4, i);
				z = 10;
			}
			Outstring(101, 13 + 2 * z + 1, 2, 0, "<<");
			Outint(103, 13 + 2 * z + 1, 1, 0, j);
			Outstring((j > 9) ? 105 : 104, 13 + 2 * z + 1, 2, 0, ">>");
	
		}
	}
}
void Not_Found()
{
	Xoa_o(48, 10, 170, 35, 0);
	/*Xoa_o(100, 24, 120, 25, 4);*/
	Outstring(102,24,0 , 4, "      Khong Tim Thay     ");
	Outstring(102, 25, 0,4, " Nhan Bat Ki De Tiep Tuc ");
	_getch();
}
//vector<string> update()
//{
//		
//}