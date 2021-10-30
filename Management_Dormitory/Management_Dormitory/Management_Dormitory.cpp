#include <iostream>
#include"Management_Student.h"
#include"Giao_dien.h"
#include <algorithm>
using namespace std;
int main()
{ 
	//Menu_chinh();
	Management_Student Database;
	//Database.Find_Student("Pham Van Tien Truong");
	Menu_chinh(Database);
	//Database.Find_Student("pham");
	/*Node<Student>* p =Database.Get_List_Student().Get_P_Head();
	vector<string> list;
	while (p != nullptr)
	{
		list.push_back(p->Get_Data().Get_Student_Code());
		p = p->Get_Next();
	}
	cout << list.size()<<endl;
	sort(begin(list), end(list));
	list.erase(unique(begin(list), end(list)), end(list));
	cout << list.size() << endl;
	while (list.size() != 0)
	{
		cout << list.back() << endl;
		list.pop_back();
	}*/
	_getch();
    return 0;
}

