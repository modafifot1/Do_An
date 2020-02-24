#pragma once
#include <iostream>
#include <string>
#include"Date.h"

using namespace std;
class NhanVien {
	const double LCB = 850;
	string maNhanVien;
	string ho;
	string ten;
	Date birthday;
	bool gioiTinh;
	string donVi;
	string chucVu;
	double heSoLuong;
	double luong;
	double phuCap;
	double thucLinh;
public:
	NhanVien();
	NhanVien(string maNhanVien, string ho, string ten, Date birthday, bool gioiTinh, string donVi, string chucVu, double heSoLuong, double luong, double phuCap, double thucLinh);
	NhanVien(const NhanVien& p);
	friend ostream& operator <<(ostream& out, const NhanVien& p);
	friend istream& operator >>(istream& in, NhanVien& p);
	NhanVien& operator =(const NhanVien& p);
	double tinhLuong();
	double tinhPhuCap();
	double tinhThucLinh();
	friend class QuanLy;

};
