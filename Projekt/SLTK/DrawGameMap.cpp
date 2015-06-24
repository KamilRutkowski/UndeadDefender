#include "DrawGameMap.h"

DrawGameMap::DrawGameMap(void)
{
	isGameOver = false;
}


DrawGameMap::~DrawGameMap(void)
{

}

void DrawGameMap::drawMap(int map, Player &player, std::list<Monster> &monsters, Animations &animations, Fl_Window &window, int &gameState)
{
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
	if (Fl::event_key(FL_Escape))
	{
		gameState = 0;
	}
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
					break;
				}
			}
		}
		//Monster attacked the base
		if (*it->getMonsterPosition.Y > 650)
		{
			it = monsters.erase(it);
			player.lowerHP();
			if (player.getHP() < 1)
			{
				isGameOver = true;
			}
			break;
		}
	}
	moveMonsters(monsters.begin(),monsters.end());
}

void moveMonsters(std::list<Monster>::iterator start, std::list<Monster>::iterator end)
{
	for (; start != end; start++)
	{
		start->moveMonster();
	}
}