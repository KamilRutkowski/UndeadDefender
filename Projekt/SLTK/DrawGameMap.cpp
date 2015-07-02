#include "DrawGameMap.h"

DrawGameMap::DrawGameMap(void)
{
	GameOver = false;
	actualTime = NULL;
	
}

int DrawGameMap::drawMap(int map, Player &player, std::list<Monster> &monsters, Animations &animations, Options &options, int &gameState, Fl_Double_Window &window)
{
	//Setting actual time if it was NULL
	if (!actualTime)
	{
		actualTime = clock() / CLOCKS_PER_SEC;
	}
	//Waiting for ESC after losing
	if (GameOver)
	{
		if (Fl::event_key(FL_Escape))
		{
			reset(player, monsters, gameState);
			return 0;
		}
		return 0;
	}
	//Drawing game map
	animations.getFrame(0, map)->draw(0, 0);
	//Drawing player
	animations.getFrame(1 + options.whichGender(), player.getAnimationFrame())->draw(player.getPosition(), 650);
	//Drawing monsters
	std::list<Monster>::iterator it;
	for (it = monsters.begin(); it != monsters.end(); it++)
	{
		animations.getFrame(it->getMonsterType(), it->getMonsterFrame())->draw(it->getMonsterPositionX(), it->getMonsterPositionY());
	}
	//Drawing HP
	Fl_Box HP(375, 700, 100, 25);
	Fl_Box Points(25, 700, 100, 25);
	Fl_Color tmp = fl_color();
	fl_color(255, 0, 0);
	fl_rect(175, 700, 500, 25, fl_color());
	fl_color(0, 255, 0);
	fl_rect(175, 700, 5 * player.getHP(), 25, fl_color());
	fl_color(tmp);
	HP.labelcolor(FL_BLACK);
	HP.label((std::to_string(player.getHP()) + "/100").c_str());
	Points.labelcolor(FL_BLACK);
	Points.label((std::string("Points: ") + std::to_string(player.getPoints())).c_str());
	// Going to main menu if Esc was pressed
	if (Fl::event_key(FL_Escape))
	{
		reset(player, monsters, gameState);
		return 0;
	}
	//Setting player attack if left mouse button was pressed
	if (FL_LEFT_MOUSE == Fl::event_button())
	{
		player.setAttack(true);
	}
	//Player is where mouse cursor is
	player.setPosition(Fl::event_x_root());
	//Going for all monsters
	for (it = monsters.begin(); it != monsters.end(); it++)
	{
		//Erasing monster from list if attacked
		if (player.isAttack())
		{
			if ((it->getMonsterPositionY() > 600) && (it->getMonsterPositionX() < 650))
			{
				if (((player.getPosition() - 5) < it->getMonsterPositionX()) && ((player.getPosition() + 5) > it->getMonsterPositionX()))
				{
					it = monsters.erase(it);
					player.addPoint();
					continue;
				}
			}
		}
		//Monster attacked the base?
		if (it->getMonsterPositionY() > 650)
		{
			it = monsters.erase(it);
			player.lowerHP();
			//Player killed?
			if (player.getHP() < 1)
			{
				GameOver = true;
			}
			break;
		}
	}
	//Moving monsters down
	moveMonsters(monsters.begin(), monsters.end());
	//Creating new monster if dTime is higher than spawn time value
	if (dTime() > SPAWN_TIME)
	{
		actualizeTime();
		monsters.push_back(Monster(animations));
	}
	//Setting player attack back to false
	player.setAttack(false);
	window.end();
	window.show();
	return Fl::run();
}

void DrawGameMap::moveMonsters(std::list<Monster>::iterator start, std::list<Monster>::iterator end)
{
	for (; start != end; start++)
	{
		start->moveMonster();
	}
}

int DrawGameMap::dTime()
{
	return ((clock() / CLOCKS_PER_SEC) - actualTime);
}

void DrawGameMap::actualizeTime()
{
	actualTime = (clock() / CLOCKS_PER_SEC);
}

void DrawGameMap::reset(Player &player, std::list<Monster> &monsters, int &gameState)
{
	//player.reset();
	monsters.clear();
	gameState = 0;
	GameOver = false;
	actualTime = NULL;
}