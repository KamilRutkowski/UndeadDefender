#pragma once

#include <FL/Fl.H>
#include <FL/Fl_PNG_Image.H>
#include <cstdlib>
#include <ctime>
#include "Animations.h"

#define MAP_WIDTH 800
#define SPAWN_MAP_WIDHT 750
#define MAP_HEIGHT 750
#define NUMBER_OF_MONSTERS 5
#define ANIMATION_TIME 60

class Monster
{
public:
	Monster(Animations &animations);
	~Monster(void);
	int getMonsterType();
	int getMonsterFrame();
	struct position getMonsterPosition();
	void moveMonster();

private:
	int numberOfFrames;
	int monsterType;
	struct position posit;
	int animationState;
};

struct position
{
	int x;
	int y;
};