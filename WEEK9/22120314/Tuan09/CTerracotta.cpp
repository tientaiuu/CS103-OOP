#include "CTerracotta.h"

void CTerracotta::Input()
{
	CProduct::Input();
	getline(cin, m_Material,',');
	cin >> m_Quantity;
	cin.ignore();
	cin.ignore();

}

void CTerracotta::Output()
{
	CProduct::Output();
	//cout << m_Material << " .";
}