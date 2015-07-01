#include "DrawGameMap.h"

DrawGameMap::DrawGameMap(void)
{
	isGameOver = false;
	actualTime = clock() / CLOCKS_PER_SEC;
	HP = new Fl_Box(400, 700, 50, 25);
}


DrawGameMap::~DrawGameMap(void)
{
	delete(HP);
}

void DrawGameMap::drawMap(int map, Player &player, std::list<Monster> &monsters, Animations &animations, Fl_Window &window, int &gameState)
{
	//Setting actual time if it was NULL
	if (!actualTime)
	{
		actualTime = clock() / CLOCKS_PER_SEC;
	}
	//Drawing game map
	animations.getFrame(0,map).draw(0,0);
	//Drawing player
	animations.getFrame(1,player.getAnimationFrame()).draw(player.getPosition(),650);
	//Drawing monsters
	std::list<Monster>::iterator it;
	for(it=monsters.begin++;it!=monsters.end();it++)
	{
		animations.getFrame(it->getMonsterType(),it->getMonsterFrame()).draw(*it->getMonsterPosition.X,*it->getMonsterPosition.Y);
	}
	//Drawing HP
	Fl_Color tmp = fl_color();
	fl_color(255,0,0);
	fl_rect(175, 700, 500, 25, fl_color());
	fl_color(0, 255, 0);
	fl_rect(175, 700, 5*player.getHP(), 25, fl_color());
	fl_color(tmp);
	HP->labelcolor(FL_BLACK);
	std::string currentHp =std::to_string(player.getHP())+"/100";
	HP->label(currentHp.c_str());
	// Going to main menu if Esc was pressed
	if (Fl::event_key(FL_Escape))
	{
		reset(player, monsters, gameState);
		return;
	}
	//Setting player attack if left mouse button was pressed
	if (FL_LEFT_MOUSE == Fl::event_button())
	{
		player.setAttack(true);
	}
	//Player is where mouse cursor is
	player.setPosition(Fl::event_x_root());
	//Going for all monsters
	for (it = monsters.begin++; it != monsters.end(); it++)
	{
		//Erasing monster from list if attacked
		if (player.isAttack())
		{
			if ((*it->getMonsterPosition.Y > 600) && (*it->getMonsterPosition.Y < 650))
			{
				if (((player.getPosition() - 5) < *it->getMonsterPosition.X) && ((player.getPosition() + 5) > *it->getMonsterPosition.X))
				{
					it = monsters.erase(it);
					continue;
				}
			}
		}
		//Monster attacked the base?
		if (*it->getMonsterPosition.Y > 650)
		{
			it = monsters.erase(it);
			player.lowerHP();
			//Player killed?
			if (player.getHP() < 1)
			{
				reset(player, monsters, gameState);
			}
			break;
		}
	}
	//Moving monsters down
	moveMonsters(monsters.begin(),monsters.end());
	//Creating new monster if dTime is higher than spawn time value
	if (dTime() > SPAWN_TIME)
	{
		actualizeTime();
		monsters.push_back(Monster(animations));
	}
	//Setting player attack back to false
	player.setAttack(false);
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
	player.reset();
	monsters.clear();
	gameState = 0;
	isGameOver = false;
	actualTime = NULL;
}