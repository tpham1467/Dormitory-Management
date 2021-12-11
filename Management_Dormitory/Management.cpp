#include "Management.h"
#include"Khoi_tao.h"
Management::Management()
{	
	this->Data_Student.Read_File();
	this->Data_Room.Read_File();
	this->Data_Profile.Read_File();
}
Management::~Management()
{
	//this->Data_Room.~Mamagement_Room();
	//this->Data_Student.Write_File();
	//this->Data_Student.~Management_Student();
}
void Management::Menu_chinh()
{
	Khoi_tao();
	Cursor(false);
	while (1)
	{

		Hien_thi_danh_sach(arr_1, 4);
		int a = bat_su_kien(arr_1, 4);
		switch (a)
		{
		case 0:
		{
			this->Data_Student.Menu_Student();
			break;
		}
		case 1:
		{
			this->Data_Room.Menu(this->Data_Student);
			break;
		}
		case 2:
		{
			Xoa_o(4, 14, 39, 35);
			this->Data_Profile.Menu(Data_Student,this->Data_Room);
			Xoa_o(46, 9, 170, 36, 0);
			Xoa_o(4, 14, 39, 35);
			break;
		}
		
		case 3:
		{
			Xoa_o(4, 14, 39, 35);
			this->tk.Menu(this->Data_Room, this->Data_Student, this->Data_Profile);
			Xoa_o(46, 9, 170, 36, 0);
			Xoa_o(4, 14, 39, 35);
			break;
		}
		case 4:
		{
			Xoa_o(0, 0, 175, 40);
			exit(0);
		}
		default:
		{
			break;
		}

		}
	}
}
