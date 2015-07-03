#include "Animations.h"

Animations::~Animations(void)
{
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		for (unsigned int j = 0; j < vec[i].size(); j++)
		{
			delete vec[i][j];
		}
	}
	vec.clear();
}

Fl_PNG_Image* Animations:: getFrame(int animatedObjectType, int frame)
{
	return vec[animatedObjectType][frame];
}

void Animations::loadFrames(std::string name, int numberOfFrames)
{
	int sizeOfVector=vec.size();
	std::vector<Fl_PNG_Image*> tmpRow;
	vec.push_back(tmpRow);
	for (int i = 0; i < numberOfFrames; i++)
	{
		std::string tmp = name + std::to_string(i) +".png";
		vec[sizeOfVector].push_back(new Fl_PNG_Image(tmp.c_str()));
	}
}

int Animations::howManyFrames(int i)
{
	return vec[i].size();
}