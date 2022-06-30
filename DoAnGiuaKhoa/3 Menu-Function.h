#include"2 Node-List-Struct-Graphic.h"

bool checkIndifferentClassCode(Lop ds_lopHoc[], int nLopHoc);//kiểm tra các mã lớp có khác nhau không

void PrintAllExistClass(Lop ds_lopHoc[], int nLopHoc);//in danh sách nhỏ lớp hiện có vs ID

void PrintAllExistClass2(Lop ds_lopHoc[], int nLopHoc); //in danh sach nhỏ tên lớp và năm nhập học

void NhapLop(Lop ds_lopHoc[], int& nLopHoc); // thêm lớp học thủ công

bool IsStudentIDValid(Lop ds_lopHoc[], int nLophoc, wstring MASV); //kiểm tra xem ID sinh viên đã tồn tại chưa

void SortClassAccAlphabet(LISTS& list); //sắp xếp các lớp theo bảng chữ cái

bool checkIndifferentSubjectCode(MH ds_monHoc[], int nMonHoc);//kiểm tra mã các môn học có khác nhau không

void NhapMonHoc(MH ds_monHoc[], int& nMonHoc); // nhập thêm 1 môn học

void InDSMonHoc(MH ds_monHoc[], int nMonhoc);//in danh sách các môn học


bool IsAnySBOnceTime(SV sv);//kiểm tra xem sinh viên này có bất kì môn nào thi 1 lần không để in sv ra trong câu 8

void DocFileMH_Lop_SV(MH, int&,Lop, int&);

void Menu(); // menu