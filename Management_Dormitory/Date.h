#pragma once
#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#include <ctime>
#include<sstream>
using namespace std;
namespace 
{
    char  month_table[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    char  leap_month_table[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
}
//check leap year or not
#define IS_LEAP_YEAR(year) ((year%400 == 0) || (year%4 == 0 && year%100 != 0))?   true : false

class CDate
{
private:
    int day;
    int month;
    int year;
public:
    CDate(int d = 0, int m = 0, int y = 0) : day(d), month(m), year(y)
    {
    }
    ~CDate()
    {
    }
    CDate(const CDate& _cdate)
    {
        this->day = _cdate.day;
        this->month = _cdate.month;
        this->year = _cdate.year;
    }
    bool validDate()
    {
        // validate dd/mm/yyyy
        if (year < 1 || year > 9999 ||
            month < 1 || month > 12 ||
            day < 1 || day > 31)
        {
            return false;
        }

        if (IS_LEAP_YEAR(year))
        {
            if (day > leap_month_table[month - 1])
            {
                return false;
            }
        }
        else
        {
            if (day > month_table[month - 1])
            {
                return false;
            }
        }
        return true;
    }
    string Get_String()
    {
        string _Date= to_string(this->day) +'/'+ to_string(this->month)+'/'+
            to_string(this->year);
        return _Date;
    }
    void Set_Day(const int& _day)
    {
        this->day = _day;
    }
    const int Get_Day()
    {
        return this->day;
    }
    void Set_month(const int& _month)
    {
        this->month = _month;
    }
    const int Get_month()
    {
        return this->month;
    }
    void Set_year(const int& _year)
    {
        this->year = _year;
    }
    const int Get_year()
    {
        return this->year;
    }
    CDate Get_time()
    {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        CDate _Date;
        _Date.year = 1900 + ltm->tm_year;
        _Date.month = 1 + ltm->tm_mon;
        _Date.day = ltm->tm_mday;
        return _Date;
    }
    CDate& operator=(const CDate& _cdate)
    {
        this->day = _cdate.day;
        this->month = _cdate.month;
        this->year = _cdate.year;
        return *this;
    }
    int TTngay()
    {
        int ngaynam[2][12] = { {31,29,31,30,31,30,31,31,30,31,30,31},{31,28,31,30,31,30,31,31,30,31,30,31} };
        int i;
        int s = this->day;
        if (this->year % 4 == 0 && this->year % 100 != 0 || this->year % 400 == 0) i = 0;
        else i = 1;
        for (int j = 0; j < this->month - 1; j++)  s += ngaynam[i][j];
        return s;
    }
    int songay(int y)
    {
        if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) return 365;
        return 366;
    }
    int operator-(CDate& _cdate)
    {
        int d1 = this->TTngay();
        int d2 = _cdate.TTngay();
        if (this->year == _cdate.year) return(abs(d1 - d2));
        int s = 0;
        if (this->year < _cdate.year)
        {
            d1 = songay(this->year) - d1;
            for (int i = this->year + 1; i < _cdate.year; i++) s += songay(i);
            return(s + d1 + d2);
        }
        else
        {
            d2 = songay(_cdate.year) - d2;
            for (int i = _cdate.year + 1; i < this->year; i++) s += songay(i);
            return(s + d1 + d2);
        }

    }
    void operator+(int x)
    {
        x = x * 30;
        int k = this->day + x;
        do {
            switch (this->month)
            {
            case 1:case 3:case 5: case 7:case 8: case 10: case 12:
                if (k > 31)
                {
                    this->month++;
                    if (this->month == 13)
                    {
                        this->month = 1;
                        this->year++;
                    }
                    k -= 31;
                }
                else
                {
                    this->day = k;
                    k = 0;
                }
                break;
            case 4:case 6: case 9: case 11:
                if (k > 30)
                {
                    this->month++;
                    k -= 30;
                }
                else
                {
                    this->day = k;
                    k = 0;
                }
                break;
            case 2:
                if (this->year % 400 == 0 || (this->year % 4 == 0 && this->year % 100 != 0))
                {
                    if (k > 29)
                    {
                        this->month++;
                        k -= 29;
                    }
                    else
                    {
                        this->day = k;
                        k = 0;
                    }
                }
                else
                {
                    if (k > 28)
                    {
                        this->month++;
                        k -= 28;
                    }
                    else
                    {
                        this->day = k;
                        k = 0;
                    }
                }
                break;
            }
        } while (k > 0);
    }
    CDate& To_CDate(string s)
    {
        CDate _c;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '/')
            {
                s[i]=' ';
            }
        }
        stringstream s1(s);

        s1 >> _c.day;
        s1 >> _c.month;
        s1 >> _c.year;
        return _c;

   }
   
};