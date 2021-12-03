#include <iostream>
#include<string>
#include <cstdlib>
#include <ctime>
// #include"management_room.h"
//#include"management_student.h"
//#include"Date.h"
//#include <fstream>
//#include"Management.h"
////#include"Doubly_Linked_List.h"
////#include <algorithm>
////#include"Management.h"
////#include"Doubly_Linked_List.h"
////#include <algorithm>
//#include"Management_Room.h"
//#include<sstream>
//#include<vector>
#include"Thong_Ke.h"
using namespace std;
int main()
{
   
    Thong_Ke tk;
    Khoi_tao();
    vector<int> v1 = {100,50,20,100,200,700};
    vector<string> v2 = { "CNTT","Hoa","QLDA","Dien Tu","Dien Lanh","Dien Tu Vien Thong"};
    tk.Draw_Column_Chart(v1,v2,"Bieu Do Cot Danh Sach Sinh Vien Cac Khoa","So Sinh Vien","Khoa");
    _getch();
    return 0;
}

