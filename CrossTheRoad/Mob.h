#pragma once
#include "Hitbox.h"
#include<condition_variable>

#define RED_CAR		0
#define BLUE_CAR	1
#define TRUCK		2
#define TRAIN		3
#define DUCK_WEED	4
const int MobWidth[5] = { 8,8,9,40,7 };
const int MobHeight[5] = { 3,3,3,5,4 };
const int MobLane[5] = { 1,1,1,3,2 };

class Mob
{
	Hitbox* mobBox;
	int type, speed, delay;

public:

	Mob();
	Mob(Point2D pos, int mob_type, int spd, int dly);
	Mob(const Mob& other);
	Mob& operator=(const Mob& other);
	~Mob();

	// get - set position of mob
	void set_position(int, int);
	Point2D get_position();

	// get - set type
	void set_type(int);
	int get_type();

	// get - set size
	void set_height(int);
	int get_height();
	void set_width(int);
	int get_width();
	void set_size(int, int);

	//get - set delay
	void set_delay(int);
	int get_delay();
	// get - set speed
	void set_speed(int);
	int get_speed();


	//get hitbox
	Hitbox* get_hitbox();

	//move mob
	void move_left();
	void move_right();

	//Draw mob
	void Draw_Right(bool);
	void Draw_Left(bool);
};

