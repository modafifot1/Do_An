#include "NhanVien.h"
#include <iomanip>
NhanVien::NhanVien()
{
	this->maNhanVien = "";
	this->ho = "";
	this->ten = "";
	this->gioiTinh = "";
	this->donVi = "";
	this->chucVu = "";
	this->heSoLuong = 0;
	this->luong = 0;
	this->phuCap = 0;
	this->thucLinh = 0;
	this->birthday = Date();
}
NhanVien::NhanVien(string maNhanVien, string ho, string ten, Date birthday, bool gioiTinh, string donVi, string chucVu, double heSoLuong, double luong, double phuCap, double thucLinh)
{
	this->maNhanVien = maNhanVien;
	this->ho = ho;
	this->ten = ten;
	this->birthday = birthday;
	this->gioiTinh = gioiTinh;
	this->donVi = donVi;
	this->chucVu = chucVu;
	this->heSoLuong = heSoLuong;
	this->luong = luong;
	this->phuCap = phuCap;
	this->thucLinh = thucLinh;
}
NhanVien::NhanVien(const NhanVien& p)
{
	this->maNhanVien = p.maNhanVien;
	this->ho = p.ho;
	this->ten = p.ten;
	this->birthday = p.birthday;
	this->gioiTinh = p.gioiTinh;
	this->donVi = p.donVi;
	this->chucVu = p.chucVu;
	this->heSoLuong = p.heSoLuong;
	this->luong = p.luong;
	this->phuCap = p.phuCap;
	this->thucLinh = p.thucLinh;
}
ostream& operator<<(ostream& out, const NhanVien& p)
{
	out <<setfill(' ')<< setw(15)<<left<<"|"+ p.maNhanVien << setw(15) << "|" + p.ho << setw(15) << "|" + p.ten << "|" <<setw(13)<< p.birthday;
	if (p.gioiTinh == true) {
		out <<left<< setw(12) << "|Nam";
	}
	else out <<setw(12)<<left <<"|Nu";
	out << setw(15) << "|" + p.donVi << setw(10) << "|" + p.chucVu << "|" << setw(14) << p.heSoLuong << "|" << setw(14) << p.luong << "|" << setw(11) << p.phuCap << "|" << setw(14) << p.thucLinh << "|" << endl;
	cout << setfill('_') << setw(15) << left << "|" << setw(15) << left << "|" << setw(15) << "|" << setw(13) << "|" << setw(12) << "|" << setw(15) << "|" << setw(10) << "|" << setw(15) << "|" << setw(15) << "|" << setw(12) << "|" << setw(15) << "|" << "|" << endl;

	return out;
}
istream& operator>>(istream& in, NhanVien& p)
{
	cout << "Nhap ma nhan vien: ";
	getline(in, p.maNhanVien);
	cout << "\t Ho: ";
	getline(in, p.ho);
	cout << "\t Ten: ";
	getline(in, p.ten);
	cout << "\t Ngay sinh: ";
	in >> p.birthday;
	bool check;
	do {
		try
		{
			check = true;
			cout << "\t Gioi tinh(1-Nam/0-Nu): ";
			in >> p.gioiTinh;
			in.ignore();
			if (!in) {
				in.clear();
				in.ignore(100, '\n');
				throw "loi";
			}

		}
		catch (...)
		{
			check = false;
			cout << "Sai dinh dang. Moi nhap lai!" << endl;
		}
	} while (check == false);	
	cout << "\t Don vi: ";
	getline(in, p.donVi);
	cout << "\t Chuc vu: ";
	getline(in, p.chucVu);
	do {
		try
		{
			cout << "\t He so luong: ";
			in >> p.heSoLuong;
			in.ignore();
			check = true;
			if (!in) {
				in.clear();
				in.ignore(100, '\n');
				throw "loi";
			}
		}
		catch (...)
		{
			check = false;
			cout << "\n Nhap sai dinh dang. Moi nhap lai!" << endl;
		}
		
	} while (check == false);
	return in;
}
NhanVien& NhanVien::operator=(const NhanVien& p)
{
	this->maNhanVien = p.maNhanVien;
	this->ho = p.ho;
	this->ten = p.ten;
	this->birthday = p.birthday;
	this->gioiTinh = p.gioiTinh;
	this->donVi = p.donVi;
	this->chucVu = p.chucVu;
	this->heSoLuong = p.heSoLuong;
	this->luong = p.luong;
	this->phuCap = p.phuCap;
	this->thucLinh = p.thucLinh;
	return *this;
}
double NhanVien::tinhLuong()
{
	this->luong = LCB * this->heSoLuong;
	return luong;
}
double NhanVien::tinhPhuCap()
{
	if (this->chucVu == "GD" || this->chucVu == "PGD")
		this->phuCap = this->luong * 0.4;
	else if (this->chucVu == "TP" || this->chucVu == "PP")
		this->phuCap = this->luong * 0.25;
	else
		this->phuCap = 0;

	return this->phuCap;
}
double NhanVien::tinhThucLinh()
{
	this->thucLinh = this->luong + this->phuCap;
	return this->thucLinh;
}
