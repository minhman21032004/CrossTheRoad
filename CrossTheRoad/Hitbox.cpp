#include "Hitbox.h"
Hitbox::Hitbox()
{
	UL = Point2D(0, 0);
	height = 0;
	width = 0;
	mode = 0;
	type = 0;
	collision = 0;
}

Hitbox::Hitbox(Point2D p, int w, int h, bool m, int t, bool c)
{
	UL = p;
	width = w;
	height = h;
	mode = m;
	type = t;
	collision = c;
}

void Hitbox::showAtrb()
{
	std::cout << UL.getX() << " " << UL.getY() << "\n";
	std::cout << "h:" << height << " w:" << width << "\n";
	std::cout << "m:" << mode << " t:" << type << " c:" << collision << "\n";
}

Point2D Hitbox::getUpLeft()
{
	return UL;
}

int Hitbox::getHeight()
{
	return height;
}

int Hitbox::getWidth()
{
	return width;
}

bool Hitbox::getMode()
{
	return mode;
}

int Hitbox::getType()
{
	return type;
}

bool Hitbox::getColli()
{
	return collision;
}

void Hitbox::setUpLeft(Point2D p)
{
	UL = p;
}

void Hitbox::setHeight(int h)
{
	height = h;
}

void Hitbox::setWidth(int w)
{
	width = w;
}

void Hitbox::setMode(bool m)
{
	mode = m;
}

void Hitbox::setType(int t)
{
	type = t;
}

void Hitbox::setColli(bool c)
{
	collision = c;
}

void Hitbox::Draw(int t_color, int b_color)
{
	UserInterface::Drawbox(getUpLeft().getX(), getUpLeft().getY(), getWidth(), getHeight());
}

void Hitbox::setup_truck(Point2D p)
{
	setUpLeft(Point2D(p.getX() - 1, p.getY()));
	setWidth(9); setHeight(3);
	setMode(1); setType(0); setColli(0);
}

void Hitbox::setup_car(Point2D p)
{
	setUpLeft(p);
	setWidth(8); setHeight(3);
	setMode(1); setType(0); setColli(0);
}

void Hitbox::setup_parrot(Point2D p)
{
	setUpLeft(p);
	setWidth(5); setHeight(3);
	setMode(1); setType(1); setColli(0);
}

void Hitbox::setup_chicky(Point2D p)
{
	setUpLeft(p);
	setWidth(5); setHeight(3);
	setMode(1); setType(1); setColli(0);
}

void Hitbox::setup_penguin(Point2D p)
{
	setUpLeft(p);
	setWidth(5); setHeight(3);
	setMode(1); setType(1); setColli(0);
}

void Hitbox::setup_dogo(Point2D p)
{
	setUpLeft(Point2D(p.getX() - 1, p.getY()));
	setWidth(7); setHeight(3);
	setMode(1); setType(1); setColli(0);
}

void Hitbox::setup_bee(Point2D p)
{
	setUpLeft(p);
	setWidth(7); setHeight(3);
	setMode(1); setType(1); setColli(0);
}
