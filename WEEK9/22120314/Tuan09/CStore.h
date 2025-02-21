#pragma once
#include "CProduct.h"
#include "CElectronic.h"
#include "CFood.h"
#include "CTerracotta.h"

class CStore
{
private:
    vector<CProduct*> m_products;
public:

    void Input();
    void Output();
    void ViewExpDate();
    void Delete();
    void Buy();
    void ViewQuantity();
};