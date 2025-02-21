#ifndef DATE_H
#define DATE_H

#include <iostream>;
using namespace std;

class CDate {
private:
	int _Year;
	int _Month;
	int _Day;
public:
	CDate();
	CDate(int iDay, int iMonth, int iYear);
	~CDate();

	void InputDate();
	void OutputDate();

	bool CheckDate();
	bool InspectLeapYear();

	CDate IncreaseYear();
	CDate IncreaseMonth();
	CDate IncreaseDay();

	CDate DecreaseYear();
	CDate DecreaseMonth();
	CDate DecreaseDay();

	CDate IncreaseYear(int n);
	CDate IncreaseMonth(int n);
	CDate IncreaseDay(int n);

	CDate DecreaseYear(int n);
	CDate DecreaseMonth(int n);
	CDate DecreaseDay(int n);

	int DayOrderInYear();
	int WeekOrderInYear();

	void ConvertDate();

	int DeductDateToDate(const CDate& otherDate);
};
#endif