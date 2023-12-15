#include "Process.h"
#include "Proccess.h"

double Process::getDistance(Point2D a, Point2D b)
{
	double xTemp = (double)b.getX() - (double)a.getX();
	double yTemp = (double)b.getY() - (double)a.getY();
	return sqrt(xTemp * xTemp + yTemp * yTemp);
}

bool Process::isCollision(Hitbox a, Hitbox b)
{
	double	a_centerX = (double)a.getUpLeft().getX() + ((double)a.getWidth() / 2),
		b_centerX = (double)b.getUpLeft().getX() + ((double)b.getWidth() / 2);
	double	a_centerY = (double)a.getUpLeft().getY() + ((double)a.getHeight() / 2),
		b_centerY = (double)b.getUpLeft().getY() + ((double)b.getHeight() / 2);
	double	touchDistanceX = ((double)a.getWidth() + (double)b.getWidth()) / 2,
		touchDistanceY = ((double)a.getHeight() + (double)b.getHeight()) / 2;
	return ((abs(a_centerX - b_centerX) <= touchDistanceX) && (abs(a_centerY - b_centerY) <= touchDistanceY));
}

bool Process::player_isIn(Player*& myPlayer, Lane*& myLane)
{
	if (abs(myLane->get_position() - myPlayer->get_position().getY()) <= 4)
		return true;
	return false;
}

bool Process::player_isCrash(Player*& myPlayer, Mob*& myMob)
{
	if (isCollision(*myPlayer->getHbox(), *myMob->get_hitbox()))
		return true;
	return false;
}

