#pragma once

#include <cstdlib>
#include <ctime>
#include "Animations.h"

#define MAP_WIDTH 800
#define SPAWN_MAP_WIDHT 750
#define MAP_HEIGHT 750
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