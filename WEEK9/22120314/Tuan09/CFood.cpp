#include "CFood.h"

void CFood::Input()
{
	CProduct::Input();
	cin >> m_MfgDate;
	cin.ignore();
	cin >> m_ExpDate;
	cin.ignore();
	cin >> m_Quantity;
	cin.ignore();
	cin.ignore();

}

void CFood::Output()
{
	CProduct::Output();
	//cout << m_MfgDate << ", " << m_ExpDate << " .";
}

