#include"3 Menu-Function.h"

bool checkIndifferentClassCode(Lop ds_lopHoc[], int nLopHoc) {
	for (int i = 0; i < nLopHoc; i++)
	{
		//convert to string
		string LopI(ds_lopHoc[i].MaLop.begin(), ds_lopHoc[i].MaLop.end());
		string LopN(ds_lopHoc[nLopHoc].MaLop.begin(), ds_lopHoc[nLopHoc].MaLop.end());
		if ( strcmpi(LopI.c_str(),LopN.c_str()) == 0 )
		{
			SetColorPro(4);
			wcout << L"\t\t\t\tMã lớp đã tồn tại, vui lòng nhập lại!\n";
			return true;
		}
	}
	return false;
}

void PrintAllExistClass(Lop ds_lopHoc[], int nLopHoc) {
	SetColorPro(10); wcout << L"\t\t\tDanh sách lớp học hiện tại :";
	if (nLopHoc == 0)
	{
		wcout << L" Chưa tồn tại lớp nào cả!";
	}
	else
	{
		SetColorPro(8);
		int index = 1;
		wcout << "\n\t";
		for (size_t i = 0; i < nLopHoc; i++)
		{
			if (index == 6) // thêm màu mè thui
			{
				wcout << "\n\t";
				index = 1;
			}
			else
			{
				index++;
			}
			wcout << L"\t" << ds_lopHoc[i].TenLop << "(" << ds_lopHoc[i].MaLop << ")";
		}
	}
}

void PrintAllExistClass2(Lop ds_lopHoc[], int nLopHoc) {
	SetColorPro(10); wcout << L"\t\t\tDanh sách lớp học hiện tại :";
	if (nLopHoc == 0)
	{
		wcout << L" Chưa tồn tại lớp nào cả!";
	}
	else
	{
		SetColorPro(8);
		int index = 1;
		wcout << "\n\t";
		for (size_t i = 0; i < nLopHoc; i++)
		{
			if (index == 6) // thêm màu mè thui
			{
				wcout << "\n\t";
				index = 1;
			}
			else
			{
				index++;
			}
			wcout << L"\t" << ds_lopHoc[i].TenLop << "(" << ds_lopHoc[i].NamNhapHoc << ")";
		}
	}
}

void NhapLop(Lop ds_lopHoc[], int& nLopHoc) {// thêm lớp học thủ công
	wcout << "\n";
	SetColorPro(15);
	do{
	
			SetColorPro(15);
		wcout << L"\t\t\tNhập vào mã lớp học : "; getline(wcin, ds_lopHoc[nLopHoc].MaLop);
	} while (checkIndifferentClassCode(ds_lopHoc, nLopHoc));
	wcout << L"\t\t\tNhập vào tên lớp học: "; getline(wcin, ds_lopHoc[nLopHoc].TenLop);
	wcout << L"\t\t\tNhập vào năm nhập học: "; wcin >> ds_lopHoc[nLopHoc].NamNhapHoc;
	wcin.ignore();
	KhoiTaoListSinhVien(ds_lopHoc[nLopHoc].ds_sv);
	nLopHoc++;
	wcout << "\t\t\t\tDONE!"; Sleep(1000);
}

bool IsStudentIDValid(Lop ds_lopHoc[], int nLophoc, wstring MASV) {
	for (int i = 0; i < nLophoc; i++)
	{
		for (NODES* k = ds_lopHoc[i].ds_sv.pHead; k != NULL; k = k->pNext)
		{
			if (k->sv.MASV == MASV)
			{
				return true;
			}
		}
	}
	return false;
}

void SortClassAccAlphabet(LISTS& list) {
	for (NODES* k = list.pHead; k != NULL; k = k->pNext) //xét node sinh viên
	{
		for (NODES* j = k->pNext; j != NULL; j = j->pNext)
		{
			if (k->sv.Ten != j->sv.Ten) //xét tên 
			{
				//convert to string
				string KName(k->sv.Ten.begin(), k->sv.Ten.end());
				string JName(j->sv.Ten.begin(), j->sv.Ten.end());
				if (strcmp(KName.c_str(), JName.c_str()) == 1)
				{
					swap(k->sv, j->sv);
				}
			}
			else  //xét họ
			{
				string KFName(k->sv.Ho.begin(), k->sv.Ho.end());
				string JFName(j->sv.Ho.begin(), j->sv.Ho.end());
				if (strcmp(KFName.c_str(), JFName.c_str()) == 1)
				{
					swap(k->sv, j->sv);
				}
			}
		}
	}
}

bool checkIndifferentSubjectCode(MH ds_monHoc[], int nMonHoc) {
	for (int i = 0; i < nMonHoc - 1; i++)
	{
		if (ds_monHoc[i].MAMH == ds_monHoc[nMonHoc].MAMH)
		{
			return true;
		}
	}
	return false;
}

void NhapMonHoc(MH ds_monHoc[], int& nMonHoc) {
	do
	{
		wcout << L"\t\t\tNhập vào mã môn học : "; getline(wcin, ds_monHoc[nMonHoc].MAMH);
	} while (checkIndifferentSubjectCode(ds_monHoc, nMonHoc));
	wcout << L"\t\t\tNhập tên môn học: "; getline(wcin, ds_monHoc[nMonHoc].TENMH);
	wcout << L"\t\t\tNhập vào số tín chỉ lý thuyết: "; wcin >> ds_monHoc[nMonHoc].STCLT;
	wcout << L"\t\t\tNhập vào số tín chỉ thực hành: "; wcin >> ds_monHoc[nMonHoc].STCTH;
	nMonHoc++;
	wcout << "\t\t\t\tDONE!"; Sleep(1000);
}

void InDSMonHoc(MH ds_monHoc[], int nMonhoc) {
	for (int i = 0; i < nMonhoc; i++)
	{
		SetColorPro(10);
		wcout << L"\t\t\tMôn học thứ " << i + 1 << " : " << endl;
		SetColorPro(7);
		wcout << L"\t\t\t\tMã môn học : " << ds_monHoc[i].MAMH << endl;
		wcout << L"\t\t\t\tTên môn học : " << ds_monHoc[i].TENMH << endl;
		wcout << L"\t\t\t\tSố tín chỉ lý thuyết : " << ds_monHoc[i].STCLT << endl;
		wcout << L"\t\t\t\tSố tín chỉ thực hành : " << ds_monHoc[i].STCTH << endl;
	}
}

bool IsAnySBOnceTime(SV sv) { 
	if (sv.ds_diem.pHead == NULL) return false;
	for (NODED* k = sv.ds_diem.pHead; k != NULL; k = k->pNext)
	{
		if (k->diem.Lan == 1)
		{
			return true;
		}
	}
	return false;
}

void Menu() {
	ConsoleSetting();
	MH ds_monHoc[MaxSoLuongMonHoc];
	int nMonHoc = 0;
	Lop ds_lopHoc[MaxSoLuongLopHoc]; // list học sinh sẽ được khỏi tạo khi thêm lớp học
	int nLopHoc = 0;
	int luachon;
	luachon = 1;
	do
	{
		system("cls");
		SetColorPro(8);
		wcout << L"\t\t\t\t♦==============="; SetColorPro(11); wcout << L" ☺ Quản lý sinh viên ☺"; SetColorPro(8); wcout << L" ===============♦";
		wcout << L"\n\t\t\t\t•1.Nhập lớp.";
		wcout << L"\n\t\t\t\t•2.Nhập sinh viên của lớp.";
		wcout << L"\n\t\t\t\t•3.Xuất danh sách sinh viên theo niên khóa";
		wcout << L"\n\t\t\t\t•4.In DSSV của 1 lớp theo thứ tự alphabet tăng dần của tên + họ";
		wcout << L"\n\t\t\t\t•5.Nhập môn học";
		wcout << L"\n\t\t\t\t•6.In DS môn học";
		wcout << L"\n\t\t\t\t•7.Nhập điểm";
		wcout << L"\n\t\t\t\t•8.In bảng điểm môn học của 1 lớp theo 1 lần thi";
		wcout << L"\n\t\t\t\t•9.Phiếu điểm in bảng điểm môn học của 1 sinh viên có mã bất kỳ";
		wcout << L"\n\t\t\t\t•0.Thoát chương trình";
		wcout << L"\n\t\t\t\t•Input File: nhập môn, lớp sinh viên.(DSMH.txt,DSSVLopSE,DSSVLopDM)";
		wcout << L"\n\t\t\t\t•Output File: xuất môn, lớp sinh viên.(DSMHout.txt,DSSV+tên lớp+out.txt)";
		wcout << L"\n\t\t\t\t♦====================================================♦";
		SetColorPro(7); wcout << L"\n\t\t\t\tNhập vào lựa chọn của bạn: "; wcin >> luachon; wcin.ignore();
		switch (luachon)
		{
		case 1: {
			if (nLopHoc == MaxSoLuongLopHoc) // các lớp không được trùng mã lớp
			{
				SetColorPro(4);
				wcout << L"\t\t\t\tĐã hết chỗ để thêm lớp học!";
			}
			else
			{
				PrintAllExistClass(ds_lopHoc,nLopHoc);
				NhapLop(ds_lopHoc, nLopHoc); //có kiểm tra trùng id
			}
			break;
		}
		case 2: {
			if (nLopHoc == 0)
			{
				SetColorPro(4);
				wcout << L"\t\t\tChưa có lớp học nào trong danh sách!";	
				SetColorPro(8);
				wcout << L"\n\t\t\t\t(Ấn phím bất kì để tiếp tục)";
				_getch();
				break;
			}
			PrintAllExistClass(ds_lopHoc, nLopHoc);
			wstring maLop;
			wcout << L"\n\t\t\t\tNhập mã lớp mà bạn muốn thêm sinh viên: ";
			getline(wcin, maLop);
			for (size_t i = 0; i < nLopHoc; i++)
			{
				if (ds_lopHoc[i].MaLop == maLop)
				{
					SV sv;
					bool isvalid = false;
					do
					{
						if (isvalid == false)
						{
							isvalid = true;
						}
						else
						{
							SetColorPro(4);
							wcout << L"\n\t\tMã sinh viên này đã tồn tại, xin nhập vào mã khác!";
							SetColorPro(7);
						}
						wcout << L"\n\t\t\tNhập vào mã sinh viên: "; getline(wcin, sv.MASV);
					} while (IsStudentIDValid(ds_lopHoc, nLopHoc, sv.MASV)); // kiểm tra xem có ai có mã sv vậy chưa
					wcout << L"\t\t\tNhập vào họ của sinh viên: "; getline(wcin, sv.Ho);
					wcout << L"\t\t\tNhập vào tên sinh viên: "; getline(wcin, sv.Ten);
					wcout << L"\t\t\tNhập vào giới tính của nhân viên: "; getline(wcin, sv.Phai);
					wcout << L"\t\t\tNhập vào số điện thoại của sinh viên: "; getline(wcin, sv.SDT);
					KhoiTaoListDiem(sv.ds_diem);
					NODES* p = KhoiTaoNodeSinhVien(sv);
					ThemVaoCuoi(ds_lopHoc[i].ds_sv, p);
					wcout << "\t\t\t\tDONE"; Sleep(1000);
					Sleep(1000);
					break;
				}
				if (i == nLopHoc - 1)
				{
					SetColorPro(4);
					wcout << L"\t\t\tKhông tìm thấy lớp nào có mã " << maLop;
					Sleep(3000);
				}
			}
			break;
		}
		case 3: {
			if (nLopHoc == 0)
			{
				SetColorPro(4);
				wcout << L"\t\t\tChưa có lớp học nào trong danh sách!";	Sleep(3000);
				break;
			}
			PrintAllExistClass2(ds_lopHoc, nLopHoc);
			int niemKhoa;
			wcout << L"\n\t\t\t\tNhập niên khóa mà bạn uống in dssv: ";
			wcin >> niemKhoa; wcin.ignore();
			bool isFinded = false;
			for (int i = 0; i < nLopHoc; i++)
			{
				if (ds_lopHoc[i].NamNhapHoc == niemKhoa)
				{
					int index = 1;
					for (NODES* k = ds_lopHoc[i].ds_sv.pHead; k != NULL; k = k->pNext)
					{
						SetColorPro(10);   wcout << L"\t\t\tThông tin sinh viên thứ " << index++ << L" lớp " << ds_lopHoc[i].TenLop << " :";
						SetColorPro(7); wcout << k->sv << endl;
					}
					if (isFinded == false) isFinded = true;
				}
				if (i == nLopHoc - 1 && isFinded == false)
				{
					SetColorPro(4);
					wcout << L"\t\t\tKhông tìm thấy sinh viên nào trong khóa " << niemKhoa;
				}
			}
			SetColorPro(8);
			wcout << L"\n\t\t\t\t(Ấn phím bất kì để tiếp tục)";
			_getch();
			break;
		}
		case 4: {
			if (nLopHoc == 0) // chưa có lớp học nào cả
			{
				SetColorPro(4);
				wcout << L"\t\t\tChưa có lớp học nào trong danh sách!";	Sleep(3000);
				break;
			}
			wstring maLopHoc;
			wcout << L"\t\t\tNhập mã lớp học mà bạn muốn in dssv theo alphabet: ";
			getline(wcin, maLopHoc);
			bool isFinded = false;
			for (int i = 0; i < nLopHoc; i++) {
				if (ds_lopHoc[i].MaLop == maLopHoc)
				{
					SortClassAccAlphabet(ds_lopHoc[i].ds_sv);
					isFinded = true;
					wcout << "\t\t\t\tXong!";
				}
			}
			if (isFinded == false)
			{
				wcout << L"\t\t\tKhông tìm thấy lớp học có mã " << maLopHoc;
			}
			SetColorPro(8);
			wcout << L"\n\t\t\t\t(Ấn phím bất kì để tiếp tục)";
			_getch();
			break;
		}
		case 5: { // mã môn học phải khác nhau
			if (nMonHoc == MaxSoLuongMonHoc) // chết slot
			{
				SetColorPro(4);
				wcout << L"\t\t\t\tĐã hết chỗ để thêm môn học!";
				SetColorPro(8);
				wcout << L"\n\t\t\t\t(Ấn phím bất kì để tiếp tục)";
				_getch();
			}
			else
			{
				NhapMonHoc(ds_monHoc, nMonHoc);
			}
			break;
		}
		case 6: {
			if (nMonHoc == 0) // chưa có môn nào
			{
				SetColorPro(4);
				wcout << L"\t\t\t\tChưa có môn học nào trong danh sách!";
				SetColorPro(8);
				wcout << L"\n\t\t\t\t(Ấn phím bất kì để tiếp tục)";
				_getch();
			}
			else
			{
				InDSMonHoc(ds_monHoc, nMonHoc);
				SetColorPro(8);
				wcout << L"\n\t\t\t\t(Ấn phím bất kì để tiếp tục)";
				_getch();
			}
			break;
		}
		case 7: { //truy cập đến lớp -> học sinh -> xét xem môn có tồn tại không, nhập điểm
			if (nLopHoc == 0) // xét xem trường có lớp nào hông 
			{
				SetColorPro(4);
				wcout << L"\t\t\t\tChưa có lớp học nào cả!";
			}
			if (nMonHoc == 0)
			{
				SetColorPro(4);
				wcout << L"\t\t\t\tChưa có môn học nào được khởi tạo để thêm điểm cả!";
			}
			else
			{
				wstring maLopHoc;
				wcout << L"\t\t\tNhập mã lớp học mà bạn muốn nhập điểm cho sv: ";
				getline(wcin, maLopHoc);
				bool isFinded = false;
				bool isFIndedClass = false;
				for (int i = 0; i < nLopHoc; i++) {
					if (ds_lopHoc[i].MaLop == maLopHoc)
					{
						isFIndedClass = true;
						if (ds_lopHoc[i].ds_sv.pHead == NULL) // lỡ như lớp k có ai thì sao
						{
							SetColorPro(4);
							wcout << L"\t\t\t\tLớp trống không chả có ai lun!"; break;
						}
						wstring maHocSinh;
						wcout << L"\t\t\tNhập mã học sinh mà bạn muốn nhập điểm: ";
						getline(wcin, maHocSinh);
						for (NODES* k = ds_lopHoc[i].ds_sv.pHead; k != NULL; k = k->pNext)
						{
							if (k->sv.MASV == maHocSinh)
							{
								wstring maMonHoc;
								wcout << L"\t\t\t\tNhập vào mã môn học để thêm: ";
								getline(wcin, maMonHoc);
								bool isFindedSubject = false;
								for (size_t j = 0; j < nMonHoc; j++)
								{
									if (ds_monHoc[j].MAMH == maMonHoc)
									{
										DIEM diem;
										diem.MAMH = maMonHoc;
										wcout << L"\t\t\t\tNhập vào số lần thi: "; wcin >> diem.Lan;
										wcout << L"\t\t\t\tNhập vào điểm thi: "; wcin >> diem.diem; wcin.ignore();
										NODED* p = KhoiTaoNODEDiem(diem);
										ThemVaoCuoi(k->sv.ds_diem, p);
										wcout << "\t\t\tDONE!";
										Sleep(2000);
									}
								}
								if (isFindedSubject == false)
								{
									SetColorPro(4);
									wcout << L"\t\t\t\tKhông tìm thấy mã môn học nào như zậy cả!";
								}
								break;
							}
						}
						break;
					}
				}
				if (isFinded == false) //không tìm thấy lớp nào như zậy cả
				{
					SetColorPro(4);
					wcout << L"\t\t\t\tKhông tìm thấy mã lớp học bạn yêu cầu!";
				}
				SetColorPro(8);
				wcout << L"\n\t\t\t\t(Ấn phím bất kì để tiếp tục)";
				_getch(); break;
			}
			break;
		}
		case 8: { //truy cập đến lớp->sinh viên xuất hết môn học
			//8-> In bảng điểm môn học của 1 lớp theo 1 lần thi
			if (nLopHoc == 0) // xét xem trường có lớp nào hông 
			{
				SetColorPro(4);
				wcout << L"\t\t\t\tChưa có lớp học nào cả!";
				SetColorPro(8);
				wcout << L"\n\t\t\t\t(Ấn phím bất kì để tiếp tục)";
				_getch(); break;
			}
			if (nMonHoc == 0)
			{
				SetColorPro(4);
				wcout << L"\t\t\t\tChưa có môn học nào được khởi tạo để thêm điểm cả!";
				SetColorPro(8);
				wcout << L"\n\t\t\t\t(Ấn phím bất kì để tiếp tục)";
				_getch(); break;
			}
			wstring maLopHoc;
			wcout << L"\t\t\tNhập mã lớp học mà bạn muốn in danh sách môn 1 lần thi: ";
			getline(wcin, maLopHoc);
			bool isFinded = false;
			for (int i = 0; i < nLopHoc; i++) {
				if (ds_lopHoc[i].MaLop == maLopHoc)
				{
					SetColorPro(14);
					wcout << L"\t\t\tDanh sách sinh viên có các môn 1 lần thi trong lớp " << ds_lopHoc[i].TenLop << L" là:";
					for (NODES* k = ds_lopHoc[i].ds_sv.pHead; k != NULL; k = k->pNext) //xuất ds học sinh
					{
						int index = 0;
						if (IsAnySBOnceTime(k->sv) == true)
						{
							if (isFinded == false) isFinded = true;
							SetColorPro(10);   wcout << L"\n\t\t\tThông tin sinh viên thứ " << index++ << " :";
							SetColorPro(7);
							wcout << L"\n\t\t\t\tMã sinh viên:" << k->sv.MASV;
							wcout << L"\n\t\t\t\tHọ và tên:" << k->sv.Ho << " " << k->sv.Ten;
							wcout << L"\n\t\t\t\tGiới tính:" << k->sv.Phai;
							wcout << L"\n\t\t\t\tSố điện thoại:" << k->sv.SDT;
							for (NODED* u = k->sv.ds_diem.pHead; u != NULL; u = u->pNext)
							{
								if (u->diem.Lan == 1)
								{
									wcout << L"\n\t\t\t\t•Mã môn: " << u->diem.MAMH << L"  •Lần: " << u->diem.Lan << L" •Điểm: " << u->diem.diem;
								}
							}
						}
					}
				}
				if (isFinded == false)
				{
					SetColorPro(4);
					wcout << L"\n\t\t\t\tKhông tìm thấy sinh viên nào hợp với yêu cầu!";
				}
				SetColorPro(8);
				wcout << L"\n\t\t\t\t(Ấn phím bất kì để tiếp tục)";
				_getch();
				break;
			}
			break;
		}
		case 9: {
			if (nLopHoc == 0) // xét xem trường có lớp nào hông 
			{
				SetColorPro(4);
				wcout << L"\t\t\t\tChưa có lớp học nào cả!";
				SetColorPro(8);
				wcout << L"\n\t\t\t\t(Ấn phím bất kì để tiếp tục)";
				_getch(); break;
			}
			if (nMonHoc == 0)
			{
				SetColorPro(4);
				wcout << L"\t\t\t\tChưa có môn học nào được khởi tạo để thêm điểm cả!";
				SetColorPro(8);
				wcout << L"\n\t\t\t\t(Ấn phím bất kì để tiếp tục)";
				_getch(); break;
			}
			wstring maSV;
			wcout << L"\t\t\tNhập vào mã sv bạn cần in phiếu bảng điểm: "; getline(wcin, maSV);
			bool isFinded = false;
			for (int i = 0; i < nLopHoc; i++)
			{
				for (NODES* k = ds_lopHoc[i].ds_sv.pHead; k != NULL; k = k->pNext)
				{
					if (k->sv.MASV == maSV)
					{
						isFinded = true;
						if (k->sv.ds_diem.pHead == NULL) // kiểm tra xem sv có nhập diểm hay chưa
						{
							SetColorPro(4);
							wcout << L"\t\t\tSinh viên này chưa được nhập điểm!";
						}
						else
						{
							wcout << L"\n\t\t\tHọc sinh: " << k->sv.Ho << " " << k->sv.Ten << "     " << L" Lớp: " << ds_lopHoc[i].TenLop;
							for (NODED* u = k->sv.ds_diem.pHead; u != NULL; u = u->pNext)
							{
								wcout << L"\n\t\t\t\t•Mã môn: " << u->diem.MAMH << L"  •Lần: " << u->diem.Lan << L" •Điểm: " << u->diem.diem;
							}
							break;
						}
					}
				}
			}
			if (isFinded == false)
			{
				SetColorPro(4);
				wcout << L"\t\t\t\tKhông tìm thấy học sinh nào có mã sinh viên như vậy cả.";
			}
			SetColorPro(8);
			wcout << L"\n\t\t\t\t(Ấn phím bất kì để tiếp tục)";
			_getch();
			break;
		}
		case 0: { //thoát, thu hồi vùng nhớ
			SetColorPro(4);
			wcout << L"\n\t\t\tĐang thu hồi vùng nhớ";
			wcout << L"."; Sleep(500);
			for (int i = 0; i < nLopHoc; i++)
			{
				for (NODES* k = ds_lopHoc[i].ds_sv.pHead; k != NULL; ) // xóa ds lk học sinh
				{
					for (NODED* e = k->sv.ds_diem.pHead; e != NULL; ) //xóa ds liên kết điểm
					{
						NODED* d = e;
						e = e->pNext;
						delete d;
					}
					NODES* d = k;
					k = k->pNext;
					delete d;
				}
			}
			wcout << L"."; Sleep(500); wcout << L"."; Sleep(500);
			wcout << L"\n\t\t\tThoát!";
			break;
		}
		default: {
			SetColorPro(4);
			wcout << L"\t\t\t\tCú pháp nhập sai, yêu cầu nhập lại!";
			SetColorPro(8);
			wcout << L"\n\t\t\t\t(Ấn phím bất kì để tiếp tục)";
			_getch();
		}
		}
	} while (luachon != 0);
}