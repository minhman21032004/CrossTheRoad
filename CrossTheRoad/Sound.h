#pragma comment(lib, "winmm.lib")
#pragma once
#include "Basic.h"
#include <string>
using namespace std;

const pair<wstring, wstring> BACKGROUND = { L"0", L"sound\\TaiyouParadise.mp3" };
const pair<wstring, wstring> CLICK = { L"1",L"sound\\clickingSound.wav" };
const pair<wstring, wstring> SELECTING = { L"2",L"sound\\selecting.wav" };
const pair<wstring, wstring> UPSTAT = { L"3",L"sound\\upStat.mp3" };
const pair<wstring, wstring> DOWNSTAT = { L"4",L"sound\\downStat.wav" };
const pair<wstring, wstring> MOVE = { L"5",L"sound\\playerMove.wav" };
const pair<wstring, wstring> CRASH = { L"6",L"sound\\crash.wav" };
const pair<wstring, wstring> SPLASH = { L"7",L"sound\\splash.mp3" };
const pair<wstring, wstring> END = { L"8",L"sound\\GameEnd.wav" };
const pair<wstring, wstring> LEVELUP = { L"9",L"sound\\levelUp.mp3" };
const pair<wstring, wstring> WIN = { L"10",L"sound\\gameWin.mp3" };
const pair<wstring, wstring> CREDIT = { L"11", L"sound\\NekoWillBe.mp3" };
const pair<wstring, wstring> GAME_BACKGROUND = { L"12", L"sound\\CatWork.mp3" };



class Sound
{
public:
	static bool backgroundSound;
	static bool sfx;
	static bool isBackgroundPlaying;	//Dung de phat lai sau khi het nhac
	static bool creditSound;
	static bool gameSound;

	static void openSound(const pair<wstring, wstring> path);
	static void playSound(const pair<wstring, wstring>);
	static void pauseSound(const pair<wstring, wstring>);
	static void repeatSound(const pair<wstring, wstring>);
	static void closeSound(const pair<wstring, wstring>);		//Khi het chuong trinh closeSound gium`

	static void TurnBackgroundSound();
	static void TurnCreditSound();
	static void TurnGameBackgroundSound();
	static void PlaySFX(const pair<wstring, wstring>);
	static void prepareSound();
};

