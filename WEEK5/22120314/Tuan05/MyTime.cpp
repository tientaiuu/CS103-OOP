#include "mytime.h"

// Constructors
CMyTime::CMyTime() : m_Hour(0), m_Minute(0), m_Second(0) {}
CMyTime::CMyTime(const CMyTime& other) : m_Hour(other.m_Hour), m_Minute(other.m_Minute), m_Second(other.m_Second) {}
CMyTime::CMyTime(int hour, int minute, int second) : m_Hour(hour), m_Minute(minute), m_Second(second) {}

// Methods
void CMyTime::Input(string& filename) {
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        inputFile >> this->m_Hour >> this->m_Minute >> this->m_Second;
        inputFile.close();
    }
    else {
        cout << "Error opening file." << endl;
    }
}


void CMyTime::Output(string& filename) {
    ofstream outputFile(filename,  ofstream::app);
    if (outputFile.is_open()) {
        outputFile << this->m_Hour << ":" << this->m_Minute << ":" << this->m_Second << endl;
        outputFile.close();
    }
    else {
        cout << "Error opening file." << endl;
    }
}

void CMyTime::OutputTime()
{
    cout << this->m_Hour << ":" << this->m_Minute << ":" << this->m_Second << endl;
}

void CMyTime::Output(ofstream& fout)
{
    fout << this->m_Hour << ":" << this->m_Minute << ":" << this->m_Second << endl;
}
// Operators
CMyTime CMyTime::operator++() 
{
    ++this->m_Second;
    if (this->m_Second >= 60)
    {
        this->m_Second = 0;
        ++this->m_Minute;
        if (this->m_Minute >= 60)
        {
            this->m_Minute = 0;
            ++this->m_Hour;
            if (this->m_Hour >= 24)
            {
                this->m_Hour = 0;
            }
        }
    }
    return *this;
}

CMyTime CMyTime::operator--()
{
    --this->m_Minute;
    if (this->m_Minute < 0)
    {
        this->m_Minute = 59;
        --this->m_Hour;
        if (this->m_Hour < 0) 
        {
            this->m_Hour = 23;
        }
    }
    return *this;
}

CMyTime CMyTime::operator+=(int hours) 
{
    this->m_Hour += hours;
    if (this->m_Hour >= 24)
    {
        int days = this->m_Hour / 24;
        this->m_Hour %= 24;
    }
    return *this;
}

CMyTime CMyTime::operator-=(int hours)
{
    this->m_Hour -= hours;
    if (this->m_Hour < 0) {
        int days = (-this->m_Hour + 23) / 24;
        this->m_Hour += (days * 24);
    }
    return *this;
}

CMyTime CMyTime::operator+(const CMyTime& other)  
{
    CMyTime result(*this);
    result.m_Hour += other.m_Hour;
    result.m_Minute += other.m_Minute;
    result.m_Second += other.m_Second;

    if (result.m_Second >= 60) {
        result.m_Second -= 60;
        ++result.m_Minute;
    }
    if (result.m_Minute >= 60) {
        result.m_Minute -= 60;
        ++result.m_Hour;
    }
    if (result.m_Hour >= 24) {
        result.m_Hour -= 24;
    }

    return result;
}

CMyTime CMyTime::operator-(const CMyTime& other)  {
    CMyTime result(*this);
    result.m_Hour -= other.m_Hour;
    result.m_Minute -= other.m_Minute;
    result.m_Second -= other.m_Second;
        
    if (result.m_Second < 0) {
        result.m_Second += 60;
        --result.m_Minute;
    }
    if (result.m_Minute < 0) {
        result.m_Minute += 60;
        --result.m_Hour;
    }
    if (result.m_Hour < 0) {
        result.m_Hour += 24;
    }

    return result;
}

bool CMyTime::operator>(const CMyTime& other)  {
    if (this->m_Hour != other.m_Hour)
        return this->m_Hour > other.m_Hour;
    else if (this->m_Minute != other.m_Minute)
        return this->m_Minute > other.m_Minute;
    else
        return this->m_Second > other.m_Second;
}

bool CMyTime::operator<(const CMyTime& other)  {
    return !(*this > other || *this == other);
}

bool CMyTime::operator>=(const CMyTime& other)  {
    return (*this > other || *this == other);
}

bool CMyTime::operator<=(const CMyTime& other)  {
    return !(*this > other);
}

bool CMyTime::operator==(const CMyTime& other)  {
    return (this->m_Hour == other.m_Hour && this->m_Minute == other.m_Minute && this->m_Second == other.m_Second);
}
