#pragma once

#include <cstdlib>
#include <ctime>
#include "Animations.h"

#define MAP_WIDTH 750
#define SPAWN_MAP_WIDHT 610
#define MAP_HEIGHT 800
#define NUMBER_OF_MONSTERS 5
#define ANIMATION_TIME 30

class Animations;

class Monster
{
public:
	Monster(Animations &animations);
	int getMonsterType();
	int getMonsterFrame();
	int getMonsterPositionX();
	int getMonsterPositionY();
	void moveMonster();

private:
	int numberOfFrames;
	int monsterType;
	int positionX;
	int positionY;
	int animationState;
};