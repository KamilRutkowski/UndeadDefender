#include "Animations.h"


Animations::Animations(void)
{

}


Animations::~Animations(void)
{
}

Fl_PNG_Image Animations:: getFrame(int animatedObjectType, int frame)
{
	return vec[animatedObjectType][frame];
}

int Animations::loadFrames(string name, int numberOfFrames)
{
	for (int i = 0; i < numberOfFrames; i++)
	{
		string tmp = name + std::to_string(i);
	}

}

int Animations::howManyFrames()
{

	
}