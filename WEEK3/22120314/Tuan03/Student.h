#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class CStudent
{
private:

	string m_Name;
	string m_Code;
	float m_Math;
	float m_Literature;

public:

	CStudent();
	CStudent(const CStudent& other);
	CStudent(const string& name, const string& code, int math, int literature); 


	friend istream& operator>>(istream &in,  CStudent& student);
	friend ostream& operator<<(ostream& out,  CStudent& student);

	float AverageGrade() const;

	bool operator>(const CStudent& other);
	bool operator>=(const CStudent& other);

	bool operator==(const CStudent& other);

	bool operator<(const CStudent& other);
	bool operator<=(const CStudent& other);

	string GetCode() const {
		return this->m_Code;
	}
	
};

class CClassStudent {
private:
	vector<CStudent*> m_Students;
	int m_Amount;

public:
	CClassStudent();
	~CClassStudent();

	void Input();
	void Output();
	CStudent* Max();
	CStudent* Min();
	void Ascending();
	void Descending();
	void Delete(long id);
	CStudent* Find(long id);
	void Rank();
};