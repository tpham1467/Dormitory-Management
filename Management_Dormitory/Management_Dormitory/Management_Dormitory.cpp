#include <iostream>
#include"Management_Student.h"
#include"Giao_dien.h"
int main()
{ 
	//Menu_chinh();
	Management_Student Database;
	//Database.Find_Student("Pham Van Tien Truong");
	Menu_chinh(Database);
	//Database.Find_Student("pham");
	_getch();
    return 0;
}

