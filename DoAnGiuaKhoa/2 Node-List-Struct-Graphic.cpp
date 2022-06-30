#include"2 Node-List-Struct-Graphic.h"
void KhoiTaoListDiem(LISTD& ld) {
	ld.pHead = NULL;
	ld.pTail = NULL;
}
NODED* KhoiTaoNODEDiem(DIEM diem) {
	NODED* p = new NODED;
	if (p == NULL) // cap phat that bai
	{
		wcout << L"Không đủ vùng nhớ cấp phát";
		return NULL;
	}
	p->diem = diem;
	p->pNext = NULL;
	return p;
}
wostream& operator<<(wostream& os, SV sv) { //nhập sinh viên
	SetColorPro(3); wcout << L"\n\t\t\t\tMã sinh viên: "; SetColorPro(7); wcout << sv.MASV;
	SetColorPro(3); wcout << L"\n\t\t\t\tHọ và tên: "; SetColorPro(7); wcout << sv.Ho << " " << sv.Ten;
	SetColorPro(3); wcout << L"\n\t\t\t\tGiới tính: "; SetColorPro(7); wcout << sv.Phai; SetColorPro(3); wcout << L"\tSố điện thoại:"; SetColorPro(7); wcout << sv.SDT;
	if (sv.ds_diem.pHead == NULL)
	{
		SetColorPro(4); wcout << L"\n\t\t\t\tSinh viên chưa được nhập điểm!";
	}
	else
	{
		for (NODED* u = sv.ds_diem.pHead; u != NULL; u = u->pNext)
		{
			SetColorPro(9); wcout << L"\n\t\t\t\t• Mã môn: "; SetColorPro(7); wcout << u->diem.MAMH;
			SetColorPro(9); wcout << L"  • Lần thi: "; SetColorPro(7); wcout << u->diem.Lan;
			SetColorPro(9); wcout << L" • Điểm: "; SetColorPro(7); wcout << u->diem.diem;
		}
	}
	return os;
}

NODES* KhoiTaoNodeSinhVien(SV sv) {
	NODES* p = new NODES;
	if (p == NULL) // cap phat that bai
	{
		wcout << L"Không đủ vùng nhớ cấp phát";
		return NULL;
	}
	p->sv = sv;
	p->pNext = NULL;
	return p;
}

void KhoiTaoListSinhVien(LISTS& ls) {
	ls.pHead = NULL;
	ls.pTail = NULL;
}


void SetColorPro(int i) { //cài màu
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, i);
}

void SetCharacterSize(int height) { //set cỡ chữ
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = height;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void ConsoleSetting() {
	SetCharacterSize(CharacterSize);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	resizeConsole(1920, 1080);
}