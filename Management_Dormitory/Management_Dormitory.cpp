#include <iostream>
#include"Management_Student.h"
#include"Management_Room.h"
#include"Giao_dien.h"
#include <algorithm>
using namespace std;
int main()
{ 
	//Menu_chinh();
	Management_Student Data_Student;
	Mamagement_Room data_room;
	data_room.Read_File();
 vector<Room> data=	data_room.Find_Room("huy truong",Data_Student);

 while (data.size() != 0)
 {
	Room _r = data.back();
	 cout << _r.Get_Room_code() <<"  " << _r.Get_NS() <<"   " << _r.Get_COF() <<"  " << _r.Get_HDTPSH() << endl;
	 data.pop_back();
 }
//	Data_Room.Find_Room();
	//Database.Find_Student("Pham Van Tien Truong");
	//Menu_chinh(Data_Student);
	//Database.Find_Student("pham");
	//Node<Student>* p = Database.Get_List_Student().Get_P_Head();
	//vector<string> list;
	//vector<string> list_1;
	//while (p != nullptr)
	//{
	//	string ma = p->Get_Data().Get_Room_Code();
	//	transform(ma.begin(), ma.end(), ma.begin(), toupper);
	//	list.push_back(ma);
	//	 string name = p->Get_Data().Get_Room_Code();
	//	 transform(name.begin(), name.end(), name.begin(), toupper);
	//	list_1.push_back(ma);
	//	p = p->Get_Next();
	//}
	/*cout << list.size()<<endl;*/
// 	/*cout << list.at(list.size() - 1) << endl;*/
//	list.pop_back();
//	cout << list_1.size() << endl;
//list_1.pop_back();
// 	// cout << list_1.at(list_1.size() - 1) << endl;
	//sort(begin(list), end(list));
	//list.erase(unique(begin(list), end(list)), end(list));
// 	sort(begin(list_1), end(list_1));
// 	list_1.erase(unique(begin(list_1), end(list_1)), end(list_1));
	//cout << list.size() << endl;
	//cout << list_1.size() << endl;
//  //p = Database.Get_List_Student().Get_P_Head();
//  //int count = 0;
//  //while (p != nullptr)
//  //{

// 	// if (p->Get_Data().Get_Student_Code() == "102200211" || p->Get_Data().Get_Student_Code() == "102200222" || p->Get_Data().Get_Student_Code() == "102200264")
// 	//	 cout << p->Get_Data().Get_Name()<<endl;
// 	// p = p->Get_Next();
//  //}
// 	/*for (unsigned i = 0; i < list.size(); i++)
// 	{
// 		cout << list.at(i)<<endl;
// 	}*/
// 		//102200211 102200222 102200264
//	int s = 0;
//	 for (unsigned i = 0; i < list.size(); i++)
//	{
//		 int count = 0;
//		 for (unsigned j = 0; j < list_1.size(); j++)
//		 {
//			 if (list.at(i) == list_1.at(j)) count++;
//		 }
//		 cout << list.at(i) << "  " << count << endl;
//		 s += count;
//}
// 	//while (p != nullptr)
// 	//	{

// 	//	    if (p->Get_Data().Get_Room_Code()=="  ")
// 	//	   	 cout << p->Get_Data().Get_Name()<<endl;
// 	//	    p = p->Get_Next();
// 	//	}
	/* cout << s;*/
// 	//Database.file_1();
 _getch();
    return 0;
}

