#pragma once
#include "Basic.h"
#include <iostream>
#include<io.h>
#include<fcntl.h>
#include<condition_variable>

using namespace std;

class UserInterface
{
public:

	static void Drawbox(int x, int y, int width, int height, int t_color = BLACK, int b_color = WHITE);	// Draw box with position, width height, color and background color


	static void DrawParrot(int x, int y, bool mode, int background_Color); //draw parrot
	static void DrawChicken(int x, int y, bool mode, int background_Color); //draw chicken
	static void DrawPenguin(int x, int y, bool mode, int background_Color); //draw penguin
	static void DrawBee(int x, int y, bool mode, int background_Color); //draw bee
	static void DrawDog(int x, int y, bool mode, int background_Color); //draw dog
	static void DrawBug(int x, int y, bool mode, int background_Color);// Draw bug

	static void DrawBCar(int x, int y, bool mode, int background_Color); //draw blue car
	static void DrawRCar(int x, int y, bool mode, int background_Color); //draw red car
	static void DrawTruck(int x, int y, bool mode, int background_Color); //draw truck
	static void DrawTrain(int x, int y, bool mode, int background_Color); //draw train


	static void DrawReverseRCar(int x, int y, bool mode, int background_Color);
	static void DrawReverseBCar(int x, int y, bool mode, int background_Color);
	static void DrawReverseTruck(int x, int y, bool mode, int background_Color);

	static void TestColor(int x, int y, int color);
	static void DrawSafeLane(int x, int y, int background_Color);
	static void DrawRoadLane(int x, int y, int background_Color);
	static void DrawRiverLane(int x, int y, int background_Color);
	static void DrawLeafRiver(int x, int y);
	static void DrawTrainLane(int x, int y, int background_Color); //dthien new train lane


	static void DrawVehicle_Right(int type, int x, int y, bool mode, int background_Color, int laneType);
	static void DrawBack_Right(int x, int y, int background_Color, int laneType);

	static void DrawBack_Left(int x, int y, int background_Color, int laneType);
	static void DrawVehicle_Left(int type, int x, int y, bool mode, int background_Color, int laneType);

	static void CarFadeEffect_Left(int y, int background_Color);

	static void DrawMenuGame();
	static void DrawC(int x, int y, int background_Color);
	static void DrawR1(int x, int y, int background_Color);
	static void DrawO1(int x, int y, int background_Color);
	static void DrawS1(int x, int y, int background_Color);
	static void DrawS2(int x, int y, int background_Color);
	static void DrawI(int x, int y, int background_Color);
	static void DrawN(int x, int y, int background_Color);
	static void DrawG(int x, int y, int background_Color);
	static void DrawR2(int x, int y, int background_Color);
	static void DrawO2(int x, int y, int background_Color);
	static void DrawA(int x, int y, int background_Color);
	static void DrawD(int x, int y, int background_Color);

	static void DrawPlayButton(int x, int y, bool mode, int background_Color);
	static void DrawLoadButton(int x, int y, bool mode, int background_Color);
	static void DrawSettingButton(int x, int y, bool mode, int background_Color);
	static void DrawCreditsButton(int x, int y, bool mode, int background_Color);
	static void DrawExitButton(int x, int y, bool mode, int background_Color);

	static void DrawAfterExitButton(int background_Color, int x = 35, int y = 15);
	static void DrawExitYesButton(int x, int y, bool mode, int background_Color);
	static void DrawExitNoButton(int x, int y, bool mode, int background_Color);

	static void DrawAfterDead(int background_Color, int x = 50, int y = 5);
	static void DrawRestartFromBeginButton(int x, int y, bool mode, int background_Color);
	static void DrawRestartThisRoundButton(int x, int y, bool mode, int background_Color);
	static void DrawRunAwayButton(int x, int y, bool mode, int background_Color);

	static void DrawAfterPause(int background_Color, int x = 50, int y = 5); //24/11/2023
	static void DrawContinueButton(int x, int y, bool mode, int background_Color); //24/11/2023
	static void DrawRestartButton(int x, int y, bool mode, int background_Color); //24/11/2023
	static void DrawLeaveButton(int x, int y, bool mode, int background_Color); //24/11/2023

	static void DrawQuestionMark(int x, int y, bool mode, int background_Color); //24/11/2023
	static void DrawCustom(int x, int y, bool mode, int background_Color); //24/11/2023
	static void DrawChoosePlayer(); //24/11/2023
	static void DrawChooseBox(int x, int y, bool mode, int& background_Color, int& cl); //24/11/2023

	static void DrawAdditionMark(int x, int y, bool mode, int background_Color); //24/11/2023
	static void DrawSubtractionMark(int x, int y, bool mode, int background_Color); //24/11/2023
	static void DrawCustomButton(int background_Color, int x = 50, int y = 20); //24/11/2023
	static void DrawStartGame_StartButton(int x, int y, bool mode, int background_Color);
	static void DrawStartGame_BackButton(int x, int y, bool mode, int background_Color);

	static void DrawRiverDeadEffect(int x, int y, int player);
	static void DrawRoadDeadEffect(int x, int y, int player);

	static void DrawBGMButton(bool mode);

	static void DrawSFXButton(bool mode);

	static void DrawCreditBackButton(bool mode);
	static void DrawCreditNextButton(bool mode);

	static void DrawLoadBackButton(bool mode);

	static void Write(const string&, int, int, int, int);
	static void Write_Info(int num, int x, int y, int background_Color);

};

