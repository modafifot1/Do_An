#pragma once
#include"Node.h"
#include<iostream>
#include<fstream>
using namespace std;
class QuanLy
{
private:
	/* data */
	Node* head;
	Node* tail;
	int soluong;
	bool sort;

public:
	QuanLy(/* args */);
	~QuanLy();
	QuanLy(int soluong);
	QuanLy(const QuanLy& p);
	void addL();
	void addData(NhanVien);
	void nhap();
	void show();
	void show(Node*);
	void deleteMauTinLast();
	void deleteMauTinFirst();
	void deleteMauTinIndex();
	void deleteMauTinIndex(int i);
	void insert();
	void MergeSort(QuanLy &p, int left, int right, bool(*m)(double x, double y));
	void Sort_Ho();
	void Sort_Ten();
	void Sort_ChucVu();
	void Sort();
	void docFile(string path);
	void ghiFile(string path, NhanVien nv);
	void xoaNhanVien();
	void tinhLuong();
	void tinhPhuCap();
	void tinhThucLinh();
	void thongKe();
	void Search_hsLuong();
	void Search_gioiTinh();
	void Search_donvi();
	void Search_ho();
	void Search_ten();
	void Search_chucvu();
	bool checkMa(Node*);
	NhanVien& operator [](int x);
	Node* address(int k);
	string toUpperCase(string s);
};


