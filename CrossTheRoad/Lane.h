#pragma once
#include "Mob.h"
#include <vector>
#include<condition_variable>
#define GRASS			0
#define HIGH_WAY		1
#define WATER			2
#define RAIL_WAY		3
#define REV_HIGH_WAY	5
#define LANE_HEIGHT		4
#define MOB_GAP			40



class Lane
{
private:
	int position;	//up point on y axis
	int type;		//type of lane
	bool status;	//on - off <=> red light - green light
	vector<Mob*> mobsList;		//List of mobs
	int speed;
	int delay;

	int background_Color; //dthien new
	int trafficFlow = 0;
public:

	Lane();
	Lane(int pos, int laneType, int spd, int dly);
	Lane(const Lane&);
	Lane& operator=(const Lane& other);
	~Lane();

	//get set position
	void set_position(int);
	int get_position();

	//get set type
	void set_type(int);
	int get_type();

	//get set status
	void set_stat(bool);
	bool get_stat();

	//get set speed of mobs
	int get_speed();
	void set_speed(int);

	//get set delay of mobs
	int get_delay();
	void set_delay(int);

	
	int get_backgroundCoLor(); 
	void set_backgroundColor(int);

	//clear mobsList
	void clearList();

	//Generate mobs
	void generate_HighwayMobs(int red = 0, int blu = 0, int truk = 0, int gap = 30);
	void generate_TrainMobs(int num = 0, int gap = 40, int posX = 0);
	void generate_WaterMobs(int num = 0, int gap = 40, int posX = 0);
	void add_WaterMobs(int posX);

	//Draw the whole lane and the mobs
	void Draw();

	//Move the mobs
	void run();

	//get list of mobs on the lane
	vector<Mob*> get_mobsList();

};
