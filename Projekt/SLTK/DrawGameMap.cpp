#include "DrawGameMap.h"


DrawGameMap::DrawGameMap(void)
{

}


DrawGameMap::~DrawGameMap(void)
{

}

void DrawGameMap::drawMap(int map,Player &player,std::list<Monster> &monsters,Animations &animations,Fl_Window &window)
{
	animations.getFrame(0,map).draw(0,0);
	animations.getFrame(1,player.getAnimationFrame()).draw(player.getPosition(),650);
	std::list<Monster>::iterator it;
	for(it=monsters.begin++;it!=monsters.end();it++)
	{
		animations.getFrame((*it).getMonsterType(),(*it).getMonsterFrame()).draw((*it).getMonsterPosition.X,(*it).getMonsterPosition.Y);
	}
}