#pragma once

#include "CProduct.h"


class CElectronic : public CProduct
{
private:
    string m_Warranty;
    string m_ElectricPower;
public:
    void Input();
    void Output();

    string getWarranty() const
    {
        return m_Warranty;
    }

    string getElecPower() const
    {
        return m_ElectricPower;
    }
};