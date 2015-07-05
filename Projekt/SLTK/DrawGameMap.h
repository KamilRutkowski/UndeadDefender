#pragma once
#include <list>
#include <ctime>
#include <string>
#include "Monster.h"
#include "Player.h"

#define PLAYER_POSITION_Y 650
#define SPAWN_TIME 0.5

class Player;
class Monster;
class Animations;
class Options;
class Menu;

class DrawGameMap
{
public:
	DrawGameMap(Menu &menu, Player &player, std::list<Monster> &monsters, Animations &animations, Options &options, Fl_Double_Window &window);
	~DrawGameMap();
	void drawMap();
	void isGameOver(int &gameState);
	static void timeOut(void *p);
	void showAll();
	void hideAll();
private:
	int click=0;
	bool clicked = false;
	bool GameOver;
	double actualTime;
	static void gameCallback(Fl_Widget* widget, void*p);
	bool startGame=false;
	std::list<Monster> *mon;
	Player *play;
	Menu *men;
	Animations *anim;
	Options *opt;
	Fl_Double_Window *win;
	double dTime();
	void actualizeTime();
	void moveMonsters(std::list<Monster>::iterator start, std::list<Monster>::iterator end);
	void reset(Player &player, std::list<Monster> &monsters);
};