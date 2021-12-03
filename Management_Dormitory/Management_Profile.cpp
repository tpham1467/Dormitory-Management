#include "Management_Profile.h"
#include <algorithm>
#include<sstream>
#include<vector>
namespace
{
	list TTBS[5] = {
	   list(ii(1,1),"Ban Photo Chung Minh"),list(ii(2,2),"Ban Photo Ho Khau"),list(ii(3,3),"Giay Chung Nhan Ho Ngheo")
	   ,list(ii(4,4),"Giay Chung Nhan Ho Can Ngheo"),list(ii(5,5),"Giay Chung Nhan Con Thuong Binh Liet Si")
	};
}
Management_Profile::Management_Profile()
{
	
}
Management_Profile:: ~Management_Profile()
{

}
Doubly_Linked_List<Admission_Profile> Management_Profile::Get_Data_AP()
{
	return this->Data_AP;
}
Doubly_Linked_List<Residency_Profile> Management_Profile::Get_Data_RP()
{
	return this->Data_RP;
}
void Management_Profile::Add_Admission_Profile(const Admission_Profile& ap)
{
	Data_AP.InsertAtTail(ap);
}
void Management_Profile::Add_Residency_Profile(const Residency_Profile& rp)
{
	Data_RP.InsertAtTail(rp);
}
void Management_Profile::Extend(string  _profile_code)
{
	Node<Residency_Profile>* p = Indexoff(_profile_code, 1);
	p->Get_Data().Extend();
}
Doubly_Linked_List< Admission_Profile> Management_Profile::Find_Admission_Profile(string data,Management_Student Database_Student)
{
    stringstream _data(data);
    Doubly_Linked_List<string> _data_Token;
    Doubly_Linked_List<Admission_Profile> data_AP;
    string token;
    while (_data >> token) {

        _data_Token.InsertAtTail(token);
    }
    //find
    Node<Admission_Profile>* p = this->Data_AP.Get_P_Head();
    while (p != nullptr)
    {

        bool check = false;
        Node<string>* pp = _data_Token.Get_P_Head();
        while (pp != nullptr && check == false)
        {
			token = pp->Get_Data();
			string _profile_code = p->Get_Data().Get_Profile_Code();
			if (_profile_code.find(token) >= 0 || _profile_code.find(token) <= _profile_code.length())
			{
				data_AP.InsertAtTail(p->Get_Data());
				check = true;
			}
			if (check == true) break;
			if (check == false)
			{
				Doubly_Linked_List<Student> data_Student = Database_Student.Find_Student(token);
				if (data_Student.Get_Lenght() != 0)
				{
					Node<Student>* p1 = data_Student.Get_P_Head();
					while (p1 != nullptr)
					{
						Node<Admission_Profile>* p2 = Indexoff(p->Get_Data().Get_Profile_Code());
						data_AP.InsertAtTail(p2->Get_Data());
					}
					check = true;
				}
			}
			pp = pp->Get_Next();
        }
		
        p = p->Get_Next();
    }
	return data_AP;
}
Doubly_Linked_List< Residency_Profile> Management_Profile::Find_Residency_Profile(string data,Management_Student Database_Student)
{
	stringstream _data(data);
	Doubly_Linked_List<string> _data_Token;
	Doubly_Linked_List<Residency_Profile> data_RP;
	string token;
	while (_data >> token) {

		_data_Token.InsertAtTail(token);
	}
	//find
	Node<Admission_Profile>* p = this->Data_AP.Get_P_Head();
	while (p != nullptr)
	{

		bool check = false;
		Node<string>* pp = _data_Token.Get_P_Head();
		while (pp != nullptr && check == false)
		{
			token = pp->Get_Data();
			string _profile_code = p->Get_Data().Get_Profile_Code();
			if (_profile_code.find(token) >= 0 || _profile_code.find(token) <= _profile_code.length())
			{
				data_RP.InsertAtTail(p->Get_Data());
				check = true;
			}
			if (check == true) break;
			if (check == false)
			{
				Doubly_Linked_List<Student> data_Student = Database_Student.Find_Student(token);
				if (data_Student.Get_Lenght() != 0)
				{
					Node<Student>* p1 = data_Student.Get_P_Head();
					while (p1 != nullptr)
					{
						Node<Admission_Profile>* p2 = Indexoff(p->Get_Data().Get_Profile_Code());
						data_RP.InsertAtTail(p2->Get_Data());
					}
					check = true;
				}
			}
			pp = pp->Get_Next();
		}

		p = p->Get_Next();
	}
	return data_RP;
}
int  Management_Profile::Pay(string _profile_code)
{
	Node<Residency_Profile>* p = Indexoff(_profile_code, 1);
	Delete_RP(_profile_code);
	return p->Get_Data().Pay();
}
void Management_Profile::Confirm(string  _profile_code)
{
	Node<Admission_Profile>* p = Indexoff(_profile_code);
	p->Get_Data().Set_Confirmation_Status(true);
}
void Management_Profile::Update_Admission_Profile(string _profile_code)
{

}
void Management_Profile::Update_Residency_Profile(string  _profile_code)
{

}
Node<Residency_Profile> * Management_Profile::Indexoff(string _profile_code, int i)
{
	Node<Residency_Profile>* p = this->Data_RP.Get_P_Head();
	while (p != nullptr)
	{
		if (p->Get_Data().Get_Profile_Code() == _profile_code) return p;
		p = p->Get_Next();
	}
	return nullptr;
}
Node<Admission_Profile>* Management_Profile::Indexoff(string _profile_code)
{
	Node< Admission_Profile>* p = this->Data_AP.Get_P_Head();
	while (p!=nullptr)
	{
		if (p->Get_Data().Get_Profile_Code() == _profile_code) return p;
		p = p->Get_Next();
	}
	return nullptr;
}
void Management_Profile::Delete_RP(string _profile_code)
{
	Node<Residency_Profile>* p = Indexoff(_profile_code,1);
	this->Data_RP.Delete_indexoff(p);
}
void Management_Profile::Delete_AP(string _profile_code)
{
	Node<Admission_Profile>* p = Indexoff(_profile_code);


}
void Management_Profile::Menu()
{
	bool flag = true;
	while (flag)
	{

		Hien_thi_danh_sach(arr_Profile, 1);
		int a = bat_su_kien(arr_Profile, 1);
		switch (a)
		{
		case 0:
		{
			bool find, update;
			Move_Page_RP(this->Data_RP,find,update);
			break;
		}
		case 1:
		{
			Xoa_o(4, 14, 39, 35);
			break;
		}
		case 27:
		{
			flag = false;
			Xoa_o(4, 14, 39, 35);
			break;
		}

		}
	}
}
void Management_Profile::Read_File()
{
	ifstream input;
	input.open("Residency_Profile.txt", ios::in);
	if (!input.is_open())
	{
		//throw "Unable to open file Student";
	}
	else
	{
		while (!input.eof())
		{
			string Profile_Code;
			string Registration_Date;
			string ID;
			string Native_lace;
			string Race;
			string Expiration_Date;
			getline(input, Profile_Code, ',');
			getline(input, Registration_Date, ',');
			getline(input, Expiration_Date, ',');
			getline(input, Native_lace, ',');
			getline(input, Race, ',');
			getline(input, ID, ',');
			input.ignore();
			CDate d1,d2;
			d1 = d1.To_CDate(Registration_Date);
			d2 = d2.To_CDate(Expiration_Date);
			Residency_Profile r1(Profile_Code, d1, ID, Native_lace, Race, d2);
			this->Data_RP.InsertAtTail(r1);
		}
		this->Data_RP.DeleteAtTail();
		input.close();
	}

	input.open("Admission_Profile.txt", ios::in);
	if (!input.is_open())
	{
		//throw "Unable to open file Student";
	}
	else
	{
		while (!input.eof())
		{
			string Profile_Code;
			string Registration_Date;
			string ID;
			string Native_lace;
			string Race;
			string Expiration_Date;
			string TTBS_s;
			getline(input, Profile_Code, ',');
			getline(input, Registration_Date, ',');
			getline(input, Expiration_Date, ',');
			getline(input, Native_lace, ',');
			getline(input, Race, ',');
			getline(input, ID, ',');
			getline(input, TTBS_s, ',');
			input.ignore();
			CDate d1, d2;
			d1 = d1.To_CDate(Registration_Date);
			d2 = d2.To_CDate(Expiration_Date);
			Doubly_Linked_List<string> Data_TTBS;
			for (int i = 0; i < TTBS_s.size(); i++)
			{
				int index = int(TTBS_s[i]) - 49;
				Data_TTBS.InsertAtTail(TTBS[index].second);
			}
			Admission_Profile r3(Profile_Code, d1, ID, Native_lace, Race, d2,Data_TTBS);
			this->Data_AP.InsertAtTail(r3);
		}
		this->Data_AP.DeleteAtTail();
		input.close();
	}
}
void Management_Profile::Write_File()
{

}
void Management_Profile::Menu_RP()
{
	//Residency_Profile _RP_section;
	////bool check_del = true;
	//int index = 0;
	//while (1)
	//{
	//ds:
	//    bool update = false;
	//    bool find = false;
	//    index = Move_Page_RP(this->Data_RP, update, find);

	//    if (index == -1)
	//    {
	//        Xoa_o(48, 10, 170, 36, 0);
	//        return;
	//    }

	//    else
	//		_RP_section = this->Database.at(index);

	//    if (update == true)
	//    {
	//    updae_info:
	//        gotoXY(3, 21);
	//        
	//        //hien thi update
	//    }
	//    else if (find == true)
	//    {
	//    find:
	//        gotoXY(3, 21);
	//        cout << 2;
	//        Xoa_o(48, 10, 170, 36, 0);
	//        Hcn(50, 20, 100, 22);
	//        Hcn(103, 20, 113, 22);
	//        Outstring(103, 21, 0, 103, "Tim Kiem");
	//        setBackgroundColor(0);
	//        setColor(15);
	//        gotoXY(52, 21);
	//        Cursor(true);
	//        string data;
	//        getline(cin, data);
	//        Cursor(false);
	//        Doubly_Linked_List<Residency_Profile> _data_find = find(data);
	//        if (_data_find.Get_Lenght() == 0)
	//        {
	//            Not_Found();
	//        }
	//        else
	//        {
	//            index = Ve_nhieu_trang_chon(_data_find, update, find);
	//            if (index == -1)
	//            {
	//                goto ds;
	//            }

	//            else
	//            {

	//                _student_section = _data_find.at(index);

	//            }
	//            if (update == true)
	//            {
	//                goto updae_info;
	//            }
	//            else if (find == true)
	//            {
	//                goto find;
	//            }
	//            else
	//            {
	//                goto hien_thi;
	//            }
	//        }

	//    }
	//    else
	//    {
	//    hien_thi:
	//        Management_Student::Menu_update(_student_section);
	//        Xoa_o(45, 9, 170, 36, 0);
	//    }

	//}
}
void Management_Profile::Draw_a_Page_RP(int y, Doubly_Linked_List<Residency_Profile> _Data, int j)
{
	if (j == -1) {


		Xoa_o(48, 10, 170, 12, 15);
		Xoa_o(48, 13, 170, 13 + 1, 6);
		Outstring(50, 11, 0, 15, "Ma Ho So");
		Outstring(72, 11, 0, 15, "Ngay Dang Ki");
		Outstring(102, 11, 0, 15, "So Chung Minh");
		Outstring(135, 11, 0, 15, "Ngay Het Han");
		Line(68, 13, 68, 13 + 1, 6);
		Line(68, 10, 68, 12, 15);
		Line(108, 13, 108, 13 + 1, 6);
		Line(108, 10, 108, 12, 15);
		Line(125, 13, 125, 13 + 1, 6);
		Line(125, 10, 125, 12, 15);
		return;
	}
	else
	{
		Xoa_o(48, 10, 170, 12, 15);
		Xoa_o(48, 13, 170, 13 + 2 * y, 6);
		Outstring(50, 11, 0, 15, "Ma Ho So");
		Outstring(72, 11, 0, 15, "Ngay Dang Ki");
		Outstring(102, 11, 0, 15, "So Chung Minh");
		Outstring(135, 11, 0, 15, "Ngay Het Han");
	}
	int i;

	for (i = 15; i < 13 + 2 * y; i += 2)
	{

		Outstring(50, i - 1, 0, 6, _Data[j].Get_Profile_Code());
		Outstring(75, i - 1, 0, 6, _Data[j].Get_Registration_Date().Get_String());
		Outstring(102, i - 1, 0, 6, _Data[j].Get_ID());
		Outstring(137, i - 1, 0, 6, _Data[j].Get_Expiration_Date().Get_String());
		Line(48, i, 170, i, 6, false);
		j++;
	}
	Outstring(50, i - 1, 0, 6, _Data[j].Get_Profile_Code());
	Outstring(75, i - 1, 0, 6, _Data[j].Get_Registration_Date().Get_String());
	Outstring(102, i - 1, 0, 6, _Data[j].Get_ID());
	Outstring(137, i - 1, 0, 6, _Data[j].Get_Expiration_Date().Get_String());
	Line(65, 13, 65, 13 + 2 * y, 6);
	Line(65, 10, 65, 12, 15);
	Line(95, 13, 95, 13 + 2 * y, 6);
	Line(95, 10, 95, 12, 15);
	Line(125, 13, 125, 13 + 2 * y, 6);
	Line(125, 10, 125, 12, 15);
	for (int i = 15; i < 13 + 2 * y; i += 2)
	{

		Confict_line(48, i, 170, i, 65, 13, 61, 13 + 2 * y, 6);
		Confict_line(48, i, 170, i, 95, 13, 95, 13 + 2 * y, 6);
		Confict_line(48, i, 170, i, 125, 13, 125, 13 + 2 * y, 6);

	}
}
int Management_Profile::Move_Page_RP(Doubly_Linked_List<Residency_Profile> _data, bool& update, bool& find)
{
	int lenght = _data.Get_Lenght();
	int so_lan = (int)(lenght / 10) + 1;
	int i = 0, j = 1; int z = 0; ; int dem = 0; bool check = false;
	Xoa_o(48, 10, 170, 35, 0);
	bool Firt = false;
	if (so_lan == 1)
	{
		Draw_a_Page_RP(lenght, _data, 0);
		Draw_Object_RP(_data, 0, 4, i);
		Firt = true;
	}
	else
	{
		Draw_a_Page_RP(10, _data, 0);
		Outstring(101, 13 + 2 * 10 + 1, 2, 0, "<<");
		Outint(103, 13 + 2 * 10 + 1, 1, 0, j);
		Outstring(104, 13 + 2 * 10 + 1, 2, 0, ">>");
		Draw_Object_RP(_data, 0, 4, i);
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
				Draw_Object_RP(_data, dem, 0, i);
				dem += -1;
				check = false;
				Draw_Object_RP(_data, dem, 4, i);
			}
			break;
		}
		case 80:
		{
			if (dem == i + 9 || dem == lenght - 1) break;
			else
			{
				Draw_Object_RP(_data, dem, 0, i);
				dem += 1;
				Draw_Object_RP(_data, dem, 4, i);
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
		case 85:
		{
			update = true;
			return dem;
		}
		case 117:
		{
			update = true;
			return dem;
		}
		case 70:
		{
			find = true;
			return dem;
		}
		case 102:
		{
			find = true;
			return dem;
		}
		}
		if (Firt == true && check == true)
		{
			Xoa_o(48, 10, 170, 35, 0);
			if (j == so_lan || lenght < 10)
			{
				if (lenght < 10)
				{
					Draw_a_Page_RP(lenght, _data, i);
					Draw_Object_RP(_data, lenght, 4, i);
					z = lenght;
				}
				else
				{
					if (lenght - (so_lan - 1) * 10 == 0)
					{
						z = 1;
						Draw_a_Page_RP(lenght - (so_lan - 1) * 10, _data, -1);
					}
					else
					{
						Draw_a_Page_RP(lenght - (so_lan - 1) * 10, _data, i);
						Draw_Object_RP(_data, dem, 4, i);
						z = lenght - (so_lan - 1) * 10;
					}
				}

			}
			else
			{
				Draw_a_Page_RP(10, _data, i);
				Draw_Object_RP(_data, dem, 4, i);
				z = 10;
			}
			Outstring(101, 13 + 2 * z + 1, 2, 0, "<<");
			Outint(103, 13 + 2 * z + 1, 1, 0, j);
			Outstring((j > 9) ? 105 : 104, 13 + 2 * z + 1, 2, 0, ">>");

		}
	}
	return 0;
}
void Management_Profile::Draw_Object_RP(Doubly_Linked_List<Residency_Profile>& _Database, int index, int color, int i)
{

	Outstring(50, (index - i) * 2 + 14, color, 6, _Database[index].Get_Profile_Code());
	Outstring(75, (index - i) * 2 + 14, color, 6, _Database[index].Get_Registration_Date().Get_String());
	Outstring(102, (index - i) * 2 + 14, color, 6, _Database[index].Get_ID());
	Outstring(137, (index - i) * 2 + 14, color, 6, _Database[index].Get_Expiration_Date().Get_String());
}
void Management_Profile::Draw_Info_Object_RP(Management_Profile&)
{

}
//
// 
//void Management_Profile::Draw_a_Page_AP(int, Doubly_Linked_List<Residency_Profile>, int)
//{
//
//}
//int Management_Profile::Move_Page_AP(Doubly_Linked_List<Residency_Profile>, bool&, bool&)
//{
//
//}
//void Management_Profile::Draw_Object_AP(Doubly_Linked_List<Residency_Profile>&, int, int, int)
//{
//
//}
//void Management_Profile::Draw_Info_Object_AP(Management_Profile&)
//{
//
//}
