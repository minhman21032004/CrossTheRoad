#include "UserInterface.h"
mutex UImtx;

int checkXdrawWhite(int x) {
	if (x <= 8) return -1;
	else if (x > 8 && x <= 20) return 0;
	else if (x > 20 && x <= 32) return 1;
	else if (x > 32 && x <= 44) return 2;
	else if (x > 44 && x <= 56) return 3;
	else if (x > 56 && x <= 68) return 4;
	else if (x > 68 && x <= 80) return 5;
	else if (x > 80 && x <= 92) return 6;
	else if (x > 92 && x <= 104) return 7;
	else if (x > 104 && x <= 116) return 8;
	else if (x > 116 && x <= 128) return 9;
}


void UserInterface::Drawbox(int x, int y, int width, int height, int t_color, int b_color )
{
	UImtx.lock();
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	for (int _X = x; _X < x + width; _X++) {
		for (int _Y = y; _Y < y + height; _Y++) {
			Basic::gotoXY(_X, _Y);
			Basic::Console_SetColor(b_color, b_color);
			cout << u8"█";
		}
	}
	for (int _X = x; _X < x + width; _X++) {
		Basic::gotoXY(_X, y);
		Basic::Console_SetColor(b_color, t_color);
		cout << u8"▀";
		Basic::gotoXY(_X, y + height - 1);
		Basic::Console_SetColor(b_color, t_color);
		cout << u8"▄";
	}
	for (int _Y = y; _Y < y + height; _Y++) {
		Basic::gotoXY(x, _Y);
		Basic::Console_SetColor(b_color, t_color);
		cout << u8"█";
		Basic::gotoXY(x + width - 1, _Y);
		Basic::Console_SetColor(b_color, t_color);
		cout << u8"█";
	}
	SetConsoleOutputCP(oldcp);
	UImtx.unlock();
}

void UserInterface::DrawParrot(int x, int y, bool mode, int background_Color) { //dthien
	UImtx.lock();
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);

	if (mode == true) {
		Basic::gotoXY(x + 1, y);
		if (background_Color == BLUE) {
			Basic::Console_SetColor(DARKBLUE, RED);
			cout << u8"▄";
		}
		else if (background_Color == BLACK) {
			Basic::Console_SetColor(LIGHTGREY, RED);
			cout << u8"▄";
		}
		else {
			Basic::Console_SetColor(background_Color, RED);
			cout << u8"▄";
		}
		Basic::Console_SetColor(WHITE, RED);
		cout << u8"▀";
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, RED);
		cout << u8"█";
		if (background_Color == BLUE) {
			Basic::Console_SetColor(DARKBLUE, RED);
			cout << u8"▄";
		}
		else if (background_Color == BLACK) {
			Basic::Console_SetColor(LIGHTGREY, RED);
			cout << u8"▄";
		}
		else {
			Basic::Console_SetColor(background_Color, RED);
			cout << u8"▄";
		}
		Basic::gotoXY(x + 1, y + 1);
		Basic::Console_SetColor(background_Color, RED);
		cout << u8"█";
		Basic::Console_SetColor(WHITE, RED);
		cout << u8"▄";
		Basic::Console_SetColor(WHITE, RED);
		cout << u8" ";
		Basic::Console_SetColor(BLACK, YELLOW);
		cout << u8"▀";
		Basic::Console_SetColor(YELLOW, YELLOW);
		cout << u8"█";
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(background_Color, RED);
		cout << u8"▀";
		Basic::Console_SetColor(DARKGREEN, GOLDEN);
		cout << u8"▀";
		Basic::Console_SetColor(LIGHTBLUE, BLUE);
		cout << u8"▀";
		Basic::Console_SetColor(RED, LIGHTRED);
		cout << u8"▀";
		Basic::Console_SetColor(RED, WHITE);
		cout << u8"▀";

	}
	else {
		Basic::gotoXY(x + 1, y);
		if (background_Color == BLUE) {
			Basic::Console_SetColor(DARKBLUE, background_Color);
			cout << u8"▄▄▄▄▄";
		}
		else if (background_Color == BLACK) {
			Basic::Console_SetColor(LIGHTGREY, background_Color);
			cout << u8"▄▄▄▄▄";
		}
		else {
			Basic::Console_SetColor(background_Color, background_Color);
			cout << u8"▄▄▄▄▄";
		}
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8" ";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8" ";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		if (background_Color == BLACK) {
			if (checkXdrawWhite(x) == -1) {
				Basic::gotoXY(1, y + 1);
				Basic::Console_SetColor(WHITE, background_Color);
				cout << u8"▀▀▀▀";
			}
			else if (x == 8) {
				Basic::gotoXY(13, y + 1);
				Basic::Console_SetColor(WHITE, background_Color);
				cout << u8"▀▀▀▀";
			}
			else {
				Basic::gotoXY(13 + 12 * (checkXdrawWhite(x + 1)), y + 1);
				Basic::Console_SetColor(WHITE, background_Color);
				cout << u8"▀▀▀▀";
			}
		}
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";

	}
	SetConsoleOutputCP(oldcp);
	UImtx.unlock();
}


void UserInterface::DrawPenguin(int x, int y, bool mode, int background_Color) { //dthien
	UImtx.lock();
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 1) {
		Basic::gotoXY(x + 2, y);
		Basic::Console_SetColor(background_Color, DARKBLUE);
		cout << u8"█";
		Basic::Console_SetColor(BLACK, DARKBLUE);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, DARKBLUE);
		cout << u8"█";
		if (background_Color == BLUE) {
			Basic::Console_SetColor(DARKBLUE, YELLOW);
			cout << u8"▄";
		}
		else if (background_Color == BLACK) {
			Basic::Console_SetColor(LIGHTGREY, YELLOW);
			cout << u8"▄";
		}
		else {
			Basic::Console_SetColor(background_Color, YELLOW);
			cout << u8"▄";
		}
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, DARKBLUE);
		cout << u8"▀";
		if (background_Color == BLACK) {
			if (x % 12 <= 4 && x % 12 > 0) {
				Basic::gotoXY(x, y + 1);
				Basic::Console_SetColor(WHITE, DARKBLUE);
				cout << u8"▀";
			}
		}
		Basic::Console_SetColor(background_Color, DARKBLUE);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, DARKBLUE);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, LIGHTGREY);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, DARKBLUE);
		cout << u8"█";
		Basic::gotoXY(x + 1, y + 2);
		Basic::Console_SetColor(background_Color, DARKBLUE);
		cout << u8"▀";
		Basic::Console_SetColor(YELLOW, LIGHTGREY);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, DARKBLUE);
		cout << u8"▀";
	}
	else {
		Basic::gotoXY(x + 2, y);
		if (background_Color == BLUE) {
			Basic::Console_SetColor(DARKBLUE, background_Color);
			cout << u8"▄▄▄▄";
		}
		else if (background_Color == BLACK) {
			Basic::Console_SetColor(LIGHTGREY, background_Color);
			cout << u8"▄▄▄▄";
		}
		else {
			Basic::Console_SetColor(background_Color, background_Color);
			cout << u8"▄▄▄▄";
		}
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 1, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		if (background_Color == BLACK) {
			if (checkXdrawWhite(x) == -1) {
				Basic::gotoXY(1, y + 1);
				Basic::Console_SetColor(WHITE, background_Color);
				cout << u8"▀▀▀▀";
			}
			else {
				Basic::gotoXY(13 + 12 * (checkXdrawWhite(x)), y + 1);
				Basic::Console_SetColor(WHITE, background_Color);
				cout << u8"▀▀▀▀";
			}
		}
	}
	SetConsoleOutputCP(oldcp);
	UImtx.unlock();
}

bool checkXRoadLane(int x) { //dthien
	if (x == 8 || x == 9 || x == 10 || x == 11) return true;
	else if (x == 20 || x == 21 || x == 22 || x == 23) return true;
	else if (x == 32 || x == 33 || x == 34 || x == 35) return true;
	else if (x == 44 || x == 45 || x == 46 || x == 47) return true;
	else if (x == 56 || x == 57 || x == 58 || x == 59) return true;
	else if (x == 68 || x == 69 || x == 70 || x == 71) return true;
	else if (x == 80 || x == 81 || x == 82 || x == 83) return true;
	else if (x == 92 || x == 93 || x == 94 || x == 95) return true;
	else if (x == 104 || x == 105 || x == 106 || x == 107) return true;
	else if (x == 116 || x == 117 || x == 118 || x == 119) return true;
	return false;
}

void UserInterface::DrawChicken(int x, int y, bool mode, int background_Color) { //dthien
	UImtx.lock();
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 1) {
		Basic::gotoXY(x + 2, y);
		if (background_Color == BLUE) {
			Basic::Console_SetColor(DARKBLUE, YELLOW);
			cout << u8"▄";
		}
		else if (background_Color == BLACK) {
			Basic::Console_SetColor(LIGHTGREY, YELLOW);
			cout << u8"▄";
		}
		else {
			Basic::Console_SetColor(background_Color, YELLOW);
			cout << u8"▄";
		}
		Basic::Console_SetColor(RED, YELLOW);
		cout << u8"▄▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▀";
		if (background_Color == BLACK) {
			if (x % 12 > 0 && x % 12 <= 4) {
				Basic::gotoXY(x, y + 1);
				Basic::Console_SetColor(WHITE, YELLOW);
				cout << u8"▀";
			}
		}
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"█";
		Basic::Console_SetColor(BLACK, GOLDEN);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, RED);
		cout << u8"▀";
		if (background_Color == BLACK) {
			if (checkXRoadLane(x)) {
				Basic::gotoXY(x + 5, y + 1);
				Basic::Console_SetColor(WHITE, RED);
				cout << u8"▀";
			}
		}
		Basic::gotoXY(x + 1, y + 2);
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▀";
		Basic::Console_SetColor(RED, GOLDEN);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▀";
	}
	else {
		Basic::gotoXY(x + 2, y);
		if (background_Color == BLUE) {
			Basic::Console_SetColor(DARKBLUE, background_Color);
			cout << u8"▄▄▄";
		}
		else if (background_Color == BLACK) {
			Basic::Console_SetColor(LIGHTGREY, background_Color);
			cout << u8"▄▄▄";
		}
		else {
			Basic::Console_SetColor(background_Color, background_Color);
			cout << u8"▄▄▄";
		}
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		if (background_Color == BLACK) {
			if (checkXdrawWhite(x) == -1) {
				Basic::gotoXY(1, y + 1);
				Basic::Console_SetColor(WHITE, background_Color);
				cout << u8"▀▀▀▀";
			}
			else if (x == 8) {
				Basic::gotoXY(13, y + 1);
				Basic::Console_SetColor(WHITE, background_Color);
				cout << u8"▀▀▀▀";
			}
			else {
				Basic::gotoXY(13 + 12 * (checkXdrawWhite(x + 1)), y + 1);
				Basic::Console_SetColor(WHITE, background_Color);
				cout << u8"▀▀▀▀";
			}
		}
		Basic::gotoXY(x + 1, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";


	}
	SetConsoleOutputCP(oldcp);
	UImtx.unlock();
}

void UserInterface::DrawDog(int x, int y, bool mode, int background_Color) {
	UImtx.lock();
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 1) {
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(BLACK, GREY);
		cout << u8"▄";
		Basic::gotoXY(x + 3, y);
		Basic::Console_SetColor(background_Color, GREY);
		cout << u8"██";
		Basic::Console_SetColor(BLACK, GREY);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, GREY);
		cout << u8"▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(BLACK, GREY);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, GREY);
		cout << u8"████";
		Basic::Console_SetColor(background_Color, GREY);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(background_Color, GREY);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 3, y + 2);
		Basic::Console_SetColor(background_Color, GREY);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";

	}
	else {
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(BLACK, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 3, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"██";
		Basic::Console_SetColor(BLACK, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"████";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 3, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
	}
	SetConsoleOutputCP(oldcp);
	UImtx.unlock();
}

void UserInterface::DrawBug(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 1) {
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(BLACK, GREY);
		cout << u8"▄";
		Basic::gotoXY(x + 3, y);
		Basic::Console_SetColor(background_Color, GREY);
		cout << u8"██";
		Basic::Console_SetColor(BLACK, GREY);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, GREY);
		cout << u8"▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(BLACK, GREY);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, GREY);
		cout << u8"████";
		Basic::Console_SetColor(background_Color, GREY);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(background_Color, GREY);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 3, y + 2);
		Basic::Console_SetColor(background_Color, GREY);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";

	}
	else {
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(BLACK, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 3, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"██";
		Basic::Console_SetColor(BLACK, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"████";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 3, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawBee(int x, int y, bool mode, int background_Color) {
	UImtx.lock();
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 1) {
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▀▀";
		Basic::Console_SetColor(YELLOW, BLACK);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, GOLDEN);
		cout << u8"█";
		Basic::Console_SetColor(BLACK, GOLDEN);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, GOLDEN);
		cout << u8"█";
		Basic::Console_SetColor(BLACK, background_Color);
		cout << u8"▀";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, GOLDEN);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, GOLDEN);
		cout << u8"█";
		Basic::Console_SetColor(BLACK, GOLDEN);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, GOLDEN);
		cout << u8"███";
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, GOLDEN);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, GOLDEN);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, GOLDEN);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, GOLDEN);
		cout << u8"▀";
	}
	else {
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"███";
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
	}
	SetConsoleOutputCP(oldcp);
	UImtx.unlock();
}

void UserInterface::DrawRCar(int x, int y, bool mode, int background_Color) {
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 1) {
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(LIGHTGREY, RED);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, LIGHTRED);
		cout << u8"████";
		Basic::Console_SetColor(LIGHTGREY, WHITE);
		cout << u8"▄";
		Basic::Console_SetColor(LIGHTGREY, RED);
		cout << u8"▄▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, LIGHTRED);
		cout << u8"█";
		Basic::Console_SetColor(LIGHTRED, RED);
		cout << u8"▄▄▄▄";
		Basic::Console_SetColor(background_Color, WHITE);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, LIGHTRED);
		cout << u8"██";
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(RED, GREY);
		cout << u8"▄";
		Basic::Console_SetColor(WHITE, GREY);
		cout << u8"▄";
		Basic::Console_SetColor(WHITE, RED);
		cout << u8"▄▄▄";
		Basic::Console_SetColor(RED, GREY);
		cout << u8"▄";
		Basic::Console_SetColor(LIGHTRED, GREY);
		cout << u8"▄";
		Basic::Console_SetColor(LIGHTRED, RED);
		cout << u8"▄";
	}
	else {
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"████";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄▄▄▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"██";
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄▄▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
	}

	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawBCar(int x, int y, bool mode, int background_Color) {
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 1) {
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(LIGHTGREY, DARKBLUE);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, BLUE);
		cout << u8"████";
		Basic::Console_SetColor(LIGHTGREY, DARKBLUE);
		cout << u8"▄";
		Basic::Console_SetColor(LIGHTGREY, DARKBLUE);
		cout << u8"▄▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, BLUE);
		cout << u8"█";
		Basic::Console_SetColor(BLUE, DARKBLUE);
		cout << u8"▄▄▄▄";
		Basic::Console_SetColor(background_Color, WHITE);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, BLUE);
		cout << u8"██";
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(DARKBLUE, GREY);
		cout << u8"▄";
		Basic::Console_SetColor(WHITE, GREY);
		cout << u8"▄";
		Basic::Console_SetColor(WHITE, DARKBLUE);
		cout << u8"▄▄▄";
		Basic::Console_SetColor(DARKBLUE, GREY);
		cout << u8"▄";
		Basic::Console_SetColor(BLUE, GREY);
		cout << u8"▄";
		Basic::Console_SetColor(BLUE, DARKBLUE);
		cout << u8"▄";
	}
	else {
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"████";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄▄▄▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"██";
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄▄▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
	}


	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawTruck(int x, int y, bool mode, int background_Color) {
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 1) {
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, LIGHTGREY);
		cout << u8"█";
		Basic::Console_SetColor(RED, LIGHTGREY);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, LIGHTGREY);
		cout << u8"█";
		Basic::Console_SetColor(RED, LIGHTGREY);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, LIGHTGREY);
		cout << u8"█";
		Basic::gotoXY(x + 6, y);
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"█";
		Basic::Console_SetColor(YELLOW, LIGHTGREY);
		cout << u8"▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, LIGHTGREY);
		cout << u8"█";
		Basic::Console_SetColor(RED, LIGHTGREY);
		cout << u8"▀";
		Basic::Console_SetColor(RED, LIGHTGREY);
		cout << u8"▄";
		Basic::Console_SetColor(RED, LIGHTGREY);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, LIGHTGREY);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, GREY);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"█";
		Basic::Console_SetColor(YELLOW, LIGHTGREY);
		cout << u8"▀▀";
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"█";
		Basic::Console_SetColor(GREY, YELLOW);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"███";
		Basic::Console_SetColor(GREY, YELLOW);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"█";
	}
	else {
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 6, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀▀";
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"███";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
	}

	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawTrain(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 1) {
		Basic::gotoXY(x, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 1, y + 3);
		Basic::Console_SetColor(BLACK, GOLDEN);
		cout << u8"▄";
		Basic::gotoXY(x + 2, y + 2);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 2, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, GOLDEN);
		cout << u8"█";
		Basic::gotoXY(x + 3, y + 2);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 3, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 4, y + 1);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 4, y + 2);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 4, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, LIGHTGREY);
		cout << u8"█";
		Basic::gotoXY(x + 5, y + 1);
		Basic::Console_SetColor(BLACK, GOLDEN);
		cout << u8"▄";
		Basic::gotoXY(x + 5, y + 2);
		Basic::Console_SetColor(GOLDEN, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 5, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 6, y);
		Basic::Console_SetColor(BLACK, LIGHTBLUE);
		cout << u8"▄";
		Basic::gotoXY(x + 6, y + 1);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 6, y + 2);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 6, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, GREY);
		cout << u8"█";
		Basic::gotoXY(x + 7, y);
		Basic::Console_SetColor(LIGHTGREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 7, y + 1);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 7, y + 2);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 7, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, GREY);
		cout << u8"█";
		Basic::gotoXY(x + 8, y);
		Basic::Console_SetColor(LIGHTGREY, RED);
		cout << u8"▄";
		Basic::gotoXY(x + 8, y + 1);
		Basic::Console_SetColor(LIGHTGREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 8, y + 2);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 8, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 9, y);
		Basic::Console_SetColor(LIGHTGREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 9, y + 1);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 9, y + 2);
		Basic::Console_SetColor(GOLDEN, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 9, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, LIGHTGREY);
		cout << u8"█";
		Basic::gotoXY(x + 10, y);
		Basic::Console_SetColor(BLACK, LIGHTBLUE);
		cout << u8"▄";
		Basic::gotoXY(x + 10, y + 1);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 10, y + 2);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 10, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 11, y + 1);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 11, y + 2);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 11, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 12, y);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 12, y + 1);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 12, y + 2);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y);
		Basic::Console_SetColor(PURPLE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 13, y + 1);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 2);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(PURPLE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(LIGHTBLUE, RED);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 14, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, LIGHTGREY);
		cout << u8"█";
		Basic::gotoXY(x + 15, y);
		Basic::Console_SetColor(PURPLE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 15, y + 1);
		Basic::Console_SetColor(RED, LIGHTGREY);
		cout << u8"▄";
		Basic::gotoXY(x + 15, y + 2);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 15, y + 3);
		Basic::Console_SetColor(BLACK, LIGHTGREY);
		cout << u8"▄";
		Basic::gotoXY(x + 16, y);
		Basic::Console_SetColor(PURPLE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 16, y + 1);
		Basic::Console_SetColor(LIGHTBLUE, RED);
		cout << u8"█";
		Basic::gotoXY(x + 16, y + 2);
		Basic::Console_SetColor(RED, GREY);
		cout << u8"▄";
		Basic::gotoXY(x + 16, y + 3);
		Basic::Console_SetColor(GREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 17, y);
		Basic::Console_SetColor(PURPLE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 17, y + 1);
		Basic::Console_SetColor(LIGHTBLUE, RED);
		cout << u8"█";
		Basic::gotoXY(x + 17, y + 2);
		Basic::Console_SetColor(GREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 17, y + 3);
		Basic::Console_SetColor(BLACK, GREY);
		cout << u8"▄";
		Basic::gotoXY(x + 18, y);
		Basic::Console_SetColor(PURPLE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 18, y + 1);
		Basic::Console_SetColor(LIGHTBLUE, RED);
		cout << u8"█";
		Basic::gotoXY(x + 18, y + 2);
		Basic::Console_SetColor(GREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 18, y + 3);
		Basic::Console_SetColor(BLACK, GREY);
		cout << u8"▄";
		Basic::gotoXY(x + 19, y);
		Basic::Console_SetColor(PURPLE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 19, y + 1);
		Basic::Console_SetColor(LIGHTBLUE, RED);
		cout << u8"█";
		Basic::gotoXY(x + 19, y + 2);
		Basic::Console_SetColor(RED, GREY);
		cout << u8"▄";
		Basic::gotoXY(x + 19, y + 3);
		Basic::Console_SetColor(GREY, LIGHTGREY);
		cout << u8"▄";
		Basic::gotoXY(x + 20, y);
		Basic::Console_SetColor(PURPLE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 20, y + 1);
		Basic::Console_SetColor(RED, LIGHTGREY);
		cout << u8"▄";
		Basic::gotoXY(x + 20, y + 2);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 20, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, LIGHTGREY);
		cout << u8"▄";
		Basic::gotoXY(x + 21, y);
		Basic::Console_SetColor(PURPLE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 21, y + 1);
		Basic::Console_SetColor(LIGHTBLUE, RED);
		cout << u8"█";
		Basic::gotoXY(x + 21, y + 2);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 21, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, LIGHTGREY);
		cout << u8"▄";
		Basic::gotoXY(x + 22, y);
		Basic::Console_SetColor(PURPLE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 22, y + 1);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 22, y + 2);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 22, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, GREY);
		cout << u8"▄";
		Basic::gotoXY(x + 23, y);
		Basic::Console_SetColor(PURPLE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 23, y + 2);
		Basic::Console_SetColor(BLACK, LIGHTBLUE);
		cout << u8"▄";
		Basic::gotoXY(x + 23, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, LIGHTGREY);
		cout << u8"▄";
		Basic::gotoXY(x + 24, y + 2);
		Basic::Console_SetColor(BLACK, LIGHTBLUE);
		cout << u8"▄";
		Basic::gotoXY(x + 24, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, LIGHTGREY);
		cout << u8"▄";
		Basic::gotoXY(x + 25, y + 1);
		Basic::Console_SetColor(BLACK, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 25, y + 2);
		Basic::Console_SetColor(BLACK, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 25, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 26, y);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 26, y + 1);
		Basic::Console_SetColor(LIGHTGREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 26, y + 2);
		Basic::Console_SetColor(GOLDEN, RED);
		cout << u8"▄";
		Basic::gotoXY(x + 26, y + 3);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 27, y);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 27, y + 1);
		Basic::Console_SetColor(LIGHTGREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 27, y + 2);
		Basic::Console_SetColor(GOLDEN, RED);
		cout << u8"▄";
		Basic::gotoXY(x + 27, y + 3);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 28, y);
		Basic::Console_SetColor(BLACK, LIGHTGREY);
		cout << u8"▄";
		Basic::gotoXY(x + 28, y + 1);
		Basic::Console_SetColor(LIGHTGREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 28, y + 2);
		Basic::Console_SetColor(GOLDEN, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 28, y + 3);
		Basic::Console_SetColor(RED, GREY);
		cout << u8"█";
		Basic::gotoXY(x + 29, y);
		Basic::Console_SetColor(BLACK, LIGHTGREY);
		cout << u8"▄";
		Basic::gotoXY(x + 29, y + 1);
		Basic::Console_SetColor(LIGHTGREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 29, y + 2);
		Basic::Console_SetColor(GOLDEN, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 29, y + 3);
		Basic::Console_SetColor(RED, GREY);
		cout << u8"█";
		Basic::gotoXY(x + 30, y);
		Basic::Console_SetColor(BLACK, LIGHTGREY);
		cout << u8"▄";
		Basic::gotoXY(x + 30, y + 1);
		Basic::Console_SetColor(LIGHTGREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 30, y + 2);
		Basic::Console_SetColor(GOLDEN, RED);
		cout << u8"▄";
		Basic::gotoXY(x + 30, y + 3);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 31, y);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 31, y + 1);
		Basic::Console_SetColor(LIGHTGREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 31, y + 2);
		Basic::Console_SetColor(GOLDEN, RED);
		cout << u8"▄";
		Basic::gotoXY(x + 31, y + 3);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 32, y);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 32, y + 1);
		Basic::Console_SetColor(LIGHTGREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 32, y + 2);
		Basic::Console_SetColor(GOLDEN, RED);
		cout << u8"▄";
		Basic::gotoXY(x + 32, y + 3);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 33, y);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 33, y + 1);
		Basic::Console_SetColor(LIGHTGREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 33, y + 2);
		Basic::Console_SetColor(GOLDEN, RED);
		cout << u8"▄";
		Basic::gotoXY(x + 33, y + 3);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 34, y);
		Basic::Console_SetColor(BLACK, LIGHTGREY);
		cout << u8"▄";
		Basic::gotoXY(x + 34, y + 1);
		Basic::Console_SetColor(LIGHTGREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 34, y + 2);
		Basic::Console_SetColor(GOLDEN, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 34, y + 3);
		Basic::Console_SetColor(RED, GREY);
		cout << u8"█";
		Basic::gotoXY(x + 35, y);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 35, y + 1);
		Basic::Console_SetColor(LIGHTGREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 35, y + 2);
		Basic::Console_SetColor(GOLDEN, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 35, y + 3);
		Basic::Console_SetColor(RED, GREY);
		cout << u8"█";
		Basic::gotoXY(x + 36, y);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 36, y + 1);
		Basic::Console_SetColor(LIGHTGREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 36, y + 2);
		Basic::Console_SetColor(GOLDEN, RED);
		cout << u8"▄";
		Basic::gotoXY(x + 36, y + 3);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 37, y);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 37, y + 1);
		Basic::Console_SetColor(LIGHTGREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 37, y + 2);
		Basic::Console_SetColor(GOLDEN, RED);
		cout << u8"▄";
		Basic::gotoXY(x + 37, y + 3);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 38, y + 1);
		Basic::Console_SetColor(BLACK, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 38, y + 2);
		Basic::Console_SetColor(BLACK, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 38, y + 3);
		Basic::Console_SetColor(LIGHTBLUE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 39, y + 2);
		Basic::Console_SetColor(BLACK, LIGHTBLUE);
		cout << u8"▄";
	}
	else {
		Basic::gotoXY(x, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 1, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 2, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 2, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 3, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 3, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 4, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 4, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 4, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 5, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 5, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 5, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 6, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 6, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 6, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 6, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 7, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 7, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 7, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 7, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 8, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 8, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 8, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 8, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 9, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 9, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 9, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 9, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 10, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 10, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 10, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 10, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 11, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 11, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 11, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 12, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 12, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 12, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 13, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 13, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 14, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 15, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 15, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 15, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 15, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 16, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 16, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 16, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 16, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 17, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 17, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 17, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 17, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 18, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 18, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 18, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 18, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 19, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 19, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 19, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 19, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 20, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 20, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 20, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 20, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 21, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 21, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 21, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 21, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 22, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 22, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 22, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 22, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 23, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 23, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 23, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 24, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 24, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 25, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 25, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 25, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 26, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 26, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 26, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 26, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 27, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 27, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 27, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 27, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 28, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 28, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 28, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 28, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 29, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 29, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 29, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 29, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 30, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 30, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 30, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 30, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 31, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 31, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 31, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 31, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 32, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 32, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 32, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 32, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 33, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 33, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 33, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 33, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 34, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 34, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 34, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 34, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 35, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 35, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 35, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 35, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 36, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 36, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 36, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 36, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 37, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 37, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 37, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 37, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x + 38, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 38, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 38, y + 3);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x + 39, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
	}
	SetConsoleOutputCP(oldcp);
}


void UserInterface::DrawReverseRCar(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 1) {
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(LIGHTGREY, RED);
		cout << u8"▄▄";
		Basic::Console_SetColor(background_Color, WHITE);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, LIGHTRED);
		cout << u8"████";
		Basic::Console_SetColor(LIGHTGREY, RED);
		cout << u8"▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, LIGHTRED);
		cout << u8"██";
		Basic::Console_SetColor(background_Color, WHITE);
		cout << u8"█";
		Basic::Console_SetColor(LIGHTRED, RED);
		cout << u8"▄▄▄▄";
		Basic::Console_SetColor(background_Color, LIGHTRED);
		cout << u8"█";
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(LIGHTRED, RED);
		cout << u8"▄";
		Basic::Console_SetColor(LIGHTRED, GREY);
		cout << u8"▄";
		Basic::Console_SetColor(RED, GREY);
		cout << u8"▄";
		Basic::Console_SetColor(WHITE, RED);
		cout << u8"▄▄▄";
		Basic::Console_SetColor(WHITE, GREY);
		cout << u8"▄";
		Basic::Console_SetColor(RED, GREY);
		cout << u8"▄";

	}
	else {
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"████";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"██";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄▄▄▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄▄▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawReverseBCar(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 1) {
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, DARKBLUE);
		cout << u8"▄▄";
		Basic::Console_SetColor(background_Color, WHITE);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, BLUE);
		cout << u8"████";
		Basic::Console_SetColor(background_Color, DARKBLUE);
		cout << u8"▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, BLUE);
		cout << u8"██";
		Basic::Console_SetColor(background_Color, WHITE);
		cout << u8"█";
		Basic::Console_SetColor(BLUE, DARKBLUE);
		cout << u8"▄▄▄▄";
		Basic::Console_SetColor(background_Color, BLUE);
		cout << u8"█";
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(BLUE, DARKBLUE);
		cout << u8"▄";
		Basic::Console_SetColor(BLUE, GREY);
		cout << u8"▄";
		Basic::Console_SetColor(DARKBLUE, GREY);
		cout << u8"▄";
		Basic::Console_SetColor(WHITE, DARKBLUE);
		cout << u8"▄▄▄";
		Basic::Console_SetColor(WHITE, GREY);
		cout << u8"▄";
		Basic::Console_SetColor(DARKBLUE, GREY);
		cout << u8"▄";

	}
	else {
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"████";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"██";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄▄▄▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄▄▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawReverseTruck(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 1) {
		Basic::gotoXY(x + 1, y);
		Basic::Console_SetColor(YELLOW, LIGHTGREY);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"█";
		Basic::gotoXY(x + 4, y);
		Basic::Console_SetColor(background_Color, LIGHTGREY);
		cout << u8"█";
		Basic::Console_SetColor(RED, LIGHTGREY);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, LIGHTGREY);
		cout << u8"█";
		Basic::Console_SetColor(RED, LIGHTGREY);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, LIGHTGREY);
		cout << u8"█";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(YELLOW, LIGHTGREY);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, GREY);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, LIGHTGREY);
		cout << u8"█";
		Basic::Console_SetColor(RED, LIGHTGREY);
		cout << u8"▀";
		Basic::Console_SetColor(RED, LIGHTGREY);
		cout << u8"▄";
		Basic::Console_SetColor(RED, LIGHTGREY);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, LIGHTGREY);
		cout << u8"█";
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"█";
		Basic::Console_SetColor(GREY, YELLOW);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"███";
		Basic::Console_SetColor(GREY, YELLOW);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"█";
	}
	else {
		Basic::gotoXY(x + 1, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::gotoXY(x + 4, y);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▄";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀▀";
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"███";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"▀▀";
		Basic::Console_SetColor(background_Color, background_Color);
		cout << u8"█";
	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::TestColor(int x, int y, int color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	Basic::gotoXY(x, y);
	Basic::Console_SetColor(color, color);
	cout << u8"███";
	Basic::gotoXY(x, y + 1);
	Basic::Console_SetColor(color, color);
	cout << u8"███";
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawSafeLane(int x, int y, int background_Color)
{
	UImtx.lock();
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	for (int _X = 1; _X < 132; _X++) {
		Basic::gotoXY(_X, y);
		Basic::Console_SetColor(background_Color, GREEN);
		cout << u8"█";
		Basic::gotoXY(_X, y + 1);
		Basic::Console_SetColor(background_Color, GREEN);
		cout << u8"█";
		Basic::gotoXY(_X, y + 2);
		Basic::Console_SetColor(background_Color, GREEN);
		cout << u8"█";
		Basic::gotoXY(_X, y + 3);
		Basic::Console_SetColor(background_Color, GREEN);
		cout << u8"█";
	}
	background_Color = GREEN;
	SetConsoleOutputCP(oldcp);
	Basic::gotoXY(0, y + 5);
	UImtx.unlock();
}

void UserInterface::DrawRoadLane(int x, int y, int background_Color)
{
	UImtx.lock();
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	int count = 0;
	for (int _X = 1; _X < 132; _X++) {
		Basic::gotoXY(_X, y);
		Basic::Console_SetColor(LIGHTGREY, BLACK);
		cout << u8"▄";
		if (count < 13 && count >= 4) {
			Basic::gotoXY(_X, y + 1);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		else if (count < 4) {
			Basic::gotoXY(_X, y + 1);
			Basic::Console_SetColor(BLACK, WHITE);
			cout << u8"▄";
		}
		Basic::gotoXY(_X, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";

		Basic::gotoXY(_X, y + 3);
		Basic::Console_SetColor(BLACK, LIGHTGREY);
		cout << u8"▄";
		count++;
		if (count == 12) count = 0;
	}
	background_Color = BLACK;
	SetConsoleOutputCP(oldcp);
	Basic::gotoXY(0, y + 5);
	UImtx.unlock();
}

void UserInterface::DrawRiverLane(int x, int y, int background_Color)
{
	UImtx.lock();
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	for (int _X = 1; _X < 132; _X++) {
		Basic::gotoXY(_X, y);
		Basic::Console_SetColor(DARKBLUE, BLUE);
		cout << u8"▄";
		Basic::gotoXY(_X, y + 1);
		Basic::Console_SetColor(background_Color, BLUE);
		cout << u8"█";
		Basic::gotoXY(_X, y + 2);
		Basic::Console_SetColor(background_Color, BLUE);
		cout << u8"█";
		Basic::gotoXY(_X, y + 3);
		Basic::Console_SetColor(BLUE, DARKBLUE);
		cout << u8"▄";
	}
	background_Color = BLUE;
	SetConsoleOutputCP(oldcp);
	Basic::gotoXY(0, y + 5);
	UImtx.unlock();
}

void UserInterface::DrawLeafRiver(int x, int y)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	Basic::gotoXY(x + 1, y);
	Basic::Console_SetColor(DARKBLUE, GREEN);
	cout << u8"▄▄▄";
	Basic::Console_SetColor(DARKBLUE, DARKGREEN);
	cout << u8"▄";
	Basic::Console_SetColor(DARKBLUE, GREEN);
	cout << u8"▄";
	Basic::gotoXY(x + 1, y + 1);
	Basic::Console_SetColor(DARKBLUE, GREEN);
	cout << u8"███";
	Basic::Console_SetColor(DARKBLUE, DARKGREEN);
	cout << u8"██";
	Basic::Console_SetColor(DARKBLUE, GREEN);
	cout << u8"█";
	Basic::gotoXY(x + 1, y + 2);
	Basic::Console_SetColor(GREEN, DARKGREEN);
	cout << u8"▀████";
	Basic::Console_SetColor(DARKBLUE, GREEN);
	cout << u8"█";
	Basic::gotoXY(x + 1, y + 3);
	Basic::Console_SetColor(BLUE, DARKBLUE);
	cout << u8"▄";
	Basic::Console_SetColor(DARKBLUE, GREEN);
	cout << u8"▀▀▀▀▀";
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawTrainLane(int x, int y, int background_Color) //dthien
{
	UImtx.lock();
	UINT oldcp = GetConsoleOutputCP();
	int count = 0;
	SetConsoleOutputCP(CP_UTF8);
	for (int _X = 1; _X < 132; _X++) {
		Basic::gotoXY(_X, y);
		Basic::Console_SetColor(DARKBLUE, LIGHTBLUE);
		cout << u8"█";
		Basic::gotoXY(_X, y + 1);
		Basic::Console_SetColor(background_Color, LIGHTBLUE);
		cout << u8"█";
		Basic::gotoXY(_X, y + 2);
		Basic::Console_SetColor(background_Color, LIGHTBLUE);
		cout << u8"█";
		if (count % 5 == 0) {
			Basic::gotoXY(_X, y + 3);
			Basic::Console_SetColor(LIGHTBLUE, GREY);
			cout << u8"▄";
			count = 0;
		}
		else {
			Basic::gotoXY(_X, y + 3);
			Basic::Console_SetColor(LIGHTBLUE, LIGHTGREY);
			cout << u8"▄";
		}
		count++;
	}
	background_Color = WHITE;
	SetConsoleOutputCP(oldcp);
	UImtx.unlock();
}

void CarFadeEffect(int y, int background_Color)	//Ve lai duong ben trai (Bi xuong dong)
{
	Basic::gotoXY(1, y + 1);
	Basic::Console_SetColor(BLACK, WHITE);
	cout << u8"▄▄▄▄▄";
	Basic::Console_SetColor(BLACK, BLACK);
	cout << u8"▄▄";
	Basic::gotoXY(1, y + 2);
	Basic::Console_SetColor(BLACK, BLACK);
	cout << u8"▄▄▄▄▄";
	Basic::gotoXY(1, y + 3);
	Basic::Console_SetColor(BLACK, LIGHTGREY);
	cout << u8"▄▄▄▄▄";
	Basic::gotoXY(132, y);
	Basic::Console_SetColor(background_Color, background_Color);
	cout << "  ";
	Basic::gotoXY(132, y + 1);
	Basic::Console_SetColor(background_Color, background_Color);
	cout << "  ";
	Basic::gotoXY(132, y + 2);
	Basic::Console_SetColor(background_Color, background_Color);
	cout << "  ";
}

void UserInterface::DrawVehicle_Right(int type, int x, int y, bool mode, int background_Color, int laneType)
{
	UImtx.lock();
	switch (type)
	{
	case 0: //Red Car
		DrawRCar(x, y, mode, background_Color);
		if (x < 133 && x>1) DrawBack_Right(x, y, background_Color, laneType);
		if (x >= 124) CarFadeEffect(y, WHITE);
		break;
	case 1: //Blue Car
		DrawBCar(x, y, mode, background_Color);
		if (x < 133 && x>1) DrawBack_Right(x, y, background_Color, laneType);
		if (x >= 124) CarFadeEffect(y, WHITE);
		break;
	case 2: //Truck
		DrawTruck(x, y, mode, background_Color);
		if (x < 133 && x>1) DrawBack_Right(x, y, background_Color, laneType);
		if (x >= 124) CarFadeEffect(y, WHITE);
		break;
	case 3:
		DrawTrain(x,y,mode,background_Color);
		break;
	case 4:
		DrawLeafRiver(x, y);
		break;
	}
	UImtx.unlock();
}

void UserInterface::DrawBack_Right(int x, int y, int background_Color, int laneType)
{	//grass, highway, water, railway
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	switch (laneType)
	{
	case 0:	//grass
		break;
	case 1: //highway
		Basic::gotoXY(x - 1, y);
		Basic::Console_SetColor(LIGHTGREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x - 1, y + 1);
		if ((x - 2) % 12 <= 4)
			Basic::Console_SetColor(BLACK, WHITE);
		else
			Basic::Console_SetColor(BLACK, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x - 1, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		break;
	case 2: //water
		Basic::gotoXY(x - 1, y);
		Basic::Console_SetColor(DARKBLUE, BLUE);
		cout << u8"▄";
		Basic::gotoXY(x - 1, y + 1);
		Basic::Console_SetColor(BLUE, BLUE);
		cout << u8"█";
		Basic::gotoXY(x - 1, y + 2);
		Basic::Console_SetColor(BLUE, BLUE);
		cout << u8"█";
		Basic::gotoXY(x - 1, y + 3);
		Basic::Console_SetColor(BLUE, DARKBLUE);
		cout << u8"▄";
		break;
	case 3:// railway
		break;
	}
}

void UserInterface::CarFadeEffect_Left(int y, int background_Color)
{
	UImtx.lock();
	Basic::gotoXY(1, y);
	Basic::Console_SetColor(LIGHTGREY, BLACK);
	cout << u8"▄▄▄▄▄▄▄▄";
	Basic::gotoXY(1, y + 1);
	Basic::Console_SetColor(BLACK, WHITE);
	cout << u8"▄▄▄▄▄";
	Basic::Console_SetColor(BLACK, BLACK);
	cout << u8"▄▄▄";
	Basic::gotoXY(1, y + 2);
	Basic::Console_SetColor(BLACK, BLACK);
	cout << u8"▄▄▄▄▄▄▄▄";
	Basic::gotoXY(1, y + 3);
	Basic::Console_SetColor(BLACK, LIGHTGREY);
	cout << u8"▄▄▄▄▄▄▄▄";
	UImtx.unlock();
}

void UserInterface::DrawVehicle_Left(int type, int x, int y, bool mode, int background_Color, int laneType)
{
	UImtx.lock();
	switch (type)
	{
	case 0: //Red Car
		DrawReverseRCar(x, y, mode, background_Color);
		DrawBack_Left(x, y, background_Color, laneType);
		break;
	case 1: //Blue Car
		DrawReverseBCar(x, y, mode, background_Color);
		DrawBack_Left(x, y, background_Color, laneType);
		break;
	case 2: //Truck
		DrawReverseTruck(x, y, mode, background_Color);
		DrawBack_Left(x, y, background_Color, laneType);
		break;
	}
	UImtx.unlock();
}

void UserInterface::DrawBack_Left(int x, int y, int background_Color, int laneType)	//done
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	switch (laneType)
	{
	case 0:	//grass
		break;
	case 1: //highway
		Basic::gotoXY(x + 8, y);
		Basic::Console_SetColor(LIGHTGREY, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 8, y + 1);
		if ((x + 8 - 2) % 12 <= 4)
			Basic::Console_SetColor(BLACK, WHITE);
		else
			Basic::Console_SetColor(BLACK, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 8, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		break;
	case 2: //water
		Basic::gotoXY(x + 8, y);
		Basic::Console_SetColor(DARKBLUE, BLUE);
		cout << u8"▄";
		Basic::gotoXY(x + 8, y + 1);
		Basic::Console_SetColor(BLUE, BLUE);
		cout << u8"█";
		Basic::gotoXY(x + 8, y + 2);
		Basic::Console_SetColor(BLUE, BLUE);
		cout << u8"█";
		Basic::gotoXY(x + 8, y + 3);
		Basic::Console_SetColor(BLUE, DARKBLUE);
		cout << u8"▄";
		break;
	case 3:// railway
		break;
	}
}

void UserInterface::DrawMenuGame()
{
	Basic::Console_SetColor(LIGHTBLUE, LIGHTBLUE);
	Basic::Console_ClearScreen();
	UINT oldcp = GetConsoleOutputCP();
	int count = 0;
	SetConsoleOutputCP(CP_UTF8);
	for (int _X = 1; _X < 138; _X++) {
		for (int _Y = CONSOLE_HEIGHT - 8; _Y < CONSOLE_HEIGHT; _Y++) {
			Basic::gotoXY(_X, _Y);
			Basic::Console_SetColor(LIGHTBLUE, GREEN);
			cout << u8"█";
		}
	}
	DrawC(22, 3, LIGHTBLUE);
	DrawR1(34, 4, LIGHTBLUE);
	DrawO1(46, 3, LIGHTBLUE);
	DrawS1(59, 4, LIGHTBLUE);
	DrawS2(70, 3, LIGHTBLUE);
	DrawI(81, 3, LIGHTBLUE);
	DrawN(86, 4, LIGHTBLUE);
	DrawG(99, 3, LIGHTBLUE);
	DrawR2(43, 13, LIGHTBLUE);
	DrawO2(55, 12, LIGHTBLUE);
	DrawA(69, 13, LIGHTBLUE);
	DrawD(81, 12, LIGHTBLUE);
	Basic::gotoXY(9, 1);
	Basic::Console_SetColor(LIGHTBLUE, WHITE);
	cout << u8"▄▄▄▄";
	Basic::gotoXY(4, 2);
	Basic::Console_SetColor(LIGHTBLUE, WHITE);
	cout << u8"▄▄▄███████▄▄▄";
	Basic::gotoXY(3, 3);
	Basic::Console_SetColor(LIGHTBLUE, WHITE);
	cout << u8"▀▀▀██▀▀▀██▀▀▀";
	Basic::gotoXY(87, 1);
	Basic::Console_SetColor(LIGHTBLUE, WHITE);
	cout << u8"▄▄▄████▄";
	Basic::gotoXY(85, 2);
	Basic::Console_SetColor(LIGHTBLUE, WHITE);
	cout << u8"▄██▀▀▀▀▀▀▀█▀▀▀";
	Basic::gotoXY(CONSOLE_WIDTH - 7, 1);
	Basic::Console_SetColor(LIGHTBLUE, GOLDEN);
	cout << u8"███████";
	Basic::gotoXY(CONSOLE_WIDTH, 1);
	Basic::Console_SetColor(LIGHTBLUE, GOLDEN);
	cout << u8"████";
	Basic::gotoXY(CONSOLE_WIDTH - 6, 2);
	Basic::Console_SetColor(LIGHTBLUE, GOLDEN);
	cout << u8"███████";
	Basic::gotoXY(CONSOLE_WIDTH, 2);
	Basic::Console_SetColor(LIGHTBLUE, GOLDEN);
	cout << u8"████";
	Basic::gotoXY(CONSOLE_WIDTH - 6, 3);
	Basic::Console_SetColor(LIGHTBLUE, GOLDEN);
	cout << u8"▀██████";
	Basic::gotoXY(CONSOLE_WIDTH, 3);
	Basic::Console_SetColor(LIGHTBLUE, GOLDEN);
	cout << u8"████";
	Basic::gotoXY(CONSOLE_WIDTH - 4, 4);
	Basic::Console_SetColor(LIGHTBLUE, GOLDEN);
	cout << u8"▀██████";
	Basic::gotoXY(CONSOLE_WIDTH, 4);
	Basic::Console_SetColor(LIGHTBLUE, GOLDEN);
	cout << u8"████";
	Basic::gotoXY(CONSOLE_WIDTH - 2, 5);
	Basic::Console_SetColor(LIGHTBLUE, GOLDEN);
	cout << u8"▀█████";
	Basic::gotoXY(CONSOLE_WIDTH, 5);
	Basic::Console_SetColor(LIGHTBLUE, GOLDEN);
	cout << u8"████";
	Basic::gotoXY(CONSOLE_WIDTH - 1, 5);
	Basic::Console_SetColor(GOLDEN, WHITE);
	cout << u8"▄▄█";
	Basic::gotoXY(CONSOLE_WIDTH - 3, 6);
	Basic::Console_SetColor(LIGHTBLUE, WHITE);
	cout << u8"▀▀▀";
	Basic::gotoXY(CONSOLE_WIDTH, 6);
	Basic::Console_SetColor(GOLDEN, WHITE);
	cout << u8"███▄";
	Basic::gotoXY(CONSOLE_WIDTH - 6, 1);
	Basic::Console_SetColor(GOLDEN, WHITE);
	cout << u8"▄▄";
	Basic::gotoXY(CONSOLE_WIDTH - 12, 2);
	Basic::Console_SetColor(LIGHTBLUE, WHITE);
	cout << u8"▄▄███████";
	Basic::Console_SetColor(GOLDEN, WHITE);
	cout << u8"▄▄";
	Basic::gotoXY(CONSOLE_WIDTH - 13, 3);
	Basic::Console_SetColor(LIGHTBLUE, WHITE);
	cout << u8"▀██▀▀";
	Basic::gotoXY(CONSOLE_WIDTH - 3, 3);
	Basic::Console_SetColor(GOLDEN, WHITE);
	cout << u8"▀";
	Basic::gotoXY(41, 1);
	Basic::Console_SetColor(LIGHTBLUE, WHITE);
	cout << u8"▀██▀▀▀▀▀██▀▀▀";

	Basic::gotoXY(1, 17);
	Basic::Console_SetColor(LIGHTBLUE, DARKGREEN);
	cout << u8"██▄▄";
	Basic::gotoXY(1, 18);
	Basic::Console_SetColor(LIGHTBLUE, DARKGREEN);
	cout << u8"█████▄▄▄";
	Basic::gotoXY(1, 19);
	Basic::Console_SetColor(LIGHTBLUE, DARKGREEN);
	cout << u8"█████████▄";
	Basic::gotoXY(1, 20);
	Basic::Console_SetColor(LIGHTBLUE, DARKGREEN);
	cout << u8"████████████";
	Basic::gotoXY(1, 21);
	Basic::Console_SetColor(LIGHTBLUE, DARKGREEN);
	cout << u8"████████████";

	Basic::gotoXY(130, 16);
	Basic::Console_SetColor(LIGHTBLUE, DARKGREEN);
	cout << u8"▄▄▄▄▄";
	Basic::gotoXY(128, 17);
	Basic::Console_SetColor(LIGHTBLUE, DARKGREEN);
	cout << u8"▄██████";
	Basic::gotoXY(124, 18);
	Basic::Console_SetColor(LIGHTBLUE, DARKGREEN);
	cout << u8"▄██████████";
	Basic::gotoXY(122, 19);
	Basic::Console_SetColor(LIGHTBLUE, DARKGREEN);
	cout << u8"▄████████████";
	Basic::gotoXY(120, 20);
	Basic::Console_SetColor(LIGHTBLUE, DARKGREEN);
	cout << u8"▄██████████████";
	Basic::gotoXY(119, 21);
	Basic::Console_SetColor(LIGHTBLUE, DARKGREEN);
	cout << u8"▄███████████████";

	Basic::gotoXY(16, 17);
	Basic::Console_SetColor(LIGHTBLUE, BLACK);
	cout << u8"▄";
	Basic::gotoXY(15, 18);
	Basic::Console_SetColor(YELLOW, BLACK);
	cout << u8"█";
	Basic::gotoXY(16, 18);
	Basic::Console_SetColor(RED, LIGHTRED);
	cout << u8"▄";
	Basic::gotoXY(17, 18);
	Basic::Console_SetColor(YELLOW, BLACK);
	cout << u8"█";
	Basic::gotoXY(15, 19);
	Basic::Console_SetColor(YELLOW, BLACK);
	cout << u8"█";
	Basic::gotoXY(16, 19);
	Basic::Console_SetColor(YELLOW, DARKGREEN);
	cout << u8"▄";
	Basic::gotoXY(17, 19);
	Basic::Console_SetColor(YELLOW, BLACK);
	cout << u8"█";
	Basic::gotoXY(15, 20);
	Basic::Console_SetColor(BLACK, LIGHTBLUE);
	cout << u8"▄";
	Basic::gotoXY(16, 20);
	Basic::Console_SetColor(GREEN, BLACK);
	cout << u8"▄";
	Basic::gotoXY(17, 20);
	Basic::Console_SetColor(BLACK, LIGHTBLUE);
	cout << u8"▄";
	Basic::gotoXY(16, 21);
	Basic::Console_SetColor(LIGHTBLUE, BLACK);
	cout << u8"█";

	Basic::gotoXY(116, 17);
	Basic::Console_SetColor(LIGHTBLUE, BLACK);
	cout << u8"▄";
	Basic::gotoXY(115, 18);
	Basic::Console_SetColor(YELLOW, BLACK);
	cout << u8"█";
	Basic::gotoXY(116, 18);
	Basic::Console_SetColor(RED, LIGHTRED);
	cout << u8"▄";
	Basic::gotoXY(117, 18);
	Basic::Console_SetColor(YELLOW, BLACK);
	cout << u8"█";
	Basic::gotoXY(115, 19);
	Basic::Console_SetColor(YELLOW, BLACK);
	cout << u8"█";
	Basic::gotoXY(116, 19);
	Basic::Console_SetColor(YELLOW, DARKGREEN);
	cout << u8"▄";
	Basic::gotoXY(117, 19);
	Basic::Console_SetColor(YELLOW, BLACK);
	cout << u8"█";
	Basic::gotoXY(115, 20);
	Basic::Console_SetColor(BLACK, LIGHTBLUE);
	cout << u8"▄";
	Basic::gotoXY(116, 20);
	Basic::Console_SetColor(GREEN, BLACK);
	cout << u8"▄";
	Basic::gotoXY(117, 20);
	Basic::Console_SetColor(BLACK, LIGHTBLUE);
	cout << u8"▄";
	Basic::gotoXY(116, 21);
	Basic::Console_SetColor(LIGHTBLUE, BLACK);
	cout << u8"█";

	/*Basic::gotoXY(3, 23);
	Basic::Console_SetColor(GREEN, DARKGREEN);
	cout << u8"▄▀▄";
	Basic::gotoXY(5, 28);
	Basic::Console_SetColor(GREEN, DARKGREEN);
	cout << u8"▄▀▄";
	Basic::gotoXY(33, 24);
	Basic::Console_SetColor(GREEN, DARKGREEN);
	cout << u8"▄▀▄";*/

	DrawPlayButton(10, 23, 0, GREEN);
	DrawLoadButton(35, 23, 0, GREEN);
	DrawCreditsButton(60, 23, 0, GREEN);
	DrawSettingButton(85, 23, 0, GREEN);
	DrawExitButton(110, 23, 0, GREEN);



	Basic::gotoXY(1, CONSOLE_HEIGHT);
	Basic::Console_SetColor(LIGHTBLUE, GREEN);
	SetConsoleOutputCP(oldcp);
}




void UserInterface::DrawC(int x, int y, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	Basic::gotoXY(x + 1, y);
	Basic::Console_SetColor(background_Color, RED);
	cout << u8"████████";
	for (int _Y = y + 1; _Y < y + 5; _Y++) {
		Basic::gotoXY(x, _Y);
		Basic::Console_SetColor(background_Color, RED);
		cout << u8"██";
	}
	Basic::gotoXY(x, y + 5);
	Basic::Console_SetColor(background_Color, RED);
	cout << u8"▀█";
	Basic::Console_SetColor(background_Color, RED);
	cout << u8"▄▄▄▄▄";
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"▄▄";
	Basic::gotoXY(x + 1, y + 6);
	Basic::Console_SetColor(background_Color, RED);
	cout << u8"▀▀▀▀▀";
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"▀▀▀";
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawR1(int x, int y, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	Basic::gotoXY(x, y);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"████████";
	for (int _Y = y + 1; _Y < y + 6; _Y++) {
		Basic::gotoXY(x, _Y);
		Basic::Console_SetColor(background_Color, LIGHTRED);
		cout << u8"██";
	}
	Basic::gotoXY(x, y + 6);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"▀▀";
	Basic::gotoXY(x + 7, y + 1);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"██";
	Basic::gotoXY(x + 2, y + 2);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"▄▄▄▄▄█▀";
	Basic::gotoXY(x + 2, y + 3);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"▀▀▀▀▀█▄";
	Basic::gotoXY(x + 7, y + 4);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"██";
	Basic::gotoXY(x + 7, y + 5);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"█";
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"█";
	Basic::gotoXY(x + 7, y + 6);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"▀";
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"▀";

	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawO1(int x, int y, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	Basic::gotoXY(x + 1, y);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"▄▄";
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"▄▄▄▄▄▄";
	Basic::gotoXY(x, y + 1);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"▄█▀";
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"▀▀▀▀▀█▄";
	Basic::gotoXY(x, y + 2);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"██";
	Basic::gotoXY(x + 8, y + 2);
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"██";
	Basic::gotoXY(x, y + 3);
	Basic::Console_SetColor(LIGHTRED, YELLOW);
	cout << u8"▄█";
	Basic::gotoXY(x + 8, y + 3);
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"██";
	Basic::gotoXY(x, y + 4);
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"██";
	Basic::gotoXY(x + 8, y + 4);
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"██";
	Basic::gotoXY(x, y + 5);
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"██";
	Basic::gotoXY(x + 8, y + 5);
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"██";
	Basic::gotoXY(x + 1, y + 6);
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"████████";
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawS1(int x, int y, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	Basic::gotoXY(x, y);
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"▄▄▄";
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"▄▄▄▄▄";
	Basic::gotoXY(x, y + 1);
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"██";
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"▀";
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"▀▀▀▀▀";
	Basic::gotoXY(x, y + 2);
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"█";
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"█";
	Basic::gotoXY(x, y + 3);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"████████";
	Basic::gotoXY(x + 6, y + 4);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"██";
	Basic::gotoXY(x + 6, y + 5);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"██";
	Basic::gotoXY(x, y + 6);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"████████";
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawS2(int x, int y, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	Basic::gotoXY(x, y);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"▄▄▄▄▄▄▄▄";
	Basic::gotoXY(x, y + 1);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"██";
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"▀";
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"▀▀▀▀▀";
	Basic::gotoXY(x, y + 2);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"█";
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"█";
	Basic::gotoXY(x, y + 3);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"████████";
	Basic::gotoXY(x + 6, y + 4);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"█";
	Basic::Console_SetColor(DARKBLUE, GREEN);
	cout << u8"▀";
	Basic::gotoXY(x + 6, y + 5);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"█";
	Basic::Console_SetColor(background_Color, DARKBLUE);
	cout << u8"█";
	Basic::gotoXY(x, y + 6);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"██████";
	Basic::Console_SetColor(background_Color, DARKBLUE);
	cout << u8"██";
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawI(int x, int y, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	for (int _Y = y; _Y < y + 6; _Y++) {
		Basic::gotoXY(x, _Y);
		Basic::Console_SetColor(background_Color, DARKBLUE);
		cout << u8"██";
	}
	Basic::gotoXY(x, y + 6);
	Basic::Console_SetColor(background_Color, DARKBLUE);
	cout << u8"▀▀";
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawN(int x, int y, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	for (int _Y = y; _Y < y + 6; _Y++) {
		Basic::gotoXY(x, _Y);
		Basic::Console_SetColor(background_Color, GREY);
		cout << u8"██";
	}
	Basic::gotoXY(x, y + 6);
	Basic::Console_SetColor(background_Color, GREY);
	cout << u8"▀▀";
	Basic::gotoXY(x + 2, y);
	Basic::Console_SetColor(background_Color, GREY);
	cout << u8"█";
	Basic::gotoXY(x + 2, y + 1);
	Basic::Console_SetColor(background_Color, GREY);
	cout << u8"█";
	Basic::gotoXY(x + 3, y + 1);
	Basic::Console_SetColor(background_Color, GREY);
	cout << u8"█";
	Basic::gotoXY(x + 3, y + 2);
	Basic::Console_SetColor(background_Color, GREY);
	cout << u8"▀";
	Basic::gotoXY(x + 4, y + 1);
	Basic::Console_SetColor(background_Color, GREY);
	cout << u8"▄";
	Basic::gotoXY(x + 4, y + 2);
	Basic::Console_SetColor(background_Color, GREY);
	cout << u8"█";
	Basic::gotoXY(x + 5, y + 2);
	Basic::Console_SetColor(background_Color, GREY);
	cout << u8"█";
	Basic::gotoXY(x + 5, y + 3);
	Basic::Console_SetColor(background_Color, GREY);
	cout << u8"▀";
	Basic::gotoXY(x + 6, y + 2);
	Basic::Console_SetColor(background_Color, GREY);
	cout << u8"▄";
	Basic::gotoXY(x + 6, y + 3);
	Basic::Console_SetColor(background_Color, GREY);
	cout << u8"█";
	Basic::gotoXY(x + 7, y + 3);
	Basic::Console_SetColor(background_Color, GREY);
	cout << u8"█";
	Basic::gotoXY(x + 7, y + 4);
	Basic::Console_SetColor(PURPLE, GREY);
	cout << u8"▀";
	for (int _Y = y; _Y < y + 3; _Y++) {
		Basic::gotoXY(x + 8, _Y);
		Basic::Console_SetColor(background_Color, GREY);
		cout << u8"██";
	}
	Basic::gotoXY(x + 9, y + 2);
	Basic::Console_SetColor(PURPLE, GREY);
	cout << u8"▀";
	Basic::gotoXY(x + 9, y + 3);
	Basic::Console_SetColor(background_Color, PURPLE);
	cout << u8"█";
	Basic::gotoXY(x + 8, y + 3);
	Basic::Console_SetColor(background_Color, GREY);
	cout << u8"█";
	Basic::gotoXY(x + 8, y + 4);
	Basic::Console_SetColor(PURPLE, GREY);
	cout << u8"▀";
	Basic::Console_SetColor(background_Color, PURPLE);
	cout << u8"█";
	Basic::gotoXY(x + 8, y + 5);
	Basic::Console_SetColor(background_Color, PURPLE);
	cout << u8"██";
	Basic::gotoXY(x + 8, y + 6);
	Basic::Console_SetColor(background_Color, PURPLE);
	cout << u8"▀▀";
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawG(int x, int y, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	Basic::gotoXY(x, y);
	Basic::Console_SetColor(background_Color, PURPLE);
	cout << u8"▄███████▄▄";
	for (int _Y = y + 1; _Y < y + 6; _Y++) {
		Basic::gotoXY(x, _Y);
		Basic::Console_SetColor(background_Color, PURPLE);
		cout << u8"██";
	}
	Basic::Console_SetColor(background_Color, PURPLE);
	cout << u8"▄▄▄▄▄▄██";
	Basic::gotoXY(x + 1, y + 6);
	Basic::Console_SetColor(background_Color, PURPLE);
	cout << u8"▀▀▀▀▀▀▀▀▀";
	Basic::gotoXY(x + 7, y + 1);
	Basic::Console_SetColor(background_Color, PURPLE);
	cout << u8"▀▀▀";
	Basic::gotoXY(x + 7, y + 3);
	Basic::Console_SetColor(background_Color, PURPLE);
	cout << u8"▄▄▄";
	Basic::gotoXY(x + 7, y + 4);
	Basic::Console_SetColor(background_Color, PURPLE);
	cout << u8"▀██";
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawR2(int x, int y, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	Basic::gotoXY(x, y);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"████████";
	for (int _Y = y + 1; _Y < y + 6; _Y++) {
		Basic::gotoXY(x, _Y);
		Basic::Console_SetColor(background_Color, LIGHTRED);
		cout << u8"██";
	}
	Basic::gotoXY(x, y + 6);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"▀▀";
	Basic::gotoXY(x + 7, y + 1);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"██";
	Basic::gotoXY(x + 2, y + 2);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"▄▄▄▄▄█▀";
	Basic::gotoXY(x + 2, y + 3);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"▀▀▀▀▀█▄";
	Basic::gotoXY(x + 7, y + 4);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"█";
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"█";
	Basic::gotoXY(x + 7, y + 5);
	Basic::Console_SetColor(YELLOW, LIGHTRED);
	cout << u8"▀";
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"█";
	Basic::gotoXY(x + 7, y + 6);
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"▀▀";
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawO2(int x, int y, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	Basic::gotoXY(x + 1, y);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"▄▄";
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"▄▄▄▄▄▄";
	Basic::gotoXY(x, y + 1);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"▄█▀";
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"▀▀▀▀▀█▄";
	Basic::gotoXY(x, y + 2);
	Basic::Console_SetColor(background_Color, LIGHTRED);
	cout << u8"██";
	Basic::gotoXY(x + 8, y + 2);
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"██";
	Basic::gotoXY(x, y + 3);
	Basic::Console_SetColor(LIGHTRED, YELLOW);
	cout << u8"▄█";
	Basic::gotoXY(x + 8, y + 3);
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"██";
	Basic::gotoXY(x, y + 4);
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"██";
	Basic::gotoXY(x + 8, y + 4);
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"██";
	Basic::gotoXY(x, y + 5);
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"██";
	Basic::gotoXY(x + 8, y + 5);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"██";
	Basic::gotoXY(x + 1, y + 6);
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"███████";
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"█";
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawA(int x, int y, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	Basic::gotoXY(x + 2, y);
	Basic::Console_SetColor(GREEN, YELLOW);
	cout << u8"█▀";
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"███";
	Basic::gotoXY(x, y + 1);
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"██";
	Basic::gotoXY(x, y + 2);
	Basic::Console_SetColor(YELLOW, GREEN);
	cout << u8"▄█";
	Basic::gotoXY(x, y + 3);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"█████████";
	Basic::gotoXY(x, y + 4);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"██";
	Basic::gotoXY(x, y + 5);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"██";
	Basic::gotoXY(x, y + 6);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"▀▀";
	Basic::gotoXY(x + 7, y + 1);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"██";
	Basic::gotoXY(x + 7, y + 2);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"██";
	Basic::gotoXY(x + 7, y + 4);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"█";
	Basic::Console_SetColor(background_Color, DARKBLUE);
	cout << u8"█";
	Basic::gotoXY(x + 7, y + 5);
	Basic::Console_SetColor(GREEN, DARKBLUE);
	cout << u8"▄█";
	Basic::gotoXY(x + 7, y + 6);
	Basic::Console_SetColor(background_Color, DARKBLUE);
	cout << u8"▀▀";
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawD(int x, int y, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	Basic::gotoXY(x, y);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"▄▄▄";
	Basic::Console_SetColor(background_Color, DARKBLUE);
	cout << u8"▄▄▄▄▄";
	Basic::gotoXY(x, y + 1);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"██";
	Basic::Console_SetColor(background_Color, DARKBLUE);
	cout << u8"▀▀▀▀▀█▄";
	Basic::gotoXY(x, y + 2);
	Basic::Console_SetColor(background_Color, GREEN);
	cout << u8"█";
	Basic::Console_SetColor(background_Color, DARKBLUE);
	cout << u8"█     ██";
	Basic::gotoXY(x, y + 3);
	Basic::Console_SetColor(background_Color, DARKBLUE);
	cout << u8"██     ██";
	Basic::gotoXY(x, y + 4);
	Basic::Console_SetColor(background_Color, DARKBLUE);
	cout << u8"██     ██";
	Basic::gotoXY(x, y + 5);
	Basic::Console_SetColor(background_Color, DARKBLUE);
	cout << u8"██     ██";
	Basic::gotoXY(x, y + 6);
	Basic::Console_SetColor(background_Color, DARKBLUE);
	cout << u8"████████";
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawPlayButton(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 0) {
		for (int _Y = y - 1; _Y < y + 6; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, background_Color);
			cout << u8"██████████████";
		}
		for (int _Y = y; _Y < y + 5; _Y++) {
			Basic::gotoXY(x + 1, _Y);
			Basic::Console_SetColor(background_Color, WHITE);
			cout << u8"██████████";
		}
		int _color = YELLOW;
		Basic::gotoXY(x + 1, y);
		Basic::Console_SetColor(background_Color, _color);
		cout << u8"▄";
		Basic::Console_SetColor(WHITE, _color);
		cout << u8"▀▀▀▀▀▀▀▀";
		Basic::Console_SetColor(background_Color, _color);
		cout << u8"▄";
		for (int _Y = y + 1; _Y < y + 5; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, _color);
			cout << u8"█";
			Basic::gotoXY(x + 11, _Y);
			Basic::Console_SetColor(background_Color, _color);
			cout << u8"█";
		}
		Basic::gotoXY(x + 1, y + 5);
		Basic::Console_SetColor(background_Color, _color);
		cout << u8"▀";
		Basic::Console_SetColor(WHITE, _color);
		cout << u8"▄▄▄▄▄▄▄▄";
		Basic::Console_SetColor(background_Color, _color);
		cout << u8"▀";

		Basic::gotoXY(x + 4, y);
		Basic::Console_SetColor(BLACK, _color);
		cout << u8"▀";
		Basic::gotoXY(x + 4, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 4, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 4, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 4, y + 4);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 5, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 5, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 5, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 5, y + 4);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 6, y + 1);
		Basic::Console_SetColor(BLACK, WHITE);
		cout << u8"▀";
		Basic::gotoXY(x + 6, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 6, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 7, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 7, y + 3);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 8, y + 2);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▄";
	}
	else {
		int _color = GOLDEN;
		for (int _Y = y; _Y < y + 6; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, _color);
			cout << u8"████████████";
		}
		x--;
		Basic::gotoXY(x + 2, y - 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄▄▄▄▄▄▄▄▄▄";
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄██";
		Basic::Console_SetColor(_color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀██▄";

		for (int _Y = y; _Y < y + 5; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"██";
			Basic::gotoXY(x + 12, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"██";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 13, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 2, y + 4);
		Basic::Console_SetColor(_color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 11, y + 4);
		Basic::Console_SetColor(_color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 1, y + 5);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀██████████▀";

		x++;
		Basic::gotoXY(x + 4, y);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 4, y + 1);
		Basic::Console_SetColor(background_Color, WHITE);
		cout << u8"█";
		Basic::gotoXY(x + 4, y + 2);
		Basic::Console_SetColor(background_Color, WHITE);
		cout << u8"█";
		Basic::gotoXY(x + 4, y + 3);
		Basic::Console_SetColor(background_Color, WHITE);
		cout << u8"█";
		Basic::gotoXY(x + 4, y + 4);
		Basic::Console_SetColor(background_Color, WHITE);
		cout << u8"█";
		Basic::gotoXY(x + 5, y + 1);
		Basic::Console_SetColor(background_Color, WHITE);
		cout << u8"█";
		Basic::gotoXY(x + 5, y + 2);
		Basic::Console_SetColor(background_Color, WHITE);
		cout << u8"█";
		Basic::gotoXY(x + 5, y + 3);
		Basic::Console_SetColor(background_Color, WHITE);
		cout << u8"█";
		Basic::gotoXY(x + 5, y + 4);
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"▀";
		Basic::gotoXY(x + 6, y + 1);
		Basic::Console_SetColor(WHITE, _color);
		cout << u8"▀";
		Basic::gotoXY(x + 6, y + 2);
		Basic::Console_SetColor(background_Color, WHITE);
		cout << u8"█";
		Basic::gotoXY(x + 6, y + 3);
		Basic::Console_SetColor(background_Color, WHITE);
		cout << u8"█";
		Basic::gotoXY(x + 7, y + 2);
		Basic::Console_SetColor(background_Color, WHITE);
		cout << u8"█";
		Basic::gotoXY(x + 7, y + 3);
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"▀";
		Basic::gotoXY(x + 8, y + 2);
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"▄";

	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawLoadButton(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 0) {
		for (int _Y = y - 1; _Y < y + 6; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, background_Color);
			cout << u8"██████████████";
		}
		for (int _Y = y; _Y < y + 5; _Y++) {
			Basic::gotoXY(x + 1, _Y);
			Basic::Console_SetColor(background_Color, WHITE);
			cout << u8"██████████";
		}
		Basic::gotoXY(x + 1, y);
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▄";
		Basic::Console_SetColor(WHITE, YELLOW);
		cout << u8"▀▀▀▀▀▀▀▀";
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▄";
		for (int _Y = y + 1; _Y < y + 5; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, YELLOW);
			cout << u8"█";
			Basic::gotoXY(x + 11, _Y);
			Basic::Console_SetColor(background_Color, YELLOW);
			cout << u8"█";
		}
		Basic::gotoXY(x + 1, y + 5);
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▀";
		Basic::Console_SetColor(WHITE, YELLOW);
		cout << u8"▄▄▄▄▄▄▄▄";
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▀";

		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▄▀█▀▀█▀▄";
		Basic::gotoXY(x + 2, y + 2);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"█  ▀▀  █";
		Basic::gotoXY(x + 2, y + 3);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"█ █▀▀█ █";
		Basic::gotoXY(x + 2, y + 4);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"█▄█▄▄█▄█";

	}
	else {
		int _color = NYAN;
		for (int _Y = y; _Y < y + 6; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, _color);
			cout << u8"████████████";
		}
		x--;
		Basic::gotoXY(x + 2, y - 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄▄▄▄▄▄▄▄▄▄";
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄██";
		Basic::Console_SetColor(_color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀██▄";

		for (int _Y = y; _Y < y + 5; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"██";
			Basic::gotoXY(x + 12, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"██";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 13, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 2, y + 4);
		Basic::Console_SetColor(_color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 11, y + 4);
		Basic::Console_SetColor(_color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 1, y + 5);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀██████████▀";

		Basic::gotoXY(x + 3, y + 1);
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"▄▀█▀▀█▀▄";
		Basic::gotoXY(x + 3, y + 2);
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"█  ▀▀  █";
		Basic::gotoXY(x + 3, y + 3);
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"█ █▀▀█ █";
		Basic::gotoXY(x + 3, y + 4);
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"█▄█▄▄█▄█";
	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawSettingButton(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 0) {
		for (int _Y = y - 1; _Y < y + 6; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, background_Color);
			cout << u8"██████████████";
		}
		for (int _Y = y; _Y < y + 5; _Y++) {
			Basic::gotoXY(x + 1, _Y);
			Basic::Console_SetColor(background_Color, WHITE);
			cout << u8"██████████";
		}
		Basic::gotoXY(x + 1, y);
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▄";
		Basic::Console_SetColor(WHITE, YELLOW);
		cout << u8"▀▀▀▀▀▀▀▀";
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▄";
		for (int _Y = y + 1; _Y < y + 5; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, YELLOW);
			cout << u8"█";
			Basic::gotoXY(x + 11, _Y);
			Basic::Console_SetColor(background_Color, YELLOW);
			cout << u8"█";
		}
		Basic::gotoXY(x + 1, y + 5);
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▀";
		Basic::Console_SetColor(WHITE, YELLOW);
		cout << u8"▄▄▄▄▄▄▄▄";
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▀";

		Basic::gotoXY(x + 5, y);
		Basic::Console_SetColor(YELLOW, BLACK);
		cout << u8"▄▄";
		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"██▄██▄██";
		Basic::gotoXY(x + 1, y + 2);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▄▄█▀  ▀█▄▄";
		Basic::gotoXY(x + 1, y + 3);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▀▀█▄  ▄█▀▀";
		Basic::gotoXY(x + 2, y + 4);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▄██████▄";
		Basic::gotoXY(x + 2, y + 5);
		Basic::Console_SetColor(YELLOW, BLACK);
		cout << u8"▀▀ ▀▀ ▀▀";
		Basic::gotoXY(x + 4, y + 5);
		Basic::Console_SetColor(YELLOW, WHITE);
		cout << u8"▀";
		Basic::gotoXY(x + 7, y + 5);
		Basic::Console_SetColor(YELLOW, WHITE);
		cout << u8"▀";
	}
	else {
		int _color = RED;
		for (int _Y = y; _Y < y + 6; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, _color);
			cout << u8"████████████";
		}
		x--;
		Basic::gotoXY(x + 2, y - 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄▄▄▄▄▄▄▄▄▄";
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄██";
		Basic::Console_SetColor(_color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀██▄";

		for (int _Y = y; _Y < y + 5; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"██";
			Basic::gotoXY(x + 12, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"██";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 13, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 2, y + 4);
		Basic::Console_SetColor(_color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 11, y + 4);
		Basic::Console_SetColor(_color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 1, y + 5);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀██████████▀";

		x++;
		Basic::gotoXY(x + 5, y);
		Basic::Console_SetColor(BLACK, WHITE);
		cout << u8"▄▄";
		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"██▄██▄██";
		Basic::gotoXY(x + 1, y + 2);
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"▄▄█▀  ▀█▄▄";
		Basic::gotoXY(x + 1, y + 3);
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"▀▀█▄  ▄█▀▀";
		Basic::gotoXY(x + 2, y + 4);
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"▄██████▄";
		Basic::gotoXY(x + 2, y + 5);
		Basic::Console_SetColor(BLACK, WHITE);
		cout << u8"▀▀ ▀▀ ▀▀";
		Basic::gotoXY(x + 4, y + 5);
		Basic::Console_SetColor(BLACK, _color);
		cout << u8"▀";
		Basic::gotoXY(x + 7, y + 5);
		Basic::Console_SetColor(BLACK, _color);
		cout << u8"▀";
	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawCreditsButton(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 0) {
		for (int _Y = y - 1; _Y < y + 6; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, background_Color);
			cout << u8"██████████████";
		}
		for (int _Y = y; _Y < y + 5; _Y++) {
			Basic::gotoXY(x + 1, _Y);
			Basic::Console_SetColor(background_Color, WHITE);
			cout << u8"██████████";
		}
		Basic::gotoXY(x + 1, y);
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▄";
		Basic::Console_SetColor(WHITE, YELLOW);
		cout << u8"▀▀▀▀▀▀▀▀";
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▄";
		for (int _Y = y + 1; _Y < y + 5; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, YELLOW);
			cout << u8"█";
			Basic::gotoXY(x + 11, _Y);
			Basic::Console_SetColor(background_Color, YELLOW);
			cout << u8"█";
		}
		Basic::gotoXY(x + 1, y + 5);
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▀";
		Basic::Console_SetColor(WHITE, YELLOW);
		cout << u8"▄▄▄▄▄▄▄▄";
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▀";

		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▄ ▄▄▄▄▄";
		Basic::gotoXY(x + 2, y + 2);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▄ ▄▄▄▄";
		Basic::gotoXY(x + 2, y + 3);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▄ ▄▄▄▄▄▄";
	}
	else {
		int _color = PURPLE;
		for (int _Y = y; _Y < y + 6; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, _color);
			cout << u8"████████████";
		}
		x--;
		Basic::gotoXY(x + 2, y - 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄▄▄▄▄▄▄▄▄▄";
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄██";
		Basic::Console_SetColor(_color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀██▄";

		for (int _Y = y; _Y < y + 5; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"██";
			Basic::gotoXY(x + 12, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"██";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 13, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 2, y + 4);
		Basic::Console_SetColor(_color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 11, y + 4);
		Basic::Console_SetColor(_color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 1, y + 5);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀██████████▀";

		x++;
		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"▄ ▄▄▄▄▄";
		Basic::gotoXY(x + 2, y + 2);
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"▄ ▄▄▄▄";
		Basic::gotoXY(x + 2, y + 3);
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"▄ ▄▄▄▄▄▄";
	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawExitButton(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 0) {
		for (int _Y = y - 1; _Y < y + 6; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, background_Color);
			cout << u8"██████████████";
		}
		for (int _Y = y; _Y < y + 5; _Y++) {
			Basic::gotoXY(x + 1, _Y);
			Basic::Console_SetColor(background_Color, WHITE);
			cout << u8"██████████";
		}
		Basic::gotoXY(x + 1, y);
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▄";
		Basic::Console_SetColor(WHITE, YELLOW);
		cout << u8"▀▀▀▀▀▀▀▀";
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▄";
		for (int _Y = y + 1; _Y < y + 5; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, YELLOW);
			cout << u8"█";
			Basic::gotoXY(x + 11, _Y);
			Basic::Console_SetColor(background_Color, YELLOW);
			cout << u8"█";
		}
		Basic::gotoXY(x + 1, y + 5);
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▀";
		Basic::Console_SetColor(WHITE, YELLOW);
		cout << u8"▄▄▄▄▄▄▄▄";
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << u8"▀";

		Basic::gotoXY(x + 4, y + 1);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▄▀▀▀▀█";
		Basic::gotoXY(x + 1, y + 2);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▄▄▄██▄▄ █";
		Basic::gotoXY(x + 1, y + 3);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▀▀▀██▀  █";
		Basic::gotoXY(x + 4, y + 4);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▀ ▄▄▄█";
	}
	else {
		int _color = GREY;
		for (int _Y = y; _Y < y + 6; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, _color);
			cout << u8"████████████";
		}
		x--;
		Basic::gotoXY(x + 2, y - 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄▄▄▄▄▄▄▄▄▄";
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄██";
		Basic::Console_SetColor(_color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀██▄";

		for (int _Y = y; _Y < y + 5; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"██";
			Basic::gotoXY(x + 12, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"██";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 13, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 2, y + 4);
		Basic::Console_SetColor(_color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 11, y + 4);
		Basic::Console_SetColor(_color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 1, y + 5);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀██████████▀";

		x++;
		Basic::gotoXY(x + 4, y + 1);
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"▄▀▀▀▀█";
		Basic::gotoXY(x + 1, y + 2);
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"▄▄▄██▄▄ █";
		Basic::gotoXY(x + 1, y + 3);
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"▀▀▀██▀  █";
		Basic::gotoXY(x + 4, y + 4);
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"▀ ▄▄▄█";
	}
	SetConsoleOutputCP(oldcp);
}



void UserInterface::DrawAfterExitButton(int background_Color, int x, int y)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	for (int _X = x; _X < x + 65; _X++) {
		for (int _Y = y; _Y < y + 10; _Y++) {
			Basic::gotoXY(_X, _Y);
			Basic::Console_SetColor(WHITE, WHITE);
			cout << u8"█";
		}
	}
	for (int _X = x; _X < x + 65; _X++) {
		Basic::gotoXY(_X, y);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▀";
		Basic::gotoXY(_X, y + 9);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▄";
	}
	for (int _Y = y; _Y < y + 10; _Y++) {
		Basic::gotoXY(x, _Y);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 64, _Y);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"█";
	}
	Basic::gotoXY(x + 20, y + 2);
	Basic::Console_SetColor(WHITE, BLACK);
	cout << "ARE YOU SURE WANT TO QUIT?";
	DrawExitYesButton(x + 10, y + 5, 0, WHITE);
	DrawExitNoButton(x + 40, y + 5, 0, WHITE);
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawExitYesButton(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 0) {
		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, WHITE);
			cout << u8"█████████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
		Basic::gotoXY(x + 5, y + 1);
		Basic::Console_SetColor(background_Color, RED);
		cout << "YES";
		Basic::gotoXY(x, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀";

		for (int _Y = y; _Y < y + 3; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 12, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
	}
	else {
		for (int _Y = y; _Y < y + 3; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, RED);
			cout << u8"███████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(BLACK, RED);
		cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
		Basic::gotoXY(x + 5, y + 1);
		Basic::Console_SetColor(RED, WHITE);
		cout << "YES";
		Basic::gotoXY(x, y + 3);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄";
		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 13, y + 2);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▀";
	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawExitNoButton(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 0) {
		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, WHITE);
			cout << u8"█████████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
		Basic::gotoXY(x + 6, y + 1);
		Basic::Console_SetColor(background_Color, GREEN);
		cout << "NO";
		Basic::gotoXY(x, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀";
		for (int _Y = y; _Y < y + 3; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 12, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
	}
	else {
		for (int _Y = y; _Y < y + 3; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, GREEN);
			cout << u8"███████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(BLACK, GREEN);
		cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
		Basic::gotoXY(x + 6, y + 1);
		Basic::Console_SetColor(GREEN, WHITE);
		cout << "NO";
		Basic::gotoXY(x, y + 3);
		Basic::Console_SetColor(GREEN, BLACK);
		cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄";
		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 13, y + 2);
		Basic::Console_SetColor(GREEN, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▀";
	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawAfterDead(int background_Color, int x, int y)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	int color_inside = WHITE;
	int color_outside = BLACK;
	for (int _X = x; _X < x + 30; _X++) {
		for (int _Y = y; _Y < y + 21; _Y++) {
			Basic::gotoXY(_X, _Y);
			Basic::Console_SetColor(color_inside, color_inside);
			cout << u8"█";
		}
	}
	for (int _X = x; _X < x + 30; _X++) {
		Basic::gotoXY(_X, y);
		Basic::Console_SetColor(color_inside, color_outside);
		cout << u8"▀";
		Basic::gotoXY(_X, y + 20);
		Basic::Console_SetColor(color_inside, color_outside);
		cout << u8"▄";
	}
	for (int _Y = y; _Y < y + 21; _Y++) {
		Basic::gotoXY(x, _Y);
		Basic::Console_SetColor(color_inside, color_outside);
		cout << u8"█";
		Basic::gotoXY(x + 29, _Y);
		Basic::Console_SetColor(color_inside, color_outside);
		cout << u8"█";
	}
	Basic::gotoXY(x + 11, y + 2);
	Basic::Console_SetColor(color_inside, color_outside);
	cout << "RESTART?";

	DrawRestartFromBeginButton(x + 7, y + 5, 0, color_inside);
	DrawRestartThisRoundButton(x + 7, y + 10, 0, color_inside);
	DrawRunAwayButton(x + 7, y + 15, 0, color_inside);

	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawRestartFromBeginButton(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 0) {
		for (int _Y = y; _Y < y + 5; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, WHITE);
			cout << u8"█████████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(background_Color, GREEN);
		cout << "RESTART";
		Basic::gotoXY(x + 2, y + 2);
		Basic::Console_SetColor(background_Color, GREEN);
		cout << "FROM BEGIN";
		Basic::gotoXY(x, y + 4);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀";

		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
	}
	else {
		x++;
		for (int _Y = y; _Y < y + 3; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, GREEN);
			cout << u8"███████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(BLACK, GREEN);
		cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(GREEN, WHITE);
		cout << "RESTART";
		Basic::gotoXY(x + 2, y + 2);
		Basic::Console_SetColor(GREEN, WHITE);
		cout << "FROM BEGIN";
		Basic::gotoXY(x, y + 3);
		Basic::Console_SetColor(BLACK, GREEN);
		cout << u8"████████████";
		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x - 1, y + 4);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 3);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(GREEN, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 11, y + 4);
		Basic::Console_SetColor(BLACK, WHITE);
		cout << u8"▄";

	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawRestartThisRoundButton(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 0) {
		for (int _Y = y; _Y < y + 5; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, WHITE);
			cout << u8"█████████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << "RESTART";
		Basic::gotoXY(x + 2, y + 2);
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << "THIS ROUND";
		Basic::gotoXY(x, y + 4);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀";

		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
	}
	else {
		x++;
		for (int _Y = y; _Y < y + 3; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, YELLOW);
			cout << u8"███████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(BLACK, YELLOW);
		cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(YELLOW, WHITE);
		cout << "RESTART";
		Basic::gotoXY(x + 2, y + 2);
		Basic::Console_SetColor(YELLOW, WHITE);
		cout << "THIS ROUND";
		Basic::gotoXY(x, y + 3);
		Basic::Console_SetColor(BLACK, YELLOW);
		cout << u8"████████████";
		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x - 1, y + 4);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 3);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(YELLOW, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 11, y + 4);
		Basic::Console_SetColor(BLACK, WHITE);
		cout << u8"▄";

	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawRunAwayButton(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 0) {
		for (int _Y = y; _Y < y + 5; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, WHITE);
			cout << u8"█████████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(background_Color, RED);
		cout << "RUN";
		Basic::gotoXY(x + 2, y + 2);
		Basic::Console_SetColor(background_Color, RED);
		cout << "AWAY";
		Basic::gotoXY(x, y + 4);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀";

		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
	}
	else {
		x++;
		for (int _Y = y; _Y < y + 3; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, RED);
			cout << u8"███████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(BLACK, RED);
		cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(RED, WHITE);
		cout << "RUN";
		Basic::gotoXY(x + 2, y + 2);
		Basic::Console_SetColor(RED, WHITE);
		cout << "AWAY";
		Basic::gotoXY(x, y + 3);
		Basic::Console_SetColor(BLACK, RED);
		cout << u8"████████████";
		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x - 1, y + 4);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 3);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 11, y + 4);
		Basic::Console_SetColor(BLACK, WHITE);
		cout << u8"▄";

	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawAfterPause(int background_Color, int x, int y)
{
	UImtx.lock();
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	int color_inside = WHITE;
	int color_outside = BLACK;
	for (int _X = x; _X < x + 30; _X++) {
		for (int _Y = y; _Y < y + 21; _Y++) {
			Basic::gotoXY(_X, _Y);
			Basic::Console_SetColor(color_inside, color_inside);
			cout << u8"█";
		}
	}
	for (int _X = x; _X < x + 30; _X++) {
		Basic::gotoXY(_X, y);
		Basic::Console_SetColor(color_inside, color_outside);
		cout << u8"▀";
		Basic::gotoXY(_X, y + 20);
		Basic::Console_SetColor(color_inside, color_outside);
		cout << u8"▄";
	}
	for (int _Y = y; _Y < y + 21; _Y++) {
		Basic::gotoXY(x, _Y);
		Basic::Console_SetColor(color_inside, color_outside);
		cout << u8"█";
		Basic::gotoXY(x + 29, _Y);
		Basic::Console_SetColor(color_inside, color_outside);
		cout << u8"█";
	}
	Basic::gotoXY(x + 11, y + 2);
	Basic::Console_SetColor(color_inside, color_outside);
	cout << "CONTINUE?";
	
	DrawContinueButton(x + 7, y + 5, 0, color_inside);
	DrawRestartButton(x + 7, y + 10, 0, color_inside);
	DrawLeaveButton(x + 7, y + 15, 0, color_inside);

	SetConsoleOutputCP(oldcp);
	UImtx.unlock();
}

void UserInterface::DrawContinueButton(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 0) {
		for (int _Y = y; _Y < y + 5; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, WHITE);
			cout << u8"█████████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(background_Color, GREEN);
		cout << "CONTINUE";
		Basic::gotoXY(x, y + 4);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀";

		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
	}
	else {
		x++;
		for (int _Y = y; _Y < y + 3; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, GREEN);
			cout << u8"███████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(BLACK, GREEN);
		cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(GREEN, WHITE);
		cout << "CONTINUE";
		Basic::gotoXY(x, y + 3);
		Basic::Console_SetColor(BLACK, GREEN);
		cout << u8"████████████";
		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x - 1, y + 4);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 3);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(GREEN, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 11, y + 4);
		Basic::Console_SetColor(BLACK, WHITE);
		cout << u8"▄";

	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawRestartButton(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 0) {
		for (int _Y = y; _Y < y + 5; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, WHITE);
			cout << u8"█████████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(background_Color, YELLOW);
		cout << "RESTART";
		Basic::gotoXY(x, y + 4);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀";

		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
	}
	else {
		x++;
		for (int _Y = y; _Y < y + 3; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, YELLOW);
			cout << u8"███████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(BLACK, YELLOW);
		cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(YELLOW, WHITE);
		cout << "RESTART";
		Basic::gotoXY(x, y + 3);
		Basic::Console_SetColor(BLACK, YELLOW);
		cout << u8"████████████";
		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x - 1, y + 4);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 3);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(YELLOW, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 11, y + 4);
		Basic::Console_SetColor(BLACK, WHITE);
		cout << u8"▄";

	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawLeaveButton(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 0) {
		for (int _Y = y; _Y < y + 5; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, WHITE);
			cout << u8"█████████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(background_Color, RED);
		cout << "LEAVE";
		Basic::gotoXY(x, y + 4);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀";

		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
	}
	else {
		x++;
		for (int _Y = y; _Y < y + 3; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, RED);
			cout << u8"███████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(BLACK, RED);
		cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(RED, WHITE);
		cout << "LEAVE";
		Basic::gotoXY(x, y + 3);
		Basic::Console_SetColor(BLACK, RED);
		cout << u8"████████████";
		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x - 1, y + 4);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 3);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 11, y + 4);
		Basic::Console_SetColor(BLACK, WHITE);
		cout << u8"▄";

	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawQuestionMark(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	Basic::gotoXY(x + 1, y);
	Basic::Console_SetColor(background_Color, BLACK);
	cout << u8"▄▀▀▀▀▄";
	Basic::gotoXY(x, y + 1);
	Basic::Console_SetColor(background_Color, BLACK);
	cout << u8"█      █";
	Basic::gotoXY(x + 5, y + 2);
	Basic::Console_SetColor(background_Color, BLACK);
	cout << u8"▄▀";
	Basic::gotoXY(x + 3, y + 3);
	Basic::Console_SetColor(background_Color, BLACK);
	cout << u8"▄▀";
	Basic::gotoXY(x + 3, y + 4);
	Basic::Console_SetColor(background_Color, BLACK);
	cout << u8"▄";


	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawCustom(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	Basic::gotoXY(x + 1, y);
	Basic::Console_SetColor(background_Color, BLACK);
	cout << u8"█  █  ▀";
	Basic::gotoXY(x + 6, y);
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"▄";
	Basic::Console_SetColor(BLACK, YELLOW);
	cout << u8"▄";
	Basic::Console_SetColor(background_Color, YELLOW);
	cout << u8"▄";
	Basic::gotoXY(x, y + 1);
	Basic::Console_SetColor(background_Color, LIGHTBLUE);
	cout << u8"▀";
	Basic::Console_SetColor(BLACK, LIGHTBLUE);
	cout << u8"▀";
	Basic::Console_SetColor(background_Color, LIGHTBLUE);
	cout << u8"▀";
	Basic::Console_SetColor(background_Color, BLACK);
	cout << u8" █  █";
	Basic::gotoXY(x + 1, y + 2);
	Basic::Console_SetColor(background_Color, BLACK);
	cout << u8"█ ";
	Basic::Console_SetColor(background_Color, RED);
	cout << u8"▀";
	Basic::Console_SetColor(BLACK, RED);
	cout << u8"▀";
	Basic::Console_SetColor(background_Color, RED);
	cout << u8"▀";
	Basic::Console_SetColor(background_Color, BLACK);
	cout << u8" █";


	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawChoosePlayer()
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);

	int background_Color = WHITE;
	int cl = BLACK;
	DrawChooseBox(20, 5, 0, background_Color, cl);
	DrawPenguin(24, 7, 1, background_Color);
	Basic::gotoXY(24, 12);
	Basic::Console_SetColor(cl, WHITE);
	cout << "PENGUIN";
	DrawChooseBox(40, 5, 0, background_Color, cl);
	DrawChicken(44, 7, 1, background_Color);
	Basic::gotoXY(45, 12);
	Basic::Console_SetColor(cl, WHITE);
	cout << "CHICK";
	DrawChooseBox(60, 5, 0, background_Color, cl);
	DrawParrot(64, 7, 1, background_Color);
	Basic::gotoXY(65, 12);
	Basic::Console_SetColor(cl, WHITE);
	cout << "PARROT";
	DrawChooseBox(80, 5, 0, background_Color, cl);
	DrawQuestionMark(84, 6, 1, background_Color);
	Basic::gotoXY(83, 12);
	Basic::Console_SetColor(cl, WHITE);
	cout << "BUGGY MAN";
	DrawChooseBox(100, 5, 0, background_Color, cl);
	DrawCustom(103, 7, 0, background_Color);
	Basic::gotoXY(105, 12);
	Basic::Console_SetColor(cl, WHITE);
	cout << "CUSTOM";

	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawChooseBox(int x, int y, bool mode, int& background_Color, int& cl)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 0) {
		cl = BLACK;
		background_Color = WHITE;
		int color_inside = WHITE;
		int color_outside = BLACK;
		for (int _X = x - 1; _X < x + 16; _X++) {
			for (int _Y = y - 1; _Y < y + 7; _Y++) {
				Basic::gotoXY(_X, _Y);
				Basic::Console_SetColor(color_inside, color_inside);
				cout << u8"█";
			}
		}
		for (int _X = x; _X < x + 15; _X++) {
			for (int _Y = y; _Y < y + 6; _Y++) {
				Basic::gotoXY(_X, _Y);
				Basic::Console_SetColor(color_inside, color_inside);
				cout << u8"█";
			}
		}
		for (int _X = x; _X < x + 15; _X++) {
			Basic::gotoXY(_X, y);
			Basic::Console_SetColor(color_inside, color_outside);
			cout << u8"▀";
			Basic::gotoXY(_X, y + 6);
			Basic::Console_SetColor(color_inside, color_outside);
			cout << u8"▄";
		}
		for (int _Y = y; _Y < y + 7; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(color_inside, color_outside);
			cout << u8"█";
			Basic::gotoXY(x + 14, _Y);
			Basic::Console_SetColor(color_inside, color_outside);
			cout << u8"█";
		}
	}
	else {
		cl = GREEN;
		background_Color = WHITE;
		x--;
		y--;
		int color_inside = WHITE;
		int color_outside = GREEN;
		for (int _X = x; _X < x + 17; _X++) {
			for (int _Y = y; _Y < y + 7; _Y++) {
				Basic::gotoXY(_X, _Y);
				Basic::Console_SetColor(color_inside, color_inside);
				cout << u8"█";
			}
		}
		for (int _X = x; _X < x + 17; _X++) {
			Basic::gotoXY(_X, y);
			Basic::Console_SetColor(color_inside, color_outside);
			cout << u8"▀";
			Basic::gotoXY(_X, y + 7);
			Basic::Console_SetColor(color_inside, color_outside);
			cout << u8"▄";
		}
		for (int _Y = y; _Y < y + 8; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(color_inside, color_outside);
			cout << u8"█";
			Basic::gotoXY(x + 16, _Y);
			Basic::Console_SetColor(color_inside, color_outside);
			cout << u8"█";
		}
	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawAdditionMark(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 0) {
		Basic::gotoXY(x + 1, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀█▀";
	}
	else {
		Basic::gotoXY(x + 1, y);
		Basic::Console_SetColor(background_Color, RED);
		cout << u8"▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, RED);
		cout << u8"▀█▀";
	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawSubtractionMark(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 0) {
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀";
	}
	else {
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(background_Color, RED);
		cout << u8"▀▀▀▀";
	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawCustomButton(int background_Color, int x, int y)
{
	
		UINT oldcp = GetConsoleOutputCP();
		SetConsoleOutputCP(CP_UTF8);
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << "SPEED:";
		DrawAdditionMark(x + 10, y - 1, 0, background_Color);
		DrawSubtractionMark(x + 30, y - 1, 0, background_Color);
		Basic::gotoXY(x, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << "JUMP:";
		DrawAdditionMark(x + 10, y + 1, 0, background_Color);
		DrawSubtractionMark(x + 30, y + 1, 0, background_Color);
		Basic::gotoXY(x, y + 4);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << "DELAY:";
		DrawAdditionMark(x + 10, y + 3, 0, background_Color);
		DrawSubtractionMark(x + 30, y + 3, 0, background_Color);

		SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawStartGame_StartButton(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 0) {
		for (int _Y = y; _Y < y + 5; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, WHITE);
			cout << u8"█████████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(background_Color, GREEN);
		cout << "START GAME";
		Basic::gotoXY(x, y + 4);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀";

		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
	}
	else {
		x++;
		for (int _Y = y; _Y < y + 3; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, GREEN);
			cout << u8"███████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(BLACK, GREEN);
		cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(GREEN, WHITE);
		cout << "START GAME";
		Basic::gotoXY(x, y + 3);
		Basic::Console_SetColor(BLACK, GREEN);
		cout << u8"████████████";
		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x - 1, y + 4);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 3);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(GREEN, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 11, y + 4);
		Basic::Console_SetColor(BLACK, WHITE);
		cout << u8"▄";

	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawStartGame_BackButton(int x, int y, bool mode, int background_Color)
{
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	if (mode == 0) {
		for (int _Y = y; _Y < y + 5; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, WHITE);
			cout << u8"█████████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(background_Color, RED);
		cout << "BACK";
		Basic::gotoXY(x, y + 4);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀";

		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▄";
	}
	else {
		x++;
		for (int _Y = y; _Y < y + 3; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, RED);
			cout << u8"███████████████";
		}
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(BLACK, RED);
		cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
		Basic::gotoXY(x + 2, y + 1);
		Basic::Console_SetColor(RED, WHITE);
		cout << "BACK";
		Basic::gotoXY(x, y + 3);
		Basic::Console_SetColor(BLACK, RED);
		cout << u8"████████████";
		for (int _Y = y; _Y < y + 4; _Y++) {
			Basic::gotoXY(x - 1, _Y);
			Basic::Console_SetColor(background_Color, BLACK);
			cout << u8"█";
		}
		Basic::gotoXY(x - 1, y + 4);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 14, y);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 1);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 14, y + 2);
		Basic::Console_SetColor(background_Color, BLACK);
		cout << u8"█";
		Basic::gotoXY(x + 13, y + 3);
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▀";
		Basic::gotoXY(x + 12, y + 3);
		Basic::Console_SetColor(RED, BLACK);
		cout << u8"▄";
		Basic::gotoXY(x + 11, y + 4);
		Basic::Console_SetColor(BLACK, WHITE);
		cout << u8"▄";

	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::Write(const string& str, int x, int y, int tColor, int bColor)
{
	UImtx.lock();
	Basic::gotoXY(x, y);
	Basic::Console_SetColor(bColor, tColor);
	cout << str;
	UImtx.unlock();
}

void UserInterface::DrawRiverDeadEffect(int x, int y, int player)
{
	Sound::PlaySFX(SPLASH);
	int _color = WHITE;
	if (player == 0) _color = RED;
	else if (player == 1) _color = DARKBLUE;
	else if (player == 2) _color = YELLOW;
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	for (int i = 0; i < 3; i++) {
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(DARKBLUE, WHITE);
		cout << u8"▄▄";
		Basic::gotoXY(x + 5, y);
		Basic::Console_SetColor(DARKBLUE, WHITE);
		cout << u8"▄▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(BLUE, BLACK);
		cout << u8"▀";
		Basic::Console_SetColor(WHITE, BLACK);
		cout << u8"▄";
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"█▄█▀";
		Basic::gotoXY(x + 1, y + 2);
		Basic::Console_SetColor(BLUE, WHITE);
		cout << u8"▄█";
		Basic::Console_SetColor(BLACK, WHITE);
		cout << u8"▀█";
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"▄";
		Basic::gotoXY(x, y + 3);
		Basic::Console_SetColor(DARKBLUE, WHITE);
		cout << u8"▀▀";
		Basic::gotoXY(x + 5, y + 3);
		Basic::Console_SetColor(DARKBLUE, WHITE);
		cout << u8"▀▀";
		Sleep(500);

		Basic::gotoXY(x, y);
		Basic::Console_SetColor(DARKBLUE, NYAN);
		cout << u8"▄▄";
		Basic::gotoXY(x + 5, y);
		Basic::Console_SetColor(DARKBLUE, NYAN);
		cout << u8"▄▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(BLUE, BLACK);
		cout << u8"▀";
		Basic::Console_SetColor(NYAN, BLACK);
		cout << u8"▄";
		Basic::Console_SetColor(_color, NYAN);
		cout << u8"█▄█▀";
		Basic::gotoXY(x + 1, y + 2);
		Basic::Console_SetColor(BLUE, NYAN);
		cout << u8"▄█";
		Basic::Console_SetColor(BLACK, NYAN);
		cout << u8"▀█";
		Basic::Console_SetColor(_color, NYAN);
		cout << u8"▄";
		Basic::gotoXY(x, y + 3);
		Basic::Console_SetColor(DARKBLUE, NYAN);
		cout << u8"▀▀";
		Basic::gotoXY(x + 5, y + 3);
		Basic::Console_SetColor(DARKBLUE, NYAN);
		cout << u8"▀▀";
		Sleep(500);

	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawRoadDeadEffect(int x, int y, int player)
{
	Sound::PlaySFX(CRASH);
	int _color = WHITE;
	if (player == 0) _color = RED;
	else if (player == 1) _color = DARKBLUE;
	else if (player == 2) _color = YELLOW;
	UINT oldcp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	for (int i = 0; i < 3; i++) {
		Basic::gotoXY(x, y);
		Basic::Console_SetColor(LIGHTGREY, WHITE);
		cout << u8"▄▄";
		Basic::gotoXY(x + 5, y);
		Basic::Console_SetColor(LIGHTGREY, WHITE);
		cout << u8"▄▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(BLACK, GREY);
		cout << u8"▀";
		Basic::Console_SetColor(WHITE, GREY);
		cout << u8"▄";
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"█▄█▀";
		Basic::gotoXY(x + 1, y + 2);
		Basic::Console_SetColor(BLACK, WHITE);
		cout << u8"▄█";
		Basic::Console_SetColor(GREY, WHITE);
		cout << u8"▀█";
		Basic::Console_SetColor(_color, WHITE);
		cout << u8"▄";
		Basic::gotoXY(x, y + 3);
		Basic::Console_SetColor(LIGHTGREY, WHITE);
		cout << u8"▀▀";
		Basic::gotoXY(x + 5, y + 3);
		Basic::Console_SetColor(LIGHTGREY, WHITE);
		cout << u8"▀▀";
		Sleep(500);

		Basic::gotoXY(x, y);
		Basic::Console_SetColor(LIGHTGREY, RED);
		cout << u8"▄▄";
		Basic::gotoXY(x + 5, y);
		Basic::Console_SetColor(LIGHTGREY, RED);
		cout << u8"▄▄";
		Basic::gotoXY(x, y + 1);
		Basic::Console_SetColor(BLACK, GREY);
		cout << u8"▀";
		Basic::Console_SetColor(RED, GREY);
		cout << u8"▄";
		Basic::Console_SetColor(_color, RED);
		cout << u8"█▄█▀";
		Basic::gotoXY(x + 1, y + 2);
		Basic::Console_SetColor(BLACK, RED);
		cout << u8"▄█";
		Basic::Console_SetColor(GREY, RED);
		cout << u8"▀█";
		Basic::Console_SetColor(_color, RED);
		cout << u8"▄";
		Basic::gotoXY(x, y + 3);
		Basic::Console_SetColor(LIGHTGREY, RED);
		cout << u8"▀▀";
		Basic::gotoXY(x + 5, y + 3);
		Basic::Console_SetColor(LIGHTGREY, RED);
		cout << u8"▀▀";
		Sleep(500);

	}
	SetConsoleOutputCP(oldcp);
}

void UserInterface::DrawBGMButton(bool mode)
{
	if (mode)
	{
		Drawbox(50, 5, 30, 4, BLACK, BLUE);
		Write("BACK GROUND MUSIC", 56, 6, GOLDEN, BLUE);
	}
	else
	{
		Drawbox(50, 5, 30, 4, BLACK, WHITE);
		Write("BACK GROUND MUSIC", 56, 6, BLUE, WHITE);
	}
	

}

void UserInterface::DrawSFXButton(bool mode)
{
	if (mode)
	{
		UserInterface::Drawbox(50, 15, 30, 4, BLACK, GREEN);
		Write("SOUND EFFECT", 59, 16, GOLDEN, GREEN);

	}
	else
	{
		UserInterface::Drawbox(50, 15, 30, 4, BLACK, WHITE);
		Write("SOUND EFFECT", 59, 16, GREEN, WHITE);

	}

}

void UserInterface::DrawCreditBackButton(bool mode)
{
	if (mode)
	{
		UserInterface::Drawbox(45, 22, 10, 3, BLACK, RED);
		UserInterface::Write("BACK", 48, 23, GOLDEN, RED);
	}
	else
	{
		UserInterface::Drawbox(45, 22, 10, 3, BLACK, WHITE);
		UserInterface::Write("BACK", 48, 23, RED, WHITE);
	}
}

void UserInterface::DrawCreditNextButton(bool mode)
{
	if (mode)
	{
		UserInterface::Drawbox(70, 22, 10, 3, BLACK, GREEN);
		UserInterface::Write("NEXT", 73, 23, GOLDEN, GREEN);
	}
	else
	{
		UserInterface::Drawbox(70, 22, 10, 3, BLACK, WHITE);
		UserInterface::Write("NEXT", 73, 23, GREEN, WHITE);
	}
}

void UserInterface::DrawLoadBackButton(bool mode)
{

	if (mode)
	{
		UserInterface::Drawbox(12, 23, 10, 3, BLACK, RED);
		UserInterface::Write("BACK", 15, 24, GOLDEN, RED);
	}
	else
	{
		UserInterface::Drawbox(12, 23, 10, 3, BLACK, WHITE);
		UserInterface::Write("BACK", 15, 24, RED, WHITE);
	}
}

void UserInterface::Write_Info(int speed, int x, int y, int background_Color)
{
	Basic::gotoXY(x, y);
	Basic::Console_SetColor(background_Color, background_Color);
	cout << "           ";
	Basic::gotoXY(x, y);
	Basic::Console_SetColor(background_Color, BLACK);
	cout << speed;
}

