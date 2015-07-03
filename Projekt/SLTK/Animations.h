#pragma once
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <iostream>
#include <vector>
#include <string>
#include "Options.h"

class Animations
{
private:
	std::vector< std::vector< Fl_PNG_Image* > > vec;

public:
	~Animations(void);
	Fl_PNG_Image* getFrame(int animatedObjectType, int frame);
	void loadFrames(std::string name, int numberOfFrames);
	int howManyFrames(int);
};
