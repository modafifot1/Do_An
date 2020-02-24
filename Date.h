#pragma once
#include<iostream>
using namespace std;
class Date
{
private:
	/* data */
	int day;
	int month;
	int year;
public:
	Date(/* args */);
	Date(int, int, int);
	~Date();
	Date(const Date& p);
	bool Check();
	Date& operator = (const Date& p);
	friend istream& operator >>(istream& in, Date& a);
	friend ostream& operator <<(ostream& out,const Date& a);
	friend class QuanLy;


};
