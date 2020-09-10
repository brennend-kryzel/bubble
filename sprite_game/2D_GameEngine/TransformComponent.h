#pragma once
#include"Components.h"

class TransformComponent :public Component
{
private:
	int xpos;
	int ypos;
public:

	TransformComponent() {
		xpos = 0;
		ypos = 0;
			
	}

	TransformComponent(int x, int y) 
	{
		xpos = x;
		ypos = y;
	}

	int x() { return xpos; }
	int y() { return ypos; }


	

	void update()override
	{
		xpos++;
		ypos++;
	}


	void setPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}


};