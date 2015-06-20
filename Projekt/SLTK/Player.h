#pragma once
class Player
{
public:
	Player(void);
	~Player(void);
	int getPosition();
	int getAnimationFrame();
	void setPosition(int nPositionX);
	bool isAttack();
};

