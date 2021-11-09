#pragma once
#include <fstream>
using namespace std;
#include <string>
#include <iostream>
#include "Khoi_tao.h"
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <vector>
Student _student_del;
bool check_del = true;
int index = 0;
void Menu_find_Student(Management_Student& Database);
void Menu_find_Studen_silde(Management_Student& Database, int n, bool flag = false, bool flag_delete = false);
void Menu_Delete_Student(Management_Student& Database);
//void Menu_update(Management_Student& Database);
void Menu_find_Studen_silde(Management_Student& Database, int n, bool flag, bool flag_delete)
{
	if (n == 0)
	{

		Hcn(50, 20, 100, 22);
		Hcn(103, 20, 113, 22);
		Outstring(103, 21, 0, 103, "Tim Kiem");
		setBackgroundColor(0);
		setColor(15);
		gotoXY(52, 21);

		if (flag == true)
		{

			Cursor(true);
			string data;
			getline(cin, data);
			Cursor(false);
			Doubly_Linked_List<Student> _data_find = Database.Find_Student(data);
			vector<Student> list_kt;
			Node<Student>* p = _data_find.Get_P_Head();
			while (p != nullptr)
			{
				list_kt.push_back(p->Get_Data());
				p = p->Get_Next();
			}
			
			
			if (list_kt.size() == 0)
			{
				Not_Found();
			}
			else
			{
				if (flag_delete == true)
				{
					index = Ve_nhieu_trang_chon(list_kt);
					if (index == -1)
					{
						return;
					}

					else
						_student_del = list_kt.at(index);

				}
				else
					Ve_nhieu_trang(list_kt);
			}
		}
	}
	else
	{
		if (flag == false)
		{

			vector<Student> list_kt;
			Node<Student>* p = Database.Get_List_Student().Get_P_Head();
			for (; p != nullptr;)
			{
				list_kt.push_back(p->Get_Data());
				p = p->Get_Next();
			}
				
			if (list_kt.size() < 10)
				Ve_mot_trang(list_kt.size() - 1, 6, list_kt, 0);
			else
				Ve_mot_trang(10, 6, list_kt, 0);
		}
		else
		{
			vector<Student> list_kt;
			Node<Student>* p = Database.Get_List_Student().Get_P_Head();
			for (; p != nullptr;)
			{
				list_kt.push_back(p->Get_Data());
				p = p->Get_Next();
			}
			list_kt.pop_back();
			if (flag_delete == true)
			{
				index = Ve_nhieu_trang_chon(list_kt);
				if (index == -1)
					return;

				else
					_student_del = list_kt.at(index);


			}
			else
				Ve_nhieu_trang(list_kt);
		}
	}

}
void Menu_find_Student(Management_Student& Database)
{
	while (1)
	{

		Hien_thi_danh_sach(arr_find, 1);
		int i = 0;
		char key;
		int n = 1;
		Outstring(arr_find[i].first.first - 2, arr_find[i].first.second, 2, 0, ">>");
		Outstring(arr_find[i].first.first, arr_find[i].first.second, 2, 0, arr_find[i].second);
		Menu_find_Studen_silde(Database, 0);
		while (true)
		{
			key = _getch();
			Outstring(arr_find[i].first.first - 2, arr_find[i].first.second, 2, 0, "  ");
			Outstring(arr_find[i].first.first, arr_find[i].first.second, 11, 0, arr_find[i].second);
			if (key == 72)
			{
				if (i == 0)
					i = n;
				else
					i--;
			}
			else if (key == 80)
			{
				if (i == n)
					i = 0;
				else
					i++;
			}
			else if (key == 13 || key == 77)
			{
				Menu_find_Studen_silde(Database, i, true);
				break;
			}
			else if (key == 27)
			{
				Xoa_o(4, 14, 39, 35, 0);
				Xoa_o(48, 10, 170, 36, 0);
				return;
				break;
			}
			Xoa_o(48, 10, 170, 36, 0);
			Outstring(arr_find[i].first.first - 2, arr_find[i].first.second, 2, 0, ">>");
			Outstring(arr_find[i].first.first, arr_find[i].first.second, 2, 0, arr_find[i].second);
			Menu_find_Studen_silde(Database, i);
		}
		Xoa_o(48, 10, 170, 36, 0);
	}
}
void Menu_Delete_Student(Management_Student& Database)
{
	while (1)
	{

		Hien_thi_danh_sach(arr_find, 1);
		int i = 0;
		char key;
		int n = 1;
		Outstring(arr_find[i].first.first - 2, arr_find[i].first.second, 2, 0, ">>");
		Outstring(arr_find[i].first.first, arr_find[i].first.second, 2, 0, arr_find[i].second);
		Menu_find_Studen_silde(Database, 0);
		while (true)
		{
			key = _getch();
			Outstring(arr_find[i].first.first - 2, arr_find[i].first.second, 2, 0, "  ");
			Outstring(arr_find[i].first.first, arr_find[i].first.second, 11, 0, arr_find[i].second);
			if (key == 72)
			{
				if (i == 0)
					i = n;
				else
					i--;
			}
			else if (key == 80)
			{
				if (i == n)
					i = 0;
				else
					i++;
			}
			else if (key == 13 || key == 77)
			{
				Menu_find_Studen_silde(Database, i, true, true);
				if (index != -1)
				{
					Database.Delete_Student(_student_del);
				}
				break;
			}
			else if (key == 27)
			{
				Xoa_o(4, 14, 39, 35, 0);
				Xoa_o(48, 10, 170, 36, 0);
				return;
				break;
			}
			Xoa_o(48, 10, 170, 36, 0);
			Outstring(arr_find[i].first.first - 2, arr_find[i].first.second, 2, 0, ">>");
			Outstring(arr_find[i].first.first, arr_find[i].first.second, 2, 0, arr_find[i].second);
			Menu_find_Studen_silde(Database, i);
		}
		Xoa_o(48, 10, 170, 36, 0);
	}
}
//void Menu_update(Management_Student& Database)
//{
//	while (1)
//	{
//
//		Hien_thi_danh_sach(arr_find, 1);
//		int i = 0;
//		char key;
//		int n = 1;
//		Outstring(arr_find[i].first.first - 2, arr_find[i].first.second, 2, 0, ">>");
//		Outstring(arr_find[i].first.first, arr_find[i].first.second, 2, 0, arr_find[i].second);
//		Menu_find_Studen_silde(Database, 0);
//		while (true)
//		{
//			key = _getch();
//			Outstring(arr_find[i].first.first - 2, arr_find[i].first.second, 2, 0, "  ");
//			Outstring(arr_find[i].first.first, arr_find[i].first.second, 11, 0, arr_find[i].second);
//			if (key == 72)
//			{
//				if (i == 0)
//					i = n;
//				else
//					i--;
//			}
//			else if (key == 80)
//			{
//				if (i == n)
//					i = 0;
//				else
//					i++;
//			}
//			else if (key == 13 || key == 77)
//			{
//				Menu_find_Studen_silde(Database, i, true, true);
//				if (index != -1)
//				{
//					update(Database,_student_del);
//				}
//				break;
//			}
//			else if (key == 27)
//			{
//				Xoa_o(4, 14, 39, 35, 0);
//				Xoa_o(48, 10, 170, 36, 0);
//				return;
//				break;
//			}
//			Xoa_o(48, 10, 170, 36, 0);
//			Outstring(arr_find[i].first.first - 2, arr_find[i].first.second, 2, 0, ">>");
//			Outstring(arr_find[i].first.first, arr_find[i].first.second, 2, 0, arr_find[i].second);
//			Menu_find_Studen_silde(Database, i);
//		}
//		Xoa_o(48, 10, 170, 36, 0);
//	}
//}