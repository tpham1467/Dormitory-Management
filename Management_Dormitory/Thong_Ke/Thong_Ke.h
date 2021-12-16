#pragma once
#include"../Graphics/Khoi_tao.h"
#include<vector>
#include<algorithm>
#include"../Profile_Management/Management_Profile.h"
#include"../Room_Management/Management_Room.h"
#include"../Student_Management/Management_Student.h"
#include<cmath>
#include<string>
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
	void Thong_Ke_Phi_Noi_Tru(Management_Profile);
	void Thong_Ke_Tinh_Trang_Vat_Chat(Mamagement_Room);
	void Thong_Ke_Ho_So_Dang_Ki(Management_Profile);
	void Draw_Column_Chart(vector<int>,  vector<string>,string name, string , string );
};

