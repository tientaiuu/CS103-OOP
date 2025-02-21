#include "CElectronic.h"

void CElectronic::Input()
{
	CProduct::Input();
	getline(cin, m_Warranty,',');
	getline(cin, m_ElectricPower,',');

	cin >> m_Quantity;
	cin.ignore();
	cin.ignore();

}

void CElectronic::Output()
{
	CProduct::Output();
	// cout << m_Warranty << ", " << m_ElectricPower << " .";
}