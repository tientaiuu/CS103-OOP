#include "Date.h"

int main()
{
	CDate time;


	time.InputDate();

	cout << "-------------------------------------------" << endl;

	time.OutputDate();

	cout << "-------------------------------------------" << endl;
	// Check Date valid or invalid
	cout << "Check Date: ";
	if (time.CheckDate() == true) cout << "Valid Date" << endl;
	else cout << "Invalid Date" << endl;


	// Check Leap Year
	cout << "Check Leap Year: ";
	if (time.InspectLeapYear() == true) cout << "True" << endl;
	else cout << "False" << endl;

	cout << "-------------------------------------------" << endl;

	// Increase 1
	cout << "Date after increase 1 year: ";
	time.IncreaseYear();
	time.OutputDate();

	cout << "Date after increase 1 month: ";
	time.IncreaseMonth();
	time.OutputDate();

	cout << "Date after increase 1 day: ";
	time.IncreaseDay();
	time.OutputDate();

	cout << "-------------------------------------------" << endl;

	// Decrease 1 
	cout << "Date after decrease 1 year: ";
	time.DecreaseYear();
	time.OutputDate();

	cout << "Date after decrease 1 month: ";
	time.DecreaseMonth();
	time.OutputDate();

	cout << "Date after decrease 1 day: ";
	time.DecreaseDay();
	time.OutputDate();

	cout << "-------------------------------------------" << endl;

	// Increase n
	cout << "Date after increase n year: ";
	time.IncreaseYear(3);
	time.OutputDate();

	cout << "Date after increase n month: ";
	time.IncreaseMonth(2);
	time.OutputDate();

	cout << "Date after increase n day: ";
	time.IncreaseDay(1);
	time.OutputDate();

	cout << "-------------------------------------------" << endl;

	// Decrease n
	cout << "Date after decrease n year: ";
	time.DecreaseYear(3);
	time.OutputDate();

	cout << "Date after decrease n month: ";
	time.DecreaseMonth(2);
	time.OutputDate();

	cout << "Date after decrease n day: ";
	time.DecreaseDay(1);
	time.OutputDate();

	cout << "-------------------------------------------" << endl;

	// So thu tu ngay trong nam
	cout << "Day order in year: " << time.DayOrderInYear() << endl;

	cout << "-------------------------------------------" << endl;
	// So thu tu tuan trong nam
	cout << "Week order in year: " << time.WeekOrderInYear() << endl;

	cout << "-------------------------------------------" << endl;
	// Conver date 
	cout << "Date after convert: ";
	time.ConvertDate();

	cout << "-------------------------------------------" << endl;
	// Deduct date to date
	cout << "Deduct date to date:" << endl;
	CDate time2;
	CDate time3;

	cout << "Date 1: " << endl;
	time2.InputDate();
	time2.OutputDate();

	cout << endl;

	cout << "Date 2: " << endl;
	time3.InputDate();
	time3.OutputDate();

	cout << "Result: " << time2.DeductDateToDate(time3) << endl;


}
