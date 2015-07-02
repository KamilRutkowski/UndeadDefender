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
	void setAttack(bool atc);
	void lowerHP();
	int getHP();
	void reset();

private:
	
	int HP;
	int positionX;
	int animationFrame;
	bool attack;
};