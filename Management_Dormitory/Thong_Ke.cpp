#include "Thong_Ke.h"
void Thong_Ke::Draw_Column_Chart(vector<int> value,vector<string> value_s,string name,string name_col,string name_row)
{
	Xoa_o(46, 9, 170, 36, 0);
	int k = 6;
	vector<int>::iterator min = min_element(begin(value), end(value));
	vector<int>::iterator max = max_element(begin(value), end(value));
	int next;
	string next_s = to_string(*max);
	string max_s = next_s;
	max_s[0] = next_s[0];
	for (int i = 1; i < next_s.size(); i++)
	{
		max_s[i] = '0';
	}
	next = stoi(max_s);
	if (next < *max)
	{
		max_s[0] = next_s[0] + 1;
		next = stoi(max_s);
	}
	next = next / (int(max_s[0] - 48));
	for (int i = 10; i < 30; i++)
	{
		Outchar(60, i, 15, 0, (char)179);
	}
	for (int i = 60; i < 155; i++)
	{
		Outchar(i, 29, 15, 0, (char)196);
	}
	Outchar(60, 29, 15, 0, (char)192);
	int v = stoi(max_s) / next;
	if (v >= 4 && v < 6) k = 3;
	else if (v >= 6 && v < 8) k = 2;
	else if (v >= 8 && v <= 10) k =2;
	else if (v <= 3 && v >= 2) k = 5;
	for (int i = 1; i <= stoi(max_s) / next; i++)
	{
		Outchar(60, 29 - i * k, 15, 0, (char)197);
		Outint(55, 29 - i * k, 15, 0, next * i);
	}
	int z = next / k;
	for (int i = 0; i < value.size(); i++)
	{
		int y = 29;
		int y0 = 0;
		while (y0 <= value[i])
		{
			y--; y0 += z;
		}
		Hcn(65 + i * 13, y, 65 + i * 13 + 4, 29, 0);
		Outint(65 + i * 13 +2, y - 1, 15, 0, value[i]);
		Outstring(65 + i * 13 - 2, 30, 15, 0, value_s[i]);
	}
	Outstring(68, 33, 15, 0, name);
	Outchar(155, 29, 15, 0, '>');
	int x = 59;
	for(int i=0;i<name_col.size();i++)
	{
		Outchar(x--, 10 , 15, 0, name_col[name_col.size()-i-1]);
	}
	x = 160;
	for (int i = 0; i < name_row.size(); i++)
	{
		Outchar(x--, 30, 15, 0, name_row[name_row.size() - i - 1]);
	}
}
void Thong_Ke::Menu(Mamagement_Room Data_Room,Management_Student Data_Student,Management_Profile Data_Profile)
{
	bool flag = true;
	while (flag)
	{

		Hien_thi_danh_sach(arr_tk, 3);
		int a = bat_su_kien(arr_tk,3);
		switch (a)
		{
		case 0:
		{
			Thong_Ke_Phi_Noi_Tru(Data_Profile);
			break;
		}
		case 1:
		{
			Thong_Ke_Phi_Sinh_Hoat(Data_Room);
			break;
		}
		case 2:
		{
			Thong_Ke_Tinh_Trang_Vat_Chat(Data_Room);
			break;
		}

		case 3:
		{
			Thong_Ke_Ho_So_Dang_Ki(Data_Profile);
			break;
		}
		default:
		{
			flag = false;
			break;
		}

		}
	}
}
void Thong_Ke::Thong_Ke_Phi_Sinh_Hoat(Mamagement_Room Data_Room)
{
	Node<Room>* p = Data_Room.Get_List_Room().Get_P_Head();
	CDate time;
	time = time.Get_time();
	vector<string> name = { "Da Dong Phi"," Chua Dong Phi" };
	vector<int>  value = {0,0};
	while (p != nullptr)
	{
		CDate d1 = p->Get_Data().Get_HDTPSH();
		if (time > d1)
		{
			value[0]++;
		}
		else
		{
			value[1]++;
		}
		p = p->Get_Next();
	}
	Draw_Column_Chart(value, name, "Bieu Do Cot Ve Tinh Trang Dong Phi o cac Phong", "Phong", "Tinh Trang");
}
void Thong_Ke::Thong_Ke_Phi_Noi_Tru(Management_Profile Data_Profile)
{
	Node<Residency_Profile>* p= Data_Profile.Get_Data_RP().Get_P_Head();
	CDate time;
	time = time.Get_time();
	vector<string> name = { "Da Dong Phi"," Chua Dong Phi" };
	vector<int>  value = { 0,0 };
	while (p != nullptr)
	{
		CDate d1 = p->Get_Data().Get_Expiration_Date();
		if (time > d1)
		{
			value[1]++;
		}
		else
		{
			value[0]++;
		}
		p = p->Get_Next();
	}
	Draw_Column_Chart(value, name, "Bieu Do Cot Ve Tinh Trang Dong Phi Noi Tru", "Sinh Vien", "Tinh Trang");
}
void Thong_Ke::Thong_Ke_Tinh_Trang_Vat_Chat(Mamagement_Room Data_Room)
{
	Node<Room>* p = Data_Room.Get_List_Room().Get_P_Head();
	vector<string> name = { "Da Sua Chua","Chua Sua Chua" };
	vector<int>  value = { 0,0 };
	while (p != nullptr)
	{;
		if (p->Get_Data().Get_COF()==true)
		{
			value[0]++;
		}
		else
		{
			value[1]++;
		}
		p = p->Get_Next();
	}
	Draw_Column_Chart(value, name, "Bieu Do Cot Ve Tinh Trang Vat Chat", "Phong", "Tinh Trang");
}
void Thong_Ke::Thong_Ke_Ho_So_Dang_Ki(Management_Profile Data_Profile)
{
	Node<Admission_Profile>* p = Data_Profile.Get_Data_AP().Get_P_Head();
	CDate time;
	time = time.Get_time();
	vector<string> name = { "Da Phe Duyet"," Chua Phe Duyet" };
	vector<int>  value = { 0,0 };
	while (p != nullptr)
	{
		bool d1 = p->Get_Data().Get_Confirmation_Status();
		if (d1==1)
		{
			value[0]++;
		}
		else
		{
			value[1]++;
		}
		p = p->Get_Next();
	}
	Draw_Column_Chart(value, name, "Bieu Do Cot Ve Trang Thai Ho So Dang Ki", "Ho So", "Tinh Trang");
}