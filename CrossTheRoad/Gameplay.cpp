#include "Gameplay.h"
mutex game_mtx;
condition_variable game_cv;
void Gameplay::setup_start()
{
	finish = false;
	pause = false;
	run = true;
	round_finish = false;
	round_status = ROUND_RUNNING;
	currentRound = 1;
	infoPos = Point2D(5, 29);
	roundList.push_back(&Gameplay::setup_round0);
	roundList.push_back(&Gameplay::setup_round1);
	roundList.push_back(&Gameplay::setup_round2);
	roundList.push_back(&Gameplay::setup_round3);
	roundList.push_back(&Gameplay::setup_round4);
	roundList.push_back(&Gameplay::setup_round5);
	roundList.push_back(&Gameplay::setup_round6);
	roundList.push_back(&Gameplay::setup_round7);
	roundList.push_back(&Gameplay::setup_round8);
	roundList.push_back(&Gameplay::setup_round9);
	roundList.push_back(&Gameplay::setup_round10);
	roundList.push_back(&Gameplay::setup_round11);
	roundList.push_back(&Gameplay::setup_round12);
	roundList.push_back(&Gameplay::setup_round13);
	roundList.push_back(&Gameplay::setup_round14);
	roundList.push_back(&Gameplay::setup_round15);
}

void Gameplay::set_character(int newType, int newHspeed, int newVspeed, int newDelay)
{
	myPlayer = new Player(STARTING_POINT, newType, newHspeed, newVspeed, newDelay);
}

void Gameplay::start_game()
{
	Basic::Console_Setup();
	bool flag = false;
	if (Sound::backgroundSound)
	{
		flag = true;
		Sound::backgroundSound = 0;
		Sound::TurnBackgroundSound();
		Sound::gameSound = 1;
		Sound::TurnGameBackgroundSound();
	}
	while (run)
	{
		start_round(currentRound);
		if (round_finish)
		{
			switch (round_status)
			{
				case ROUND_WIN:
				{
					currentRound += 1;
					if (currentRound > TOTAL_ROUND)
					{
						Gameplay_endingCredit();
						run = false;
					}
					round_finish = false;
					round_status = ROUND_RUNNING;
					break;
				}
				case ROUND_RESTART:
				{
					round_finish = false;
					round_status = ROUND_RUNNING;
					break;
				}

				case ROUND_LOOSE:
				{
					Gameplay_deadEffect();
					Gameplay_askRestart();
					break;
				}

				case ROUND_RESTART_BEGIN:
				{
					round_finish = false;
					round_status = ROUND_RUNNING;
					currentRound = 1;
					break;
				}
			}
		}
	}
	Sound::gameSound = 0;
	Sound::TurnGameBackgroundSound();
	if (flag)
	{
		Sound::backgroundSound = 1;
		Sound::TurnBackgroundSound();
	}
}

void Gameplay::start_round(int currentRound)
{
	Sound::PlaySFX(LEVELUP);
	myPlayer->set_position(STARTING_POINT.getX(), STARTING_POINT.getY());
	(*this.*roundList[currentRound])();
	Gameplay_draw();
	Round_Info(infoPos);
	thread player_Thread(&Gameplay::start_player, this);
	thread lane_Thread(&Gameplay::start_lane, this);
	Basic::joinThread(&player_Thread);
	Basic::joinThread(&lane_Thread);

}

void Gameplay::game_proccess() //dthien
{	
	Lane*currentLane = laneList[myPlayer->get_position().getY()/4];
	switch (currentLane->get_type())
	{
		case HIGH_WAY:
		{
			for (auto& it : currentLane->get_mobsList())
				if (Process::player_isCrash(myPlayer, it))
				{
					round_finish = true;
					round_status = ROUND_LOOSE;
					break;
				}
			break;
		}
		case REV_HIGH_WAY:
		{
			for (auto& it : currentLane->get_mobsList())
				if (Process::player_isCrash(myPlayer, it))
				{
					pause = true;
					round_finish = true;
					round_status = ROUND_LOOSE;
					break;

				}
			break;
		}
		case GRASS:
		{
			
			if (currentLane->get_position() == first)
			{
				round_finish = true;
				round_status = ROUND_WIN;
			}
			else if (currentLane->get_position() == eigth)
			{
				if (myPlayer->get_position().getX() > infoPos.getX() && myPlayer->get_position().getX() < infoPos.getX() + 30)
				{
					currentLane->Draw();
					infoPos == INFO_POS_1 ? infoPos = INFO_POS_2 : infoPos = INFO_POS_1;
					Round_Info(infoPos);
					myPlayer->Draw(1,GREEN);
				}
			}
				
		}
		case RAIL_WAY:
		{
			break;
		}
		case WATER:
		{
			bool flag = false;
			for (auto& it : currentLane->get_mobsList())
				if (Process::player_isCrash(myPlayer, it))
				{
					flag = true; 
					break;
				}
			if (!flag)
			{
				round_finish = true;
				round_status = ROUND_LOOSE;
			}
			break;
		}

		default: break;
	}
}

void Gameplay::start_player() //dthien
{
	Sound::prepareSound();
	while (!round_finish)
	{
		if (!pause)
		{
			switch (Basic::getKeyInput())
			{
			case 1:
				myPlayer->move_up(laneList);
				Sound::PlaySFX(MOVE);
				break;
			case 2:
				myPlayer->move_left(laneList[myPlayer->get_position().getY() / 4]);
				Sound::PlaySFX(MOVE);
				break;
			case 3:
				myPlayer->move_down(laneList); 
				Sound::PlaySFX(MOVE);
				break;
			case 4:
				myPlayer->move_right(laneList[myPlayer->get_position().getY() / 4]); 
				Sound::PlaySFX(MOVE);
				break;
			case 8:
				Gameplay_pause();
			default: break;
			}
			game_proccess();
			Basic::sleepFor_milisec(myPlayer->get_delay());
		}
	}
}

void Gameplay::start_lane()
{
	while (!round_finish)
	{
		if (!pause)
		{
			vector<thread> threadList;
			for (auto& it : laneList)
			{
				threadList.push_back(thread(&Lane::run, &*(it)));
			}
			for (auto& it : threadList)
			{
				Basic::joinThread(&it);
			}
		}
		
	}
		
}

void Gameplay::Gameplay_draw()
{
	int current = myPlayer->get_position().getY() / 4;
	for (auto& it : laneList)
	{
		it->Draw();
	}
	myPlayer->Draw(1, laneList[current]->get_backgroundCoLor());

}

void Gameplay::Gameplay_deadEffect()
{
	Basic::sleepFor_milisec(100);
	Lane* currentLane = laneList[myPlayer->get_position().getY() / 4];
	switch (currentLane->get_type())
	{
		case HIGH_WAY:
			UserInterface::DrawRoadDeadEffect(myPlayer->get_position().getX(), myPlayer->get_position().getY(), myPlayer->get_type()); break;
		case REV_HIGH_WAY:
			UserInterface::DrawRoadDeadEffect(myPlayer->get_position().getX(), myPlayer->get_position().getY(), myPlayer->get_type()); break;
		case WATER:
			UserInterface::DrawRiverDeadEffect(myPlayer->get_position().getX(), myPlayer->get_position().getY(), myPlayer->get_type()); break;

	}
	Basic::sleepFor_milisec(100);

}

void Gameplay::Gameplay_endingCredit()
{
	Sound::PlaySFX(WIN);
	Basic::sleepFor_milisec(500);
	UserInterface::Drawbox(10, 2, 115, 25);
	UserInterface::Write("--------CONGRATULATION--------", 45, 4, RED, WHITE);
	UserInterface::Write("----YOU HAVE WON THE GAME-----", 45, 6, RED, WHITE);
	UserInterface::Write("+ CREDIT: ", 30, 8, DARKGREEN, WHITE);
	UserInterface::Write("_ MAN PHAM (BUGGY MAN)", 35, 10, DARKGREEN, WHITE);
	UserInterface::Write("_ LE THANH MINH TRI", 35, 12, DARKGREEN, WHITE);
	UserInterface::Write("_ TRAN DUC THIEN", 35, 14, DARKGREEN, WHITE);
	UserInterface::Write("_ NGUYEN DINH KIN", 35, 16, DARKGREEN, WHITE);
	UserInterface::Write("+ COURSES: ", 75, 8, DARKBLUE, WHITE);
	UserInterface::Write("_ OBJECT ORIENTED PROGRAMMING", 80, 10, DARKBLUE, WHITE);
	UserInterface::Write("_ ADVISOR: TRUONG TOAN THINH", 80, 12, DARKBLUE, WHITE);
	UserInterface::Write("@ COPY RIGHT 2023 ALL RIGHT RESERVED", 45, 20, DARKPURPLE, WHITE);
	UserInterface::Write("CLICK ANYWHERE TO RETURN TO MENU...", 45, 22, YELLOW, WHITE);
	UserInterface::DrawRCar(15, 10, 1, WHITE);
	UserInterface::DrawBCar(15, 16, 1, WHITE);
	UserInterface::DrawTruck(15, 22, 1, WHITE);
	UserInterface::DrawReverseRCar(112, 10, 1, WHITE);
	UserInterface::DrawReverseBCar(112, 16, 1, WHITE);
	UserInterface::DrawReverseTruck(112, 22, 1, WHITE);
	Basic::gotoXY(80, 22);
	Basic::Console_showCursor(true);
	while (true)
	{
		if (Basic::getKeyInput() == 8)
		{
			Basic::Console_showCursor(false);
			break;
		}
	}
}

void Gameplay::Gameplay_pause()
{
	pause = true;
	Basic::sleepFor_milisec(500);
	UserInterface::DrawAfterPause(WHITE);
	bool in = true;
	POINT oldp = Basic::getMousePos();
	while (in)
	{
		POINT newp = Basic::getMousePos();
		if (oldp.x != newp.x || oldp.y != newp.y)
		{
			pause_process(oldp, newp);
			
		}
		if (Basic::getKeyInput() == 8)
		{
			switch (pause_interac(newp))
			{
			case 0:
			{
				Sound::PlaySFX(CLICK);
				pause = false;
				in = false;
				Gameplay_draw();
				break;
			}
			case 1:
			{
				Sound::PlaySFX(CLICK);
				pause = false;
				round_status = ROUND_RESTART;
				round_finish = true;
				in = false;
				break;
			}
			case 2:
			{
				Sound::PlaySFX(CLICK);
				round_finish = true;
				run = false;
				in = false;
				break;
			}
			}
		}
		oldp = newp;
	}
}


void Gameplay::clearList()
{
	for (auto& it : laneList)
		if (it != nullptr) delete it;
	laneList.clear();
}


void Gameplay::Round_Info(Point2D pos)
{
	UserInterface::Drawbox(pos.getX(), pos.getY(), 30, 3);
	UserInterface::Write("ROUND: ", pos.getX() + 5, pos.getY()+1, RED, WHITE);
	UserInterface::Write("    ", pos.getX() + 12, pos.getY() + 1, YELLOW, WHITE);	
	UserInterface::Write(to_string(currentRound), pos.getX() + 12, pos.getY() + 1, YELLOW, WHITE);
}

Gameplay::~Gameplay()
{
	clearList();
	if (myPlayer != nullptr)
		delete myPlayer;
}

void Gameplay::restartB_askBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 685 && oldp.x <= 850 && oldp.y >= 260 && oldp.y <= 369)))
		if (newp.x >= 685 && newp.x <= 850 && newp.y >= 260 && newp.y <= 369)
			UserInterface::DrawRestartFromBeginButton(57, 10, 1, WHITE);

	if ((oldp.x >= 685 && oldp.x <= 850 && oldp.y >= 260 && oldp.y <= 369))
		if (!(newp.x >= 685 && newp.x <= 850 && newp.y >= 260 && newp.y <= 369))
			UserInterface::DrawRestartFromBeginButton(57, 10, 0, WHITE);
}

void Gameplay::restartT_askBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 685 && oldp.x <= 850 && oldp.y >= 382 && oldp.y <= 491)))
		if (newp.x >= 685 && newp.x <= 850 && newp.y >= 382 && newp.y <= 491)
			UserInterface::DrawRestartThisRoundButton(57, 15, 1, WHITE);

	if ((oldp.x >= 685 && oldp.x <= 850 && oldp.y >= 382 && oldp.y <= 491))
		if (!(newp.x >= 685 && newp.x <= 850 && newp.y >= 382 && newp.y <= 491))
			UserInterface::DrawRestartThisRoundButton(57, 15, 0, WHITE);
}

void Gameplay::runaway_askBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 685 && oldp.x <= 850 && oldp.y >= 502 && oldp.y <= 611)))
		if (newp.x >= 685 && newp.x <= 850 && newp.y >= 502 && newp.y <= 611)
			UserInterface::DrawRunAwayButton(57, 20, 1, WHITE);

	if ((oldp.x >= 685 && oldp.x <= 850 && oldp.y >= 502 && oldp.y <= 611))
		if (!(newp.x >= 685 && newp.x <= 850 && newp.y >= 502 && newp.y <= 611))
			UserInterface::DrawRunAwayButton(57, 20, 0, WHITE);
}

void Gameplay::restartAsk_process(POINT oldp, POINT newp)
{
	restartB_askBox(oldp, newp);
	restartT_askBox(oldp, newp);
	runaway_askBox(oldp, newp);
}

int Gameplay::restartAsk_inteac(POINT newp)
{
	if (newp.x >= 685 && newp.x <= 850 && newp.y >= 260 && newp.y <= 369)
		return 0;	//Start from begin
	else if (newp.x >= 685 && newp.x <= 850 && newp.y >= 382 && newp.y <= 491)
		return 1;	//Start from current round
	else if (newp.x >= 685 && newp.x <= 850 && newp.y >= 502 && newp.y <= 611)
		return 2;	//Start from end
	return -1;
}

void Gameplay::Gameplay_askRestart()
{
	pause = true;
	Basic::sleepFor_milisec(500);
	UserInterface::DrawAfterDead(WHITE);
	bool in = true;
	POINT oldp = Basic::getMousePos();
	while (in)
	{
		POINT newp = Basic::getMousePos();
		if (oldp.x != newp.x || oldp.y != newp.y)
		{
			restartAsk_process(oldp, newp);
			oldp = newp;
		}
		if (Basic::getKeyInput() == 8)
		{
			switch (restartAsk_inteac(newp))
			{
			case 0:
				pause = false;
				round_status = ROUND_RESTART_BEGIN;
				round_finish = true;
				in = false;
				break;
			case 1:
				pause = false;
				round_status = ROUND_RESTART;
				round_finish = true;
				in = false;
				break;
			case 2:
				round_finish = true;
				run = false;
				in = false;
				break;
			default: break;
			}
		}
	}
}

void Gameplay::pause_continueBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 685 && oldp.x <= 850 && oldp.y >= 260 && oldp.y <= 369)))
		if (newp.x >= 685 && newp.x <= 850 && newp.y >= 260 && newp.y <= 369)
		{
			Sound::playSound(SELECTING);
			UserInterface::DrawContinueButton(57, 10, 1, WHITE);
		}

	if ((oldp.x >= 685 && oldp.x <= 850 && oldp.y >= 260 && oldp.y <= 369))
		if (!(newp.x >= 685 && newp.x <= 850 && newp.y >= 260 && newp.y <= 369))
			UserInterface::DrawContinueButton(57, 10, 0, WHITE);
}

void Gameplay::pause_restartBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 685 && oldp.x <= 850 && oldp.y >= 382 && oldp.y <= 491)))
		if (newp.x >= 685 && newp.x <= 850 && newp.y >= 382 && newp.y <= 491)
		{
			Sound::playSound(SELECTING);
			UserInterface::DrawRestartButton(57, 15, 1, WHITE);
		}

	if ((oldp.x >= 685 && oldp.x <= 850 && oldp.y >= 382 && oldp.y <= 491))
		if (!(newp.x >= 685 && newp.x <= 850 && newp.y >= 382 && newp.y <= 491))
			UserInterface::DrawRestartButton(57, 15, 0, WHITE);
}

void Gameplay::pause_leaveBox(POINT oldp, POINT newp)
{
	if (!((oldp.x >= 685 && oldp.x <= 850 && oldp.y >= 502 && oldp.y <= 611)))
		if (newp.x >= 685 && newp.x <= 850 && newp.y >= 502 && newp.y <= 611)
		{
			Sound::playSound(SELECTING);
			UserInterface::DrawLeaveButton(57, 20, 1, WHITE);
		}

	if ((oldp.x >= 685 && oldp.x <= 850 && oldp.y >= 502 && oldp.y <= 611))
		if (!(newp.x >= 685 && newp.x <= 850 && newp.y >= 502 && newp.y <= 611))
			UserInterface::DrawLeaveButton(57, 20, 0, WHITE);
}

void Gameplay::pause_process(POINT oldp, POINT newp)
{
	pause_continueBox(oldp, newp);
	pause_restartBox(oldp,newp);
	pause_leaveBox(oldp, newp);

}

int Gameplay::pause_interac(POINT newp)
{
	if (newp.x >= 685 && newp.x <= 850 && newp.y >= 260 && newp.y <= 369)
		return 0;	//continue
	else if (newp.x >= 685 && newp.x <= 850 && newp.y >= 382 && newp.y <= 491)
		return 1;	//restart round
	else if (newp.x >= 685 && newp.x <= 850 && newp.y >= 502 && newp.y <= 611)
		return 2;	//leave game
	return -1;
}

void Gameplay::setup_round1()
{
	clearList();
	laneList.push_back(new Lane(first, GRASS, 15, 10));
	laneList.push_back(new Lane(second, GRASS, 15, 10));
	laneList.push_back(new Lane(third, GRASS, 15, 10));
	laneList.push_back(new Lane(fourth, HIGH_WAY, 15, 10));
	laneList.push_back(new Lane(fith, HIGH_WAY, 10, 15));
	laneList.push_back(new Lane(sixth, GRASS, 15, 10));
	laneList.push_back(new Lane(seventh, GRASS, 15, 10));
	laneList.push_back(new Lane(eigth, GRASS, 15, 10));
	laneList[3]->generate_HighwayMobs(1, 0, 1, 50);
	laneList[4]->generate_HighwayMobs(2, 0, 0, 30);
	
}

void Gameplay::setup_round2()
{
	clearList();
	laneList.push_back(new Lane(first, GRASS, 15, 10));
	laneList.push_back(new Lane(second, HIGH_WAY, 15, 10));
	laneList.push_back(new Lane(third, GRASS, 15, 10));
	laneList.push_back(new Lane(fourth, GRASS, 15, 10));
	laneList.push_back(new Lane(fith, REV_HIGH_WAY, 15, 20));
	laneList.push_back(new Lane(sixth, GRASS, 15, 15));
	laneList.push_back(new Lane(seventh, GRASS, 15, 10));
	laneList.push_back(new Lane(eigth, GRASS, 15, 10));
	laneList[1]->generate_HighwayMobs(1, 1, 1, 30);
	laneList[4]->generate_HighwayMobs(0, 2, 1, 40);
	
}

void Gameplay::setup_round3()
{
	clearList();
	laneList.push_back(new Lane(first, GRASS, 15, 10));
	laneList.push_back(new Lane(second, GRASS, 15, 10));
	laneList.push_back(new Lane(third, REV_HIGH_WAY, 15, 25));
	laneList.push_back(new Lane(fourth, RAIL_WAY, 15, 10));
	laneList.push_back(new Lane(fith, RAIL_WAY, 15, 20));
	laneList.push_back(new Lane(sixth, GRASS, 15, 10));
	laneList.push_back(new Lane(seventh, HIGH_WAY, 15, 15));
	laneList.push_back(new Lane(eigth, GRASS, 15, 10));
	laneList[2]->generate_HighwayMobs(0, 1, 1, 50);
	laneList[4]->generate_TrainMobs(1, 50,50);
	laneList[6]->generate_HighwayMobs(2, 1, 1, 30);

}

void Gameplay::setup_round4()
{
	clearList();
	laneList.push_back(new Lane(first, GRASS, 15, 10));
	laneList.push_back(new Lane(second, GRASS, 0, 0));
	laneList.push_back(new Lane(third, HIGH_WAY, 10, 10));
	laneList.push_back(new Lane(fourth, REV_HIGH_WAY, 20, 12));
	laneList.push_back(new Lane(fith, TRAIN, 15, 20));
	laneList.push_back(new Lane(sixth, GRASS, 15, 10));
	laneList.push_back(new Lane(seventh, HIGH_WAY, 15, 15));
	laneList.push_back(new Lane(eigth, GRASS, 15, 10));
	laneList[2]->generate_HighwayMobs(1, 1, 0, 50);
	laneList[3]->generate_HighwayMobs(0, 0, 2, 50);
	laneList[4]->generate_TrainMobs(2, 50, 10);
	laneList[6]->generate_HighwayMobs(2, 1, 1, 30);

}

void Gameplay::setup_round5()
{
	clearList();
	laneList.push_back(new Lane(first, GRASS, 15, 10));
	laneList.push_back(new Lane(second, GRASS, 0, 0));
	laneList.push_back(new Lane(third, WATER, 10, 10));
	laneList.push_back(new Lane(fourth, HIGH_WAY, 20, 13));
	laneList.push_back(new Lane(fith, WATER, 15, 20));
	laneList.push_back(new Lane(sixth, GRASS, 15, 10));
	laneList.push_back(new Lane(seventh, GRASS, 15, 15));
	laneList.push_back(new Lane(eigth, GRASS, 15, 10));
	laneList[2]->generate_WaterMobs(4, 30,10);
	laneList[3]->generate_HighwayMobs(1, 2, 0, 30);
	laneList[4]->add_WaterMobs(10);
	laneList[4]->add_WaterMobs(15);
	laneList[4]->add_WaterMobs(20);
	laneList[4]->add_WaterMobs(25);

	laneList[4]->add_WaterMobs(50);
	laneList[4]->add_WaterMobs(60);
	laneList[4]->add_WaterMobs(65);
	laneList[4]->add_WaterMobs(70);
	laneList[4]->add_WaterMobs(80);
}

void Gameplay::setup_round6()
{
	clearList();
	laneList.push_back(new Lane(first, GRASS, 15, 10));
	laneList.push_back(new Lane(second, REV_HIGH_WAY, 15, 12));
	laneList.push_back(new Lane(third, GRASS, 10, 10));
	laneList.push_back(new Lane(fourth, WATER, 20, 5));
	laneList.push_back(new Lane(fith, GRASS, 15, 20));
	laneList.push_back(new Lane(sixth, RAIL_WAY, 15, 10));
	laneList.push_back(new Lane(seventh, HIGH_WAY, 15, 15));
	laneList.push_back(new Lane(eigth, GRASS, 15, 10));
	laneList[1]->generate_HighwayMobs(1, 1, 0, 50);
	laneList[3]->add_WaterMobs(30);
	laneList[3]->add_WaterMobs(35);
	laneList[3]->add_WaterMobs(40);
	laneList[3]->add_WaterMobs(70);
	laneList[3]->add_WaterMobs(75);
	laneList[5]->generate_TrainMobs(2, 70, 10);
	laneList[6]->generate_HighwayMobs(1, 2, 1, 30);

}

void Gameplay::setup_round7()
{
	clearList();
	laneList.push_back(new Lane(first, GRASS, 15, 10));
	laneList.push_back(new Lane(second, HIGH_WAY, 15, 12));
	laneList.push_back(new Lane(third, HIGH_WAY, 20, 15));
	laneList.push_back(new Lane(fourth,WATER, 10, 10));
	laneList.push_back(new Lane(fith, GRASS, 15, 20));
	laneList.push_back(new Lane(sixth, RAIL_WAY, 15, 10));
	laneList.push_back(new Lane(seventh, REV_HIGH_WAY, 15, 11));
	laneList.push_back(new Lane(eigth, GRASS, 15, 10));
	laneList[1]->generate_HighwayMobs(1, 1, 1, 40);
	laneList[2]->generate_HighwayMobs(0, 2, 2, 30);
	laneList[3]->add_WaterMobs(50);
	laneList[3]->add_WaterMobs(57);
	laneList[3]->add_WaterMobs(60);
	laneList[3]->add_WaterMobs(67);
	laneList[3]->add_WaterMobs(70);
	laneList[5]->generate_TrainMobs(3,50, 10);
	laneList[6]->generate_HighwayMobs(0, 1, 3, 30);

}

void Gameplay::setup_round8()
{
	clearList();
	laneList.push_back(new Lane(first, GRASS, 15, 10));
	laneList.push_back(new Lane(second, TRAIN, 15, 2));
	laneList.push_back(new Lane(third, WATER, 20, 5));
	laneList.push_back(new Lane(fourth, WATER, 15, 3));
	laneList.push_back(new Lane(fith, WATER, 15, 4));
	laneList.push_back(new Lane(sixth, WATER, 10, 5));
	laneList.push_back(new Lane(seventh, WATER, 15, 20));
	laneList.push_back(new Lane(eigth, GRASS, 15, 10));
	laneList[1]->generate_TrainMobs(3, 50, 1);
	laneList[2]->add_WaterMobs(5);
	laneList[2]->add_WaterMobs(12);
	laneList[2]->add_WaterMobs(19);
	laneList[2]->add_WaterMobs(26);
	laneList[2]->add_WaterMobs(33);
	laneList[2]->add_WaterMobs(54);
	laneList[2]->add_WaterMobs(61);
	laneList[2]->add_WaterMobs(68);
	laneList[2]->add_WaterMobs(75);
	laneList[2]->add_WaterMobs(82);
	laneList[2]->add_WaterMobs(54);
	laneList[2]->add_WaterMobs(124);
	laneList[2]->add_WaterMobs(117);
	laneList[2]->add_WaterMobs(110);
	laneList[2]->add_WaterMobs(103);
	laneList[2]->add_WaterMobs(96);
	laneList[3]->add_WaterMobs(5);
	laneList[3]->add_WaterMobs(33);
	laneList[3]->add_WaterMobs(54);
	laneList[3]->add_WaterMobs(82);
	laneList[3]->add_WaterMobs(124);
	laneList[4]->add_WaterMobs(5);
	laneList[4]->add_WaterMobs(33);
	laneList[4]->add_WaterMobs(54);
	laneList[4]->add_WaterMobs(82);
	laneList[4]->add_WaterMobs(124);
	laneList[5]->add_WaterMobs(5);
	laneList[5]->add_WaterMobs(33);
	laneList[5]->add_WaterMobs(40);
	laneList[5]->add_WaterMobs(47);
	laneList[5]->add_WaterMobs(54);
	laneList[5]->add_WaterMobs(82);
	laneList[5]->add_WaterMobs(89);
	laneList[5]->add_WaterMobs(96);
	laneList[5]->add_WaterMobs(103);
	laneList[5]->add_WaterMobs(110);
	laneList[5]->add_WaterMobs(117);
	laneList[5]->add_WaterMobs(124);
	laneList[6]->add_WaterMobs(5);
	

}

void Gameplay::setup_round9()
{
	clearList();
	laneList.push_back(new Lane(first, GRASS, 15, 10));
	laneList.push_back(new Lane(second, REV_HIGH_WAY, 15, 12));
	laneList.push_back(new Lane(third, HIGH_WAY, 20, 13));
	laneList.push_back(new Lane(fourth, WATER, 15, 4));
	laneList.push_back(new Lane(fith, HIGH_WAY, 15, 11));
	laneList.push_back(new Lane(sixth, TRAIN, 10, 2));
	laneList.push_back(new Lane(seventh, REV_HIGH_WAY, 15, 13));
	laneList.push_back(new Lane(eigth, GRASS, 15, 10));
	laneList[1]->generate_HighwayMobs(0, 1, 0, 50);
	laneList[2]->generate_HighwayMobs(1, 0, 1, 40);
	laneList[3]->add_WaterMobs(30);
	laneList[3]->add_WaterMobs(40);
	laneList[3]->add_WaterMobs(50);
	laneList[3]->add_WaterMobs(60);
	laneList[3]->add_WaterMobs(70);
	laneList[3]->add_WaterMobs(80);
	laneList[3]->add_WaterMobs(85);
	laneList[3]->add_WaterMobs(90);
	laneList[3]->add_WaterMobs(95);
	laneList[3]->add_WaterMobs(100);
	laneList[4]->generate_HighwayMobs(1, 1, 2, 35);
	laneList[5]->generate_TrainMobs(2, 60, 30);
	laneList[6]->generate_HighwayMobs(1, 2, 1, 20);

	
}

void Gameplay::setup_round10()
{
	clearList();
	laneList.push_back(new Lane(first, GRASS, 15, 10));
	laneList.push_back(new Lane(second, GRASS, 15, 2));
	laneList.push_back(new Lane(third, GRASS, 20, 3));
	laneList.push_back(new Lane(fourth, GRASS, 15, 4));
	laneList.push_back(new Lane(fith, HIGH_WAY, 100, 1));
	laneList.push_back(new Lane(sixth, GRASS, 10, 2));
	laneList.push_back(new Lane(seventh, GRASS, 15, 3));
	laneList.push_back(new Lane(eigth, GRASS, 15, 10));
	laneList[4]->generate_HighwayMobs(1, 1, 1, 43);
}

void Gameplay::setup_round11()
{
	clearList();
	laneList.push_back(new Lane(first, GRASS, 15, 10));
	laneList.push_back(new Lane(second, TRAIN, 15, 2));
	laneList.push_back(new Lane(third, HIGH_WAY, 20, 13));
	laneList.push_back(new Lane(fourth, REV_HIGH_WAY, 15, 14));
	laneList.push_back(new Lane(fith, HIGH_WAY, 15, 11));
	laneList.push_back(new Lane(sixth, TRAIN, 10, 2));
	laneList.push_back(new Lane(seventh, GRASS, 15, 3));
	laneList.push_back(new Lane(eigth, GRASS, 15, 10));
	laneList[1]->generate_TrainMobs(2, 50, 20);
	laneList[2]->generate_HighwayMobs(1, 1, 1, 50);
	laneList[3]->generate_HighwayMobs(2, 2, 0, 30);
	laneList[4]->generate_HighwayMobs(1, 1, 1, 50);
	laneList[5]->generate_TrainMobs(1, 50, 50);
}

void Gameplay::setup_round12()
{
	clearList();
	laneList.push_back(new Lane(first, GRASS, 15, 10));
	laneList.push_back(new Lane(second, TRAIN, 15, 2));
	laneList.push_back(new Lane(third, GRASS, 20, 3));
	laneList.push_back(new Lane(fourth, HIGH_WAY, 15, 14));
	laneList.push_back(new Lane(fith, WATER, 15, 1));
	laneList.push_back(new Lane(sixth, HIGH_WAY, 10, 12));
	laneList.push_back(new Lane(seventh, REV_HIGH_WAY, 15, 13));
	laneList.push_back(new Lane(eigth, GRASS, 15, 10));
	laneList[1]->generate_TrainMobs(1, 50, 60);
	laneList[3]->generate_HighwayMobs(2, 2, 0, 35);
	laneList[4]->generate_WaterMobs(8, 15, 10);
	laneList[5]->generate_HighwayMobs(1, 1, 1, 40);
	laneList[6]->generate_HighwayMobs(2, 1, 1, 30);
}

void Gameplay::setup_round13()
{
	clearList();
	laneList.push_back(new Lane(first, GRASS, 15, 10));
	laneList.push_back(new Lane(second, GRASS, 15, 2));
	laneList.push_back(new Lane(third, REV_HIGH_WAY, 20, 13));
	laneList.push_back(new Lane(fourth, TRAIN, 15, 4));
	laneList.push_back(new Lane(fith, HIGH_WAY, 15, 11));
	laneList.push_back(new Lane(sixth, WATER ,10, 2));
	laneList.push_back(new Lane(seventh, HIGH_WAY, 15, 13));
	laneList.push_back(new Lane(eigth, GRASS, 15, 10));
	laneList[2]->generate_HighwayMobs(1, 1, 1, 40);
	laneList[3]->generate_TrainMobs(3, 50, 5);
	laneList[4]->generate_HighwayMobs(1, 2, 1,30);
	laneList[5]->generate_WaterMobs(6, 20, 5);
	laneList[6]->generate_HighwayMobs(2, 1, 1, 30);
}

void Gameplay::setup_round14()
{
	clearList();
	laneList.push_back(new Lane(first, GRASS, 15, 10));
	laneList.push_back(new Lane(second, WATER, 15, 2));
	laneList.push_back(new Lane(third, REV_HIGH_WAY, 20, 13));
	laneList.push_back(new Lane(fourth, WATER, 15, 4));
	laneList.push_back(new Lane(fith, HIGH_WAY, 15, 11));
	laneList.push_back(new Lane(sixth, REV_HIGH_WAY, 10, 12));
	laneList.push_back(new Lane(seventh, WATER, 15, 3));
	laneList.push_back(new Lane(eigth, GRASS, 15, 10));
	laneList[1]->generate_WaterMobs(3, 30, 10);
	laneList[2]->generate_HighwayMobs(1, 2, 0, 40);
	laneList[3]->generate_WaterMobs(4, 25, 25);
	laneList[4]->generate_HighwayMobs(1, 2, 1, 30);
	laneList[5]->generate_HighwayMobs(2, 1, 1, 30);
	laneList[6]->generate_WaterMobs(6, 20, 5);
}

void Gameplay::setup_round15()
{
	clearList();
	laneList.push_back(new Lane(first, GRASS, 15, 10));
	laneList.push_back(new Lane(second, RAIL_WAY, 0, 0));
	laneList.push_back(new Lane(third, HIGH_WAY, 10, 10));
	laneList.push_back(new Lane(fourth, REV_HIGH_WAY, 20, 13));
	laneList.push_back(new Lane(fith, RAIL_WAY, 15, 20));
	laneList.push_back(new Lane(sixth, WATER, 15, 10));
	laneList.push_back(new Lane(seventh, REV_HIGH_WAY, 15, 15));
	laneList.push_back(new Lane(eigth, GRASS, 15, 10));
	laneList[1]->generate_TrainMobs(1, 50, 50);
	laneList[2]->generate_HighwayMobs(1, 1, 1, 40);
	laneList[3]->generate_HighwayMobs(1, 1, 1, 35);
	laneList[4]->generate_TrainMobs(2, 55, 50);
	laneList[5]->generate_WaterMobs(3, 50, 20);
	laneList[6]->generate_HighwayMobs(1,1, 1, 30);
}

void Gameplay::setup_round0()
{
	clearList();
	laneList.push_back(new Lane(first, GRASS, 15, 10));
	laneList.push_back(new Lane(second, GRASS, 0, 0));
	laneList.push_back(new Lane(third, HIGH_WAY, 10, 10));
	laneList.push_back(new Lane(fourth, REV_HIGH_WAY, 20, 12));
	laneList.push_back(new Lane(fith, RAIL_WAY, 15, 20));
	laneList.push_back(new Lane(sixth, WATER, 15, 10));
	laneList.push_back(new Lane(seventh, REV_HIGH_WAY, 15, 15));
	laneList.push_back(new Lane(eigth, GRASS, 15, 10));
	laneList[2]->generate_HighwayMobs(1, 1, 1, 50);
	laneList[3]->generate_HighwayMobs(1, 1, 1, 30);
	laneList[4]->generate_TrainMobs(1, 50, 20);
	laneList[5]->generate_WaterMobs(3, 50, 20);
	laneList[6]->generate_HighwayMobs(0, 0, 0, 30);
}


bool Gameplay::Gameplay_save(string savename)
{
	Basic::reFormat(savename);
	ifstream checkFile("SavedFile\\" + savename + ".bin");
	if (checkFile)
	{
		checkFile.close();
		return false;
	}
	ofstream out("SavedFile\\" + savename + ".bin", ios::binary);
	if (!out) {
		out.close();
		return false;
	}
	int buf[5];
	buf[0] = myPlayer->get_type();
	buf[1] = myPlayer->get_Hspeed();
	buf[2] = myPlayer->get_Vspeed();
	buf[3] = myPlayer->get_delay();
	buf[4] = currentRound;
	for (int i = 0; i < 5; i++)
		out.write((char*)&buf[i], sizeof(int));
	out.close();
	return true;
}

bool Gameplay::Gameplay_load(string savename)
{
	Basic::reFormat(savename);
	ifstream in("SavedFile\\" + savename + ".bin", ios::binary);
	if (!in) {
		in.close();
		return false;
	}
	int buf[5];
	for (int i = 0; i < 5; i++)
		in.read((char*)&buf[i], sizeof(int));
	if (myPlayer)
		delete myPlayer;
	set_character(buf[0], buf[1], buf[2], buf[3]);
	currentRound = buf[4];
	in.close();
	return true;
}

int Gameplay::get_currentRound()
{
	return currentRound;
}

void Gameplay::set_currentRound(int round)
{
	currentRound = round;
}

int Gameplay::getPlayer_type()
{
	return myPlayer->get_type();
}
