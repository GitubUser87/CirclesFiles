#include "Circle.h"
#include <cstdlib>
#include <iostream>
#include "Framework.h"

//This will create the first circle.
//It's default values have been set to make it an opaque red at the beginning.
//It will also make it a random size when it starts.
Circle::Circle(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha):
	r(red),
	g(green),
	b(blue),
	a(alpha),
	radius(rand() % 10 + 2),
	Shape(rand() % (800 - 12 * 2), rand() % (500 - 12 * 2))
	//Shape(0, 0)
{
	//radius = rand() % 10 + 2;
	//position.x = rand() % (800 - radius * 2);
	//position.y = rand() % (500 - radius * 2);
	//std::cout << position.x << " " << position.y << std::endl;
	xDir = -2 + rand() % 5;
	yDir = -2 + rand() % 5;
}

Circle::~Circle()
{
	std::cout << "Circle destroyed" << std::endl;
}

//This will draw a new circle when called. 
void Circle::Draw()
{
	ChangeColour(GetRed(), GetGreen(), GetBlue(), GetAlpha());
	// Draws a circle at 100,200 with radius 20
	DrawCircle(position.x, position.y, radius);
	
}

//This code will detect if the circle hits a wall and then send it off in the opposing dirction.
//At the end of the code it will return add_circle so that the main.cpp will knwo that it is true and draw a new circle when the old one hits a wall.
bool Circle::Update()
{
	if (rand() % 100 == 0)
	{
		Randomize();
	}
	bool add_circle = false;
	if (rand() % 100 == 0)
	{
		xDir = (rand() % 5) - 2;
		yDir = (rand() % 5) - 2;
		radius = 5 + rand() % 36;
	}
	position.x = position.x + xDir;
	if (position.x > 800 - (2 * radius))
	{
		position.x = 800 - (2 * radius) - 5;
		xDir = -xDir;
		add_circle = true;
	}
	if (position.x < 0)
	{
		position.x = 5;
		xDir = -xDir;
		add_circle = true;
	}
	position.y = position.y + yDir;
	if (position.y > 500 - (2 * radius))
	{
		position.y = 500 - (2 * radius) - 5;
		yDir = -yDir;
		add_circle = true;
	}
	if (position.y < 0)
	{
		position.y = 5;
		yDir = -yDir;
		add_circle = true;
	}
	return add_circle;
}

//This sets x & y as where my mouse cursor is currently located.
void Circle::UpdateLocation(int mx, int my)
{
	position.x = mx - radius;
	position.y = my - radius;
}

unsigned char Circle::GetRed()
{
	return r;
}

unsigned char Circle::GetGreen()
{
	return g;
}

unsigned char Circle::GetBlue()
{
	return b;
}

unsigned char Circle::GetAlpha()
{
	return a;
}

//This will now randomize the scale and direction of the circles.
void Circle::Randomize()
{
	int old_radius = radius;
	radius = rand() % 10 + 2;
	xDir = -2 + rand() % 5;
	yDir = -2 + rand() % 5;
	position.move(old_radius - radius, old_radius - radius);
}
