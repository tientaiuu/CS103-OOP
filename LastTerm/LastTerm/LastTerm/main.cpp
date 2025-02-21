#include <iostream>
#include <string>
#include <vector>
using namespace std;

//-------------------- Lớp Project ---------------------
class Project
{
protected:
    string name;
public:
    Project();
    virtual long grantMoney();
    virtual void print() = 0;
};

Project::Project()
{
    name = " ";
}

long Project::grantMoney()
{
    //Để cho có
    return 1;
}

//-------------------- Lớp Idea ---------------------
class Idea : public Project
{
private:
    int growth;
public:
    Idea(string, int);
    long grantMoney();
    void print();
};

Idea::Idea(string nam, int gro)
{
    name = nam;
    growth = gro;
}

long Idea::grantMoney()
{
    return growth * 20000000;
}

void Idea::print()
{
    cout << "Y tuong: " << name << ". " << "Phat trien: " << growth << " thang. ";
    cout << "Kinh phi: " << grantMoney();
    cout << endl;
}

//-------------------- Lớp Mvp ---------------------
class Mvp : public Project
{
private:
    int operation;
    int marketing;
public:
    Mvp(string, int, int);
    long grantMoney();
    void print();
};

Mvp::Mvp(string nam, int ope, int mar)
{
    name = nam;
    operation = ope;
    marketing = mar;
}

long Mvp::grantMoney()
{
    return (operation + marketing) * 15000000;
}

void Mvp::print()
{
    cout << "San pham: " << name << ". " << "Van hanh: " << operation << " thang. ";
    cout << "Marketing: " << marketing << "thang. ";
    cout << "Kinh phi: " << grantMoney();
    cout << endl;
}

int main()
{
    cout << "Chương trình hỗ trợ Hackathon của AlphaTech tháng 6/2023" << endl;
    vector<Project*> projects = { // Bỏ qua tiềm ẩn rò rỉ vùng nhớ
        new Idea("SuperTech", 6),
        new Mvp("FutureCar", 6, 3),
        new Idea("VirtualHouse", 7),
        new Idea("NightVision", 4),
        new Mvp("SmartKey", 4, 5)
    };
    cout << "Số dự án: " << projects.size() << endl;
    int sum = 0;
    for (int i = 0; i < projects.size(); i++) {
        sum += projects[i]->grantMoney();
        cout << i + 1 << ".";
        projects[i]->print();
        cout << endl;
    }
    cout << "Tổng tiền tài trợ:" << sum;
    return 0;
}
