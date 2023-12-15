#include "Menu.h"

Menu::Menu()
{
	run = true;
	pause = false;
	menu_status = 0;
	pType = -1;
	pSpeed = 3;
	pJump = 1;
	pDelay = 50;
	is_chosen = false;

	ifstream inf;
	inf.open(DATAFILE, ios::in);
	if (inf.is_open())
	{
		inf >> saveList;
		inf.close();
	}
}

void Menu::Menu_startGamebox(POINT oldp,POINT newp)
{
	if (!((oldp.x >= 160 && oldp.x <= 295 && oldp.y >= 573 && oldp.y <= 714)))
		if (newp.x >= 160 && newp.x <= 295 && newp.y >= 573 && newp.y <= 714)
		{
			UserInterface::DrawPlayButton(10, 23, 1, GREEN);
			Sound::PlaySFX(SELECTING);
		}

	if ((oldp.x >= 160 && oldp.x <= 295 && oldp.y >= 573 && oldp.y <= 714))
		if (!(newp.x >= 160 && newp.x <= 295 && newp.y >= 573 && newp.y <= 714))
			UserInterface::DrawPlayButton(10, 23, 0, GREEN);
}

void Menu::Menu_loadGamebox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 438 && oldp.x <= 573 && oldp.y >= 573 && oldp.y <= 714)))
		if (newp.x >= 438 && newp.x <= 573 && newp.y >= 573 && newp.y <= 714)
		{
			UserInterface::DrawLoadButton(35, 23, 1, GREEN);
			Sound::PlaySFX(SELECTING);
		}

	if ((oldp.x >= 438 && oldp.x <= 573 && oldp.y >= 573 && oldp.y <= 714))
		if (!(newp.x >= 438 && newp.x <= 573 && newp.y >= 573 && newp.y <= 714))
			UserInterface::DrawLoadButton(35, 23, 0, GREEN);

}

void Menu::Menu_creditBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 719 && oldp.x <= 854 && oldp.y >= 573 && oldp.y <= 714)))
		if (newp.x >= 719 && newp.x <= 854 && newp.y >= 573 && newp.y <= 714)
		{
			UserInterface::DrawCreditsButton(60, 23, 1, GREEN);
			Sound::PlaySFX(SELECTING);
		}
	if ((oldp.x >= 719 && oldp.x <= 854 && oldp.y >= 573 && oldp.y <= 714))
		if (!(newp.x >= 719 && newp.x <= 854 && newp.y >= 573 && newp.y <= 714))
			UserInterface::DrawCreditsButton(60, 23, 0, GREEN);
}

void Menu::Menu_settingBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 999 && oldp.x <= 1134 && oldp.y >= 573 && oldp.y <= 714)))
		if (newp.x >= 999 && newp.x <= 1134 && newp.y >= 573 && newp.y <= 714)
		{
			UserInterface::DrawSettingButton(85, 23, 1, GREEN);
			Sound::PlaySFX(SELECTING);
		}
	if ((oldp.x >= 999 && oldp.x <= 1134 && oldp.y >= 573 && oldp.y <= 714))
		if (!(newp.x >= 999 && newp.x <= 1134 && newp.y >= 573 && newp.y <= 714))
			UserInterface::DrawSettingButton(85, 23, 0, GREEN);
}

void Menu::Menu_quitBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 1278 && oldp.x <= 1413 && oldp.y >= 573 && oldp.y <= 714)))
		if (newp.x >= 1278 && newp.x <= 1413 && newp.y >= 573 && newp.y <= 714)
		{
			UserInterface::DrawExitButton(110, 23, 1, GREEN);
			Sound::PlaySFX(SELECTING);
		}
	if ((oldp.x >= 1278 && oldp.x <= 1413 && oldp.y >= 573 && oldp.y <= 714))
		if (!(newp.x >= 1278 && newp.x <= 1413 && newp.y >= 573 && newp.y <= 714))
			UserInterface::DrawExitButton(110, 23, 0, GREEN);
}

void Menu::Menu_QyesBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 550 && oldp.x <= 715 && oldp.y >= 500 && oldp.y <= 585)))
		if (newp.x >= 550 && newp.x <= 715 && newp.y >= 500 && newp.y <= 585)
		{
			UserInterface::DrawExitYesButton(45, 20, 1, WHITE);
			Sound::PlaySFX(SELECTING);
		}
	if ((oldp.x >= 550 && oldp.x <= 715 && oldp.y >= 500 && oldp.y <= 585))
		if (!(newp.x >= 550 && newp.x <= 715 && newp.y >= 500 && newp.y <= 585))
			UserInterface::DrawExitYesButton(45, 20, 0, WHITE);
}

void Menu::Menu_QnoBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 885 && oldp.x <= 1050 && oldp.y >= 500 && oldp.y <= 585)))
		if (newp.x >= 885 && newp.x <= 1050 && newp.y >= 500 && newp.y <= 585)
			if (newp.x >= 885 && newp.x <= 1050 && newp.y >= 500 && newp.y <= 585)
			{
				UserInterface::DrawExitNoButton(75, 20, 1, WHITE);
				Sound::PlaySFX(SELECTING);
			}
	if ((oldp.x >= 885 && oldp.x <= 1050 && oldp.y >= 500 && oldp.y <= 585))
		if (!(newp.x >= 885 && newp.x <= 1050 && newp.y >= 500 && newp.y <= 585))
			UserInterface::DrawExitNoButton(75, 20, 0, WHITE);
}

void Menu::Menu_askQuit()
{
	UserInterface::DrawAfterExitButton(WHITE);
	POINT oldp = Basic::getMousePos();
	bool in = true;
	while (in)
	{
		POINT newp = Basic::getMousePos();
		if (oldp.x != newp.x || oldp.y != newp.y)
		{
			Menu_askQuitProccess(oldp, newp);
			
			oldp = newp;
		}
		if (Basic::getKeyInput() == 8)
		{
			switch (Menu_askQuitInterac(newp))
			{
			case 1:
			{
				Sound::PlaySFX(END);
				run = false;
				in = false;
				Basic::gotoXY(1, 1);
				for (int i = 0; i < 1000; i++)
				{
					cout << "    ";
					Sleep(1);
				}
				system("cls");
				break;
			}
			case 0:
			{
				in = false;
				break;
			}
			default: break;
			}
		}
	}
}

void Menu::Menu_askQuitProccess(POINT oldp, POINT newp)
{
	Menu_QyesBox(oldp, newp);
	Menu_QnoBox(oldp, newp);
}

int Menu::Menu_askQuitInterac(POINT newp)
{
	if (newp.x >= 550 && newp.x <= 715 && newp.y >= 500 && newp.y <= 585)
		return 1;
	if (newp.x >= 885 && newp.x <= 1050 && newp.y >= 500 && newp.y <= 585)
		return 0;
	return -1;
}

void Menu::Menu_process(POINT oldp, POINT newp)
{
	Menu_startGamebox(oldp, newp);
	Menu_loadGamebox(oldp, newp);
	Menu_settingBox(oldp, newp);
	Menu_creditBox(oldp, newp);
	Menu_quitBox(oldp, newp);
}

void Menu::Menu_startGame()
{
	Basic::Console_SetColor(WHITE, WHITE);
	UserInterface::Drawbox(10, 2, 115, 25);
	menu_status = MENU_STARTGAME;
	UserInterface::DrawChoosePlayer();
	UserInterface::DrawStartGame_StartButton(100,20,0,WHITE);
	UserInterface::DrawStartGame_BackButton(20,20,0,WHITE);
	UserInterface::Write("SPEED", 50, 20, BLACK, WHITE);
	UserInterface::Write("JUMP", 50, 22, BLACK, WHITE);
	UserInterface::Write("DELAY", 50, 24, BLACK, WHITE);
	POINT oldp = Basic::getMousePos();
	bool in = true;
	while (in)
	{
		POINT newp = Basic::getMousePos();
		if (oldp.x != newp.x || oldp.y != newp.y)
		{
			startgame_process(oldp, newp);
		}
		if (Basic::getKeyInput() == 8)
		{
			switch (startgame_interac(newp))
			{
			case 1:
			{
				Menu_drawChooseBox(pType, 0);
				is_chosen = true;
				pType = PENGUIN;
				pSpeed = 3;
				pJump = 1;
				pDelay = 100;
				UserInterface::Write_Info(pSpeed, 67, 20, WHITE);
				UserInterface::Write_Info(pJump, 67, 22, WHITE);
				UserInterface::Write_Info(pDelay, 67, 24, WHITE);
				break;
			}
			case 2:
			{
				Menu_drawChooseBox(pType, 0);
				is_chosen = true;
				pType = CHICK;
				pSpeed = 2;
				pJump = 1;
				pDelay = 20;
				UserInterface::Write_Info(pSpeed, 67, 20, WHITE);
				UserInterface::Write_Info(pJump, 67, 22, WHITE);
				UserInterface::Write_Info(pDelay, 67, 24, WHITE);
				break;
			}
			case 3:
			{
				Menu_drawChooseBox(pType, 0);
				is_chosen = true;
				pType = PEROT;
				pSpeed = 5;
				pJump = 2;
				pDelay = 200;
				UserInterface::Write_Info(pSpeed, 67, 20, WHITE);
				UserInterface::Write_Info(pJump, 67, 22, WHITE);
				UserInterface::Write_Info(pDelay, 67, 24, WHITE);
				break;
			}
			case 4:
			{
				Menu_drawChooseBox(pType, 0);
				is_chosen = true;
				pType = BUG;
				pSpeed = 3;
				pJump = 1;
				pDelay = 50;
				UserInterface::Write_Info(pSpeed, 67, 20, WHITE);
				UserInterface::Write_Info(pJump, 67, 22, WHITE);
				UserInterface::Write_Info(pDelay, 67, 24, WHITE);
				break;
			}
			case 5:
			{
				menu_status = MENU_CUSTOMING;
				switch (Menu_custom())
				{
				case 6:
				{
					menu_status = MENU_PLAYING_GAME;
					Gameplay gameplay;
					gameplay.setup_start();
					gameplay.set_character(pType, pSpeed, pJump, pDelay);
					gameplay.start_game();
					
					if (gameplay.get_currentRound() <= TOTAL_ROUND)
					{
						string savename = Menu_getSaveName(gameplay.getPlayer_type(), gameplay.get_currentRound());
						gameplay.Gameplay_save(savename);
						add_saveName(savename);
						Menu_saveUpdate();
					}
					in = false;
					break;
				}
				case 7:
				{
					in = false;
					break;
				}
				}
				break;
			}
			case 6:
			{
				if (pType != -1)
				{
					menu_status = MENU_PLAYING_GAME;
					Gameplay gameplay;
					gameplay.setup_start();
					gameplay.set_character(pType, pSpeed, pJump, pDelay);
					gameplay.start_game();
					if (gameplay.get_currentRound() <= TOTAL_ROUND)
					{
						string savename = Menu_getSaveName(gameplay.getPlayer_type(), gameplay.get_currentRound());
						gameplay.Gameplay_save(savename);
						add_saveName(savename);
						Menu_saveUpdate();
					}
					in = false;
				}
				break;
			}
			case 7:
			{
				menu_status = MENU_RUNNING;
				in = false;
				break;
			}
			}
		}
		oldp = newp;
	}
}

void Menu::Menu_loadGame()
{
	Menu_loadScreen();
	POINT oldp = Basic::getMousePos();
	bool in = true;
	while (in)
	{
		POINT newp = Basic::getMousePos();
		if (oldp.x != newp.x || oldp.y != newp.y)
		{
			Menu_loadProcess(oldp, newp);
			oldp = newp;
		}
		if (Basic::getKeyInput() == 8)
		{
			switch (Menu_loadInterac(newp))
			{
				case 0:
				{
					in = false; break;
				}
				case 1:
				{
					if (saveList.size() > 0)
					{
						menu_status = MENU_PLAYING_GAME;
						Gameplay gameplay;
						gameplay.setup_start();
						gameplay.Gameplay_load(saveList[0]);
						gameplay.start_game();
						if (gameplay.get_currentRound() <= TOTAL_ROUND)
						{
							string savename = Menu_getSaveName(gameplay.getPlayer_type(), gameplay.get_currentRound());
							gameplay.Gameplay_save(savename);
							add_saveName(savename);
							Menu_saveUpdate();
						}
						in = false;
						break;
					}
				}
				case 2:
				{
					if (saveList.size() > 1)
					{
						menu_status = MENU_PLAYING_GAME;
						Gameplay gameplay;
						gameplay.setup_start();
						gameplay.Gameplay_load(saveList[1]);
						gameplay.start_game();
						if (gameplay.get_currentRound() <= TOTAL_ROUND)
						{
							string savename = Menu_getSaveName(gameplay.getPlayer_type(), gameplay.get_currentRound());
							gameplay.Gameplay_save(savename);
							add_saveName(savename);
							Menu_saveUpdate();
						}
						in = false;
						break;
					}
				}
				case 3:
				{
					if (saveList.size() > 2)
					{
						menu_status = MENU_PLAYING_GAME;
						Gameplay gameplay;
						gameplay.setup_start();
						gameplay.Gameplay_load(saveList[2]);
						gameplay.start_game();
						if (gameplay.get_currentRound() <= TOTAL_ROUND)
						{
							string savename = Menu_getSaveName(gameplay.getPlayer_type(), gameplay.get_currentRound());
							gameplay.Gameplay_save(savename);
							add_saveName(savename);
							Menu_saveUpdate();
						}
						in = false;
						break;
					}
				}
				case 4:
				{
					if (saveList.size() > 3)
					{
						menu_status = MENU_PLAYING_GAME;
						Gameplay gameplay;
						gameplay.setup_start();
						gameplay.Gameplay_load(saveList[3]);
						gameplay.start_game();
						if (gameplay.get_currentRound() <= TOTAL_ROUND)
						{
							string savename = Menu_getSaveName(gameplay.getPlayer_type(), gameplay.get_currentRound());
							gameplay.Gameplay_save(savename);
							add_saveName(savename);
							Menu_saveUpdate();
						}
						in = false;
						break;
					}
				}
			}
		}

	}
}

void Menu::Menu_loadScreen()
{
	Basic::Console_SetColor(WHITE, WHITE);
	UserInterface::Drawbox(10, 2, 115, 25);
	UserInterface::Drawbox(25, 5,  85, 3, BLACK, WHITE);
	UserInterface::Drawbox(25, 10, 85, 3, BLACK, WHITE);
	UserInterface::Drawbox(25, 15, 85, 3, BLACK, WHITE);
	UserInterface::Drawbox(25, 20, 85, 3, BLACK, WHITE);
	if (saveList.size() > 0)
	{
		Basic::gotoXY(47, 6);
		Basic::Console_SetColor(WHITE, RED);
		cout << saveList[0];
	}
	if (saveList.size() > 1)
	{
		Basic::gotoXY(47, 11);
		Basic::Console_SetColor(WHITE, GREEN);
		cout << saveList[1];
	}
	if (saveList.size() > 2)
	{
		Basic::gotoXY(47, 16);
		Basic::Console_SetColor(WHITE, BLUE);
		cout << saveList[2];
	}
	if (saveList.size() > 3)
	{
		Basic::gotoXY(47, 21);
		Basic::Console_SetColor(WHITE, YELLOW);
		cout << saveList[3];
	}
	UserInterface::DrawLoadBackButton(0);
	
	
}

void Menu::Menu_loadProcess(POINT oldp, POINT newp)
{
	Menu_saveSlot_1(oldp, newp);
	Menu_saveSlot_2(oldp, newp);
	Menu_saveSlot_3(oldp, newp);
	Menu_saveSlot_4(oldp, newp);
	Menu_loadGoback(oldp, newp);
}

void Menu::Menu_saveSlot_1(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 338 && oldp.x <= 1295 && oldp.y >= 145 && oldp.y <= 215)))
		if (newp.x >= 338 && newp.x <= 1295 && newp.y >= 145 && newp.y <= 215)
		{
			UserInterface::Drawbox(25, 5, 85, 3, BLACK, RED);
			if (saveList.size() > 0)
			{
				Basic::gotoXY(47, 6);
				Basic::Console_SetColor(RED, WHITE);
				cout << saveList[0];
			}
		}


	if ((oldp.x >= 338 && oldp.x <= 1295 && oldp.y >= 145 && oldp.y <= 215))
		if (!(newp.x >= 338 && newp.x <= 1295 && newp.y >= 145 && newp.y <= 215))
		{
			UserInterface::Drawbox(25, 5, 85, 3, BLACK, WHITE);
			if (saveList.size() > 0)
			{
				Basic::gotoXY(47, 6);
				Basic::Console_SetColor(WHITE, RED);
				cout << saveList[0];
			}
		}
}

void Menu::Menu_saveSlot_2(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 338 && oldp.x <= 1295 && oldp.y >= 265 && oldp.y <= 337)))
		if (newp.x >= 338 && newp.x <= 1295 && newp.y >= 265 && newp.y <= 337)
		{
			UserInterface::Drawbox(25, 10, 85, 3, BLACK, GREEN);
			if (saveList.size() > 1)
			{
				Basic::gotoXY(47, 11);
				Basic::Console_SetColor(GREEN, WHITE);
				cout << saveList[1];
			}
		}


	if ((oldp.x >= 338 && oldp.x <= 1295 && oldp.y >= 265 && oldp.y <= 337))
		if (!(newp.x >= 338 && newp.x <= 1295 && newp.y >= 265 && newp.y <= 337))
		{
			UserInterface::Drawbox(25, 10, 85, 3, BLACK, WHITE);
			if (saveList.size() > 1)
			{
				Basic::gotoXY(47, 11);
				Basic::Console_SetColor(WHITE, GREEN);
				cout << saveList[1];
			}
		}
}

void Menu::Menu_saveSlot_3(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 338 && oldp.x <= 1295 && oldp.y >= 385 && oldp.y <= 457)))
		if (newp.x >= 338 && newp.x <= 1295 && newp.y >= 385 && newp.y <= 457)
		{
			UserInterface::Drawbox(25, 15, 85, 3, BLACK, BLUE);
			if (saveList.size() > 2)
			{
				Basic::gotoXY(47, 16);
				Basic::Console_SetColor(BLUE, WHITE);
				cout << saveList[2];
			}
		}


	if ((oldp.x >= 338 && oldp.x <= 1295 && oldp.y >= 385 && oldp.y <= 457))
		if (!(newp.x >= 338 && newp.x <= 1295 && newp.y >= 385 && newp.y <= 457))
		{
			UserInterface::Drawbox(25, 15, 85, 3, BLACK, WHITE);
			if (saveList.size() > 2)
			{
				Basic::gotoXY(47, 16);
				Basic::Console_SetColor(WHITE, BLUE);
				cout << saveList[2];
			}
		}
}

void Menu::Menu_saveSlot_4(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 338 && oldp.x <= 1295 && oldp.y >= 505 && oldp.y <= 577)))
		if (newp.x >= 338 && newp.x <= 1295 && newp.y >= 505 && newp.y <= 577)
		{
			UserInterface::Drawbox(25, 20, 85, 3, BLACK, YELLOW);
			if (saveList.size() > 3)
			{
				Basic::gotoXY(47, 21);
				Basic::Console_SetColor(YELLOW, WHITE);
				cout << saveList[3];
			}
		}


	if ((oldp.x >= 338 && oldp.x <= 1295 && oldp.y >= 505 && oldp.y <= 577))
		if (!(newp.x >= 338 && newp.x <= 1295 && newp.y >= 505 && newp.y <= 577))
		{
			UserInterface::Drawbox(25, 20, 85, 3, BLACK, WHITE);
			if (saveList.size() > 3)
			{
				Basic::gotoXY(47, 21);
				Basic::Console_SetColor(WHITE, YELLOW);
				cout << saveList[3];
			}
		}
}

void Menu::Menu_loadGoback(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 193 && oldp.x <= 303 && oldp.y >= 577 && oldp.y <= 649)))
		if (newp.x >= 193 && newp.x <= 303 && newp.y >= 577 && newp.y <= 649)
			UserInterface::DrawLoadBackButton(1);


	if ((oldp.x >= 193 && oldp.x <= 303 && oldp.y >= 577 && oldp.y <= 649))
		if (!(newp.x >= 193 && newp.x <= 303 && newp.y >= 577 && newp.y <= 649))
			UserInterface::DrawLoadBackButton(0);
}

int Menu::Menu_loadInterac(POINT newp)
{
	if (newp.x >= 338 && newp.x <= 1295 && newp.y >= 145 && newp.y <= 215)
		return 1;	// slot 1
	if (newp.x >= 338 && newp.x <= 1295 && newp.y >= 265 && newp.y <= 337)
		return 2;	//slot 2
	if (newp.x >= 338 && newp.x <= 1295 && newp.y >= 385 && newp.y <= 457)
		return 3;	//slot 3
	if (newp.x >= 338 && newp.x <= 1295 && newp.y >= 505 && newp.y <= 577)
		return 4;	//slot 4
	if (newp.x >= 193 && newp.x <= 303 && newp.y >= 577 && newp.y <= 649)
		return 0;	//go back
	return -1;

}

void Menu::Menu_Quit()
{
	Menu_askQuit();
}

void Menu::Menu_Setting()
{
	Basic::Console_SetColor(WHITE, WHITE);
	UserInterface::Drawbox(10, 2, 115, 25);
	UserInterface::DrawStartGame_BackButton(20, 20, 0, WHITE);
	UserInterface::DrawBGMButton(0);
	UserInterface::DrawSFXButton(0);
	Menu_BGMstat();
	Menu_SFXstat();
	POINT oldp = Basic::getMousePos();
	bool in = true;
	while (in)
	{
		POINT newp = Basic::getMousePos();
		if (oldp.x != newp.x || oldp.y != newp.y)
		{
			setting_process(oldp, newp);
		}
		if (Basic::getKeyInput() == 8)
		{
			switch (setting_interac(newp))
			{
				case 0:
				{
					in = false; break;
				}
				case 1:
				{
					Sound::backgroundSound = !Sound::backgroundSound;
					Menu_BGMstat();
					Sound::TurnBackgroundSound();
					break;
				}
				case 2:
				{
					Sound::sfx = !Sound::sfx;
					Menu_SFXstat();
					break;
				}
				default: break;
			}
		}
		oldp = newp;
	}
}

void Menu::Menu_Credit()
{
	bool flag = false;
	if (Sound::backgroundSound)
	{
		flag = true;
		Sound::backgroundSound = 0;
		Sound::TurnBackgroundSound();
		Sound::creditSound = 1;
		Sound::TurnCreditSound();
	}
	About_page1();
	int currentPage = 1;
	
	POINT oldp = Basic::getMousePos();
	bool in = true;
	while (in)
	{
		POINT newp = Basic::getMousePos();
		if (oldp.x != newp.x || oldp.y != newp.y)
		{
			Credit_process(oldp, newp,currentPage);
		}
		if (Basic::getKeyInput() == 8)
		{
			switch (Credit_interac(newp,currentPage))
			{
				case 0 :
				{
					in = 0; break;
				}
				case 1:
				{
					currentPage = 1;
					About_page1();
					break;
				}
				case 2:
				{
					currentPage = 2;
					About_page2();
					break;
				}
			}
		}
		oldp = newp;
	}
	Sound::creditSound = 0;
	Sound::TurnCreditSound();
	if (flag)
	{
		Sound::backgroundSound = 1;
		Sound::TurnBackgroundSound();
	}
}

void Menu::Menu_screen()
{
	Basic::Console_Setup();
	Sound::TurnBackgroundSound();
	POINT oldp = Basic::getMousePos();
	while (run)
	{
		Basic::Console_SetColor(LIGHTBLUE, LIGHTBLUE);
		Basic::Console_ClearScreen();
		UserInterface::DrawMenuGame();
		while (!pause)
		{
			POINT newp = Basic::getMousePos();
			if (oldp.x != newp.x || oldp.y != newp.y)
			{
				Menu_process(oldp, newp);
				oldp = newp;
			}
			if (Basic::getKeyInput() == 8)
				Menu_Interac(newp);
		}
		if (pause)
		{
			pause = false;
			continue;
		}
	}
}

void Menu::startgame_PenguinBox(POINT oldp, POINT newp)
{
	if (!(is_chosen && pType == PENGUIN))
	{
		int tempW = WHITE, tempB = BLACK;
		if (!((oldp.x >= 269 && oldp.x <= 437 && oldp.y >= 140 && oldp.y <= 309)))
			if (newp.x >= 269 && newp.x <= 437 && newp.y >= 140 && newp.y <= 309)
			{
				Sound::PlaySFX(SELECTING);
				UserInterface::DrawChooseBox(20, 5, 1, tempW, tempB);
				UserInterface::DrawPenguin(24, 7, 1, WHITE);
			}

		if ((oldp.x >= 269 && oldp.x <= 437 && oldp.y >= 140 && oldp.y <= 309))
			if (!(newp.x >= 269 && newp.x <= 437 && newp.y >= 140 && newp.y <= 309))
			{
				UserInterface::DrawChooseBox(20, 5, 0, tempW, tempB);
				UserInterface::DrawPenguin(24, 7, 1, WHITE);

			}
	}
}

void Menu::startgame_ChickBox(POINT oldp, POINT newp)
{
	if (!(is_chosen && pType == CHICK))
	{
		int tempW = WHITE, tempB = BLACK;
		if (!((oldp.x >= 494 && oldp.x <= 662 && oldp.y >= 140 && oldp.y <= 309)))
			if (newp.x >= 494 && newp.x <= 662 && newp.y >= 140 && newp.y <= 309)
			{
				Sound::PlaySFX(SELECTING);
				UserInterface::DrawChooseBox(40, 5, 1, tempW, tempB);
				UserInterface::DrawChicken(44, 7, 1, tempW);

			}


		if ((oldp.x >= 494 && oldp.x <= 662 && oldp.y >= 140 && oldp.y <= 309))
			if (!(newp.x >= 494 && newp.x <= 662 && newp.y >= 140 && newp.y <= 309))
			{
				UserInterface::DrawChooseBox(40, 5, 0, tempW, tempB);
				UserInterface::DrawChicken(44, 7, 1, tempW);
			}
	}

}

void Menu::startgame_ParrotBox(POINT oldp, POINT newp)
{
	if (!(is_chosen && pType == PEROT))
	{
		int tempW = WHITE, tempB = BLACK;
		if (!((oldp.x >= 718 && oldp.x <= 886 && oldp.y >= 140 && oldp.y <= 309)))
			if (newp.x >= 718 && newp.x <= 886 && newp.y >= 140 && newp.y <= 309)
			{
				Sound::PlaySFX(SELECTING);
				UserInterface::DrawChooseBox(60, 5, 1, tempW, tempB);
				UserInterface::DrawParrot(64, 7, 1, WHITE);
			}

		if ((oldp.x >= 718 && oldp.x <= 886 && oldp.y >= 140 && oldp.y <= 309))
			if (!(newp.x >= 718 && newp.x <= 886 && newp.y >= 140 && newp.y <= 309))
			{
				UserInterface::DrawChooseBox(60, 5, 0, tempW, tempB);
				UserInterface::DrawParrot(64, 7, 1, WHITE);
			}
	}

}

void Menu::startgame_BuggymanBox(POINT oldp, POINT newp)
{
	if (!(is_chosen && pType == BUG))
	{
		int tempW = WHITE, tempB = BLACK;
		if (!((oldp.x >= 942 && oldp.x <= 1110 && oldp.y >= 140 && oldp.y <= 309)))
			if (newp.x >= 942 && newp.x <= 1110 && newp.y >= 140 && newp.y <= 309)
			{
				Sound::PlaySFX(SELECTING);
				UserInterface::DrawChooseBox(80, 5, 1, tempW, tempB);
				UserInterface::DrawQuestionMark(84, 6, 1, WHITE);

			}

		if ((oldp.x >= 942 && oldp.x <= 1110 && oldp.y >= 140 && oldp.y <= 309))
			if (!(newp.x >= 942 && newp.x <= 1110 && newp.y >= 140 && newp.y <= 309))
			{
				UserInterface::DrawChooseBox(80, 5, 0, tempW, tempB);
				UserInterface::DrawQuestionMark(84, 6, 1, WHITE);

			}
	}
	
}

void Menu::startgame_CustomBox(POINT oldp, POINT newp)
{
	int tempW = WHITE, tempB = BLACK;
	if (!((oldp.x >= 1166 && oldp.x <= 1334 && oldp.y >= 140 && oldp.y <= 309)))
		if (newp.x >= 1166 && newp.x <= 1334 && newp.y >= 140 && newp.y <= 309)
		{
			Sound::PlaySFX(SELECTING);
			UserInterface::DrawChooseBox(100, 5, 1, tempW, tempB);
			UserInterface::DrawCustom(103, 7, 0, WHITE);

		}

	if ((oldp.x >= 1166 && oldp.x <= 1334 && oldp.y >= 140 && oldp.y <= 309))
		if (!(newp.x >= 1166 && newp.x <= 1334 && newp.y >= 140 && newp.y <= 309))
		{
			UserInterface::DrawChooseBox(100, 5, 0, tempW, tempB);
			UserInterface::DrawCustom(103, 7, 0, WHITE);

		}
}

void Menu::startgame_startButtonBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 1166 && oldp.x <= 1334 && oldp.y >= 501 && oldp.y <= 610)))
		if (newp.x >= 1166 && newp.x <= 1334 && newp.y >= 501 && newp.y <= 610)
		{
			Sound::PlaySFX(SELECTING);
			UserInterface::DrawStartGame_StartButton(100, 20, 1, WHITE);
		}


	if ((oldp.x >= 1166 && oldp.x <= 1334 && oldp.y >= 501 && oldp.y <= 610))
		if (!(newp.x >= 1166 && newp.x <= 1334 && newp.y >= 501 && newp.y <= 610))
			UserInterface::DrawStartGame_StartButton(100, 20, 0, WHITE);

}

void Menu::startgame_backButtonBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 270 && oldp.x <= 438 && oldp.y >= 501 && oldp.y <= 610)))
		if (newp.x >= 270 && newp.x <= 438 && newp.y >= 501 && newp.y <= 610)
		{
			Sound::PlaySFX(SELECTING);
			UserInterface::DrawStartGame_BackButton(20, 20, 1, WHITE);
		}

	if ((oldp.x >= 270 && oldp.x <= 438 && oldp.y >= 501 && oldp.y <= 610))
		if (!(newp.x >= 270 && newp.x <= 438 && newp.y >= 501 && newp.y <= 610))
			UserInterface::DrawStartGame_BackButton(20, 20, 0, WHITE);
}

void Menu::startgame_process(POINT oldp, POINT newp)
{
	startgame_PenguinBox(oldp, newp);
	startgame_ChickBox(oldp, newp);
	startgame_ParrotBox(oldp, newp);
	startgame_BuggymanBox(oldp, newp);
	startgame_CustomBox(oldp, newp);
	startgame_startButtonBox(oldp, newp);
	startgame_backButtonBox(oldp, newp);
}

int Menu::startgame_interac(POINT newp)
{
	if (newp.x >= 269 && newp.x <= 437 && newp.y >= 140 && newp.y <= 309)
		return 1;
	if (newp.x >= 494 && newp.x <= 662 && newp.y >= 140 && newp.y <= 309)
		return 2;	//Chicken
	if (newp.x >= 718 && newp.x <= 886 && newp.y >= 140 && newp.y <= 309)
		return 3;	//Parrot
	if (newp.x >= 942 && newp.x <= 1110 && newp.y >= 140 && newp.y <= 309)
		return 4;	//Bug
	if (newp.x >= 1166 && newp.x <= 1334 && newp.y >= 140 && newp.y <= 309)
		return 5;	//Custom
	if (newp.x >= 1166 && newp.x <= 1334 && newp.y >= 501 && newp.y <= 610)
		return 6;	//Start game
	if (newp.x >= 270 && newp.x <= 438 && newp.y >= 501 && newp.y <= 610)
		return 7;	//Go back
	return -1;

}

void Menu::custom_addSpeedBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 718 && oldp.x <= 750 && oldp.y >= 490 && oldp.y <= 525)))
		if (newp.x >= 718 && newp.x <= 750 && newp.y >= 490 && newp.y <= 525)
			if (newp.x >= 718 && newp.x <= 750 && newp.y >= 490 && newp.y <= 525)
			{
				Sound::PlaySFX(SELECTING);
				UserInterface::DrawAdditionMark(60, 19, 1, WHITE);
			}
	if ((oldp.x >= 718 && oldp.x <= 750 && oldp.y >= 490 && oldp.y <= 525))
		if (!(newp.x >= 718 && newp.x <= 750 && newp.y >= 490 && newp.y <= 525))
			UserInterface::DrawAdditionMark(60, 19, 0, WHITE);

}

void Menu::custom_subSpeedBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 942 && oldp.x <= 986 && oldp.y >= 499 && oldp.y <= 515)))
		if (newp.x >= 942 && newp.x <= 986 && newp.y >= 499 && newp.y <= 515)
		{
			Sound::PlaySFX(SELECTING);
			UserInterface::DrawSubtractionMark(80, 19, 1, WHITE);
		}
	if ((oldp.x >= 942 && oldp.x <= 986 && oldp.y >= 499 && oldp.y <= 515))
		if (!(newp.x >= 942 && newp.x <= 986 && newp.y >= 499 && newp.y <= 515))
			UserInterface::DrawSubtractionMark(80, 19, 0, WHITE);
}

void Menu::custom_addJumpBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 718 && oldp.x <= 750 && oldp.y >= 538 && oldp.y <= 573)))
		if (newp.x >= 718 && newp.x <= 750 && newp.y >= 538 && newp.y <= 573)
		{
			Sound::PlaySFX(SELECTING);
			UserInterface::DrawAdditionMark(60, 21, 1, WHITE);
		}

	if ((oldp.x >= 718 && oldp.x <= 750 && oldp.y >= 538 && oldp.y <= 573))
		if (!(newp.x >= 718 && newp.x <= 750 && newp.y >= 538 && newp.y <= 573))
			UserInterface::DrawAdditionMark(60, 21, 0, WHITE);
}

void Menu::custom_subJumpBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 942 && oldp.x <= 986 && oldp.y >= 547 && oldp.y <= 564)))
		if (newp.x >= 942 && newp.x <= 986 && newp.y >= 547 && newp.y <= 564)
			if (newp.x >= 942 && newp.x <= 986 && newp.y >= 547 && newp.y <= 564)
			{
				Sound::PlaySFX(SELECTING);
				UserInterface::DrawSubtractionMark(80, 21, 1, WHITE);
			}
	if ((oldp.x >= 942 && oldp.x <= 986 && oldp.y >= 547 && oldp.y <= 564))
		if (!(newp.x >= 942 && newp.x <= 986 && newp.y >= 547 && newp.y <= 564))
			UserInterface::DrawSubtractionMark(80, 21, 0 , WHITE);
}

void Menu::custom_addDelayBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 718 && oldp.x <= 750 && oldp.y >= 586 && oldp.y <= 621)))
		if (newp.x >= 718 && newp.x <= 750 && newp.y >= 586 && newp.y <= 621)
		{
			Sound::PlaySFX(SELECTING);
			UserInterface::DrawAdditionMark(60, 23, 1, WHITE);
		}
	if ((oldp.x >= 718 && oldp.x <= 750 && oldp.y >= 586 && oldp.y <= 621))
		if (!(newp.x >= 718 && newp.x <= 750 && newp.y >= 586 && newp.y <= 621))
			UserInterface::DrawAdditionMark(60, 23, 0, WHITE);
}

void Menu::custom_subDelayBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 942 && oldp.x <= 986 && oldp.y >= 595 && oldp.y <= 611)))
		if (newp.x >= 942 && newp.x <= 986 && newp.y >= 595 && newp.y <= 611)
		{
			Sound::PlaySFX(SELECTING);
			UserInterface::DrawSubtractionMark(80, 23, 1, WHITE);
		}
	if ((oldp.x >= 942 && oldp.x <= 986 && oldp.y >= 595 && oldp.y <= 611))
		if (!(newp.x >= 942 && newp.x <= 986 && newp.y >= 595 && newp.y <= 611))
			UserInterface::DrawSubtractionMark(80, 23, 0, WHITE);
}

void Menu::custom_process(POINT oldp, POINT newp)
{
	startgame_PenguinBox(oldp, newp);
	startgame_ChickBox(oldp, newp);
	startgame_ParrotBox(oldp, newp);
	startgame_BuggymanBox(oldp, newp);
	startgame_backButtonBox(oldp, newp);
	startgame_startButtonBox(oldp, newp);
	custom_addSpeedBox(oldp, newp);
	custom_subSpeedBox(oldp, newp);
	custom_addJumpBox(oldp, newp);
	custom_subJumpBox(oldp, newp);
	custom_addDelayBox(oldp, newp);
	custom_subDelayBox(oldp, newp);
}

int Menu::custom_interac(POINT newp, int& speed, int& jump, int& delay)
{
	if (newp.x >= 269 && newp.x <= 437 && newp.y >= 140 && newp.y <= 309)
	{
		Menu_drawChooseBox(pType, 0);
		pType = PENGUIN;
		is_chosen = true;
	}
	else if (newp.x >= 494 && newp.x <= 662 && newp.y >= 140 && newp.y <= 309)
	{
		Menu_drawChooseBox(pType, 0);
		is_chosen = true;
		pType = CHICK;
	}
	else if (newp.x >= 718 && newp.x <= 886 && newp.y >= 140 && newp.y <= 309)
	{
		Menu_drawChooseBox(pType, 0);
		is_chosen = true;
		pType = PEROT;
	}	
	else if (newp.x >= 942 && newp.x <= 1110 && newp.y >= 140 && newp.y <= 309)
	{
		Menu_drawChooseBox(pType, 0);
		is_chosen = true;
		pType = BUG;
	}
	else if (newp.x >= 1166 && newp.x <= 1334 && newp.y >= 501 && newp.y <= 610)
	{
		if (is_chosen)
			return 6;	//Start game
	}
	else if (newp.x >= 270 && newp.x <= 438 && newp.y >= 501 && newp.y <= 610)
		return 7;	//Go back
	else if (newp.x >= 718 && newp.x <= 750 && newp.y >= 490 && newp.y <= 525)
	{
		Sound::PlaySFX(UPSTAT);
		speed + 1 > 100 ? speed = 100 : speed += 1;
		if (speed == 100)
			UserInterface::Write("YOU INSANE", 67, 20, RED, WHITE);
		else
			UserInterface::Write_Info(speed, 67, 20, WHITE);
	}
	else if (newp.x >= 942 && newp.x <= 986 && newp.y >= 499 && newp.y <= 515)
	{
		Sound::PlaySFX(DOWNSTAT);
		speed - 1 < 1 ? speed = 1 : speed -= 1;
		UserInterface::Write_Info(speed, 67, 20, WHITE);
	}
	else if (newp.x >= 718 && newp.x <= 750 && newp.y >= 538 && newp.y <= 573)
	{
		Sound::PlaySFX(UPSTAT);
		jump + 1 > 8 ? jump = 8 : jump += 1;
		if(jump == 8)
			UserInterface::Write("LIMIT BREAK", 67, 22, RED, WHITE);
		else
			UserInterface::Write_Info(jump, 67, 22, WHITE);
	}
	else if (newp.x >= 942 && newp.x <= 986 && newp.y >= 547 && newp.y <= 564)
	{
		Sound::PlaySFX(DOWNSTAT);
		jump - 1 < 1 ? jump = 1 : jump -= 1;
		UserInterface::Write_Info(jump, 67, 22, WHITE);
	}
	else if (newp.x >= 718 && newp.x <= 750 && newp.y >= 586 && newp.y <= 621)
	{
		Sound::PlaySFX(UPSTAT);
		delay + 10 > 1000 ? delay = 1000 : delay += 10;
		if(delay == 1000)
			UserInterface::Write("DRUNK", 67, 24, RED, WHITE);
		else
			UserInterface::Write_Info(delay, 67, 24, WHITE);
	}
	else if (newp.x >= 942 && newp.x <= 986 && newp.y >= 595 && newp.y <= 611)
	{
		Sound::PlaySFX(DOWNSTAT);
		delay - 10 < 0 ? delay = 0 : delay -= 10;
		if (delay == 0)
			UserInterface::Write("SONIC MODE", 67, 24, RED, WHITE);
		else
			UserInterface::Write_Info(delay, 67, 24, WHITE);
	}
}

int Menu::Menu_custom()
{
	is_chosen = false;
	pType = -1;
	UserInterface::DrawCustomButton(WHITE);
	UserInterface::DrawChoosePlayer();
	UserInterface::DrawStartGame_StartButton(100, 20, 0, WHITE);
	UserInterface::DrawStartGame_BackButton(20, 20, 0, WHITE);
	POINT oldp = Basic::getMousePos();
	bool in = true;
	while (in)
	{
		POINT newp = Basic::getMousePos();
		if (oldp.x != newp.x || oldp.y != newp.y)
		{
			custom_process(oldp, newp);
			
		}
		if (Basic::getKeyInput() == 8)
		{
			switch (custom_interac(newp, pSpeed, pJump, pDelay))
			{
				case 6:
				{
					return 6;
					break;
				}
				case 7:
				{
					return 7;
					in = false;
					break;
				}
					
			}
		}
		oldp = newp;
	}
	
}

void Menu::setting_bgmBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 619 && oldp.x <= 954 && oldp.y >= 145 && oldp.y <= 240)))
		if (newp.x >= 619 && newp.x <= 954 && newp.y >= 145 && newp.y <= 240)
		{
			UserInterface::DrawBGMButton(1);
			Sound::PlaySFX(SELECTING);
		}
	if ((oldp.x >= 619 && oldp.x <= 954 && oldp.y >= 145 && oldp.y <= 240))
		if (!(newp.x >= 619 && newp.x <= 954 && newp.y >= 145 && newp.y <= 240))
			UserInterface::DrawBGMButton(0);
}

void Menu::setting_sfxBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 619 && oldp.x <= 954 && oldp.y >= 385 && oldp.y <= 482)))
		if (newp.x >= 619 && newp.x <= 954 && newp.y >= 385 && newp.y <= 482)
		{
			UserInterface::DrawSFXButton(1);
			Sound::PlaySFX(SELECTING);
		}
	if ((oldp.x >= 619 && oldp.x <= 954 && oldp.y >= 385 && oldp.y <= 482))
		if (!(newp.x >= 619 && newp.x <= 954 && newp.y >= 385 && newp.y <= 482))
			UserInterface::DrawSFXButton(0);
}

void Menu::setting_backBox(POINT oldp, POINT newp)
{
	startgame_backButtonBox(oldp, newp);
}

void Menu::setting_process(POINT oldp, POINT newp)
{
	setting_bgmBox(oldp, newp);
	setting_sfxBox(oldp, newp);
	setting_backBox(oldp, newp);
}

int Menu::setting_interac(POINT newp)
{
	if (newp.x >= 270 && newp.x <= 438 && newp.y >= 501 && newp.y <= 610)
		return 0;	//go back
	if (newp.x >= 619 && newp.x <= 954 && newp.y >= 145 && newp.y <= 240)
		return 1;	//BGM
	if (newp.x >= 619 && newp.x <= 954 && newp.y >= 385 && newp.y <= 482)
		return 2;	//SFX
	return -1;
}

void Menu::Menu_BGMstat()
{
	if(Sound::backgroundSound)
		UserInterface::Drawbox(85, 5, 10, 4, BLACK, GREEN);
	else
		UserInterface::Drawbox(85, 5, 10, 4, BLACK, RED);

}

void Menu::Menu_SFXstat()
{
	if(Sound::sfx)
		UserInterface::Drawbox(85, 15, 10, 4, BLACK, GREEN);
	else
		UserInterface::Drawbox(85, 15, 10, 4, BLACK, RED);

}

void Menu::About_page1()
{
	UserInterface::Drawbox(10, 2, 115, 25);
	UserInterface::Write("----------HOW TO PLAY----------", 48, 8, GREEN, WHITE);
	UserInterface::Write("+ YOUR OBJECTIVE IS TO GET TO THE TOP LANE WITHOUT GETTING CRASH OR FALLING INTO RIVER", 20, 10, GREEN, WHITE);
	UserInterface::Write("+ PRESS W,A,S,D TO MOVE UP, MOVE LEFT, MOVE DOWN, MOVE RIGHT", 20, 12, GREEN, WHITE);
	UserInterface::Write("+ EVERY TIME YOU PASS, YOU WILL BE MOVED TO THE NEXT ROUND, BEAT 15 ROUND TO WIN THE GAME", 20, 14, GREEN, WHITE);
	UserInterface::Write("+ CLICK ANYWHERE TO PAUSE, GAME ARE SAVED AUTOMATICALLY", 20, 16, GREEN, WHITE);
	UserInterface::DrawPenguin(15, 4, 1, WHITE);
	UserInterface::DrawParrot(115, 4, 1, WHITE);
	UserInterface::DrawDog(15, 18, 1, WHITE);
	UserInterface::DrawChicken(60, 18, 1, WHITE);
	UserInterface::DrawBee(113, 18, 1, WHITE);
	UserInterface::DrawCreditNextButton(0);
	UserInterface::DrawCreditBackButton(0);
}

void Menu::About_page2()
{
	UserInterface::Drawbox(10, 2, 115, 25);
	UserInterface::Write("----------ABOUT----------", 50, 6, RED, WHITE);
	UserInterface::Write("+ CREDIT: ", 30, 8, DARKGREEN, WHITE);
	UserInterface::Write("_ MAN PHAM (BUGGY MAN)", 35, 10, DARKGREEN, WHITE);
	UserInterface::Write("_ LE THANH MINH TRI", 35, 12, DARKGREEN, WHITE);
	UserInterface::Write("_ TRAN DUC THIEN", 35, 14, DARKGREEN, WHITE);
	UserInterface::Write("_ NGUYEN DINH KIN", 35, 16, DARKGREEN, WHITE);
	UserInterface::Write("+ COURSES: ", 75, 8, DARKBLUE, WHITE);
	UserInterface::Write("_ OBJECT ORIENTED PROGRAMMING", 80, 10, DARKBLUE, WHITE);
	UserInterface::Write("_ ADVISOR: TRUONG TOAN THINH", 80, 12, DARKBLUE, WHITE);
	UserInterface::Write("@ COPY RIGHT 2023 ALL RIGHT RESERVED", 45, 20, DARKPURPLE, WHITE);
	UserInterface::DrawRCar(15, 10, 1, WHITE);
	UserInterface::DrawBCar(15, 16, 1, WHITE);
	UserInterface::DrawTruck(15, 22, 1, WHITE);
	UserInterface::DrawReverseRCar(112, 10, 1, WHITE);
	UserInterface::DrawReverseBCar(112, 16, 1, WHITE);
	UserInterface::DrawReverseTruck(112, 22, 1, WHITE);
	UserInterface::Drawbox(70, 22, 10, 3, WHITE, WHITE);
	UserInterface::DrawCreditBackButton(0);

}

void Menu::Credit_backBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 563 && oldp.x <= 675 && oldp.y >= 578 && oldp.y <= 625)))
		if (newp.x >= 563 && newp.x <= 675 && newp.y >= 578 && newp.y <= 625)
		{
			UserInterface::DrawCreditBackButton(1);
			Sound::PlaySFX(SELECTING);
		}
	if ((oldp.x >= 563 && oldp.x <= 675 && oldp.y >= 578 && oldp.y <= 625))
		if (!(newp.x >= 563 && newp.x <= 675 && newp.y >= 578 && newp.y <= 625))
			UserInterface::DrawCreditBackButton(0);
}

void Menu::Credit_nextBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 841 && oldp.x <= 955 && oldp.y >= 578 && oldp.y <= 625)))
		if (newp.x >= 841 && newp.x <= 955 && newp.y >= 578 && newp.y <= 625)
		{
			UserInterface::DrawCreditNextButton(1);
			Sound::PlaySFX(SELECTING);
		}
	if ((oldp.x >= 841 && oldp.x <= 955 && oldp.y >= 578 && oldp.y <= 625))
		if (!(newp.x >= 841 && newp.x <= 955 && newp.y >= 578 && newp.y <= 625))
			UserInterface::DrawCreditNextButton(0);
}

void Menu::Credit_process(POINT oldp, POINT newp, int page)
{
	if (page == 1)
		Credit_nextBox(oldp, newp);
	Credit_backBox(oldp, newp);
}

int Menu::Credit_interac(POINT newp, int page)
{
	switch(page)
	{
		case 1:
		{
			if (newp.x >= 841 && newp.x <= 955 && newp.y >= 578 && newp.y <= 625)
				return 2;	//Go page 2
			if (newp.x >= 563 && newp.x <= 675 && newp.y >= 578 && newp.y <= 625)
				return 0;	//Go back
		}
		case 2:
		{
			if (newp.x >= 563 && newp.x <= 675 && newp.y >= 578 && newp.y <= 625)
				return 1;	//Go page 1
		}
	}
	return -1;

}

void Menu::Menu_drawChooseBox(int type, bool mode)
{
	Sound::PlaySFX(CLICK);
	int tempW = WHITE, tempB = BLACK;
	switch (type)
	{
		case PENGUIN:
		{
			UserInterface::DrawChooseBox(20, 5, mode, tempW, tempB);
			UserInterface::DrawPenguin(24, 7, 1, WHITE);
			break;
		}
		case CHICK:
		{
			UserInterface::DrawChooseBox(40, 5, mode, tempW, tempB);
			UserInterface::DrawChicken(44, 7, 1, tempW);
			break;
		}
		case PEROT:
		{
			UserInterface::DrawChooseBox(60, 5, mode, tempW, tempB);
			UserInterface::DrawParrot(64, 7, 1, WHITE);
			break;
		}
		case BUG:
		{
			UserInterface::DrawChooseBox(80, 5, mode, tempW, tempB);
			UserInterface::DrawQuestionMark(84, 6, 1, WHITE);
			break;
		}
		default: break;
	}
}


void Menu::Menu_Interac(POINT newp)
{
	if (newp.x >= 160 && newp.x <= 295 && newp.y >= 573 && newp.y <= 714)
	{
		pause = true;
		menu_status = MENU_STARTGAME;
		Sound::PlaySFX(CLICK);
		Menu_startGame();
	}
	else if (newp.x >= 438 && newp.x <= 573 && newp.y >= 573 && newp.y <= 714)
	{
		pause = true;
		Sound::PlaySFX(CLICK);
		Menu_loadGame();
	}
	else if (newp.x >= 999 && newp.x <= 1134 && newp.y >= 573 && newp.y <= 714)
	{
		pause = true;
		Sound::PlaySFX(CLICK);
		Menu_Setting();
	}
	else if (newp.x >= 719 && newp.x <= 854 && newp.y >= 573 && newp.y <= 714)
	{
		pause = true;
		Sound::PlaySFX(CLICK);
		Menu_Credit();
	}
	else if (newp.x >= 1278 && newp.x <= 1413 && newp.y >= 573 && newp.y <= 714)
	{
		pause = true;
		Sound::PlaySFX(CLICK);
		Menu_Quit();
	}
}

void Menu::Menu_saveSetup()
{
	ifstream inf;
	inf.open(DATAFILE, ios::in);
	if (inf.is_open())
	{
		inf >> saveList;
		inf.close();
	}
	else
		cout << "Cannot open file";
}

void Menu::Menu_saveUpdate()
{
	ofstream outf;
	outf.open(DATAFILE, ios::out);
	if (outf.is_open())
	{
		outf << saveList;
		outf.close();
	}
	else
		cout << "Cannot open file";
}

void Menu::add_saveName(const string& newName)
{
	if (saveList.size() >= 4)
		saveList.erase(saveList.begin());
	saveList.push_back(newName);
}

string Menu::Menu_getSaveName(int type, int round)
{
	string str;
	switch (type)
	{
	case PENGUIN:
	{
		str += "Penguin\t"; break;
	}
	case CHICK:
	{
		str += "Chicken\t"; break;
	}
	case PEROT:
	{
		str += "Parrot\t"; break;
	}
	case BUG:
	{
		str += "Buggy\t"; break;
	}
	}
	str += "Round ";
	str += to_string(round);
	str += "\t";
	str += Basic::get_dateTime();
	str.erase(str.find('\n'));
	string ret;
	for (int i = 0; i < str.length(); i += 1)
	{
		ret.push_back(toupper(str[i]));
	}
	return ret;
}