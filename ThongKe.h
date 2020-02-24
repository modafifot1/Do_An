#pragma once
#include<string>
using namespace std;
class ThongKe {
public:
	string donVi;
	int soNam;
	int soNu;
	double tongThucLinh;
	ThongKe* next;
	ThongKe();
	~ThongKe();
};