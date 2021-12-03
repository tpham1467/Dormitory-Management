#include "Thong_Ke.h"
#include<cmath>
#include<string>
void Thong_Ke::Draw_Column_Chart(vector<int> value,vector<string> value_s,string name,string name_col,string name_row)
{
	int k = 5;
	vector<int>::iterator min = min_element(begin(value), end(value));
	vector<int>::iterator max = max_element(begin(value), end(value));
	int next;
	string next_s = to_string(*max);
	string max_s = next_s;
	max_s[0] = next_s[0];
	for (int i = 1; i < next_s.size(); i++)
	{
		max_s[i] = '0';
	}
	next = stoi(max_s);
	if (next < *max)
	{
		max_s[0] = next_s[0] + 1;
		next = stoi(max_s);
	}
	next = next / (int(max_s[0] - 48));
	for (int i = 10; i < 30; i++)
	{
		Outchar(60, i, 15, 0, (char)179);
	}
	for (int i = 60; i < 155; i++)
	{
		Outchar(i, 29, 15, 0, (char)196);
	}
	Outchar(60, 29, 15, 0, (char)192);
	int v = stoi(max_s);
	while (v > 3000)
	{
		k--;
		v -= 1000;
	}
	while (v > 400)
	{
		k--;
		v -= 100;
	}
	for (int i = 1; i <= stoi(max_s) / next; i++)
	{
		Outchar(60, 29 - i * k, 15, 0, (char)197);
		Outint(55, 29 - i * k, 15, 0, next * i);
	}
	int z = next / k;
	for (int i = 0; i < value.size(); i++)
	{
		int y = 29;
		int y0 = 0;
		while (y0 <= value[i])
		{
			y--; y0 += z;
		}
		Hcn(65 + i * 13, y, 65 + i * 13 + 4, 29, 0);
		Outint(65 + i * 13 +2, y - 1, 15, 0, value[i]);
		Outstring(65 + i * 13 - 2, 30, 15, 0, value_s[i]);
	}
	Outstring(68, 33, 15, 0, name);
	Outchar(155, 29, 15, 0, '>');
	int x = 59;
	for(int i=0;i<name_col.size();i++)
	{
		Outchar(x--, 11 , 15, 0, name_col[name_col.size()-i-1]);
	}
	x = 160;
	for (int i = 0; i < name_row.size(); i++)
	{
		Outchar(x--, 30, 15, 0, name_row[name_row.size() - i - 1]);
	}
	Outstring(68, 31, 15, 0, name_row);
}
	
