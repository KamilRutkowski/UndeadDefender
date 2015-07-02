#pragma once
#include <list>
#include <ctime>
#include <string>
#include "Monster.h"
#include "Player.h"

#define PLAYER_POSITION_Y 650
#define SPAWN_TIME 500

class DrawGameMap
{
public:
	DrawGameMap(void);
	int drawMap(int map, Player &player, std::list<Monster> &monsters, Animations &animations, Options &options, int &gameState, Fl_Double_Window &window);
	void isGameOver(int &gameState);
private:
	bool GameOver;
	int actualTime;
	int dTime();
	void actualizeTime();
	void moveMonsters(std::list<Monster>::iterator start, std::list<Monster>::iterator end);
	void reset(Player &player, std::list<Monster> &monsters, int &gameState);
};