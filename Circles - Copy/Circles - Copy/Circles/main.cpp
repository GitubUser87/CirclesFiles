/*
    Start shape drawing file
*/

#include <iostream>
#include <vector>
#include "Framework.h"
#include "Circle.h"

// Variables with global scope - do not rename them, feel free to change values though

// Screen dimensions

// Delay to slow things down.
int gTimeDelayMS{10};

using namespace std;

int gScreenWidth{ 800 };
int gScreenHeight{ 500 };

int main()
{
	std::cout << "Hello Circles" << endl;
	srand(time(NULL));
	const int num_circles{ 1 };
	//vector<Circle> circles;
	vector<Circle*> circles;
	circles.push_back(new Circle());


	while (UpdateFramework())
	{

		//This will make sure that the program isn't constantly making new circles.
		bool add_circle = false;

		//This will grab all the circles that have been created and will place them where my mouse cursor is as long as I hold the left mouse button.
		if (IsButtonPressed(EButton::eLeft))
		{
			int mx{ 0 };
			int my{ 0 };
			GetMousePosition(mx, my);
			//for (Circle & circle : circles)
			//{
			//	circle.UpdateLocation(mx, my);
			//}
			for (Circle* circle : circles)
			{
				circle->UpdateLocation(mx, my);
			}
		}

		//This will create new circles for as long as the right mouse button is held down.
		if (IsButtonPressed(EButton::eRight) && circles.size() < 100)
		{
			circles.push_back(new Circle(rand() % 256, rand() % 256, rand() % 256, 200 + rand() % 50));
		}
		for (Circle* circle : circles)
		{
			if (circle -> Update())
			{
				add_circle = true;
			}
		}
		
		//This adds a new circle if add_circle equals true.
		if (add_circle && circles.size() < 100)
		{
		
			circles.push_back(new Circle(rand() % 256, rand() % 256, rand() % 256,50 + rand() % 200));
			
		}

		for (Circle* & circle : circles)
		{
			circle -> Draw();
			
		}
	}

	std::cout << "Bye Bye" << endl;

	return 0;
}
