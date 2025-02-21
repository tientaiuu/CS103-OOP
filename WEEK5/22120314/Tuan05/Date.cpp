#include "Date.h"

CDate::CDate()
{
	this->_Day = 1;
	this->_Month = 1;
	this->_Year = 0;
}

CDate::CDate(int iDay, int iMonth, int iYear)
{
	this->_Day = iDay;
	this->_Month = iMonth;
	this->_Year = iYear;
}

CDate::~CDate()
{
	this->_Day = 0;
	this->_Month = 0;
	this->_Year = -1;
}

void CDate::InputDate()
{
	cout << "Input day: ";
	cin >> this->_Day;
	cout << "Input month: ";
	cin >> this->_Month;
	cout << "Input year: ";
	cin >> this->_Year;
}

void CDate::OutputDate()
{
	cout << "Date: " << this->_Day << "/" << this->_Month << "/" << this->_Year << endl;
}

int tinhSoNgayTrongThang(int nMonth, int nYear)
{
	int nNumOfDays = 0;

	switch (nMonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		nNumOfDays = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		nNumOfDays = 30;
		break;
	case 2:
		if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
		{
			nNumOfDays = 29;
		}
		else
		{
			nNumOfDays = 28;
		}
		break;
	}

	return nNumOfDays;
}

bool CDate::CheckDate()
{
	if (this->_Year < 0)
	{
		return false;
	}

	if (this->_Month < 1 || this->_Month > 12)
	{
		return false;
	}

	if (this->_Day < 1 || this->_Day > tinhSoNgayTrongThang(this->_Month, this->_Year))
	{
		return false;
	}

	return true;
}

bool CDate::InspectLeapYear()
{
	if ((this->_Year % 4 == 0 && this->_Year % 100 != 0) || this->_Year % 400 == 0)
	{
		return true;
	}
	return false;
}

CDate CDate::IncreaseYear()
{
	if (this->CheckDate() == true)
	{
		this->_Year++;
	}
	return *this;
}

CDate CDate::IncreaseMonth()
{
	if (this->CheckDate() == true)
	{
		this->_Month++;
		if (this->_Month > 12)
		{
			this->_Month = 1;
			this->_Year++;
		}
		if (this->_Day > tinhSoNgayTrongThang(this->_Month, this->_Year))
		{
			this->_Day = tinhSoNgayTrongThang(this->_Month, this->_Year);
		}
	}
	return *this;
}

CDate CDate::IncreaseDay()
{
	if (this->CheckDate() == true)
	{
		this->_Day++;
		if (this->_Day > tinhSoNgayTrongThang(this->_Month, this->_Year))
		{
			this->_Day = 1;
			this->_Month++;
			if (this->_Month > 12)
			{
				this->_Month = 1;
				this->_Year++;
			}
		}
	}
	return *this;
}

CDate CDate::DecreaseDay()
{
	if (this->CheckDate() == true)
	{
		this->_Day--;
		if (this->_Day == 0)
		{
			this->_Month--;
			if (this->_Month == 0)
			{
				this->_Month = 12;
				this->_Year--;
			}
			this->_Day = tinhSoNgayTrongThang(this->_Month, this->_Year);
		}
	}
	return *this;
}

CDate CDate::DecreaseMonth()
{
	if (this->CheckDate() == true)
	{
		this->_Month--;
		if (this->_Month == 0)
		{
			this->_Month = 12;
			this->_Year--;
		}
		if (this->_Day > tinhSoNgayTrongThang(this->_Month, this->_Year))
		{
			this->_Day = tinhSoNgayTrongThang(this->_Month, this->_Year);
		}
	}
	return *this;
}

CDate CDate::DecreaseYear()
{
	if (this->CheckDate() == true)
	{
		this->_Year--;
		if (this->_Year < 0) cout << " Cann't Decrease Year! " << endl;
	}
	return *this;
}

CDate CDate::IncreaseYear(int n)
{
	if (this->CheckDate() == true)
	{
		this->_Year += n;
	}
	return *this;
}

CDate CDate::IncreaseMonth(int n)
{
	int total_months = this->_Year * 12 + this->_Month - 1;
	total_months += n;
	this->_Year = total_months / 12;
	this->_Month = total_months % 12 + 1;
	if (this->_Day > tinhSoNgayTrongThang(this->_Month, this->_Year))
	{
		this->_Day = tinhSoNgayTrongThang(this->_Month, this->_Year);
	}
	return *this;
}

CDate CDate::IncreaseDay(int n)
{
	int days_in_month;
	while (n > 0) {
		days_in_month = 31;

		if (this->_Month == 2) {
			if (this->InspectLeapYear())
				days_in_month = 29;
			else
				days_in_month = 28;
		}
		else if (this->_Month == 4 || this->_Month == 6 || this->_Month == 9 || this->_Month == 11)
			days_in_month = 30;

		if (_Day + n > days_in_month) {
			n -= (days_in_month - this->_Day + 1);
			this->_Day = 1;
			IncreaseMonth(1);
		}
		else {
			this->_Day += n;
			break;
		}
	}
	return *this;
}

CDate CDate::DecreaseYear(int n) {
	this->_Year -= n;
	return *this;
}

CDate CDate::DecreaseMonth(int n) {
	int total_months = this->_Year * 12 + this->_Month - 1;
	total_months -= n;
	this->_Year = total_months / 12;
	this->_Month = total_months % 12 + 1;
	if (this->_Day > tinhSoNgayTrongThang(this->_Month, this->_Year))
	{
		this->_Day = tinhSoNgayTrongThang(this->_Month, this->_Year);
	}
	return *this;
}

CDate CDate::DecreaseDay(int n) {
	while (n > 0) {
		if (this->_Day - n < 1) {
			this->DecreaseMonth(1);
			int days_in_previous_month;
			if (this->_Month == 2) {
				if (this->InspectLeapYear())
					days_in_previous_month = 29;
				else
					days_in_previous_month = 28;
			}
			else if (this->_Month == 4 || this->_Month == 6 || this->_Month == 9 || this->_Month == 11)
				days_in_previous_month = 30;
			else
				days_in_previous_month = 31;
			this->_Day = days_in_previous_month - (n - this->_Day);
			n -= this->_Day;
		}
		else {
			this->_Day -= n;
			break;
		}
	}
	return *this;
}

int CDate::DayOrderInYear()
{
	int count = this->_Day;

	for (int i = 1; i <= this->_Month - 1; i++)
	{
		count += tinhSoNgayTrongThang(i, this->_Year);
	}
	return count;
}

int CDate::WeekOrderInYear()
{
	int days_passed = 0;
	for (int i = 1; i < this->_Month; ++i) {
		if (i == 2) {
			if (this->InspectLeapYear())
				days_passed += 29;
			else
				days_passed += 28;
		}
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			days_passed += 30;
		else
			days_passed += 31;
	}
	days_passed += this->_Day - 1;

	int week_number = days_passed / 7 + 1;

	return week_number;
}

void CDate::ConvertDate()
{
	switch (this->_Month)
	{
	case 1:
	{
		cout << "January " << this->_Day << ", " << this->_Year << endl;
		break;
	}
	case 2:
	{
		cout << "February " << this->_Day << ", " << this->_Year << endl;
		break;
	}
	case 3:
	{
		cout << "March  " << this->_Day << ", " << this->_Year << endl;
		break;
	}
	case 4:
	{
		cout << "April  " << this->_Day << ", " << this->_Year << endl;
		break;
	}
	case 5:
	{
		cout << "May  " << this->_Day << ", " << this->_Year << endl;
		break;
	}
	case 6:
	{
		cout << "June  " << this->_Day << ", " << this->_Year << endl;
		break;
	}
	case 7:
	{
		cout << "July " << this->_Day << ", " << this->_Year << endl;
		break;
	}
	case 8:
	{
		cout << "August  " << this->_Day << ", " << this->_Year << endl;
		break;
	}
	case 9:
	{
		cout << "September   " << this->_Day << ", " << this->_Year << endl;
		break;
	}
	case 10:
	{
		cout << "October   " << this->_Day << ", " << this->_Year << endl;
		break;
	}
	case 11:
	{
		cout << "November   " << this->_Day << ", " << this->_Year << endl;
		break;
	}
	case 12:
	{
		cout << "December   " << this->_Day << ", " << this->_Year << endl;
		break;
	}
	}
}

int CDate::DeductDateToDate(const CDate& otherDate)
{
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int days = otherDate._Day - this->_Day;

	for (int i = this->_Month - 1; i < otherDate._Month - 1; ++i)
		days += daysInMonth[i];

	for (int i = this->_Year; i < otherDate._Year; ++i) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
			days += 366;
		else
			days += 365;
	}
	return days;
}

void CDate::Output(ofstream& fout) {
	fout << this->_Day << "/" << this->_Month << "/" << this->_Year << endl;
}