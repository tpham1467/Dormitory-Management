#include <iostream>
#include<string>
#include <cstdlib>
#include <ctime>
// #include"management_room.h"
//#include"Management_Student.h"
#include"Date.h"
#include <fstream>
//#include"Management.h"
//#include"Doubly_Linked_List.h"
//#include <algorithm>
#include"Management_Room.h"
#include<sstream>
#include<vector>
using namespace std;
typedef pair<int, int> ll;
typedef pair<int, string > list;
int main()
{ 
    Mamagement_Room data;
    Management_Student data_s;
    data_s.Read_File();
    data.Draw_Info_Object(data_s);
    return 0;
}

