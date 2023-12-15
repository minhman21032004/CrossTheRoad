#pragma once
#include<iostream>
#include<Windows.h>
#include"Gameplay.h"
#include"UserInterface.h"

#define MENU_RUNNING		0
#define MENU_CUSTOMING		1
#define MENU_STARTGAME		2
#define MENU_PLAYING_GAME	3
#define MENU_LOADGAME		4
#define DATAFILE			"savedata.txt"
using namespace std;
class Menu
{
	bool run;
	bool pause;
	int menu_status;
	bool is_chosen;
	int pType, pSpeed, pJump, pDelay;
	vector<string> saveList;
public:
	Menu();
	void Menu_startGamebox(POINT,POINT);
	void Menu_loadGamebox(POINT, POINT);
	void Menu_settingBox(POINT, POINT);
	void Menu_creditBox(POINT, POINT);
	void Menu_quitBox(POINT, POINT);

	//Menu main page process
	void Menu_process(POINT, POINT);
	void Menu_Interac(POINT);
	void Menu_screen();

	//Menu quit process
	void Menu_QyesBox(POINT, POINT);
	void Menu_QnoBox(POINT, POINT);
	void Menu_askQuit();
	void Menu_askQuitProccess(POINT,POINT);
	int Menu_askQuitInterac(POINT);
	void Menu_Quit();


	//Menu start game process
	void Menu_startGame();
	void startgame_PenguinBox(POINT, POINT);
	void startgame_ChickBox(POINT, POINT);
	void startgame_ParrotBox(POINT, POINT);
	void startgame_BuggymanBox(POINT, POINT);
	void startgame_CustomBox(POINT, POINT);
	void startgame_startButtonBox(POINT, POINT);
	void startgame_backButtonBox(POINT, POINT);
	void startgame_process(POINT, POINT);
	int startgame_interac(POINT);

	//Menu custom process
	void custom_addSpeedBox(POINT, POINT);
	void custom_subSpeedBox(POINT, POINT);
	void custom_addJumpBox(POINT, POINT);
	void custom_subJumpBox(POINT, POINT);
	void custom_addDelayBox(POINT, POINT);
	void custom_subDelayBox(POINT, POINT);
	void custom_process(POINT, POINT);
	int custom_interac(POINT, int&, int&, int&);
	int Menu_custom();

	//Menu setting process
	void Menu_Setting();
	void setting_bgmBox(POINT, POINT);
	void setting_sfxBox(POINT, POINT);
	void setting_backBox(POINT, POINT);
	void setting_process(POINT, POINT);
	int setting_interac(POINT);
	void Menu_BGMstat();
	void Menu_SFXstat();

	//Menu credit process
	void Menu_Credit();
	void About_page1();
	void About_page2();
	void Credit_backBox(POINT, POINT);
	void Credit_nextBox(POINT, POINT);
	void Credit_process(POINT, POINT, int);
	int Credit_interac(POINT, int);

	//Menu save load process
	void Menu_saveSetup();
	void Menu_saveUpdate();
	void add_saveName(const string&);
	string Menu_getSaveName(int, int);
	void Menu_loadGame();
	void Menu_loadScreen();
	void Menu_loadProcess(POINT, POINT);
	void Menu_saveSlot_1(POINT, POINT);
	void Menu_saveSlot_2(POINT, POINT);
	void Menu_saveSlot_3(POINT, POINT);
	void Menu_saveSlot_4(POINT, POINT);
	void Menu_loadGoback(POINT, POINT);
	int Menu_loadInterac(POINT);

	void Menu_drawChooseBox(int, bool);
};

