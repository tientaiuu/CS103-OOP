#pragma once
#include "CProduct.h"


class CTerracotta : public CProduct
{
private:
    string m_Material;
public:

    void Input();
    void Output();

    string getMaterial() const
    {
        return m_Material;
    }
};