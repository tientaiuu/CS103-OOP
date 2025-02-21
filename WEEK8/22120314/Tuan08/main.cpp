#include "Company.h"
#ifdef _WIN32
#include <windows.h>
#endif

void setupConsole() {
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	wcout.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
#endif
}
int main()
{
	setupConsole();

	CCompany Company;

	Company.Input();
	Company.Output();

	Company.Salary();

	Company.SortYearOld();
	Company.Search();
}