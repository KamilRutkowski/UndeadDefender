#include "Monster.h"
#include <FL/Fl.H>
#include <FL/Fl_PNG_Image.H>
#include <cstdlib>
#include <ctime>


Monster::Monster(void)
{
	srand((unsigned int)time(NULL));
	posit.x=rand() % SPAWN_MAP_WIDHT;
	posit.y=0;
	monsterType=rand() % NUMBER_OF_MONSTERS;
	animationState=0;
}

Monster::~Monster(void)
{
	delete this;
}

int Monster::getMonsterType()
{
	return monsterType;
}

struct position Monster::getMonsterPosition()
{
	return posit;
}

void Monster::moveMonster()
{
	posit.y+=10;
}

int getMonsterFrame()
{

}