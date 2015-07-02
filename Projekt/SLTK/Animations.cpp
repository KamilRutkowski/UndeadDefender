#include "Animations.h"


Animations::Animations(void)
{

}


Animations::~Animations(void)
{
	vec.clear();
}

Fl_PNG_Image Animations:: getFrame(int animatedObjectType, int frame)
{
	return vec[animatedObjectType][frame];
}

int Animations::loadFrames(string name, int numberOfFrames)
{
	int fVector=vec.size();
	for (int i = 0; i < numberOfFrames; i++)
	{
		string tmp = name + std::to_string(i) + ".png";
		vec[fVector].push_back(Fl_PNG_Image(tmp.c_str()));
	}

}

int Animations::howManyFrames(int i)
{

	return vec[i].size();
}