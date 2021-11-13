#pragma once
#include"Profile.h"
#include<string>
using namespace std;
class Residency_Profile
{
private:
	string Expiration_Date;
public:
	Residency_Profile();
	~Residency_Profile();
	void Pay();
	void Extend();
};

