#include "CProduct.h"

CProduct::CProduct()
{
	m_Code = "";
	m_Name = "";
	m_Producer = "";
	m_Price = 0;
	m_Quantity = 0;
}

void CProduct::Input()
{
	getline(cin, m_Code , ' ');
	cin.ignore();
	getline(cin, m_Name, ',');	
	getline(cin, m_Producer, ',');

	cin >> m_Price;
	cin.ignore();
}

void CProduct::Output()
{
	cout << m_Name << "," << m_Producer << ", " << m_Price << ", " << m_Quantity << ".";
}

