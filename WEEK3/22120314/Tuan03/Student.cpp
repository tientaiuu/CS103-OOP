#include "Student.h"


CStudent::CStudent() : m_Name(""), m_Code(""), m_Math(0.0f), m_Literature(0.0f) {}

CStudent::CStudent(const CStudent& other)
{
	this->m_Name = other.m_Name;
	this->m_Code = other.m_Code;
	this->m_Math = other.m_Math;
	this->m_Literature = other.m_Literature;
}

CStudent::CStudent(const string& name, const string& code, int math, int literature)
{
    this->m_Name = name;
    this->m_Code = code;
    this->m_Math = math;
    this->m_Literature = literature;
}
istream& operator>>(std::istream& in,  CStudent& student) 
 {

     cout << "Name: ";
     getline(in, student.m_Name);
     cout << "Code: ";
     getline(in, student.m_Code);
     cout << "Math: ";
     in >> student.m_Math;
     cout << "Literature: ";
     in >> student.m_Literature;
     return in;
 }

ostream& operator<<(std::ostream& out, CStudent& student)
{
    out << "Name: " << student.m_Name << std::endl;
    out << "Code: " << student.m_Code << std::endl;
    out << "Math: " << student.m_Math << std::endl;
    out << "Literature: " << student.m_Literature << std::endl;
    return out;
}

 float CStudent::AverageGrade() const
 {
     return (this->m_Math + this->m_Literature) / 2.0f;
 }

 bool CStudent::operator>(const CStudent& other)
 {
     return this->AverageGrade() > other.AverageGrade();
 }

 bool CStudent::operator>=(const CStudent& other) 
 {
     return this->AverageGrade() >= other.AverageGrade();
 }
 
 bool CStudent::operator==(const CStudent& other) 
 {
     return this->AverageGrade() == other.AverageGrade();
 }

 bool CStudent::operator<(const CStudent& other) 
 {
     return this->AverageGrade() < other.AverageGrade();
 }

 bool CStudent::operator<=(const CStudent& other)  
 {
     return this->AverageGrade() <= other.AverageGrade();
 }

 CClassStudent::CClassStudent()
 {
     this->m_Amount = 0;
 }

 CClassStudent::~CClassStudent()
 {
     for (CStudent* student : this->m_Students) 
     {
         delete student;
     }
     this->m_Students.clear();
 }

 void CClassStudent::Input()
 {
     int numStudents;
     cout << "Number of students: ";
     cin >> numStudents;
     cin.ignore();

     for (int i = 0; i < numStudents; i++)
     {
         CStudent* student = new CStudent();
         cout << "Enter information for student " << i + 1 << ":" << endl;
         cin >> *student;
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         this->m_Students.push_back(student);
     }

     this->m_Amount = numStudents;
 }
 void CClassStudent::Output() 
 {
     for (int i = 0; i < this->m_Amount; i++)
     {
         cout << "Student " << i + 1 << ":" << endl;
         cout << *this->m_Students[i] << endl;
     }
 }

 CStudent* CClassStudent::Max() 
 {
     if (this->m_Amount == 0) 
     {
         return nullptr;
     }

     CStudent* maxStudent = this->m_Students[0];
     for (int i = 1; i < this->m_Amount; i++)
     {
         if (*this->m_Students[i] > *maxStudent) 
         {
             maxStudent = this->m_Students[i];
         }
     }

     return maxStudent;
 }

 CStudent* CClassStudent::Min() 
 {
     if (this->m_Amount == 0) 
     {
         return nullptr;
     }

     CStudent* minStudent = m_Students[0];

     for (int i = 1; i < this->m_Amount; i++) 
     {
         if (*this->m_Students[i] < *minStudent) 
         {
             minStudent = this->m_Students[i];
         }
     }

     return minStudent;
 }

 void CClassStudent::Ascending()
 {
     for (int i = 0; i < this->m_Amount - 1; i++)
     {
         for (int j = 0; j < this->m_Amount - i - 1; j++)
         {
             if (*this->m_Students[j] > *this->m_Students[j + 1])
             {
                 CStudent* temp = this->m_Students[j];
                 this->m_Students[j] = this->m_Students[j + 1];
                 this->m_Students[j + 1] = temp;
             }
         }
     }
 }

 void CClassStudent::Descending()
 {
     for (int i = 0; i < this->m_Amount - 1; i++)
     {
         for (int j = 0; j < this->m_Amount - i - 1; j++)
         {
             if (*this->m_Students[j] < *this->m_Students[j + 1])
             {
                 CStudent* temp = this->m_Students[j];
                 this->m_Students[j] = this->m_Students[j + 1];
                 this->m_Students[j + 1] = temp;
             }
         }
     }
 }

 void CClassStudent::Delete(long id)
 {
     string idStr = to_string(id);
     int index = -1;
     for (int i = 0; i < this->m_Amount; i++) 
     {
         if (this->m_Students[i]->GetCode() == idStr)
         {
             index = i;
             break;
         }
     }

     if (index != -1) 
     {
         delete this->m_Students[index];
         this->m_Students.erase(this->m_Students.begin() + index);
         this->m_Amount--;
         cout << "Student with ID " << id << " has been deleted." << endl;
     }
     else 
     {
         cout << "Student with ID " << id << " not found." <<endl;
     }
 }

 CStudent* CClassStudent::Find(long id)
 {
     string idStr = to_string(id);
     for (int i = 0; i < this->m_Amount; i++)
     {
         if (this->m_Students[i]->GetCode() == idStr) 
         {
             return this->m_Students[i];
         }
     }

     return nullptr;
 }
 

 void CClassStudent::Rank() 
 {
     Descending();
     for (int i = 0; i < this->m_Amount; i++) 
     {
         cout << "Rank " << i + 1 << ":" << endl;
         cout << *this->m_Students[i] << endl;

         double averageScore = this->m_Students[i]->AverageGrade();
         if (averageScore >= 0 && averageScore <= 2.9) {
             cout << "Type: Loai Kem" << endl;
         }
         else if (averageScore >= 3 && averageScore <= 4.9)
         {
             cout << "Type: Loai Yeu" << endl;
         }
         else if (averageScore >= 5 && averageScore <= 6.4) 
         {
             cout << "Type: Loai TB" << endl;
         }
         else if (averageScore >= 6.5 && averageScore <= 7.9) 
         {
            cout << "Type: Loai Kha" << endl;
         }
         else if (averageScore >= 8 && averageScore <= 8.9) 
         {
            cout << "Type: Loai Gioi" << endl;
         }
         else if (averageScore >= 9 && averageScore <= 10) 
         {
             cout << "Type: Loai Xuat sac" << endl;
         }
         cout << endl;
     }
 }