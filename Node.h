#pragma once
#include"Nhanvien.h"
class Node
{
public:
	NhanVien data;
	Node* left;
	Node* right;
	/* data */
public:
	Node(/* args */);
	~Node();
};

