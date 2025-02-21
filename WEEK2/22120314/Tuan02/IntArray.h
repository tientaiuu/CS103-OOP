#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

class CIntArray
{
private:
	int m_Length;
	int* m_Array;
public:
	CIntArray();
	CIntArray(int length);
	CIntArray(const CIntArray& otherArray);
	~CIntArray();

	void InputArray();
	void OutputArray();

	CIntArray Remove();
	CIntArray Remove(int x);
	CIntArray Remove(int n, int k);

	CIntArray Replace(int x, int newX);

	CIntArray AddHead(int x);
	CIntArray AddTail(int x);

	CIntArray Insert(int x, int k);

	int Max();
	int Min();

	CIntArray Ascending();
	CIntArray Descending();

	bool IsSymmetry();

	CIntArray MoveForward();
	CIntArray MoveForward(int n);

	CIntArray MoveBeHind();
	CIntArray MoveBeHind(int n);

	CIntArray Invert();

	int Appearance(int x);

};

