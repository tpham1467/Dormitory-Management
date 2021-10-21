#pragma once
#include<string>
#include<iostream>
using namespace std;
class Person
{
public:
    Person() { this->name_ = ""; };
    Person(std::string name, unsigned int age, bool sex);
    ~Person() { ; };
    void operator =(Person& p);
    std::string get_name() const { return name_; }
    unsigned int get_age() const { return age_; }
    bool get_sex() const { return sex_; }

    void ShowInfo()
    {
        std::cout << "  Name = " << name_.c_str();
        std::cout << "  Age = " << age_;
        std::cout << "  Sex = " << ((sex_ == 1) ? "Male" : "Female");
    }
private:
    std::string name_;
    unsigned int age_;
    bool sex_;
};

Person::Person(std::string name, unsigned int age, bool sex)
{
    name_ = name;
    age_ = age;
    sex_ = sex;
}

void Person::operator =(Person& p) //Lưu ý là khi xây dựng các lơp đối tượng, hãy dựng các phép toán cho lớp.
{
    this->name_ = p.name_;
    this->age_ = p.age_;
    this->sex_ = p.sex_;
}

