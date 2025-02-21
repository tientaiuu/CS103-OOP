#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <codecvt>
#include <locale>
#include <unordered_map>
using namespace std;

class CMyDate {
private:
	int day;
	int month;
	int year;
public:
	CMyDate() {
		day = month = year = 0;
	}

	CMyDate(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}

	CMyDate(const CMyDate& other) {
		day = other.day;
		month = other.month;
		year = other.year;
	}

	friend ostream& operator << (ostream& os, CMyDate a) {
		os << setw(2) << setfill('0') << a.day << "/" << setw(2) << setfill('0') << a.month << "/" << a.year;
		return os;
	};

	friend istream& operator >> (istream& is, CMyDate& a) {
		is >> a.day;
		is.ignore();
		is >> a.month;
		is.ignore();
		is >> a.year;
		return is;
	};

	bool operator <(CMyDate other) {
		if (year < other.year) return 1;
		if (year > other.year) return 0;

		if (month < other.month) return 1;
		if (month > other.month) return 0;

		return day < other.day;
	}
	bool operator >(CMyDate other) {
		if (year > other.year) return 1;
		if (year < other.year) return 0;

		if (month > other.month) return 1;
		if (month < other.month) return 0;

		return day > other.day;
	}
	bool operator == (CMyDate other) {
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

class CEmployee
{
protected:
	string m_ID;
	string m_Department;
	string m_Name;
	CMyDate m_Birthday;
	string m_Address;	
	float m_WageCoefficient;
public:
	CEmployee();
	CEmployee(string id, string department, string name, CMyDate birthday, string address, float wageCoef);
	CEmployee(const CEmployee& other);

	virtual void Output(ofstream& output);

	string getID() const
	{
		return m_ID;
	}

	string getDepartment() const
	{
		return m_Department;
	}

	string getName() const
	{
		return m_Name;
	}

	CMyDate getBirthday() const
	{
		return m_Birthday;
	}

	string getAddress() const
	{
		return m_Address;
	}

	float getWageCoefficient() const
	{
		return m_WageCoefficient;
	}

	int getAge() const
	{
		time_t Time = time(0);

		tm* Now = localtime(&Time);
		return Now->tm_year + 1900 - m_Birthday.getYear();
	};

};

class CManager : public CEmployee
{
public:
	using CEmployee::CEmployee;
};

class CProgrammer : public CEmployee
{
private:
	float m_OvertimePay;
public:
	CProgrammer(string id, string department, string name, CMyDate birthday, string address, float wageCoef, float ovt);

	float getOvtPay()
	{
		return m_OvertimePay;
	}
};

class CDesigner : public CEmployee
{
private:
	float m_Bonus;
public:
	CDesigner(string id, string department, string name, CMyDate birthday, string address, float wageCoef, float bonus);

	float getBonus()
	{
		return m_Bonus;
	}
};

class CTester : public CEmployee
{
private:
	float m_Error;
public:
	CTester(string id, string department, string name, CMyDate birthday, string address, float wageCoef, float error);

	float getError()
	{
		return m_Error;
	}
};

class CCompany
{
private:
	vector<CEmployee*> Employees;
public:

	~CCompany();

	void Input();
	void Output();

	float Salary();
	void Search();
	void SortYearOld();
};

