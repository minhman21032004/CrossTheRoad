#include "Basic.h"


HWND Basic::consoleWindow = GetConsoleWindow();
HANDLE Basic::consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);



void Basic::gotoXY(int x, int y)
{

	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { (short int)(x - 1),(short int)(y - 1) };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void Basic::Console_showCursor(bool s)
{
	CONSOLE_CURSOR_INFO info = { 1, s };
	SetConsoleCursorInfo(consoleOutput, &info);
}

int Basic::getKeyInput()
{
	short upState = GetAsyncKeyState(VK_UP);
	short leftState = GetAsyncKeyState(VK_LEFT);
	short downState = GetAsyncKeyState(VK_DOWN);
	short rightState = GetAsyncKeyState(VK_RIGHT);

	short wState = GetAsyncKeyState('W');
	short aState = GetAsyncKeyState('A');
	short sState = GetAsyncKeyState('S');
	short dState = GetAsyncKeyState('D');

	short escState = GetAsyncKeyState(VK_ESCAPE);

	short spaceState = GetAsyncKeyState(VK_SPACE);
	short enterState = GetAsyncKeyState(VK_RETURN);

	short hState = GetAsyncKeyState('H');

	short mState = GetAsyncKeyState('M');
	short zState = GetAsyncKeyState('Z');

	short lMouseState = GetAsyncKeyState(MOUSEEVENTF_MOVE);

	if (upState & 1 || wState & 1)
		return 1;
	if (leftState & 1 || aState & 1)
		return 2;
	if (downState & 1 || sState & 1)
		return 3;
	if (rightState & 1 || dState & 1)
		return 4;
	if (escState & 1)
		return 5;
	if (spaceState & 1 || enterState & 1)
		return 6;
	if (hState & 1)
		return 7;
	if (lMouseState & 1)
		return 8;
	if (mState & 1)
		return 9;
	if (zState & 1)
		return 10;
	return 0;

	/*int c = _getch();
	if (c == 0 || c == 224)
	{
		int c2 = _getch();
		switch (c2)
		{
		case 72: return 1; //up arrow
		case 75: return 2; // left arrow
		case 80: return 3; // down arrow
		case 77: return 4; // right arrow
		default: return 0;
		}
	}
	else
	{
		if (c == 87 || c == 119) return 1; //w or W
		if (c == 65 || c == 97) return 2; // a or A
		if (c == 83 || c == 115) return 3; // s or S
		if (c == 68 || c == 100) return 4; // d or D
		if (c == 27)             return 5;// Esc
		if (c == 32 || c == 13)  return 8;//space or enter
		if (c == 72 || c == 104) return 7;// h or H

		return 0;
	}*/
}

void setConsoleBufferSize(int width, int height) {
	COORD coord;
	coord.X = width;
	coord.Y = height;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setConsoleWindowSize(int width, int height) {
	SMALL_RECT rect;
	rect.Left = 0;
	rect.Top = 0;
	rect.Right = width - 1;
	rect.Bottom = height - 1;
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &rect);
}

void setConsoleWindowPosition(int x, int y) {
	HWND consoleWindow = GetConsoleWindow();
	SetWindowPos(consoleWindow, 0, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}


void Basic::Console_SetAndCenterWindow()
{
	setConsoleBufferSize(136, 31);
	setConsoleWindowSize(136, 31);
	setConsoleWindowPosition(63, 19);
}

void Basic::Console_SetColor(int background, int text)
{
	SetConsoleTextAttribute(consoleOutput, background * 16 + text);
	//background*16 + text: the formula give the correct combination of background and text

}

void Basic::Console_setTitle()
{
	SetConsoleTitleA("CROSS THE ROAD");
}

void Basic::Console_SetFont()
{
	CONSOLE_FONT_INFOEX info;
	info.cbSize = sizeof(info);
	GetCurrentConsoleFontEx(consoleOutput, FALSE, &info);
	info.dwFontSize.X = 12;//input width here
	info.dwFontSize.Y = 24;//input height here
	wcscpy_s(info.FaceName, L"Consolas");//input font here
	SetCurrentConsoleFontEx(consoleOutput, FALSE, &info);

	//Font: Consolas, Size: 24
}

void Basic::Console_DisableMaxSize()
{
	SetWindowLong(consoleWindow, GWL_STYLE,
		GetWindowLong(consoleWindow, GWL_STYLE) & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME));
}

void Basic::Console_HideScrollBar()
{
	ShowScrollBar(consoleWindow, SB_BOTH, 0);

}

void Basic::Console_ClearScreen()
{
	system("cls");
}

void Basic::Console_DisableMouseInput()
{
	DWORD prev_mode;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
}

bool Sound::backgroundSound = true;
bool Sound::sfx = true;
bool Sound::creditSound = true;
bool Sound::gameSound = true;

void Basic::Console_Setup()
{
	Console_SetColor(WHITE, WHITE);
	Console_SetFont();
	Console_SetAndCenterWindow();
	Console_setTitle();
	Console_HideScrollBar();
	Console_showCursor(false);
	Console_DisableMouseInput();
	Console_DisableMaxSize();
	Console_SetColor(WHITE, BLACK);
	Console_ClearScreen();
	Sound::prepareSound();
}

void Basic::textcolor(int x)
{
	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleOutput, x);
}

void Basic::joinThread(std::thread* t)
{
	if (t->joinable())
		t->join();
}

void Basic::sleepFor_second(int sec)
{
	std::this_thread::sleep_for(std::chrono::seconds(sec));
}

void Basic::sleepFor_milisec(int milisec)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milisec));
}

void Basic::Console_setFullscr()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

POINT Basic::getMousePos()
{
	POINT cursorPos;
	if (GetCursorPos(&cursorPos)) {
		// Convert screen coordinates to console coordinates
		HWND console = GetConsoleWindow();
		RECT consoleRect;
		GetClientRect(console, &consoleRect);
		MapWindowPoints(console, NULL, reinterpret_cast<POINT*>(&consoleRect), 2);

		// Check if the cursor is within the console window
		if (cursorPos.x >= consoleRect.left && cursorPos.x <= consoleRect.right &&
			cursorPos.y >= consoleRect.top && cursorPos.y <= consoleRect.bottom) {
			// Calculate relative position inside the console
			int consoleX = cursorPos.x - consoleRect.left;
			int consoleY = cursorPos.y - consoleRect.top;
		}
	}
	return cursorPos;
}

string Basic::get_dateTime()
{
	auto now = std::chrono::system_clock::now();
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
	std::string dateTime = std::ctime(&currentTime);
	return dateTime;
}

void Basic::reFormat(string& str)
{
	while (str.find(' ') != string::npos)
	{
		str.erase(str.find(' '), 1);
	}
	while (str.find(':') != string::npos)
	{
		str.erase(str.find(':'), 1);
	}
	while (str.find('/') != string::npos)
	{
		str.erase(str.find('/'), 1);
	}
	while (str.find('\t') != string::npos)
	{
		str.erase(str.find('\t'), 1);
	}
}



ofstream& operator<<(ofstream& out, vector<string>& List)
{
	out << List.size() << endl;
	for (auto& it : List)
		out << it << endl;
	return out;
}

ifstream& operator>>(ifstream& in, vector<string>& List)
{
	int n;
	in >> n;
	in.ignore();
	string temp;
	for (int i = 0; i < n; i += 1)
	{
		getline(in, temp);
		List.push_back(temp);
	}
	return in;
}
