#pragma once
//#include"Lane.h"
#include"Player.h"
#include"Proccess.h"
#include<condition_variable>
#include"Sound.h"

#define STARTING_POINT		Point2D(50,29)
#define ROUND_WIN				 1
#define ROUND_LOOSE				-1
#define ROUND_RESTART			 0
#define ROUND_RUNNING			 2
#define ROUND_RESTART_BEGIN		 3
#define TOTAL_ROUND				15

#define INFO_POS_1			Point2D(5,29)
#define INFO_POS_2			Point2D(100,29)

class Gameplay
{
private:
	vector<Lane*> laneList;	//list of lane
	bool finish, pause, run, round_finish;
	int round_status, currentRound;
	Player* myPlayer;
	vector<void(Gameplay::*)()> roundList;
	Point2D infoPos;
public:

	enum laneOrd {first = 1, second = 5, third = 9, fourth = 13, fith = 17, sixth = 21, seventh = 25, eigth = 29 };
	Gameplay() = default;
	~Gameplay();
	
	void restartB_askBox(POINT, POINT);		//restart begining ask box
	void restartT_askBox(POINT, POINT);		//restart this round ask box
	void runaway_askBox(POINT, POINT);		//runaway ask box
	void restartAsk_process(POINT, POINT);	//Restart ask full process
	int restartAsk_inteac(POINT);			//Restart ask interaction
	void Gameplay_askRestart();				//Restart ask

	void pause_continueBox(POINT, POINT);	//continue box
	void pause_restartBox(POINT, POINT);	//restart box
	void pause_leaveBox(POINT, POINT);		//leave box
	void pause_process(POINT, POINT);		//pause full process
	int pause_interac(POINT);				//pause interaction
	void Gameplay_pause();					//pause

	void setup_start();						//setup start

	//setup round
	void setup_round0();
	void setup_round1();
	void setup_round2();
	void setup_round3();
	void setup_round4();
	void setup_round5();
	void setup_round6();
	void setup_round7();
	void setup_round8();
	void setup_round9();
	void setup_round10();
	void setup_round11();
	void setup_round12();
	void setup_round13();
	void setup_round14();
	void setup_round15();

	void set_character(int,int,int,int);	//setup character

	void start_game();						//start game

	void start_round(int);					//start round

	void game_proccess();					//game process

	void start_player();					//start moving player by keyboard

	void start_lane();						//start moving lane automatic
	
	void Gameplay_draw();					//draw the current round

	void Gameplay_deadEffect();				//after dead effect

	void Gameplay_endingCredit();			//ending credit

	void clearList();						//clear the vector mobList

	bool Gameplay_save(string savename);	//save the game into binary file

	bool Gameplay_load(string savename);	//load the game from binary file

	int get_currentRound();					//get current round

	void set_currentRound(int);				//set current round

	int getPlayer_type();					//get player type

	void Round_Info(Point2D);				//draw round info box
};

