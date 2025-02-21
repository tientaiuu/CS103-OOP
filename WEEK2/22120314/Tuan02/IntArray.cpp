#include "IntArray.h"



CIntArray::CIntArray()
{
	this->m_Array = NULL;
	this->m_Length = 0;
}


CIntArray::~CIntArray()
{
	delete[] this->m_Array;
}

CIntArray::CIntArray(const CIntArray& otherArray)
{
	this->m_Length = otherArray.m_Length;
	this->m_Array = new int[this->m_Length];
	for (int i = 0; i < this->m_Length; i++)
	{
		this->m_Array[i] = otherArray.m_Array[i];
	}
}

CIntArray::CIntArray(int length)
{
	this->m_Length = length;
	this->m_Array = new int[this->m_Length];
}

void CIntArray::InputArray()
{
	cout << "Input Array: ";
	for (int i = 0; i < this->m_Length; i++)
	{
		cin >> this->m_Array[i];
	}
}

void CIntArray::OutputArray()
{
	cout << "Output Array: ";
	for (int i = 0; i < this->m_Length; i++)
	{
		cout << this->m_Array[i] << " ";
	}
	cout << endl;
}

CIntArray CIntArray::Remove()
{

	int newSize = 1;
	for (int i = 1; i < this->m_Length; ++i) 
	{
		int j;
		for (j = 0; j < newSize; ++j) 
		{
			if (this->m_Array[i] == this->m_Array[j])
				break;
		}
		if (j == newSize)
		{
			this->m_Array[newSize] = this->m_Array[i];
			newSize++;
		}
	}
	this->m_Length = newSize;
	return *this;
}

CIntArray CIntArray::Remove(int x)
{
	if (x >= 0 && x < this->m_Length) 
	{
		for (int i = x; i < this->m_Length - 1; ++i) 
		{
			this->m_Array[i] = this->m_Array[i + 1];
		}
		this->m_Length--;
	}
	return *this;
}

CIntArray CIntArray::Remove(int n, int k)
{
	if (k >= 0 && k + n <= this->m_Length) 
	{
		for (int i = k; i < this->m_Length - n; ++i) 
		{
			this->m_Array[i] = this->m_Array[i + n];
		}
		this->m_Length -= n;
	}
	return *this;
}

CIntArray CIntArray::Replace(int x, int newX)
{
	for (int i = 0; i < this->m_Length; ++i)
	{
		if (this->m_Array[i] == x)
		{
			this->m_Array[i] = newX;
		}
	}
	return *this;
}

CIntArray CIntArray::AddHead(int x)
{
	int* newArray = new int[this->m_Length + 1];
	newArray[0] = x;
	for (int i = 0; i < this->m_Length; i++) 
	{
		newArray[i + 1] = this->m_Array[i];
	}
	delete[] this->m_Array;
	this->m_Array = newArray;
	this->m_Length++;
	return *this;
}

CIntArray CIntArray::AddTail(int x)
{
	int* newArray = new int[this->m_Length + 1];
	for (int i = 0; i < this->m_Length; i++)
	{
		newArray[i] = this->m_Array[i];
	}
	newArray[this->m_Length] = x;
	delete[] this->m_Array;
	this->m_Array = newArray;
	this->m_Length++;
	return *this;

}

CIntArray CIntArray::Insert(int x, int k)
{
	if (k >= this->m_Length)	
		k = this->m_Length;
	else if (k <= 0) 
		k = 0;

	for (int i = this->m_Length; i > k; --i)
	{
		this->m_Array[i] = this->m_Array[i - 1];
	}
	this->m_Array[k] = x;
	this->m_Length++;

	return *this;
}

int CIntArray::Min()
{
	if (this->m_Length == 0)
		return -1;

	int min = this->m_Array[0];
	for (int i = 0; i < this->m_Length; ++i)
	{
		if (min > this->m_Array[i])
		{
			min = this->m_Array[i];
		}
	}
	return min;
}

int CIntArray::Max()
{
	if (this->m_Length == 0)
		return -1;

	int max = this->m_Array[0];
	for (int i = 0; i < this->m_Length; ++i)
	{
		if (max < this->m_Array[i])
		{
			max = this->m_Array[i];
		}
	}
	return max;
}

CIntArray CIntArray::Ascending()
{
	for (int i = 0; i < this->m_Length - 1; ++i)
	{
		for (int j = 0; j < this->m_Length - i - 1; ++j)
		{
			if (this->m_Array[j] > this->m_Array[j + 1])
			{
				int temp = this->m_Array[j];
				this->m_Array[j] = this->m_Array[j + 1];
				this->m_Array[j + 1] = temp;
			}
		}
	}
	return*this;
}

CIntArray CIntArray::Descending()
{
	for (int i = 0; i < this->m_Length - 1; ++i)
	{
		for (int j = 0; j < this->m_Length - i - 1; ++j)
		{
			if (this->m_Array[j] < this->m_Array[j + 1])
			{
				int temp = this->m_Array[j];
				this->m_Array[j] = this->m_Array[j + 1];
				this->m_Array[j + 1] = temp;
			}
		}
	}
	return*this;
}

bool CIntArray::IsSymmetry() 
{
	for (int i = 0; i < this->m_Length / 2; ++i)
	{
		if (this->m_Array[i] != this->m_Array[this->m_Length - i - 1])
			return false;
	}
	return true;
}

CIntArray CIntArray::MoveForward()
{
	int firstValue = this->m_Array[0];
	for (int i = 0; i < this->m_Length - 1; i++)
	{
		this->m_Array[i] = this->m_Array[i +1];
	}
	this->m_Array[this->m_Length -1] = firstValue;
	return	*this;
}

CIntArray CIntArray::MoveForward(int n)
{
	for (int i = 0; i < n; i++)
	{
		this->MoveForward();
	}
	return *this;
}

CIntArray CIntArray::MoveBeHind()
{
	int lastValue = this->m_Array[this->m_Length - 1];
	for (int i = this->m_Length - 1; i > 0; i--)
	{
		this->m_Array[i] = this->m_Array[i - 1];
	}
	this->m_Array[0] = lastValue;
	return	*this;
}

CIntArray CIntArray::MoveBeHind(int n)
{
	for (int i = 0; i < n; i++)
	{
		this->MoveBeHind();
	}
	return *this;
}

CIntArray CIntArray::Invert()
{
	int* newArray = new int[this->m_Length];

	for (int i = 0; i < this->m_Length; ++i) {
		newArray[i] = this->m_Array[this->m_Length - 1 - i];
	}

	delete[] this->m_Array;

	this->m_Array = newArray;

	return *this;
}

int CIntArray::Appearance(int x)
{
	int count = 0;
	for (int i = 0; i < this->m_Length; i++)
	{
		if (this->m_Array[i] == x)
		{
			count++;
		}
	}
	return count;
}