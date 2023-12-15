#pragma once
#include<iostream>
#include "Point2D.h"
#include"UserInterface.h"
using namespace std;
/*
	Console axis:
	.-----> +x
	|
	|
	V
	+y
*/
//Hit box is an rectangle, if the character hitbox touch the mob box then he die
class Hitbox
{
private:
	//up left cornor of an retangle
	Point2D UL;

	//Other attribute
	int height;
	int width;

	bool mode;	//on - off
	int type;	//player box or mob box
	bool collision;	//check if collision happen

public:

	//Type of hitbox
	enum HitboxType {
		mob,
		player,
		train
	};

	//Draw hitbox on screen
	enum ShowHitbox {
		off,
		on
	};

	Hitbox();	//constructor

	Hitbox(Point2D p, int w, int h, bool m, int t, bool c);	//constructor
	
	Hitbox(int);	//Constructor for each animal

	~Hitbox() { };	//destructor

	void showAtrb();	//SHow attribute

	Point2D getUpLeft();	//Get up left cornor of the box

	//Get attribute of the box
	int getHeight();
	int getWidth();
	bool getMode();
	int getType();
	bool getColli();

	//Set attribute for the box
	void setUpLeft(Point2D);
	void setHeight(int);
	void setWidth(int);
	void setMode(bool);
	void setType(int);
	void setColli(bool);

	//Draw the box
	void Draw(int, int);

	//Setup
	void setup_truck(Point2D);
	void setup_car(Point2D);
	void setup_parrot(Point2D);
	void setup_chicky(Point2D);
	void setup_penguin(Point2D);
	void setup_dogo(Point2D);
	void setup_bee(Point2D);
};

