#include "Management_Student.h"
#include <fstream>
#include <string>
Management_Student::Management_Student()
{
}

Management_Student::~Management_Student()
{
    this->Database.~Doubly_Linked_List();
}