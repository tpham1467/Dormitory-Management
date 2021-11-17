#pragma once
#include<fstream>
using namespace std;
#include<string>
#include<iostream>
#include"console.h"
#include<windows.h>
#include<conio.h>
#include"Doubly_Linked_List.h"
#include"Student.h"
#include<vector>
typedef pair<int, int > ii;
typedef pair<ii, string > list;
namespace
{
	list arr_1[6];
	list arr_Student[5];
	list arr_Room[4];
	list arr_Profile[6];
	list arr_Card[5];
	list arr_find[2];
}
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
void Ve_mot_trang(int y, int color, Doubly_Linked_List<Student>& Database, int j);
void Ve_nhieu_trang(Doubly_Linked_List<Student>& Database);
int Ve_nhieu_trang_chon(Doubly_Linked_List<Student>& Database, bool& update, bool& find);
void To_mau_mot_doi_tuong(Doubly_Linked_List<Student>& Database, int index, int color, int i);
void Not_Found();
//vector<string> update();

