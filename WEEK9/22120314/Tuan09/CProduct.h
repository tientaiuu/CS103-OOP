#pragma once
#include "CMyDate.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

class CProduct
{
protected:
    string m_Code;
    string m_Name;
    string m_Producer;
    int m_Price;
    int m_Quantity;
public:
    CProduct();
    virtual void Input();
    virtual void Output();

    string getCode() const
    {
        return m_Code;
    }

    string getName() const
    {
        return m_Name;
    }

    string getProducer() const
    {
        return m_Producer;
    }

    int getPrice() const
    {
        return m_Price;
    }

    int getQuantity() const
    {
        return m_Quantity;
    }

    void setQuantity(int quantity) { m_Quantity = quantity; }

};



