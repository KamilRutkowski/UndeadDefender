#include "Monster.h"

Monster::Monster(Animations &animations)
{
	srand((unsigned int)time(NULL));
	posit.x=rand() % SPAWN_MAP_WIDHT;
	posit.y=0;
	monsterType=(int)(rand() % NUMBER_OF_MONSTERS)+2;
	animationState=0;
	numberOfFrames = animations.howManyFrames(monsterType);
}

Monster::~Monster(void)
{
	
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

int Monster::getMonsterFrame()
{
	animationState = animationState % ANIMATION_TIME;
	return (int)(animationState++/(ANIMATION_TIME/numberOfFrames));
}