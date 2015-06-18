#pragma once

#include <FL/Fl.H>
#include <FL/Fl_PNG_Image.H>
#include <cstdlib>
#include <ctime>

#define MAP_WIDTH 800;
#define SPAWN_MAP_WIDHT 750;
#define MAP_HEIGHT 750;
#define NUMBER_OF_MONSTERS 5;

class Monster
{
public:
	Monster(void);
	~Monster(void);
	int getMonsterType();
	int getMonsterFrame();
	struct position getMonsterPosition();
	void moveMonster();

private:
	int monsterType;
	struct position posit;
	int animationState;
};

struct position
{
	int x;
	int y;
};