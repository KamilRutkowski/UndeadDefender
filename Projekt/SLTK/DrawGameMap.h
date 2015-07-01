#pragma once
#include <list>
#include <vector>
#include <FL/Fl_Window.H>
#include <FL/Fl.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>
#include <ctime>
#include <string>
#include "Monster.h"
#include "Animations.h"
#include "Player.h"

#define PLAYER_POSITION_Y 650
#define SPAWN_TIME 500

class DrawGameMap
{
public:
	DrawGameMap(void);
	~DrawGameMap(void);
	void drawMap(int map,Player &player,std::list<Monster> &monsters,Animations &animations,Fl_Window &window,int &gameState);
	void isGameOver(int &gameState);
private:
	Fl_Box* HP;
	bool isGameOver;
	int actualTime;
	int dTime();
	void actualizeTime();
	void moveMonsters(std::list<Monster>::iterator start, std::list<Monster>::iterator end);
	void reset(Player &player, std::list<Monster> &monsters, int &gameState);
};