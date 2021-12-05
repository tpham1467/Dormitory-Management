#pragma once
#include"Khoi_tao.h"
#include<vector>
#include<algorithm>
#include"Management_Profile.h"
#include"Management_Room.h"
#include"Management_Student.h"
using namespace std;
class Thong_Ke
{
public:
	Thong_Ke()
	{
	}
	~Thong_Ke()
	{
	}
	void Menu(Mamagement_Room, Management_Student, Management_Profile);
	void Thong_Ke_Phi_Sinh_Hoat(Mamagement_Room);
	void Draw_Column_Chart(vector<int>,  vector<string>,string name, string , string );
};

