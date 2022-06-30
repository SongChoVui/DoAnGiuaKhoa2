#pragma once
#include"1 Config.h"

typedef struct monHoc { // môn học, tuyến tính
	wstring MAMH;
	wstring TENMH;
	int STCLT{}; // số tín chỉ lý thuytế
	int STCTH{}; // số tín chỉ thực hành
}MH;

// liên quan tới điểm của học sinh
typedef struct Diem { // điểm của sv, dslk
	wstring MAMH{};
	int Lan{};
	float diem{};
}DIEM;

typedef struct NodeDiem { //node điểm 
	DIEM diem;
	struct NodeDiem* pNext;
}NODED;

typedef struct ListDiem { // list điểm của sinh viên
	NODED* pHead;
	NODED* pTail;
}LISTD;

void KhoiTaoListDiem(LISTD& ld); //tạo list điểm null-null cho học sinh

NODED* KhoiTaoNODEDiem(DIEM diem); // tạo node điểm cho học sinh để gắn vô list


//làm việc với sinh viên

typedef struct SinhVien { // dslk
	wstring MASV;
	wstring Ho;
	wstring Ten;
	wstring Phai;
	wstring SDT;
	LISTD ds_diem{};
}SV;

wostream& operator<<(wostream& os, SV sv); //nhập sinh viên

typedef struct NodeSinhVien { // node sinh vien NODES
	SV sv;
	struct NodeSinhVien* pNext;
}NODES;

NODES* KhoiTaoNodeSinhVien(SV sv);//khởi tạo NODES sinh vien

typedef struct ListSinhVien {
	NODES* pHead;
	NODES* pTail;
}LISTS;

typedef struct Class { // lớp, tuyến tính
	wstring MaLop;
	wstring TenLop;
	int NamNhapHoc{};
	LISTS ds_sv{}; // mỗi lớp sẽ chưa 1 danh sách sinh viên riêng của lớp đó
}Lop;



void KhoiTaoListSinhVien(LISTS& ls); // tạo list sinh viên

template<typename L, typename P>
void ThemVaoCuoi(L& l, P p) {// hàm thêm vào cuối cho list điểm và list sinh viên
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}; 


//Graphic
//các hàm graphic này máy em chạy bình thuòng còn visual 2022 thì em k biết

void SetColorPro(int i); //cài màu

void SetCharacterSize(int height);//set cỡ chữ

void resizeConsole(int width, int height);//chỉnh cỡ console

void ConsoleSetting();//thiết lập ban đầu cho console