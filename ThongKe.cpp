#include "ThongKe.h"

ThongKe::ThongKe()
{
	this->donVi = "";
	this->soNam = 0;
	this->soNu = 0;
	this->tongThucLinh = 0;
	this->next = NULL;
}

ThongKe::~ThongKe()
{
	delete next;
}
