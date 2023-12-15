#include "Sound.h"


//wstring Alias(const wstring path)
//{
//	if (path.first == BACKGROUND)
//		return L"0";
//	else return L"1";
//}

void Sound::openSound(const pair<wstring, wstring> path)
{
	wstring command = L"open \"" + path.second + L"\" type mpegvideo alias " + path.first;
	mciSendString(command.c_str(), NULL, 0, NULL);
}

void Sound::playSound(const pair<wstring, wstring> path)
{
	wstring command = L"play " + path.first + L" from 0";
	mciSendString(command.c_str(), NULL, 0, NULL);
}

void Sound::pauseSound(const pair<wstring, wstring> path)
{
	wstring command = L"pause " + path.first;
	mciSendString(command.c_str(), NULL, 0, NULL);
}

void Sound::repeatSound(const pair<wstring, wstring> path) {
	Sound::openSound(path);
	wstring command = L"play " + path.first + L" from 0 repeat";
	mciSendString(command.c_str(), 0, 0, 0);
}

void Sound::closeSound(const pair<wstring, wstring> path)
{
	wstring command = L"close " + path.first;
	mciSendString(command.c_str(), NULL, 0, NULL);
}



void Sound::PlaySFX(const pair<wstring, wstring> path)
{
	if (sfx)
		playSound(path);
}

void Sound::prepareSound()
{
	openSound(BACKGROUND);
	openSound(CLICK);
	openSound(SELECTING);
	openSound(UPSTAT);
	openSound(DOWNSTAT);
	openSound(MOVE);
	openSound(CRASH);
	openSound(SPLASH);
	openSound(END);
	openSound(LEVELUP);
	openSound(WIN);
	openSound(CREDIT);
	openSound(GAME_BACKGROUND);
}


void Sound::TurnBackgroundSound()
{
	if (backgroundSound)
		playSound(BACKGROUND);
	else
		pauseSound(BACKGROUND);
}

void Sound::TurnCreditSound()
{
	if (creditSound)
		playSound(CREDIT);
	else
		pauseSound(CREDIT);
}

void Sound::TurnGameBackgroundSound()
{
	if (gameSound)
		playSound(GAME_BACKGROUND);
	else
		pauseSound(GAME_BACKGROUND);
}

