#pragma once
#include"Khoi_tao.h"
void Khoi_tao_cac_danh_sach()
{

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
		else if (key == 27)
		{
			return int(key);
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
	/*SetWindowSize(175, 41);
	SetScreenBufferSize(175, 41);*/
	/*SetWindowSize(2, 60);
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
	Outstring(3, 6, 11, 0, "Nut U  :De Thay Doi Thong Tin");
	Outstring(3, 7, 11, 0, "Nut F  :De Tim Kiem ");
	Outstring(3, 8, 11, 0, "Nut M  :De Dung Chuc Nang Mo Rong ");
	Outstring(3, 9, 11, 0, "Nut S  :De Sap Xep Danh Sach ");
	Outstring(3, 10, 11, 0, "Nut X  :De Xuat Danh Sach ");
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
	Outstring(21, 14, 5, 0, "MENU");
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
		Outchar(i, 11, 15, 0, (char)219);
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
void Not_Change()
{
	Outstring(102, 28, 0, 4, "      Du Lieu Khong Duoc Thay Doi      ");
	Outstring(102, 29, 0, 4, "       Nhan Bat Ki De Tiep Tuc         ");
	_getch();
	Outstring(102, 28, 0, 0, "                                       ");
	Outstring(102, 29, 0, 0, "                                       ");
}
void Input_Error()
{
	Outstring(102, 28, 0, 4, "      Du Lieu Khong Hop Le Vui Long Nhap Lai     ");
	Outstring(102, 29, 0, 4, "            Nhan Bat Ki De Tiep Tuc              ");
	_getch();
	Outstring(102, 28, 0, 0, "                                                 ");
	Outstring(102, 29, 0, 0, "                                                 ");
}
void Payment_Success(int i)
{
		Outstring(80, 33, 0, 4, "      Thanh Toan Thanh Cong         ");
		Outstring(80, 34, 0, 4, "      Nhan Bat Ki De Tiep Tuc       ");
		_getch();
		Outstring(80, 33, 0, 0, "                                    ");
		Outstring(80, 34, 0, 0, "                                    ");
}
void Confirm(int i)
{
	if (i == 0)
	{
		Outstring(80, 33, 0, 4, "      Xac Nhan Sua Chua Thanh Cong         ");
		Outstring(80, 34, 0, 4, "        Nhan Bat Ki De Tiep Tuc            ");
		_getch();
		Outstring(80, 33, 0, 0, "                                           ");
		Outstring(80, 34, 0, 0, "                                           ");
	}
	else
	{
		Outstring(80, 33, 0, 4, "           Phong Nay Khong Can Sua Chua                 ");
		Outstring(80, 34, 0, 4, "      Nhan Y/N Neu Ban Muon Dang Ki Sua Chua            ");
	}
}
void Add_Success(int i)
{
	if (i == 0)
	{
		Xoa_o(48, 10, 170, 35, 0);
		Outstring(90, 20, 0, 4, "      Chuyen Phong Thanh Cong     ");
		Outstring(90, 21, 0, 4, "      Nhan Bat Ki De Tiep Tuc     ");
		_getch();
	}
	else
	{
		Xoa_o(48, 10, 170, 35, 0);
		Outstring(90, 20, 0, 4, "       Them Phong Thanh Cong      ");
		Outstring(90, 21, 0, 4, "      Nhan Bat Ki De Tiep Tuc     ");
		_getch();
	}
}
void Room_Full()
{
	Xoa_o(48, 10, 170, 35, 0);
	Outstring(90, 20, 0, 4, "      Phong Da Day Vui Long Chon Lai     ");
	Outstring(90, 21, 0, 4, "           Nhan Bat Ki De Tiep Tuc       ");
	_getch();
}
void Extend_tb()
{
	Outstring(80, 33, 0, 4, "      Gia Han Thanh Cong     ");
	Outstring(80, 34, 0, 4, "    Nhan Bat Ki De Tiep Tuc  ");
	_getch();
	Outstring(80, 33, 0, 0, "                                           ");
	Outstring(80, 34, 0, 0, "                                           ");
}
void Pay_Tb(int i,int t)
{
	if (i == 0)
	{  
		Outstring(80, 33, 0, 4, "     Thanh Toan Thanh Cong                ");
		Outstring(80, 34, 0, 4, "    Nhan Bat Ki De Tiep Tuc               ");
		Outstring(80, 34, 0, 4, "    So Tien Du la:                        ");
		Outint(100, 34, 0, 4, t);
		Outstring(80, 34, 0, 4, "    So Tien Du la:                        ");
		Outint(100, 34, 0, 4, t);
	}
	else
	{
		Outstring(80, 33, 0, 4, "     Thanh Toan Khong Thanh cong                      ");
		Outstring(80, 34, 0, 4, "     So Tien Con No La:                               ");
		Outint(104, 34, 0, 4, t);
		Outstring(80, 35, 0, 4, "    Vui Long Thanh Toan Not So Tien Con Lai           ");
	}
	_getch();
	Outstring(80, 33, 0, 0, "                                                     ");
	Outstring(80, 34, 0, 0, "                                                      ");
	Outstring(80, 35, 0, 0, "                                                  ");
}
void Phe_Duyet(int i)
{
	if (i == 0)
	{
		Outstring(80, 33, 0, 4, "     Phe Duyet Thanh  Thanh Cong          ");
		Outstring(80, 34, 0, 4, "       Nhan Bat Ki De Tiep Tuc            ");
	}
	else
	{
		Outstring(80, 33, 0, 4, "       Ho So Da Duoc Phe Duyet          ");
		Outstring(80, 34, 0, 4, "       Nhan Bat Ki De Tiep Tuc          ");
	}
	_getch();
	Outstring(80, 33, 0, 0, "                                                     ");
	Outstring(80, 34, 0, 0, "                                                      ");
}
void Bo_Sung(int i)
{
	if (i == 0)
	{
		Outstring(80, 33, 0, 4, "     Bo Sung Thong Tin Thanh Cong       ");
		Outstring(80, 34, 0, 4, "       Nhan Bat Ki De Tiep Tuc          ");
	}
	else
	{
		Outstring(80, 33, 0, 4, "       Khong Can Giay To nay            ");
		Outstring(80, 34, 0, 4, "       Nhan Bat Ki De Tiep Tuc          ");
	}
	_getch();
	Outstring(80, 33, 0, 0, "                                                     ");
	Outstring(80, 34, 0, 0, "                                                     ");
}
void Chua_Duoc_Xac_Nhan()
{
	Outstring(80, 33, 0, 4, "    Ho So Chua Duoc Xac Nhan . Vui Long Xac Nhan       ");
	Outstring(80, 34, 0, 4, "                Nhan Bat Ki De Tiep Tuc                ");
	_getch();
	Outstring(80, 33, 0, 0, "                                                        ");
	Outstring(80, 34, 0, 0, "                                                        ");
}
void Chua_Du_Thong_Tin()
{
	Outstring(80, 33, 0, 4, "      Ho So Con Thieu Giay To Di Kem         ");
	Outstring(80, 34, 0, 4, "         Nhan Bat Ki De Tiep Tuc             ");
	_getch();
	Outstring(80, 33, 0, 0, "                                                        ");
	Outstring(80, 34, 0, 0, "                                                        ");
}
void Them_Giay_To(int i)
{
	if (i == 0)
	{
		Outstring(80, 33, 0, 4, "     Bo Sung Thong Tin Thanh Cong       ");
		Outstring(80, 34, 0, 4, "       Nhan Bat Ki De Tiep Tuc          ");
	}
	else
	{
		Outstring(80, 33, 0, 4, "       Giay To nay Da Duoc Bo Sung        ");
		Outstring(80, 34, 0, 4, "         Nhan Bat Ki De Tiep Tuc          ");
	}
	_getch();
	Outstring(80, 33, 0, 0, "                                                     ");
	Outstring(80, 34, 0, 0, "                                                     ");
}
void Dang_sap_xep()
{
	Xoa_o(48, 10, 170, 35, 0);
	Outstring(102, 24, 0, 4, "     Dang Sap Xep     ");
}
void Sap_Xep_Xong()
{
	Xoa_o(48, 10, 170, 35, 0);
	Outstring(102, 24, 0, 4, "     Da Sap Xep Xong     ");
	Outstring(102, 25, 0, 4, " Nhan Bat Ki De Tiep Tuc ");
	_getch();
}
ofstream Save_File()
{
	OPENFILENAME ofn;
	char szFileName[MAX_PATH] = "";
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = (LPCWSTR)L"CSV Files (*.csv)\0*.csv\0All Files (*.*)\0*.*\0";
	ofn.lpstrFile = (LPWSTR)szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = (LPCWSTR)L"csv";
	GetSaveFileName(&ofn);
	ofstream open;
	open.open(ofn.lpstrFile, ios::out);
	return open;
}