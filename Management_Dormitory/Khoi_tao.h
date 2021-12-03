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
	   list(ii(15,16),"Quan Li Sinh Vien"),list(ii(17,19),"Quan Li Phong"),list(ii(17,22),"Quan Li Ho So")
	   ,list(ii(19,28),"Thong Ke"),list(ii(21,31),"Thoat")
	};
	list arr_Student[5];
	list arr_Room[4];
	list arr_Profile[6] =
	{
		list(ii(13,16),"Quan Li Ho So Noi Tru"),list(ii(13,19),"Quan Li Ho So Dang Ki")
	};
	list arr_Card[5];
	list arr_find[2];
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
//vector<string> update();

