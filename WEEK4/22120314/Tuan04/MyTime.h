#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class CMyTime
{
private:
    int m_Hour;
    int m_Minute;
    int m_Second;

public:
    // Constructors
    CMyTime();
    CMyTime(const CMyTime& other);
    CMyTime(int hour, int minute, int second);

    // Methods
    void Input(string& filename);
    void Output(string& filename);

    void OutputTime();

    // Operators
    CMyTime operator++();
    CMyTime operator--();
    CMyTime operator+=(int hours);
    CMyTime operator-=(int hours);
    CMyTime operator+(const CMyTime& other) ;
    CMyTime operator-(const CMyTime& other) ;
    bool operator>(const CMyTime& other) ;
    bool operator<(const CMyTime& other) ;
    bool operator>=(const CMyTime& other) ;
    bool operator<=(const CMyTime& other) ;
    bool operator==(const CMyTime& other) ;
};

