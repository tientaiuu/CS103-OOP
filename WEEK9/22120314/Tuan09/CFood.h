#pragma once
#include "CProduct.h"


class CFood : public CProduct
{
private:
    CMyDate m_MfgDate;
    CMyDate m_ExpDate;
public:

    void Input();
    void Output();

    CMyDate getMfg() const
    {
        return m_MfgDate;
    }

    CMyDate getExp() const
    {
        return m_ExpDate;
    }
};