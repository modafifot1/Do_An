#include "Date.h"
#include<iomanip>
Date::Date(/* args */)
{
	this->day = NULL;
	this->month = NULL;
	this->year = NULL;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::~Date()
{
}
istream& operator>>(istream& in, Date& a)
{
	// TODO: insert return statement here
	do
	{
		bool check = true;
		do{
		try
		{cout << "\n \t\tday: ";
		in >> a.day;
		cout << "\t\tmonth: ";
		in >> a.month;
		cout << "\t\tyear: ";
		in >> a.year;
		check = true;
		if (!in) {
			
			in.clear();
			in.ignore(100, '\n');
			throw "loi";
		}
		}
		catch (...)
		{	check = false;
			cout << "\nSai dinh dang. Moi nhap lai ngay!" << endl;
		}
		}while (check == false);
		if (a.Check() == false) {
			cout << "Nhap sai ngay moi nhap lai." << endl;
		}
	} while (a.Check()== false);
	return in;
}

ostream& operator<<(ostream& out,const Date& x)
{
	// TODO: insert return statement here
	if (x.day == NULL) cout << setw(12) << "00/00/0000";
	else {
		if (x.day < 10) out <<setw(1)<< "0" << x.day << "/";
		else out <<setw(2)<< x.day << "/";
		if (x.month < 10) out<<setw(1) << "0" << x.month << "/";
		else out <<setw(2)<< x.month << "/";
		if (x.year < 10) out <<setw(3)<< "000" <<setw(3)<< x.year;
		else
			if (x.year < 100) out<<setw(2) << "00" <<setw(4)<< x.year;
			else
				if (x.year < 1000) out <<setw(1)<< "0" <<setw(5)<< x.year;
				else out <<setw(6)<< x.year;
	}
	return out;
}

Date::Date(const Date& p)
{
	this->day = p.day;
	this->month = p.month;
	this->year = p.year;
}

Date& Date::operator=(const Date& p)
{
	// TODO: insert return statement here
	this->day = p.day;
	this->month = p.month;
	this->year = p.year;
	return *this;
}
bool Date::Check() {

	if (month > 12 || month < 1) return false;
	else
		if (month == 4 || month == 6 || month == 9 || month == 11)
			if (day <= 0 || day > 30) return 0;
			else return 1;
		else
			if (month == 2)
				if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
					if (day <= 0 || day > 29) return 0;
					else return 1;
				else
					if (day <= 0 || day > 28) return 0;
					else return 1;
			else
				if (day <= 0 || day > 31) return 0;
				else return 1;
}
