#include "Player.h"

Player::Player()
{
	HP = 100;
	positionX = 0;
	animationFrame = 0;
	attack = false;
}

int& Player::getPosition()
{
	return positionX;
}

int& Player::getAnimationFrame()
{
	return animationFrame; 
}

void Player::setPosition(int pos)
{
	positionX = pos;
}

bool& Player::isAttack()
{
	return attack;
}

void Player::setAttack(bool atc)
{
	attack=atc;
}

int& Player::getHP()
{
	return HP;
}

void Player::lowerHP()
{
	HP-=10;
}

void Player::reset()
{
	HP = 100;
	positionX = 0;
	animationFrame = 0;
	attack = false;
	points = 0;
}

int& Player::getPoints()
{
	return points;
}

void Player::addPoint()
{
	points +=1;
}
