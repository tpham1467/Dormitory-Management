#pragma once
#include"Khoi_tao.h"
void Khoi_tao_cac_danh_sach()
{
	/*arr_1[0].first.first = 15; arr_1[0].first.second = 16; arr_1[0].second = "Quan Li Sinh Vien";
	arr_1[1].first.first = 17; arr_1[1].first.second = 19; arr_1[1].second = "Quan Li Phong";
	arr_1[2].first.first = 17; arr_1[2].first.second = 22; arr_1[2].second = "Quan Li Ho So";
	arr_1[3].first.first = 14; arr_1[3].first.second = 25; arr_1[3].second = "Quan Li The Ra Vao";
	arr_1[4].first.first = 19; arr_1[4].first.second = 28; arr_1[4].second = "Thong Ke";
	arr_1[5].first.first = 21; arr_1[5].first.second = 31; arr_1[5].second = "Thoat";*/
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
void Xoa_o(int x, int y, int x2, int y2, int color)
{
	string _string;
	for (int i = x; i <= x2; i++)
		_string.push_back(' ');
	for (int i = y; i <= y2; i++)
	{
		Outstring(x, i, color, color, _string);
	}
}
void Khoi_tao()
{
<<<<<<< HEAD
	SetWindowSize(175, 41);
	SetScreenBufferSize(175, 41);
=======
	/*SetWindowSize(2, 60);
	SetScreenBufferSize(200, 50);*/
>>>>>>> 719b41b9401dc152faff1cb55369e2c10e7f101d
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
void Hcn(int x, int y, int x1, int y1, int color)
{
	for (int i = x; i <= x1; i++)
	{
		Outchar(i, y, 14, color, (char)196);
		Outchar(i, y1, 14, color, (char)196);
	}
	for (int i = y; i <= y1; i++)
	{
		Outchar(x - 1, i, 14, color, (char)179);
		Outchar(x1 + 1, i, 14, color, (char)179);
	}
	gotoXY(x - 1, y); cout << char(218);
	gotoXY(x1 + 1, y); cout << char(191);
	gotoXY(x - 1, y1); cout << char(192);
	gotoXY(x1 + 1, y1); cout << char(217);
	//Xoa_o(x , y , x1 , y1 ,2);
}
void Line(int x, int y, int x1, int y1, int color, bool thang)
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

void Confict_line(int x, int y, int x1, int y1, int _x, int _y, int _x1, int _y1, int color)
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

void Not_Found()
{
	Xoa_o(48, 10, 170, 35, 0);
	/*Xoa_o(100, 24, 120, 25, 4);*/
	Outstring(102, 24, 0, 4, "      Khong Tim Thay     ");
	Outstring(102, 25, 0, 4, " Nhan Bat Ki De Tiep Tuc ");
	_getch();
}