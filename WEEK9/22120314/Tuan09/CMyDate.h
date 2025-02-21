#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class CMyDate
{
private:
    int day;
    int month;
    int year;
public:
    CMyDate()
    {
        day = month = year = 0;
    }

    CMyDate(int d, int m, int y) 
    {
        day = d;
        month = m;
        year = y;
    }

    CMyDate(const CMyDate& other) 
    {
        day = other.day;
        month = other.month;
        year = other.year;
    }



    void Output()
    {
        cout << setw(2) << setfill('0') << day << "/" << setw(2) << setfill('0') << month << "/" << year;
    }

    friend std::ostream& operator<<(std::ostream& os, const CMyDate& a) {
        os << std::setw(2) << std::setfill('0') << a.day << "/" << std::setw(2) << std::setfill('0') << a.month << "/" << a.year;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, CMyDate& a) {
        char discard;
        is >> a.day >> discard >> a.month >> discard >> a.year;
        return is;
    }

    bool operator <(CMyDate other)
    {
        if (year < other.year) return 1;
        if (year > other.year) return 0;

        if (month < other.month) return 1;
        if (month > other.month) return 0;

        return day < other.day;
    }
    bool operator >(CMyDate other)
    {
        if (year > other.year) return 1;
        if (year < other.year) return 0;

        if (month > other.month) return 1;
        if (month < other.month) return 0;

        return day > other.day;
    }
    bool operator == (CMyDate other) 
    {
        return day == other.day && month == other.month && year == other.year;
    }

    int getYear() const
    {
        return year;
    }

    int getMonth() const
    {
        return month;
    }
    int getDay() const
    {
        return day;
    }
};