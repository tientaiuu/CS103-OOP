#include "Company.h"


// CEmployee
CEmployee::CEmployee()
{
	m_ID = m_Department = m_Name = m_Address = "";
	m_Birthday = CMyDate(0, 0, 0);
	m_WageCoefficient = 0;
}

CEmployee::CEmployee(string id, string department, string name, CMyDate birthday, string address, float wageCoef)
{
	m_ID = id;
	m_Department = department;
	m_Name = name;
	m_Birthday = CMyDate(birthday);
	m_Address = address;
	m_WageCoefficient = wageCoef;
}

CEmployee::CEmployee(const CEmployee& other)
{
	m_ID = other.m_ID;
	m_Department = other.m_Department;
	m_Name = other.m_Name;
	m_Birthday = CMyDate(other.m_Birthday);
	m_Address = other.m_Address;
	m_WageCoefficient = other.m_WageCoefficient;
}

void CEmployee::Output(ofstream& output)
{
	output << m_ID << "," << m_Name << ", " << m_Birthday  << ".\n";

}

// CProgrammer
CProgrammer::CProgrammer(string id, string department, string name, CMyDate birthday, string address, float wageCoef, float ovt)
	: CEmployee(  id,  department,  name,  birthday,  address , wageCoef), m_OvertimePay(ovt) {}


// CDesigner
CDesigner::CDesigner(string id, string department, string name, CMyDate birthday, string address, float wageCoef, float bonus)
	: CEmployee(id, department, name, birthday, address, wageCoef), m_Bonus(bonus) {}

// CTester
CTester::CTester(string id, string department, string name, CMyDate birthday, string address, float wageCoef, float error)
	: CEmployee(id, department, name, birthday, address, wageCoef ), m_Error(error) {}

// CCompany
CCompany::~CCompany()
{

	for (auto item : this->Employees)
	{
		delete item;
	}
}

void CCompany::Input()
{
	ifstream file("INPUT.TXT");

	if (!file) {
		cerr << "Error openning file: INPUT.TXT" << endl;
		return;
	}

	string line;
	while (getline(file, line)) {
		if (!line.empty())
		{
			stringstream ss(line);
			string id, department, name, date, address;
			float wageCoef;
			getline(ss, id, ',');
			getline(ss, department, ',');
			getline(ss, name, ',');
			getline(ss, date, ',');
			getline(ss, address, ',');
			ss >> wageCoef;

			int day, month, year;
			char discard;
			stringstream ss1(date);
			ss1 >> day >> discard >> month >> discard >> year;

			CMyDate birthday(day, month, year);

			this->Employees.push_back(new CEmployee(id, department, name, birthday, address, wageCoef));
		}
	}
	file.close();
}

void CCompany::Output()
{
	ofstream output("OUTPUT.TXT");
	if (!output.is_open())
	{
		cerr << "Error opening file: OUTPUT.TXT" << endl;
		return;
	}

	int count = Employees.size();

	wstring str = L" Nhân viên: \n";
	wstring_convert<codecvt_utf8<wchar_t>> converter;
	
	output << count << converter.to_bytes(str);

	int i = 1;
	for (auto& item : this->Employees)
	{
		output << i << ". ";
		item->Output(output);
		i++;
	}

	output.close();
}

float CCompany::Salary()
{
	ifstream salaryFileStream("SALARY.TXT");
	if (!salaryFileStream) {
		cerr << "Error opening file: SALARY.TXT" << endl;
		return 0;
	}

	string line;
	getline(salaryFileStream, line);
	float baseWage = stof(line);

	unordered_map<string, float> salaryMap;
	while (getline(salaryFileStream, line)) {
		if (!line.empty()) {
			stringstream ss(line);
			string id;
			float value;
			getline(ss, id, ' ');
			ss >> value;
			salaryMap[id] = value;
		}
	}

	float totalSalary = 0;
	for (auto emp : Employees) 
	{
		float extra = 0;
		if (salaryMap.find(emp->getID()) != salaryMap.end()) 
		{
			extra = salaryMap[emp->getID()];
		}

		float salary = baseWage * emp->getWageCoefficient();
		string id = emp->getID();
		char category = id[0];
		switch (category)
		{
		case 'P':
			salary += extra;
			break;
		case 'D':
			salary += extra;
			break;
		case 'T':
			salary += extra * 100000;
			break;
		case 'M':
			break;
		}

		wstring str = L" Lương: ";
		wstring_convert<codecvt_utf8<wchar_t>> converter;
		cout << emp->getID() << "," << emp->getName() << "," << converter.to_bytes(str) << fixed << setprecision(0) << salary << endl;
		totalSalary += salary;
	}

	wstring str = L"Tổng lương: ";
	wstring_convert<codecvt_utf8<wchar_t>> converter;
	cout << converter.to_bytes(str) << fixed << setprecision(0) << totalSalary << endl;

	salaryFileStream.close();
	return totalSalary;
}

void CCompany::SortYearOld()
{
	sort(this->Employees.begin(), this->Employees.end(), [](CEmployee* a, CEmployee* b) {
		return a->getBirthday() < b->getBirthday();
		});

	ofstream file("SORTYEAROLD.OUT");
	int i = 1;
	for (auto& item : this->Employees)
	{
		file << i << ". ";
		file << item->getID() << item->getName() << " " << item->getAge() << "\n";
		i++;
	}
	file.close();
}


void CCompany::Search()
{
	string department;
	cin >> department;

	ofstream file("SEARCH.TXT");
	for (auto& emp : this->Employees) {
		string tmp = emp->getDepartment();
		tmp.erase(tmp.begin() + 0 , tmp.begin() + 1);
		if (tmp == department) 
		{
			file << emp->getID() << "," << emp->getName() << ", " << emp->getBirthday() << "," << emp->getAddress() << endl;
		}
	}
	file.close();
}