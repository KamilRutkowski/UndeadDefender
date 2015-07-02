#include "Monster.h"

Monster::Monster(Animations &animations)
{
	srand((unsigned int)time(NULL));
	positionX=rand() % SPAWN_MAP_WIDHT;
	positionY=0;
	monsterType=(int)(rand() % NUMBER_OF_MONSTERS)+3;
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

int Monster::getMonsterPositionX()
{
	return positionX;
}

int Monster::getMonsterPositionY()
{
	return positionY;
}

void Monster::moveMonster()
{
	positionY+=10;
}

int Monster::getMonsterFrame()
{
	animationState = animationState % ANIMATION_TIME;
	return (int)(animationState++/(ANIMATION_TIME/numberOfFrames));
}