#pragma once
/*
	Console axis:
	.-----> +x
	|
	|
	V
	+y
*/
class Point2D
{
private:
	int x;
	int y;
public:
	Point2D();	//Constructor

	Point2D(int, int);	//Constructor

	~Point2D() { };

	void set(int, int);	//Set value for a point

	int getX();	//Get x value

	int getY();	//Get y value

	bool operator==(const Point2D&);
	bool operator!=(const Point2D&);
};
