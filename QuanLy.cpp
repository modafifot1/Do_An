#include"QuanLy.h"
#include"ThongKe.h"
#include<ctime>
#include<iomanip>
#include<Windows.h>
using namespace std;
bool TD(double left, double right) {
	if (left > right)
		return true;
	return false;
}
bool GD(double left, double right) {
	if (left < right)
		return true;
	return false;
}
bool String_TD(string left, string right) {
	if (left > right)
		return true;
	return false;
}
bool String_GD(string left, string right) {
	if (left < right)
		return true;
	return false;
}
QuanLy::QuanLy(/* args */)
{
	this->head = NULL;
	this->tail = NULL;
	this->soluong = 0;
	this->sort = false;
}

QuanLy::~QuanLy()
{
	delete head, tail;
}

QuanLy::QuanLy(int soluong)
{
	this->sort = false;
	this->soluong = soluong;
	head = tail = NULL;
	for (int i = 0; i < this->soluong; i++) {
		Node* temp = new Node();	
		if (head == NULL) {
			head = tail = temp;
		}
		else
		{
			temp->left = tail;
			tail->right = temp;
			tail = temp;
		}
	}
}

QuanLy::QuanLy(const QuanLy& p)
{
	this->soluong = 0;
	Node* q = p.head;
	while (q) {
		this->addData(q->data);
		q = q->right;
	}
}

void QuanLy::addL()
{
	Node* temp = new Node();
	do {
		cin >> temp->data;
		temp->data.chucVu = toUpperCase(temp->data.chucVu);
		if (checkMa(temp) == false) cout << "Ma nhan vien da trung. Moi nhap lai!" << endl;
	} while (checkMa(temp) == false);
	if (soluong == 0) {
		head = tail = temp;
	}
	else
	{
		temp->left = tail;
		tail->right = temp;
		tail = temp;
	}
	soluong++;
	ghiFile("./data.txt", temp->data);
	show(temp);
}

void QuanLy::addData(NhanVien data)
{
	Node* temp = new Node();
	temp->data = data;
	if (soluong == 0) {
		head = tail = temp;
	}
	else
	{
		temp->left = tail;
		tail->right = temp;
		tail = temp;
	}
	soluong++;
	
	
}

void QuanLy::nhap()
{
	Node* p = new Node;
	p = head;
	while (p)
	{
		cin >> p->data;
		p = p->right;
	}
}
void QuanLy::show()
{
	if (head == NULL) {
		cout << "DANH SACH RONG!"<<endl;
	}
	else
	{
		cout << "--------------------------------------------------DANH SACH NHAN VIEN-----------------------------------------" << endl;
		cout << setfill('_')<<setw(152) <<""<< endl;
		cout << setfill(' ') << setw(15) << left << "|Ma nhan vien" << setw(15) << left << "|Ho" << setw(15) << "|Ten" << setw(13) << "|Ngay sinh" << setw(12) << "|Gioi tinh" << setw(15) << "|Don vi" << setw(10) << "|Chuc vu" << setw(15) << "|Hs luong" << setw(15) << "|Luong" << setw(12) << "|Phu cap" << setw(15) << "|Thuc linh" << "|" << endl;
		cout << setfill('_') << setw(15) << left << "|" << setw(15) << left << "|" << setw(15) << "|" << setw(13) << "|" << setw(12) << "|" << setw(15) << "|" << setw(10) << "|" << setw(15) << "|" << setw(15) << "|" << setw(12) << "|" << setw(15) << "|" << "|" << endl;

		Node* p = new Node();
		p = head;
		
		while (p)
		{
			
			cout << p->data;

			p = p->right;
		}
		
	}
	
}

void QuanLy::show(Node* changeNode)
{
	if (head == NULL) {
		cout << "DANH SACH RONG!"<<endl;
	}
	else
	{
		cout << "--------------------------------------------------DANH SACH NHAN VIEN-----------------------------------------" << endl;
		cout << setfill('_')<<setw(152) <<""<< endl;
		cout << setfill(' ') << setw(15) << left << "|Ma nhan vien" << setw(15) << left << "|Ho" << setw(15) << "|Ten" << setw(13) << "|Ngay sinh" << setw(12) << "|Gioi tinh" << setw(15) << "|Don vi" << setw(10) << "|Chuc vu" << setw(15) << "|Hs luong" << setw(15) << "|Luong" << setw(12) << "|Phu cap" << setw(15) << "|Thuc linh" << "|" << endl;
		cout << setfill('_') << setw(15) << left << "|" << setw(15) << left << "|" << setw(15) << "|" << setw(13) << "|" << setw(12) << "|" << setw(15) << "|" << setw(10) << "|" << setw(15) << "|" << setw(15) << "|" << setw(12) << "|" << setw(15) << "|" << "|" << endl;

		Node* p = new Node();
		p = head;
		
		while (p)
		{
			if (p == changeNode) {
				HANDLE hConsoleColor;
				hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsoleColor, 2);
				cout << p->data;
				p = p->right;
				SetConsoleTextAttribute(hConsoleColor, 7);
			}
			else {
				cout << p->data;

				p = p->right;
			}
		}
		
	}
}

void QuanLy::deleteMauTinLast()
{
	if (soluong == 0) {
		cout << "Danh sach rong !!! " << endl;
	}
	else
	{
		Node* temp = new Node();
		temp = tail->left;
		delete tail;
		tail = temp;
		tail->right = NULL;
		soluong--;
	}


}
void QuanLy::deleteMauTinFirst()
{
	if (soluong == 0) {
		cout << "Danh sach rong !!!" << endl;
	}
	else
	{
		Node* temp = new Node();
		temp = head->right;
		delete head;
		head = temp;
		soluong--;
	}
}
void QuanLy::deleteMauTinIndex()
{
	if (soluong == 0) {
		cout << "Danh sach rong !!!" << endl;
	}
	else
	{
		Node* deleteNode = new Node();
		int k;
		cout << "Nhap vi tri can xoa :";
		bool a = true;
		do
		{
			cin >> k;
			cin.ignore();
			if (k >= 1 && k <= soluong) {
				a = true;
			}
			else
			{
				a = false;
				cout << "Moi nhap lai :";
			}

		} while (a == false);
		if (k == soluong) {
			deleteNode->data = tail->data;
			deleteMauTinLast();
		}
		else if (k == 1)
		{
			deleteNode->data = head->data;
			deleteMauTinFirst();
		}
		else
		{
			int i = 1;
			Node* p = new Node();
			p = head;
			while (i != k)
			{
				p = p->right;
				i++;
			}
			deleteNode->data = p->data;
			p->left->right = p->right;
			p->right->left = p->left;
			delete p;
			soluong--;
		}
		
		show();
		HANDLE hConsoleColor;
		hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsoleColor, 12);
		cout << "\n\nNhan vien da xoa:\n " << endl;
		cout << deleteNode->data;
		SetConsoleTextAttribute(hConsoleColor, 7);

	}
}
void QuanLy::deleteMauTinIndex(int k)
{
	if (soluong == 0) {
		cout << "Danh sach rong !!!" << endl;
	}
	else
	{
		if (k == soluong-1) {
			deleteMauTinLast();
		}
		else if (k == 0)
		{
			deleteMauTinFirst();
		}
		else
		{
			int i = 1;
			Node* p = new Node();
			p = head;
			while (i != k)
			{
				p = p->right;
				i++;
			}
			p->left->right = p->right;
			p->right->left = p->left;
			delete p;
			soluong--;
		}
		
	}
}
void QuanLy::insert()
{
	Node* temp = new Node();
	do {
		cin >> temp->data;
		temp->data.chucVu = toUpperCase(temp->data.chucVu);
		if (checkMa(temp) == false) cout << "Ma nhan vien da trung. Moi nhap lai!" << endl;
	} while (checkMa(temp) == false);
	if (soluong == 0) {
		head = tail = temp;
	}
	else {
		if (this->sort == false) MergeSort(*this, 1, soluong, TD);
		bool a = this->address(0)->data.heSoLuong > this->address(soluong - 1)->data.heSoLuong;
		int i;
		for (i = 0 ; i < soluong; i++) {
			if (a == true && temp->data.heSoLuong > this->address(i)->data.heSoLuong) 
				break;
			if (a == false && temp->data.heSoLuong < this->address(i)->data.heSoLuong) break;
		}
		if (i < soluong&&i>0) {
			temp->right = this->address(i);
			temp->left = this->address(i)->left;
			this->address(i)->left->right = temp;
			this->address(i)->left= temp;
		}
		else
		if (i==soluong){
			temp->left = tail;
			tail->right = temp;
			tail = temp;
		}
		else {
			temp->right = head;
			head->left = temp;
			head = temp;
		}
	}
	soluong++;
	ghiFile("./data.txt", temp->data);
	show(temp);
}
void QuanLy::MergeSort(QuanLy &p, int left, int right, bool(*m)(double x, double y))
{
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(p, left, mid, m);
		MergeSort(p, mid + 1, right, m);
		QuanLy q(right + 1);

		int l1 = left, l2 = mid + 1, i = left;
		for (; l1 <= mid && l2 <= right; i++) {
			if (m(p[l2].heSoLuong, p[l1].heSoLuong)) {
				q[i] = p[l1];
				l1++;
			}
			else {
				q[i] = p[l2];
				l2++;
			}
		}
		while (l1 <= mid)
		{
			q[i] = p[l1];
			i++;
			l1++;
		}
		while (l2 <= right)
		{
			q[i] = p[l2];
			i++;
			l2++;
		}
		for (int i = left; i <= right; i++) {
			p[i] = q[i];
		}
	}
}
void QuanLy::Sort_Ho()
{
	if (head == NULL) {
		cout << "Danh sach rong!" << endl;
	}
	else {
		bool(*myCom)(string x, string y);
		while (1) {
			int c;
			cout << "Sap xep theo tang dan hay giam dan : " << endl;
			cout << "1. Tang dan" << endl;
			cout << "2. Giam dan" << endl;
			cout << "Nhap lua chon: " << endl;
			cin >> c;
			cin.ignore();
			if (c == 1) {
				myCom = String_TD;
				break;
			}
			else {
				if (c == 2) {
					myCom = String_GD;
					break;
				}
				else {
					cout << "Nhap sai tham so" << endl;
				}
			}
		}
		for (int i = 0; i < this->soluong - 1; i++)
			for (int j = 0; j < this->soluong - i; j++)
				if (myCom(this->address(j)->data.ho, this->address(j + 1)->data.ho))
				{
					NhanVien temp = this->address(j)->data;
					this->address(j)->data = this->address(j + 1)->data;
					this->address(j + 1)->data = temp;
				}
		this->sort = false;
		show();
					
			
	}
}
void QuanLy::Sort_Ten()
{
	if (head == NULL) {
		cout << "Danh sach rong!" << endl;
	}
	else {
		bool(*myCom)(string x, string y);
		while (1) {
			int c;
			cout << "Sap xep theo tang dan hay giam dan : " << endl;
			cout << "1. Tang dan" << endl;
			cout << "2. Giam dan" << endl;
			cout << "Nhap lua chon: " << endl;
			cin >> c;
			cin.ignore();
			if (c == 1) {
				myCom = String_TD;
				break;
			}
			else {
				if (c == 2) {
					myCom = String_GD;
					break;
				}
				else {
					cout << "Nhap sai tham so" << endl;
				}
			}
		}
		for (int i = 0; i < this->soluong - 1; i++)
			for (int j = 0; j < this->soluong - i; j++)
				if (myCom(this->address(j)->data.ten, this->address(j + 1)->data.ten))
				{
					NhanVien temp = this->address(j)->data;
					this->address(j)->data = this->address(j + 1)->data;
					this->address(j + 1)->data = temp;
				}
		this->sort = false;
		show();
	}
}
void QuanLy::Sort_ChucVu()
{
	if (head == NULL) {
		cout << "Danh sach rong!" << endl;
	}
	else {
		bool(*myCom)(string x, string y);
		while (1) {
			int c;
			cout << "Sap xep theo tang dan hay giam dan : " << endl;
			cout << "1. Tang dan" << endl;
			cout << "2. Giam dan" << endl;
			cout << "Nhap lua chon: " << endl;
			cin >> c;
			cin.ignore();
			if (c == 1) {
				myCom = String_TD;
				break;
			}
			else {
				if (c == 2) {
					myCom = String_GD;
					break;
				}
				else {
					cout << "Nhap sai tham so" << endl;
				}
			}
		}
		for (int i = 0; i < this->soluong - 1; i++)
			for (int j = 0; j < this->soluong - i; j++)
				if (myCom(this->address(j)->data.chucVu, this->address(j + 1)->data.chucVu))
				{
					NhanVien temp = this->address(j)->data;
					this->address(j)->data = this->address(j + 1)->data;
					this->address(j + 1)->data = temp;
				}
		this->sort = false;
		show();
	}
}
void QuanLy::Sort()
{
	this->sort = true;
	if (head == NULL) {
		cout << "Danh sach rong!" << endl;
	}
	else {
		int c;
			cout << "Sap xep theo tang dan hay giam dan : " << endl;
			cout << "1. Tang dan" << endl;
			cout << "2. Giam dan" << endl;
			cout << "Nhap lua chon: " << endl;
			cin >> c;
			cin.ignore();
		if(c==1)
		MergeSort(*this, 1, soluong, TD);
		else 
		MergeSort(*this, 1, soluong, GD);
	}

}
void QuanLy::docFile(string path)
{
	fstream file;
	file.open(path);
	file >> this->soluong;
	
	for (int i = 0; i < this->soluong; i++) {
		NhanVien nv;
		if (file.eof() == false) {
			file.ignore();
			getline(file, nv.maNhanVien, ',');
			getline(file, nv.ho, ',');
			getline(file, nv.ten, ',');
			file >> nv.birthday.day;
			file >> nv.birthday.month;
			file >> nv.birthday.year;
			file >> nv.gioiTinh;
			file.ignore();
			getline(file, nv.donVi, ',');
			getline(file, nv.chucVu, ',');
			file >> nv.heSoLuong;
			Node* temp = new Node();
			temp->data = nv;
			if (head == NULL) {
				head = tail = temp;
			}
			else
			{
				temp->left = tail;
				tail->right = temp;
				tail = temp;
			}
		}

	}
	file.close();
}
void QuanLy::ghiFile(string path, NhanVien nv)
{
	fstream file;
	file.open(path);
	file << this->soluong;
	file.seekg(0, ios::end);
	file << endl;
	file << nv.maNhanVien + ",";
	file << nv.ho + ",";
	file << nv.ten + ", ";
	file << nv.birthday.day;
	file << " ";
	file << nv.birthday.month;
	file << " ";
	file << nv.birthday.year;
	file << " ";
	file << nv.gioiTinh;
	file << " ";
	file << nv.donVi + ",";
	file << nv.chucVu + ", ";
	file << nv.heSoLuong;
	file.close();
}
void QuanLy::xoaNhanVien() {
	if (head == NULL) cout << "Danh sach rong!" << endl;
	else {
		time_t now = time(0);
		struct tm ltm;
		localtime_s(&ltm, &now);
		int z = ltm.tm_year + 1900;
		QuanLy* deleteNode = new QuanLy();
		Node* p = head;
		while (p) {
			int tuoi = z - p->data.birthday.year;
			if ( tuoi > 50) {
				if (p->left == NULL) {
					p = p->right;
					deleteNode->addData(head->data);
					deleteMauTinFirst();

				}
				else
					if (p->right == NULL) {
						p = p->right;
						deleteNode->addData(tail->data);
						deleteMauTinLast();
					}
					else {
						deleteNode->addData(p->data);
						p->left->right = p->right;
						p->right->left = p->left;
						p = p->left;
						soluong--;
					}
				
			}
			if(p!=NULL)
			p = p->right;
			
		}
		show();
		HANDLE hConsoleColor;
		hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsoleColor, 12);
		if (deleteNode->soluong == 0) {
			cout << "Khong co nhan vien nao bi xoa" << endl;
		}
		else {
			cout << "\n\nNhan vien da xoa:\n " << endl;
			Node* t = deleteNode->head;
			while (t) {
				cout << t->data;
				t = t->right;
			}
		}
		SetConsoleTextAttribute(hConsoleColor, 7);
	}
}
void QuanLy::tinhLuong() {
	if (head == NULL) cout << "Danh sach rong!" << endl;
	else {
		Node* p = head;
		while (p) {
			p->data.tinhLuong();
			p = p->right;
		}
	}
}
void QuanLy::tinhPhuCap() {
	if (head == NULL) cout << "Danh sach rong!" << endl;
	else {
		Node* p = head;
		while (p) {
			p->data.tinhPhuCap();
			p = p->right;
		}
	}
}
void QuanLy::tinhThucLinh() {
	if (head == NULL) cout << "Danh sach rong!" << endl;
	else {
		Node* p = head;
		while (p) {
			p->data.tinhThucLinh();
			p = p->right;
		}
	}
}
void QuanLy::thongKe() {
	tinhLuong();
	tinhPhuCap();
	tinhThucLinh();
	if (this->head == NULL) cout << "Danh sach rong!" << endl;
	else {
		ThongKe* head = NULL;
		Node* p = this->head;
		
		while (p) {
			ThongKe* q = head;
			while (q) {
				if (p->data.donVi == q->donVi) {
					if (p->data.gioiTinh == 1) q->soNam++;
					else q->soNu++;
					q->tongThucLinh += p->data.thucLinh;
					break;

				}
				else {
					q = q->next;
				}
			}
			if (q == NULL) {
				q = new ThongKe();
				q->donVi = p->data.donVi;
				if (p->data.gioiTinh == 1) q->soNam++;
				else q->soNu++;
				q->tongThucLinh += p->data.thucLinh;
				if (head == NULL) head = q;
				else {
					q->next = head;
					head = q;
				}
			}
			p = p->right;

		}
		//in danh sach thong ke
		ThongKe* q = head;
		cout << "---------------------------DANH SACH THONG KE----------------------------" << endl;
		cout << setfill('_') << setw(60) << "" << endl;
		cout <<setfill(' ')<< setw(20)<<left << "|Don Vi" << setw(10) << "|So nam" << setw(10) << "|So nu" << setw(20) << "|Tong thuc linh" <<"|"<< endl;
		cout << setfill('_') << setw(20) << "|" << setw(10) << "|" << setw(10) << "|" << setw(20) << "|" << "|" << endl;

		while (q) {
			cout <<setfill(' ')<< setw(20) <<"|" +q->donVi <<"|"<< setw(9) << q->soNam << "|" << setw(9) << q->soNu << "|" << setw(19) << q->tongThucLinh <<"|"<< endl;
			cout << setfill('_') << setw(20) << "|" << setw(10) << "|" << setw(10) << "|" << setw(20) << "|" << "|" << endl;

			q = q->next;
		}

	}
}

void QuanLy::Search_hsLuong()
{
	if (head == NULL) {
		cout << "Danh sach rong!" << endl;
	}
	else {
		if (this->sort == false) {
			this->MergeSort(*this, 1, soluong, TD);
		}
		cout << "Nhap he so luong can tim kiem: ";
		double x;
		cin >> x;
		cin.ignore();
		QuanLy* search = new QuanLy();
		QuanLy* copQuanLy = new QuanLy(*this);
		lui:
			if (copQuanLy->soluong != 0) {
				int low = 0, height = copQuanLy->soluong - 1, mid = -1;
				if (copQuanLy->address(low)->data.heSoLuong == copQuanLy->address(height)->data.heSoLuong)
				{
					search->addData(copQuanLy->address(low)->data);
					copQuanLy->deleteMauTinIndex(low);
					goto lui;
				}
				else
				{
					while (low < height && copQuanLy->address(low)->data.heSoLuong <= x && copQuanLy->address(height)->data.heSoLuong >= x)
					{
						mid = low + (height - low) * (x - copQuanLy->address(low)->data.heSoLuong) / (copQuanLy->address(height)->data.heSoLuong - copQuanLy->address(low)->data.heSoLuong);
						if (x == copQuanLy->address(mid)->data.heSoLuong)
						{
							search->addData(copQuanLy->address(mid)->data);
							copQuanLy->deleteMauTinIndex(mid);
							goto lui;
						}

						if (x > copQuanLy->address(mid)->data.heSoLuong) low = mid + 1;
						else height = mid - 1;
					}
				}
			}
		if (search->soluong == 0) {
			cout << "\nKhong tim thay" << endl;
		}
		else {
			search->show();
			delete search;
		}
	}
	

}

void QuanLy::Search_gioiTinh()
{
	Node* p = new Node();
	p = head;
	int x;
	cout << "Nhap gioi tinh can tim kiem 1(nam)/0(nu): ";
	cin >> x;
	cin.ignore();
	int dem = 0;
	QuanLy* q = new QuanLy();
	
	for (int i = 0; i < this->soluong; i++) {
		if (p->data.gioiTinh == x) {
			q->addData(p->data);
			dem++;
		}
		p = p->right;
	}
	if (dem == 0) cout << "\nKhong tim thay" << endl;
	else {
		q->show();
	}
	delete p;
}

void QuanLy::Search_donvi()
{
	Node* p = new Node();
	p = head;
	string x;

	cout << "Nhap don vi: ";
	getline(cin, x);
	int dem = 0;
	QuanLy* q = new QuanLy();
	for (int i = 0; i < this->soluong; i++) {
		if (toUpperCase(p->data.donVi) == toUpperCase(x)) {
			q->addData(p->data);
			dem++;
		}
		p = p->right;
	}
	if (dem == 0) cout << "\nKhong tim thay" << endl;
	else {
		q->show();
	}
	delete p;
}

void QuanLy::Search_ho()
{

	Node* p = new Node();
	p = head;
	string x;

	cout << "Nhap ho: ";
	getline(cin, x);
	int dem = 0;
	QuanLy* q = new QuanLy();
	for (int i = 0; i < this->soluong; i++) {
		if (toUpperCase(p->data.ho) == toUpperCase(x)) {
			q->addData(p->data);
			dem++;
		}
		p = p->right;
	}
	if (dem == 0) cout << "\nKhong tim thay" << endl;
	else {
		q->show();
	}
	delete p;
}

void QuanLy::Search_ten()
{
	Node* p = new Node();
	p = head;
	string x;

	cout << "Nhap ten: ";
	getline(cin, x);
	int dem = 0;
	QuanLy* q = new QuanLy();
	for (int i = 0; i < this->soluong; i++) {
		if (toUpperCase(p->data.ten) == toUpperCase(x)) {
			q->addData(p->data);
			dem++;
		}
		p = p->right;
	}
	if (dem == 0) cout << "\nKhong tim thay" << endl;
	else {
		q->show();
	}
	delete p;
}
void QuanLy::Search_chucvu()
{
	Node* p = new Node();
	p = head;
	string x;

	cout << "Nhap chuc vu: ";
	getline(cin, x);
	int dem = 0;
	QuanLy* q = new QuanLy();
	for (int i = 0; i < this->soluong; i++) {
		if (toUpperCase(p->data.chucVu) == toUpperCase(x)) {
			q->addData(p->data);
			dem++;
		}
		p = p->right;
	}
	if (dem == 0) cout << "\nKhong tim thay" << endl;
	else {
		q->show();
	}
	delete p;
}
bool QuanLy::checkMa(Node* n)
{
	if (this->soluong == 0) return true; 
	else{
		Node* p = head;
		while (p) {
			if (p->data.maNhanVien == n->data.maNhanVien)
				return false;
			p = p->right;
		}
		return true;
	}
}
NhanVien& QuanLy::operator [](int x) {
	Node* p = head;
	for (int i = 1; i < x; i++) {
		p = p->right;
	}
	return p->data;
}
Node* QuanLy::address(int k)
{
	Node* p = head;
	for (int i = 1; i < k; i++) {
		p = p->right;
	}
	return p;
}
string QuanLy::toUpperCase(string s)
{
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 97) {
			s[i] = s[i] - 32;
		}
	}
	return s;
}


