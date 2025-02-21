#pragma once
#include "mytime.h"
#include "Date.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

class CMessage
{
private: 
	string m_Number;
	int m_Vote;
	CDate m_Date;
	CMyTime m_Time;
public:

	void Input(ifstream& fin);
	void Output(ofstream& fout);

	int GetVote() const {
		return m_Vote;
	}

	string GetPhoneNumBer() const
	{
		return m_Number;
	}

	CDate GetDate() const {
		return m_Date;
	}

	CMyTime GetTime() const {
		return m_Time;
	}
};

class CListMessage
{
private:
	vector<CMessage> m_Message;
	int m_Amount;
public:
	void Input(string& filename);
	void Output(string& filename);	

	int FindCode();
	string FindPhone();
	CDate FindDay();
	CMyTime FindTime();
	void Top10();

};
