#pragma once
#include"Hitbox.h"
#include"Player.h"
#include"Lane.h"
using namespace std;

class Process
{
public:
	static double getDistance(Point2D a, Point2D b);

	static bool isCollision(Hitbox a, Hitbox b);

	static bool player_isIn(Player*&, Lane*&);
	
	static bool player_isCrash(Player*&, Mob*&);

};

