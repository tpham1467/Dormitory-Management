#pragma once
#include<fstream>
using namespace std;
#include<string>
#include<iostream>
#include"console.h"
#include<windows.h>
#include<conio.h>
#include<vector>
typedef pair<int, int > ii;
typedef pair<ii, string > list;
namespace {
	list arr_1[6] = {
	   list(ii(15,16),"Quan Ly Sinh Vien"),list(ii(17,19),"Quan Ly Phong"),list(ii(17,22),"Quan Ly Ho So")
	   ,list(ii(19,25),"Thong Ke"),list(ii(21,28),"Thoat")
	};
	list arr_tk[4] =
	{
		 list(ii(13,16),"Thong Ke Phi Noi Tru"),list(ii(12,19),"Thong Ke Phi Sinh Hoat"),
		 list(ii(10,22),"Thong ke Tinh Trang Vat Chat")
	   ,list(ii(12,25),"Thong Ke Ho So Dang Ki")
	};
	list arr_Menu_r[2] =
	{
		list(ii(17,22),"Chuyen Phong"),list(ii(18,25),"Them Phong")
	};
	list arr_Profile[6] =
	{
		list(ii(13,16),"Quan Ly Ho So Noi Tru"),list(ii(13,19),"Quan Ly Ho So Dang Ki")
	};
	list arr_ttbs[6] =
	{
		list(ii(103,8),"Ban Photo Chung Minh"),list(ii(105,11),"Ban Photo Ho Khau"),list(ii(101,14),"Giay Chung Nhan Ho Ngheo")
	   ,list(ii(99,17),"Giay Chung Nhan Ho Can Ngheo"),list(ii(94,20),"Giay Chung Nhan Con Thuong Binh Liet Si"),
		list(ii(100,23),"Giay Chung Nhan Khuyet Tat")
	};

};
int bat_su_kien(list arr[], int n);
void Introduction();
void Xoa_o(int x, int y, int x2, int y2, int color = 0);
void Hien_thi_danh_sach(list arr[], int n);
void Khoi_tao();
void huong_dan();
void khung_chon();
void khung();
void Hcn(int x, int y, int x1, int y1, int color = 0);
void Line(int x, int y, int x1, int y1, int color = 15, bool thang = true);
void Confict_line(int x, int y, int x1, int y1, int _x, int _y, int _x1, int _y1, int color);
void Not_Found();
void Not_Change();
void Input_Error();
void Payment_Success(int);
void Confirm(int);
void Add_Success(int);
void Room_Full();
ofstream Save_File();
void Extend_tb();
void Pay_Tb(int, int );
void Phe_Duyet(int);
void Bo_Sung(int);
//vector<string> update();

