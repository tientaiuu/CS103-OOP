#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class CCatalogue
{
protected:
    string m_ID;        // Mã số
    string m_Title;     // Tiêu đề
    string m_Author;    // Tác giả
    int m_Count;        // Số lần mượn

public:
    CCatalogue(string id, string title, string author, int count);

    virtual void Output(ofstream& output) = 0;

    string GetID() const
    {
        return m_ID;
    }

    virtual string GetYear() const = 0;

    int GetCount() const
    {
        return m_Count;
    }
};

class CPaper : public CCatalogue {
private:
    string m_Journal;   // Tên tạp chí đăng bài báo
    string m_Year;      // Năm đăng

public:
    CPaper(string id, string title, string author, int count, string journal, string year);


    void Output(ofstream& output);

    string GetYear() const {
        return m_Year;
    }

};

class CBook : public CCatalogue {
private:
    string m_Publisher; // Nhà xuất bản
    string m_Version;   // Phiên bản
    string m_Year;      // Năm xuất bản

public:
    CBook(string id, string title, string author, int count, string publisher, string version, string year);

    void Output(ofstream& output);

    string GetYear() const {
        return m_Year;
    }
};

class CThesis : public CCatalogue 
{
private:
    string m_School;    // Trường
    string m_Faculty;   // Khoa
    string m_Year;      // Năm hoàn thành khóa luận

public:
    CThesis(string id, string title, string author, int count, string school, string faculty, string year);

    void Output(ofstream& output);

    string GetYear() const {
        return m_Year;
    }
};

class CLibrary
{
private:
    vector<CCatalogue*> Library;

public: 
    ~CLibrary();

    void Input();
    void Output();

    void Delete();
    void SortYear();
    void SortCount();
};



