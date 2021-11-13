#pragma once
#include <iostream>
#include <string>

using namespace std;

char  month_table[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
char  leap_month_table[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

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
    CDate& operator=(const CDate& _cdate)
    {
        this->day = _cdate.day;
        this->month = _cdate.month;
        this->year = _cdate.year;
        return *this;
    }
};