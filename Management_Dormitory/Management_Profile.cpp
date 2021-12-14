#include "Management_Profile.h"
#include <algorithm>
#include<sstream>
#include<vector>
Residency_Profile _Profile_section;
Admission_Profile _Profile_add;
namespace
{
	list TTBS[6] = {
	   list(ii(1,1),"Ban Photo Chung Minh"),list(ii(2,2),"Ban Photo Ho Khau"),list(ii(3,3),"Giay Chung Nhan Ho Ngheo")
	   ,list(ii(4,4),"Giay Chung Nhan Ho Can Ngheo"),list(ii(5,5),"Giay Chung Nhan Con Thuong Binh Liet Si"),
		list(ii(6,6),"Giay Chung Nhan Khuyet Tat")
	};
}
Management_Profile::Management_Profile()
{
	
}
Management_Profile:: ~Management_Profile()
{
	this->Data_AP.~Doubly_Linked_List();
	this->Data_RP.~Doubly_Linked_List();
}
Doubly_Linked_List<Admission_Profile>& Management_Profile::Get_Data_AP()
{
	return this->Data_AP;
}
Doubly_Linked_List<Residency_Profile>& Management_Profile::Get_Data_RP()
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
void Management_Profile::Set_Room(Management_Student& Data_Student,Mamagement_Room& Data_Room)
{
room_full:
	Xoa_o(46, 8, 170, 36, 0);
	Outstring(90, 37, 0, 103, "      Vui Long Chon Phong  ");
	Data_Room.Menu(Data_Student, false);
	Room _room_section = Data_Room.Get_Room_Section();
	string rc = _room_section.Get_Room_code();
	if (_room_section.Get_NS() == 6)
	{
		Room_Full();
		goto room_full;
	}
	Data_Room.Add_Student(rc);
	string st_code = _Profile_add.Get_Student(Data_Student)->Get_Data().Get_Student_Code();
	Node<Student>* p = Data_Student.Index_off(st_code);
	p->Get_Data().Set_Room_Code(rc);
	Xoa_o(46, 8, 170, 36, 0);
	Outstring(90, 37, 0, 0, "                           ");
	_Profile_add.Set_ID("NULL");
}
void Management_Profile::Extend(string  _profile_code,int i)
{
	Node<Residency_Profile>* p = Indexoff(_profile_code, 1);
	if (i == 0)
	{
		CDate d;
		d = d.Get_time();
		p->Get_Data().Set_Registration_Date(d);
		d.operator+(6);
		p->Get_Data().Set_Expiration_Date(d);
	}
	else 
	p->Get_Data().Extend();
}
Doubly_Linked_List< Admission_Profile> Management_Profile::Find_Admission_Profile(string data,Management_Student& Database_Student)
{
    stringstream _data(data);
    Doubly_Linked_List<string> _data_Token;
    Doubly_Linked_List<Admission_Profile> data_AP;
    string token;
    while (_data >> token) {

        _data_Token.InsertAtTail(token);
    }
    //find
	bool   check = false;
    Node<Admission_Profile>* p = this->Data_AP.Get_P_Head();
    while (p != nullptr)
    {
		while (p != nullptr)
		{
			check = false;
			Node<string>* pp = _data_Token.Get_P_Head();
			while (pp != nullptr && check == false)
			{
				token = pp->Get_Data();
				string _profile_code = p->Get_Data().Get_Profile_Code();
				if (_profile_code == token)
				{
					data_AP.InsertAtTail(p->Get_Data());
					check = true;
				}
				if (check == true) break;
				pp = pp->Get_Next();
			}

			p = p->Get_Next();
		}
    }
	if (check == false)
	{
		Node<Admission_Profile>* p = this->Data_AP.Get_P_Head();
		bool check = false;
		while (p != nullptr)
		{
			check = false;
			Node<string>* pp = _data_Token.Get_P_Head();
			while (pp != nullptr && check == false)
			{
				token = pp->Get_Data();
				string _id = p->Get_Data().Get_ID();
				if (_id == token)
				{
					data_AP.InsertAtTail(p->Get_Data());
					check = true;
				}
				if (check == true) break;
				pp = pp->Get_Next();
			}

			p = p->Get_Next();
		}
	}
	if (check == false)
	{
		Doubly_Linked_List<Student> data_Student = Database_Student.Find_Student(data);
		if (data_Student.Get_Lenght() != 0)
		{
			Node<Student>* p1 = data_Student.Get_P_Head();
			while (p1 != nullptr)
			{
				string sc = p1->Get_Data().Get_Profile_Code();
				Node<Admission_Profile>* p2 = Indexoff(sc);
				if (p2 != nullptr)
					data_AP.InsertAtTail(p2->Get_Data());
				p1 = p1->Get_Next();
			}
		}
	}
	return data_AP;
}
Doubly_Linked_List< Residency_Profile> Management_Profile::Find_Residency_Profile(string data,Management_Student& Database_Student)
{
	stringstream _data(data);
	Doubly_Linked_List<string> _data_Token;
	Doubly_Linked_List<Residency_Profile> data_RP;
	string token;
	while (_data >> token) {

		_data_Token.InsertAtTail(token);
	}
	//find
	Node<Residency_Profile>* p = this->Data_RP.Get_P_Head();
	bool check = false;
	while (p != nullptr)
	{
		check = false;
		Node<string>* pp = _data_Token.Get_P_Head();
		while (pp != nullptr && check == false)
		{
			token = pp->Get_Data();
			string _profile_code = p->Get_Data().Get_Profile_Code();
			if (_profile_code==token)
			{
				data_RP.InsertAtTail(p->Get_Data());
				check = true;
			}
			if (check == true) break;
			pp = pp->Get_Next();
		}

		p = p->Get_Next();
	}
	if (check == false)
	{
		Node<Residency_Profile>* p = this->Data_RP.Get_P_Head();
		bool check = false;
		while (p != nullptr)
		{
			check = false;
			Node<string>* pp = _data_Token.Get_P_Head();
			while (pp != nullptr && check == false)
			{
				token = pp->Get_Data();
				string _id = p->Get_Data().Get_ID();
				if (_id == token)
				{
					data_RP.InsertAtTail(p->Get_Data());
					check = true;
				}
				if (check == true) break;
				pp = pp->Get_Next();
			}

			p = p->Get_Next();
		}
	}
	if (check == false)
	{
		Doubly_Linked_List<Student> data_Student = Database_Student.Find_Student(data);
		if (data_Student.Get_Lenght() != 0)
		{
			Node<Student>* p1 = data_Student.Get_P_Head();
			while (p1 != nullptr)
			{
				string sc = p1->Get_Data().Get_Profile_Code();
				Node<Residency_Profile>* p2 = Indexoff(sc, 1);
				if(p2!=nullptr)
				data_RP.InsertAtTail(p2->Get_Data());
				p1 = p1->Get_Next();
			}
		}
	}
	return data_RP;
}
int  Management_Profile::Pay(string _profile_code, Management_Student& Data_Student)
{
	Node<Residency_Profile>* p = Indexoff(_profile_code, 1);
	return p->Get_Data().Pay();
}
void Management_Profile::Update_Admission_Profile(string _profile_code, const  Admission_Profile& ap)
{
	Node<Admission_Profile>* p = Indexoff(_profile_code);
	this->Data_AP.replace(p, ap);
}
void Management_Profile::Update_Residency_Profile(string  _profile_code,const  Residency_Profile& rp)
{
	Node<Residency_Profile>* p = Indexoff(_profile_code, 1);
	this->Data_RP.replace(p, rp);
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
void Management_Profile::Delete_RP(string _profile_code, Management_Student& Data_Student, Mamagement_Room& Data_Room)
{
	Node<Residency_Profile>* p = Indexoff(_profile_code, 1);
	Node<Student>* p1 = p->Get_Data().Get_Student(Data_Student);
	Data_Room.Delete_Student(p1->Get_Data().Get_Room_Code());
	Data_Student.Delete_Student(p1->Get_Data());
	this->Data_RP.Delete_indexoff(p);
}
void Management_Profile::Delete_AP(string _profile_code)
{
	Node<Admission_Profile>* p = Indexoff(_profile_code);
	this->Data_RP.InsertAtTail(p->Get_Data());
	this->Data_AP.Delete_indexoff(p);
	Node<Residency_Profile>* p1 = this->Data_RP.Get_P_Tail();
	Extend(p1->Get_Data().Get_Profile_Code(), 0);
}
void Management_Profile::Menu(Management_Student& Data_Student, Mamagement_Room& Data_Room)
{
	bool flag = true;
	while (flag)
	{

		Hien_thi_danh_sach(arr_Profile, 2);
		int a = bat_su_kien(arr_Profile, 2);
		switch (a)
		{
		case 0:
		{
			Menu_RP(Data_Student,Data_Room);
			break;
		}
		case 1:
		{
			Menu_AP(Data_Student,Data_Room);
			break;
		}
		case 2:
		{
			Xoa_o(46, 9, 170, 36, 0);
			Add_Profile(Data_Student);
			Xoa_o(46, 9, 170, 36, 0);
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
void Management_Profile::Add_Profile(Management_Student& Data_Student)
{
	Cursor(true);
	Student _Student;
	Admission_Profile ap;
	CDate d;
	d = d.Get_time();
	ap.Set_Registration_Date(d);
	d.operator+(6);
	ap.Set_Expiration_Date(d);
	Xoa_o(48, 10, 170, 36, 0);
	Hcn(48, 9, 60, 11);
	Outstring(50, 10, 2, 0, "Ho Va Ten");
	Hcn(63, 9, 112, 11);
	Outstring(120, 10, 2, 0, "Gioi Tinh");
	Hcn(118, 9, 132, 11);
	Hcn(135, 9, 165, 11);
	Outstring(50, 14, 2, 0, "Dia Chi");
	Hcn(48, 13, 58, 15);
	Hcn(61, 13, 112, 15);
	Outstring(120, 14, 2, 0, "Ngay Sinh");
	Hcn(118, 13, 132, 15);
	Hcn(135, 13, 165, 15);
	Outstring(50, 18, 2, 0, "Ma Sinh Vien");
	Hcn(48, 17, 63, 19);
	Hcn(66, 17, 112, 19);
	Outstring(120, 18, 2, 0, "Ma Phong");
	Hcn(118, 17, 130, 19);
	Hcn(133, 17, 165, 19);
	Outstring(50, 22, 2, 0, "Email");
	Hcn(48, 21, 58, 23);
	Hcn(61, 21, 112, 23);
	Outstring(120, 22, 2, 0, "So Dien Thoai");
	Hcn(118, 21, 135, 23);
	Hcn(138, 21, 165, 23);
	Outstring(50, 26, 2, 0, "Ma Ho So");
	Hcn(48, 25, 58, 27);
	Hcn(61, 25, 112, 27);
	Outstring(120, 26, 2, 0, "Ngay Het Han");
	Hcn(118, 25, 134, 27);
	Hcn(137, 25, 165, 27);
	Outstring(50, 30, 2, 0, "Que Quan");
	Hcn(48, 29, 60, 31);
	Hcn(63, 29, 112, 31);
	Outstring(120, 30, 2, 0, "Dan Toc");
	Hcn(118, 29, 129, 31);
	Hcn(132, 29, 165,31);
	Outstring(50, 34, 2, 0, "So Chung Minh");
	Hcn(48, 33, 65, 35);
	Hcn(68, 33, 112, 35);
	Outstring(120, 34, 2, 0, "Ngay Dang Ki");
	Hcn(118, 33, 134, 35);
	Hcn(137, 33, 165, 35);
	Outstring(135, 18, 9, 0, "NULL");
	int mssv = rand() % (999999999 - 100000000 + 1) + 100000000;
	string _Profile_Code = "HS"+to_string(mssv);
	Outstring(63, 26, 9, 0, _Profile_Code);
	Outstring(68, 18, 9, 0, to_string(mssv));
	Outstring(139, 26, 9, 0, ap.Get_Expiration_Date().Get_String());
	Outstring(139, 34, 9, 0, ap.Get_Registration_Date().Get_String());
	string data;
	gotoXY(65, 10);
	getline(cin, data);
	_Student.Set_Name(data);
	gotoXY(63, 14);
	getline(cin, data);
	_Student.Set_Address(data);
	gotoXY(63, 22);
	getline(cin, data);
	_Student.Set_Email(data);
	gotoXY(65, 30);
	getline(cin, data);
	ap.Set_Native_lace(data);
	gotoXY(70, 34);
	getline(cin, data);
	ap.Set_ID(data);
	gotoXY(137, 10);
	getline(cin, data);
	if(data.size()>2) 
	_Student.Set_Gender(1);
	else _Student.Set_Gender(1);
quaylai:
	Outstring(137, 14, 0, 0, "                ");
	gotoXY(137, 14);
	Outstring(137, 14, 9, 0, "");
	getline(cin, data);
	d = d.To_CDate(data);
	if (d.validDate() == false) goto quaylai;
	_Student.Set_Date_of_Birth(d);
	gotoXY(140, 22);
	getline(cin, data);
	_Student.Set_Phone_number(data);
	gotoXY(134, 30);
	getline(cin, data);
	ap.Set_Race(data);
	_Student.Set_Profile_Code(_Profile_Code);
	_Student.Set_Student_Code(to_string(mssv));
	_Student.Set_Room_Code("NULL");
	ap.Set_Profile_Code(_Profile_Code);
	while (1)
	{
		Xoa_o(46, 9, 170, 36, 0);
		_Profile_add = ap;
		Draw_Info_Object_AP();
		Hien_thi_danh_sach(arr_ttbs, 5);
		int a = bat_su_kien(arr_ttbs, 5);
		if (a == 27) break;
		Node<string>* p = _Profile_add.Get_TTBS().Get_P_Head();
		while (p != nullptr)
		{
			if (arr_ttbs[a].second == "Giay Chung Nhan Ho Ngheo" && p->Get_Data() == "Giay Chung Nhan Ho Can Ngheo")
			{
				Them_Giay_To(1);
				break;
			}
			if (p->Get_Data() == "Giay Chung Nhan Ho Ngheo" && arr_ttbs[a].second == "Giay Chung Nhan Ho Can Ngheo")
			{
				Them_Giay_To(1);
				break;
			}
			if (arr_ttbs[a].second == p->Get_Data())
			{
				Them_Giay_To(1);
				break;
			}
			p = p->Get_Next();
		}
		if (p == nullptr)
		{
			Them_Giay_To(0);
			ap.Get_TTBS().InsertAtTail(arr_ttbs[a].second);
		}
	}
	Xoa_o(46, 8, 170, 36, 0);
	Data_Student.Get_List_Student().InsertAtTail(_Student);
	this->Data_AP.InsertAtTail(ap);
	Cursor(false);
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
			int cof;
			getline(input, Profile_Code, ',');
			getline(input, Registration_Date, ',');
			getline(input, Expiration_Date, ',');
			getline(input, Native_lace, ',');
			getline(input, Race, ',');
			getline(input, ID, ',');
			getline(input, TTBS_s, ',');
			char z;
			input >> cof >> z;
			input.ignore();
			CDate d1, d2;
			d1 = d1.To_CDate(Registration_Date);
			d2 = d2.To_CDate(Expiration_Date);
			Doubly_Linked_List<string> Data_TTBS;
			if(TTBS_s!="NULL")
			for (int i = 0; i < TTBS_s.size(); i++)
			{
				int index = int(TTBS_s[i]) - 48;
				Data_TTBS.InsertAtTail(TTBS[index - 1].second);
			}
			Admission_Profile r3(Profile_Code, d1, ID, Native_lace, Race, d2,Data_TTBS,cof);
			if (r3.Get_Profile_Code() != "")
			this->Data_AP.InsertAtTail(r3);
		}
		input.close();
	}
}
void Management_Profile::Write_File()
{
	Node<Residency_Profile>* p = this->Data_RP.Get_P_Head();
	Node<Admission_Profile>* p1 = this->Data_AP.Get_P_Head();
	ofstream output;
	output.open("Residency_Profile.txt", ios::out);
	while (p != nullptr)
	{
		output << p->Get_Data().Get_Profile_Code() << ',' << p->Get_Data().Get_Registration_Date().Get_String() << ','
			<< p->Get_Data().Get_Expiration_Date().Get_String() << ',' << p->Get_Data().Get_Native_lace() << ','
			<< p->Get_Data().Get_Race() << ',' << p->Get_Data().Get_ID() << ',' << endl;
		p = p->Get_Next();
	}
	output.close();
	output.open("Admission_Profile.txt", ios::out);
	while (p1 != nullptr)
	{
		if (p1->Get_Data().Get_Profile_Code() != "")
		{
			output << p1->Get_Data().Get_Profile_Code() << ',' << p1->Get_Data().Get_Registration_Date().Get_String() << ','
				<< p1->Get_Data().Get_Expiration_Date().Get_String() << ',' << p1->Get_Data().Get_Native_lace() << ','
				<< p1->Get_Data().Get_Race() << ',' << p1->Get_Data().Get_ID() << ',';
			Node<string>* pp = p1->Get_Data().Get_TTBS().Get_P_Head();
			if (p1->Get_Data().Get_TTBS().Get_Lenght() == 0)
			{
				output << "NULL";
			}
			else
			{
				while (pp != nullptr)
				{
					for (int i = 0; i < 6; i++)
					{
						if (pp->Get_Data() == TTBS[i].second)
						{
							output << TTBS[i].first.first;
							break;
						}
					}
					pp = pp->Get_Next();
				}
			}
			output << ',' << p1->Get_Data().Get_Confirmation_Status() << ',' << endl;
		}
		p1 = p1->Get_Next();
	}
	output.close();
}
void Management_Profile::Menu_RP(Management_Student& Data_Student, Mamagement_Room& Data_Room)
{
	int index = 0;
	while (1)
	{
	ds:
	    bool update = false;
	    bool find = false;
	    index = Move_Page_RP(this->Data_RP, update, find, Data_Student);

		if (index == -1)
		{
			Xoa_o(48, 10, 170, 36, 0);
			return;
		}

		else
			_Profile_section = this->Data_RP.at(index);

	    if (update == true)
	    {
	    updae_info:
	        gotoXY(3, 21);
			Update_RP(Data_Student, Data_Room);
			Xoa_o(46, 9, 170, 36, 0);
	    }
	    else if (find == true)
	    {
	    find:
	        gotoXY(3, 21);
	        cout << 2;
	        Xoa_o(48, 10, 170, 36, 0);
	        Hcn(50, 20, 100, 22);
	        Hcn(103, 20, 113, 22);
	        Outstring(103, 21, 0, 103, "Tim Kiem");
	        setBackgroundColor(0);
	        setColor(15);
	        gotoXY(52, 21);
	        Cursor(true);
	        string data;
	        getline(cin, data);
	        Cursor(false);
			Doubly_Linked_List<Residency_Profile> _data_find = Find_Residency_Profile(data, Data_Student);
	        if (_data_find.Get_Lenght() == 0)
	        {
	            Not_Found();
	        }
	        else
	        {
				bool update = false;
				bool find = false;
	            index = Move_Page_RP(_data_find, update, find, Data_Student);
	            if (index == -1)
	            {
	                goto ds;
	            }

	            else
	            {

					_Profile_section = _data_find.at(index);

	            }
	            if (update == true)
	            {
	                goto updae_info;
	            }
	            else if (find == true)
	            {
	                goto find;
	            }
	            else
	            {
	                goto hien_thi;
	            }
	        }

	    }
	    else
	    {
	    hien_thi:
			Draw_Info_Object_RP(Data_Student);
			_getch();
	        Xoa_o(46, 9, 170, 36, 0);
	    }

	}
}
void Management_Profile::Draw_a_Page_RP(int y, Doubly_Linked_List<Residency_Profile> _Data, int j,Management_Student& Data_Student)
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
		Outstring(75, 11, 0, 15, "Ho Va Ten");
		Outstring(102, 11, 0, 15, "So Chung Minh");
		Outstring(135, 11, 0, 15, "Ngay Het Han");
	}
	int i;
	Node<Residency_Profile>* p = _Data.Get_Pointer(j);
	for (i = 15; i < 13 + 2 * y; i += 2)
	{

		Outstring(50, i - 1, 0, 6, p->Get_Data().Get_Profile_Code());
		Outstring(69, i - 1, 0, 6, p->Get_Data().Get_Student(Data_Student)->Get_Data().Get_Name());
		Outstring(102, i - 1, 0, 6, p->Get_Data().Get_ID());
		Outstring(137, i - 1, 0, 6, p->Get_Data().Get_Expiration_Date().Get_String());
		Line(48, i, 170, i, 6, false);
		p = p->Get_Next();
	}
	Outstring(50, i - 1, 0, 6, p->Get_Data().Get_Profile_Code());
	Outstring(69, i - 1, 0, 6, p->Get_Data().Get_Student(Data_Student)->Get_Data().Get_Name());
	Outstring(102, i - 1, 0, 6, p->Get_Data().Get_ID());
	Outstring(137, i - 1, 0, 6, p->Get_Data().Get_Expiration_Date().Get_String());
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
int Management_Profile::Move_Page_RP(Doubly_Linked_List<Residency_Profile> _data, bool& update, bool& find,Management_Student& Data_Student)
{
	int lenght = _data.Get_Lenght();
	int so_lan = (int)(lenght / 10) + 1;
	int i = 0;int  j = 1; int z = 0; ; int dem = 0; bool check = false;
	Xoa_o(48, 10, 170, 35, 0);
	bool Firt = false;
	if (so_lan == 1)
	{
		Draw_a_Page_RP(lenght, _data, 0, Data_Student);
		Draw_Object_RP(_data[0], 0, 4, i, Data_Student);
		Firt = true;
	}
	else
	{
		Draw_a_Page_RP(10, _data, 0, Data_Student);
		Outstring(101, 13 + 2 * 10 + 1, 2, 0, "<<");
		Outint(103, 13 + 2 * 10 + 1, 1, 0, j);
		Outstring(104, 13 + 2 * 10 + 1, 2, 0, ">>");
		Draw_Object_RP(_data[0], 0, 4, i, Data_Student);
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
				Draw_Object_RP(_data[dem], dem, 0, i, Data_Student);
				dem += -1;
				check = false;
				Draw_Object_RP(_data[dem], dem, 4, i, Data_Student);
			}
			break;
		}
		case 80:
		{
			if (dem == i + 9 || dem == lenght - 1) break;
			else
			{
				Draw_Object_RP(_data[dem], dem, 0, i, Data_Student);
				dem += 1;
				Draw_Object_RP(_data[dem], dem, 4, i, Data_Student);
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
					Draw_a_Page_RP(lenght, _data, i, Data_Student);
					Draw_Object_RP(_data[dem], lenght, 4, i, Data_Student);
					z = lenght;
				}
				else
				{
					if (lenght - (so_lan - 1) * 10 == 0)
					{
						z = 1;
						Draw_a_Page_RP(lenght - (so_lan - 1) * 10, _data, -1, Data_Student);
					}
					else
					{
						Draw_a_Page_RP(lenght - (so_lan - 1) * 10, _data, i, Data_Student);
						Draw_Object_RP(_data[dem], dem, 4, i, Data_Student);
						z = lenght - (so_lan - 1) * 10;
					}
				}

			}
			else
			{
				Draw_a_Page_RP(10, _data, i, Data_Student);
				Draw_Object_RP(_data[dem], dem, 4, i, Data_Student);
				z = 10;
			}
			Outstring(101, 13 + 2 * z + 1, 2, 0, "<<");
			Outint(103, 13 + 2 * z + 1, 1, 0, j);
			Outstring((j > 9) ? 105 : 104, 13 + 2 * z + 1, 2, 0, ">>");

		}
	}
	return 0;
}
void Management_Profile::Draw_Object_RP(Residency_Profile RP, int index, int color, int i,Management_Student& Data_Student)
{

	Outstring(50, (index - i) * 2 + 14, color, 6, RP.Get_Profile_Code());
	Outstring(69, (index - i) * 2 + 14, color, 6, RP.Get_Student(Data_Student)->Get_Data().Get_Name());
	Outstring(102, (index - i) * 2 + 14, color, 6, RP.Get_ID());
	Outstring(137, (index - i) * 2 + 14, color, 6, RP.Get_Expiration_Date().Get_String());
}
void Management_Profile::Draw_Info_Object_RP(Management_Student& Data)
{
	Xoa_o(48, 10, 170, 36, 0);
	Hcn(48, 9, 61, 11);
	Outstring(50, 10, 2, 0, "Ma Ho So");
	Hcn(64, 9, 112, 11);
	Outstring(120, 10, 2, 0, "Ho Va Ten");
	Hcn(118, 9, 132, 11);
	Hcn(135, 9, 165, 11);
	Outstring(50, 14, 2, 0, "Ngay Het Han");
	Hcn(48, 13, 63, 15);
	Hcn(66, 13, 112, 15);
	Outstring(120, 14, 2, 0, "Que Quan");
	Hcn(118, 13, 130, 15);
	Hcn(133, 13, 165, 15);
	Outstring(50, 18, 2, 0, "Dan Toc");
	Hcn(48, 17, 59, 19);
	Hcn(62, 17, 112, 19);
	Outstring(120, 18, 2, 0, "So Chung Minh");
	Hcn(118, 17, 136, 19);
	Hcn(139, 17, 165, 19);
	Outstring(50, 22, 2, 0, "Ngay Dang Ki");
	Hcn(48, 21, 65, 23);
	Hcn(68, 21, 112, 23);
	Outstring(65, 10, 9, 0, _Profile_section.Get_Profile_Code());
	Outstring(137, 10, 9, 0, _Profile_section.Get_Student(Data)->Get_Data().Get_Name());
	Outstring(68, 14, 9, 0, _Profile_section.Get_Expiration_Date().Get_String());
	Outstring(135, 14, 9, 0, _Profile_section.Get_Native_lace());
	Outstring(141, 18, 9, 0, _Profile_section.Get_ID());
	Outstring(64, 18, 9, 0, _Profile_section.Get_Race());
	Outstring(70, 22, 9, 0, _Profile_section.Get_Registration_Date().Get_String());
	CDate d; d = d.Get_time();
	if (d > _Profile_section.Get_Expiration_Date())
	{
		Outstring(50, 26, 2, 0, "Ho So Qua Han Nop Phi");
		Hcn(48, 25, 73, 27);
	}
	else
	{
		Xoa_o(47, 25, 73, 27);
	}
}
void Management_Profile::Update_RP(Management_Student& Data, Mamagement_Room& Data_Room)
{
	Draw_Info_Object_RP(Data);
	int i = 1;
	Outstring(90, 26, 2, 0, "Gia Han");
	Hcn(88, 25, 99, 27);
	Outstring(120, 26, 2, 0, "Ket Thuc Hop Dong");
	Hcn(118, 25, 139, 27);
	while (1)
	{
		char key = ' ';
		key = _getch();
		Doi_Mau(i, 9, Data);
		if (key == 80)
		{
			if (i ==9)
			{
				i = 1;
			}
			else
			{
				i++;
			}

		}
		else if (key == 72)
		{
			if (i == 1)
			{
				i = 9;
			}
			else
			{
				i--;
			}

		}
		else if (key == 75)
		{
			if (i >= 6)
			{
				i -= 5;
			}

		}
		else if (key == 77)
		{
			if (i < 6)
			{
				if (i == 5)
				{
					i = 9;
				}
				else
				{


					i += 5;
				}
			}

		}
		else if (key == 13)
		{
			Update_Info(i, Data,Data_Room);
			if (i == 5)
			{
				Draw_Info_Object_RP(Data);
				Outstring(90, 26, 2, 0, "Gia Han");
				Hcn(88, 25, 99, 27);
				Outstring(120, 26, 2, 0, "Ket Thuc Hop Dong");
				Hcn(118, 25, 139, 27);
			}
			if (i == 9) return;
		}
		else if (key == 27)
		{
			Update_Residency_Profile(_Profile_section.Get_Profile_Code(), _Profile_section);
			break;
		}
		Doi_Mau(i, 4,Data);
	}
}
void Management_Profile::Doi_Mau(int i,int color,Management_Student& Data)
{
	if (i == 1)
	{
		Outstring(65, 10, color, 0, _Profile_section.Get_Profile_Code());
	}
	else if (i == 2)
	{
		Outstring(68, 14, color, 0, _Profile_section.Get_Expiration_Date().Get_String());
	}
	else if (i == 3)
	{
		Outstring(64, 18, color, 0, _Profile_section.Get_Race());

	}
	else if (i == 4)
	{
		Outstring(70, 22, color, 0, _Profile_section.Get_Registration_Date().Get_String());
	}
	else if (i == 5)
	{
		Outstring(90, 26, color, 0, "Gia Han");
	}
	else if (i == 6)
	{
		Outstring(137, 10, color, 0, _Profile_section.Get_Student(Data)->Get_Data().Get_Name());
	}
	else if (i == 7)
	{
		Outstring(135, 14, color, 0, _Profile_section.Get_Native_lace());
	}
	else if (i == 8)
	{
		Outstring(141, 18, color, 0, _Profile_section.Get_ID());
	}
	else if (i == 9)
	{
		Outstring(120, 26, color, 0, "Ket Thuc Hop Dong");
	}
}
void Management_Profile::Update_Info(int i,Management_Student& Data_Student, Mamagement_Room& Data_Room)
{
	int color = 0;
	if (i == 1)
	{
		Outstring(65, 10, color, 0, _Profile_section.Get_Profile_Code());
		Not_Change();
	}
	else if (i == 2)
	{
		Outstring(68, 14, color, 0, _Profile_section.Get_Expiration_Date().Get_String());
		Not_Change();
	}
	else if (i == 3)
	{
		Outstring(64, 18, color, 0, _Profile_section.Get_Race());
		gotoXY(64, 18);
		Outchar(32, 170, 15, 0, ' ');
		string data;
		getline(cin, data);
		_Profile_section.Set_Race(data);
		Outstring(64, 18, 0, 0, data + " ");
	}
	else if (i == 4)
	{
		Outstring(70, 22, color, 0, _Profile_section.Get_Registration_Date().Get_String());
		Not_Change();
	}
	else if (i == 5)
	{
		_Profile_section.Extend();
		Extend_tb();
		Outstring(68, 14, 9, 0, "                        ");
		Outstring(68, 14, 9, 0, _Profile_section.Get_Expiration_Date().Get_String());
	}
	else if (i == 6)
	{
		Not_Change();
	}
	else if (i == 7)
	{
		Outstring(135, 14, color, 0, _Profile_section.Get_Native_lace());
		gotoXY(135, 14);
		Outchar(32, 170, 15, 0, ' ');
		string data;
		getline(cin, data);
		_Profile_section.Set_Native_lace(data);
		Outstring(135, 14, 0, 0, data + " ");
	}
	else if (i == 8)
	{
		Outstring(141, 18, color, 0, _Profile_section.Get_ID());
		Not_Change();
	}
	else if (i == 9)
	{
		this->Data_RP.replace(Indexoff(_Profile_section.Get_Profile_Code(), 1), _Profile_section);
		int So_tien = Pay(_Profile_section.Get_Profile_Code(),Data_Student);
		Delete_RP(_Profile_section.Get_Profile_Code(), Data_Student,Data_Room);
		if (So_tien < 0)
		{
			Pay_Tb(1, So_tien);
		}
		else
		{
			Pay_Tb(0, So_tien);
		}
		return;
	}
}
int Management_Profile::Move_Page_AP(Doubly_Linked_List<Admission_Profile> _data, bool& update, bool& find,Management_Student& Data_Student)
{
	Doubly_Linked_List<Residency_Profile> _Data_Rp;
	Node<Admission_Profile>* p = _data.Get_P_Head();
	while (p != nullptr)
	{
		_Data_Rp.InsertAtTail(p->Get_Data());
		p = p->Get_Next();
	}
	return Move_Page_RP(_Data_Rp, update, find, Data_Student);
}
void Management_Profile::Draw_Info_Object_AP()
{
	Xoa_o(47, 25, 84, 27);
	Outstring(50, 26, 2, 0, "Thong Tin Can Bo Sung");
	Hcn(48, 25, 71, 27);
	int x = 76, y = 26;
	Doubly_Linked_List<string> _ttbs = _Profile_add.Get_TTBS();
	for (int i = 0; i < _ttbs.Get_Lenght(); i++)
	{
		if (x >= 175||(x + _ttbs[i].size() >= 175))
		{
			Outstring(x -2, y, 0, 0, "  ");
			Hcn(74, 25, x, 27);
			x = 50;
			y = 30;
		}
		Outstring(x, y, 9, 0, _ttbs[i]);
		x += _ttbs[i].size();
		Outstring(x+1, y, 2, 0, ",");
		x+=3;
	}
	Outstring(x - 2, y, 0 , 0, "  ");
	Hcn(((y==30)?48:74), y-1, x, y+1);
}
void Management_Profile::Menu_AP(Management_Student& Data_Student,Mamagement_Room& Data_Room)
{
	int index = 0;
	while (1)
	{
	ds:
		bool update = false;
		bool find = false;
		index = Move_Page_AP(this->Data_AP, update, find, Data_Student);

		if (index == -1)
		{
			Xoa_o(48, 10, 170, 36, 0);
			return;
		}

		else
		{
			_Profile_section = this->Data_AP.at(index);
			_Profile_add = this->Data_AP.at(index);
		}
		if (update == true)
		{
		updae_info:
			gotoXY(3, 21);
			Update_AP(Data_Student, Data_Room);
			Xoa_o(46, 8, 170, 36, 0);
		}
		else if (find == true)
		{
		find:
			gotoXY(3, 21);
			cout << 2;
			Xoa_o(48, 10, 170, 36, 0);
			Hcn(50, 20, 100, 22);
			Hcn(103, 20, 113, 22);
			Outstring(103, 21, 0, 103, "Tim Kiem");
			setBackgroundColor(0);
			setColor(15);
			gotoXY(52, 21);
			Cursor(true);
			string data;
			getline(cin, data);
			Cursor(false);
			Doubly_Linked_List<Admission_Profile> _data_find = Find_Admission_Profile(data, Data_Student);
			if (_data_find.Get_Lenght() == 0)
			{
				Not_Found();
			}
			else
			{
				bool update = false;
				bool find = false;
				index = Move_Page_AP(_data_find, update, find, Data_Student);
				if (index == -1)
				{
					goto ds;
				}

				else
				{
					_Profile_section = _data_find.at(index);
					_Profile_add = this->Data_AP.at(index);
				}
				if (update == true)
				{
					goto updae_info;
				}
				else if (find == true)
				{
					goto find;
				}
				else
				{
					goto hien_thi;
				}
			}

		}
		else
		{
		hien_thi:
			Draw_Info_Object_RP(Data_Student);
			Draw_Info_Object_AP();
			_getch();
			Xoa_o(46, 9, 170, 36, 0);
		}

	}
}
void Management_Profile::Update_AP(Management_Student& Data, Mamagement_Room& Data_Room)
{
	Draw_Info_Object_RP(Data);
	Xoa_o(47, 25, 84, 27);
	Outstring(120, 22, 2, 0, "Xac Nhan");
	Hcn(118, 21, 130, 23);
	Outstring(50, 26, 2, 0, "Xep Phong");
	Hcn(48, 25, 61, 27);
	Outstring(120, 26, 2, 0, "Bo Sung Thong Tin");
	Hcn(118, 25, 139, 27);
	int i = 1;
	while (1)
	{
		char key = ' ';
		key = _getch();
		Doi_Mau_AP(i, 9, Data);
		if (key == 80)
		{
			if (i == 10)
			{
				i = 1;
			}
			else
			{
				i++;
			}

		}
		else if (key == 72)
		{
			if (i == 1)
			{
				i = 10;
			}
			else
			{
				i--;
			}

		}
		else if (key == 75)
		{
			if (i >= 6)
			{
				i -= 5;
			}

		}
		else if (key == 77)
		{
			if (i < 6)
			{
				i += 5;
			}

		}
		else if (key == 13)
		{
			Update_Info_AP(i, Data, Data_Room);
			if (i == 10)
			{
				Draw_Info_Object_RP(Data);
				Xoa_o(47, 25, 84, 27);
				Outstring(120, 22, 2, 0, "Xac Nhan");
				Hcn(118, 21, 130, 23);
				Outstring(50, 26, 2, 0, "Xep Phong");
				Hcn(48, 25, 61, 27);
				Outstring(120, 26, 2, 0, "Bo Sung Thong Tin");
				Hcn(118, 25, 139, 27);
			}
			if (i == 5)
			{
				if (_Profile_add.Get_ID() == "NULL")
				{
					Delete_AP(_Profile_add.Get_Profile_Code());
					return;
				}
			}
		}
		else if (key == 27)
		{
			Update_Admission_Profile(_Profile_add.Get_Profile_Code(), _Profile_add);
			return;
		}
		Doi_Mau_AP(i, 4, Data);
	}
}
void Management_Profile::Doi_Mau_AP(int i, int color, Management_Student& Data_Student)
{
	if (i == 1)
	{
		Outstring(65, 10, color, 0, _Profile_section.Get_Profile_Code());
	}
	else if (i == 2)
	{
		Outstring(68, 14, color, 0, _Profile_section.Get_Expiration_Date().Get_String());
	}
	else if (i == 3)
	{
		Outstring(64, 18, color, 0, _Profile_section.Get_Race());

	}
	else if (i == 4)
	{
		Outstring(70, 22, color, 0, _Profile_section.Get_Registration_Date().Get_String());
	}
	else if (i == 5)
	{
		Outstring(50, 26, color, 0, "Xep Phong");
	}
	else if (i == 6)
	{
		Outstring(137, 10, color, 0, _Profile_section.Get_Student(Data_Student)->Get_Data().Get_Name());
	}
	else if (i == 7)
	{
		Outstring(135, 14, color, 0, _Profile_section.Get_Native_lace());
	}
	else if (i == 8)
	{
		Outstring(141, 18, color, 0, _Profile_section.Get_ID());

	}
	else if (i == 9)
	{
		Outstring(120, 22, color, 0, "Xac Nhan");
	}
	else if (i == 10)
	{
		Outstring(120, 26, color, 0, "Bo Sung Thong Tin");
	}
}
void Management_Profile::Update_Info_AP(int i, Management_Student& Data_Student, Mamagement_Room& Data_Room)
{
	int color = 0;
	if (i == 1)
	{
		Outstring(65, 10, color, 0, _Profile_section.Get_Profile_Code());
		Not_Change();
	}
	else if (i == 2)
	{
		Outstring(68, 14, color, 0, _Profile_section.Get_Expiration_Date().Get_String());
		Not_Change();
	}
	else if (i == 3)
	{
		Outstring(64, 18, color, 0, _Profile_section.Get_Race());
		gotoXY(64, 18);
		Outchar(32, 170, 15, 0, ' ');
		string data;
		getline(cin, data);
		_Profile_section.Set_Race(data);
		Outstring(64, 18, 0, 0, data + " ");
	}
	else if (i == 4)
	{
		Outstring(70, 22, color, 0, _Profile_section.Get_Registration_Date().Get_String());
		Not_Change();
	}
	else if (i == 5)
	{
		bool cf = _Profile_add.Get_Confirmation_Status();
		if (cf == false)
		{
			Chua_Duoc_Xac_Nhan();
			return;
		}
		else
		{
			Set_Room(Data_Student, Data_Room);
		}
	}
	else if (i == 6)
	{
		Not_Change();
	}
	else if (i == 7)
	{
		Outstring(135, 14, color, 0, _Profile_section.Get_Native_lace());
		gotoXY(135, 14);
		Outchar(32, 170, 15, 0, ' ');
		string data;
		getline(cin, data);
		_Profile_section.Set_Native_lace(data);
		Outstring(135, 14, 0, 0, data + " ");
	}
	else if (i == 8)
	{
		Outstring(141, 18, color, 0, _Profile_section.Get_ID());
		Not_Change();
	}
	else if (i == 9)
	{
		bool cf = _Profile_add.Get_Confirmation_Status();
		int n = _Profile_add.Get_TTBS().Get_Lenght();
		if (n != 0)
		{
			Chua_Du_Thong_Tin();
		}
		else if (cf == true)
		{
			Phe_Duyet(1);
		}
		else
		{
			Phe_Duyet(0);
			_Profile_add.Set_Confirmation_Status(true);
		}
	}
	else if (i == 10)
	{
		while (1)
		{
			Xoa_o(46, 9, 170, 36, 0);
			Draw_Info_Object_AP();
			Hien_thi_danh_sach(arr_ttbs, 5);
			int a = bat_su_kien(arr_ttbs, 5);
			if (a == 27) break;
			Node<string>* p = _Profile_add.Get_TTBS().Get_P_Head();
			while (p != nullptr)
			{
				if (arr_ttbs[a].second == p->Get_Data())
				{
					_Profile_add.Get_TTBS().Delete_indexoff(p);
					Bo_Sung(0);
					break;
				}
				p = p->Get_Next();
			}
			if (p == nullptr) Bo_Sung(1);
		}
		Xoa_o(46, 8, 170, 36, 0);
	}
}
