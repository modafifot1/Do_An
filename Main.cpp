#pragma once
#include"Date.h";
#include"Nhanvien.h"
#include<iostream>;
#include"QuanLy.h"
#include"iomanip";
using namespace std;
int main() {
	QuanLy L;
	L.docFile("./data.txt");
	int c;
	do {
		cout << endl<<"---------------------Menu----------------------" << endl;
		cout << "0. Thoat" << endl;
		cout << "1. In danh sach" << endl;
		cout << "2. Them" << endl;
		cout << "3. Tim kiem" << endl;
		cout << "4. Sap xep" << endl;
		cout << "5. Chen" << endl;
		cout << "6. Xoa mau tin"<<endl;
		cout << "7. Xoa nhan vien tren 50t" << endl;
		cout << "8. Tinh luong, phu cap, thuc linh" << endl;
		cout << "9. Thong ke" << endl;
		cout << "Nhap lua chon cua ban :";
		cin >> c;
		cin.ignore();
		switch (c) {
		case 0:
			return 0;
		case 1:
			L.show();
			break;
		case 2:
			L.addL();
			break;
		case 3:
			int chin;
			cout << "1.Theo he so luong." << endl;
			cout << "2.theo gioi tinh." << endl;
			cout << "3.Theo ho." << endl;
			cout << "4.Theo ten." << endl;
			cout << "5.Theo chuc vu." << endl;
			cout << "6. Theo don vi." << endl;
			cin >> chin;
			cin.ignore();

			switch (chin)
			{
			case 1:
				L.Search_hsLuong();
				break;
			case 2:
				L.Search_gioiTinh();
				break;
			case 3:
				L.Search_ho();
				break;
			case 4:
				L.Search_ten();
				break;
			case 5:
				L.Search_chucvu();
				break;
			case 6:
				L.Search_donvi();
				break;
			default:
				cout << "Nhap sai!" << endl;
				break;
			}
			break;
		case 4:
			int chon;
			cout << "1.Theo he so luong." << endl;
			cout << "2.theo ho." << endl;
			cout << "3.Theo ten." << endl;
			cout << "4.Theo chuc vu." << endl;
			cin >> chon;
			cin.ignore();

			switch (chon)
			{
			case 1:
				L.Sort();
				L.show();
				break;
			case 2:
				L.Sort_Ho();
				break;
			case 3:
				L.Sort_Ten();
				break;
			case 4:
				L.Sort_ChucVu();
				break;
			default:
				cout << "Nhap sai!" << endl;
				break;
			}
			break;
		case 5:
			L.insert();
			break;
		case 6:
			L.deleteMauTinIndex();
			break;
		case 7:
			L.xoaNhanVien();
			break;
		case 8:
			L.tinhLuong();
			L.tinhPhuCap();
			L.tinhThucLinh();
			L.show();
			break;
		case 9:
			L.thongKe();
			break;		
		default:
			cout << "Nhap sai!" << endl;
			break;
		}
		
		getchar();
		system("cls");
	} while (c);
}