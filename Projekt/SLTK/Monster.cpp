#include "Monster.h"

Monster::Monster(Animations &animations)
{
	positionX=rand() % SPAWN_MAP_WIDHT;
	positionY=0;
	monsterType=(int)(rand() % NUMBER_OF_MONSTERS)+3;
	animationState=0;
	numberOfFrames = animations.howManyFrames(monsterType);
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
	positionY+=7;
}

int Monster::getMonsterFrame()
{
	animationState = (animationState+1) % (ANIMATION_TIME*numberOfFrames);
	return (int)(animationState++/ANIMATION_TIME);
}