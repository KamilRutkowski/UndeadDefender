#pragma once
#include <list>
#include <ctime>
#include <string>
#include "Monster.h"
#include "Player.h"

#define PLAYER_POSITION_Y 650
#define SPAWN_TIME 500

class Player;
class Monster;
class Animations;
class Options;

class DrawGameMap
{
public:
	DrawGameMap(Player &player, std::list<Monster> &monsters, Animations &animations, Options &options);
	~DrawGameMap();
	void drawMap();
	void isGameOver(int &gameState);
	void showAll();
	void hideAll();
private:
	bool GameOver;
	int actualTime;
	static void gameCallback(Fl_Widget* widget, void*p);
	bool startGame=false;
	std::list<Monster> *mon;
	Player *play;
	Animations *anim;
	Options *opt;
	Fl_Box *gameArea;
	Fl_Box *HP;
	Fl_Box *Points;
	int dTime();
	void actualizeTime();
	void moveMonsters(std::list<Monster>::iterator start, std::list<Monster>::iterator end);
	void reset(Player &player, std::list<Monster> &monsters);
};