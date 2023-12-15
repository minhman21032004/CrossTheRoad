#pragma once
#pragma warning(disable : 4996)
#include <Windows.h>
#include <string>
#include<fstream>
#include<iostream>
#include <vector>
#include <conio.h>
#include <Random>
#include<chrono>
#include<thread>
#include<ctime>
#include"Sound.h"
using namespace std;
#pragma comment(lib, "Winmm.lib")

#define BLACK		0
#define DARKBLUE	1
#define DARKGREEN	2
#define LIGHTBLUE	3
#define RED			4
#define DARKPURPLE	5
#define YELLOW		6
#define LIGHTGREY	7
#define GREY		8
#define BLUE		9
#define GREEN		10
#define NYAN		11
#define LIGHTRED	12
#define PURPLE		13
#define GOLDEN		14
#define WHITE		15

#define CONSOLE_WIDTH	131 
#define CONSOLE_HEIGHT	30 

class Basic
{
public:
	static HWND consoleWindow;    //Pointer to handle console
	static HANDLE consoleOutput;  //Pointer to handle output console


	static void gotoXY(int, int);	//Set cursor posittion into x and y

	static void Console_showCursor(bool s);	//Show-hide cursor on the console

	static int getKeyInput();	//Get keyboard input, return a number

	static void Console_SetAndCenterWindow();	//Place console in the center and set size

	static void Console_SetColor(int, int);	//Set background and text color

	static void Console_setTitle();		//Set title for the console

	static void Console_SetFont();	//Set font and size

	static void Console_DisableMaxSize();	//Prevent user to maximizing the console window

	static void Console_HideScrollBar();	// Hide scroll bar

	static void Console_ClearScreen();	//Clear console screen

	static void Console_DisableMouseInput();	//Disable mouse input

	static void Console_Setup();	//set startup console

	static void textcolor(int);	//Set text color

	static void joinThread(std::thread*);	//Join thread

	static void sleepFor_second(int);	//Sleep for second

	static void sleepFor_milisec(int);	//Sleep for milisecond

	static void Console_setFullscr();	//Set console to fullscreen

	static POINT getMousePos();	//Get mouse position

	static string get_dateTime();	//Get current date and time

	static void reFormat(string&);	//Reformat string for save load purpose
};

ofstream& operator<<(ofstream&, vector<string>&);	//Overload operator << for writting binary file
ifstream& operator >> (ifstream&, vector<string>&);	//Overload operator >> for reading binary file
