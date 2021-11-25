#include <iostream>
#include<string>
#include <cstdlib>
#include <ctime>
// #include"management_room.h"
//#include"Management_Student.h"
#include"Date.h"
#include <fstream>
<<<<<<< HEAD
#include"Management.h"
//#include"Doubly_Linked_List.h"
//#include <algorithm>
=======
//#include"Management.h"
//#include"Doubly_Linked_List.h"
//#include <algorithm>
#include"Management_Room.h"
>>>>>>> 719b41b9401dc152faff1cb55369e2c10e7f101d
#include<sstream>
#include<vector>
using namespace std;
typedef pair<int, int> ll;
typedef pair<int, string > list;
int main()
<<<<<<< HEAD
{
    Management data;
    data.Menu_chinh();
=======
{ 
    Mamagement_Room data;
    Management_Student data_s;
    data_s.Read_File();
    data.Draw_Info_Object(data_s);
>>>>>>> 719b41b9401dc152faff1cb55369e2c10e7f101d
    return 0;
}

