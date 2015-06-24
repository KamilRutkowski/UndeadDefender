#pragma once
#include <list>
#include <vector>
#include <FL/Fl_Window.H>
#include <FL/Fl.H>
#include <FL/Fl_PNG_Image.H>
#include "Monster.h"
#include "Animations.h"
#include "Player.h"

#define PLAYER_POSITION_Y 650;

class DrawGameMap
{
public:
	DrawGameMap(void);
	~DrawGameMap(void);
	void drawMap(int map,Player &player,std::list<Monster> &monsters,Animations &animations,Fl_Window &window,int &gameState);
	void moveMonsters(std::list<Monster>::iterator start, std::list<Monster>::iterator end);
	void isGameOver(int &gameState);
private:
	bool isGameOver;
};