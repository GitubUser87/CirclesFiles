#pragma once
#include "Vector2.h"
#include "Shape.h"


#ifndef CIRCLE_H
#define CIRCLE_H


class Circle : Shape {
public:
	//This sets the default value of the first circle as an opaque Red.
	Circle(unsigned char r=255, unsigned char g=0, unsigned char b=0, unsigned char a=255);
	~Circle();
	
	// Draw: This will create a new circle when it is called upon.
	void Draw();
	// Update: This updates the location of the circle and returns add_circle = true if the circle has collided with a wall.
	bool Update();
	// UpdateLocation: This will attach the circles to my mouse cursor when I click/hold the right mouse button.
	void UpdateLocation(int mx, int my);
	unsigned char GetRed();
	unsigned char GetGreen();
	unsigned char GetBlue();
	// GetAlpha: This will return the Alpha value so the transparency can be altered/set.
	unsigned char GetAlpha();

private:
	//This will now randomize the scale and direction of the circles.
	void Randomize();
	int radius;
	//This is a class that will hold the position of the x & y values.
	
	int xDir;
	int yDir;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
	

};

#endif