#include "DrawGameMap.h"

DrawGameMap::DrawGameMap(Menu &menu,Player &player, std::list<Monster> &monsters, Animations &animations, Options &options, Fl_Double_Window &window)
{
	GameOver = false;
	actualTime = NULL;
	men = &menu;
	mon = &monsters;
	play = &player;
	anim = &animations;
	opt = &options;
	win = &window;
	srand((unsigned int)time(NULL));
	hideAll();
}

DrawGameMap::~DrawGameMap()
{

}

void DrawGameMap::drawMap()
{
	win->begin();
	//Setting actual time if it was NULL
	if (actualTime==NULL)
	{
		actualTime = clock() / CLOCKS_PER_SEC;
	}
	//Waiting for ESC after losing
	if (GameOver)
	{
		if (Fl::event_key('e'))
		{
			win->end();
			win->redraw();
			reset(*play, *mon);
			hideAll();
			men->showAll();
			return;
		}
		Fl::repeat_timeout(0.02, timeOut, this);
		return;
	}
	//Setting player attack if left mouse button was pressed
	if (Fl::event_buttons())
	{
		if (FL_LEFT_MOUSE == Fl::event_button())
		{
			if (!clicked)
			{
				play->setAttack(true);
				clicked = true;
				click = 15;
			}
		}
	}
	else clicked = false;
	//Drawing game map
	anim->getFrame(0, opt->whichMap())->draw(0,0);
	//Drawing player
	anim->getFrame(1 + (int)opt->whichGender(), (int)play->isAttack())->draw(play->getPosition(), 650);
	//Drawing monsters
	std::list<Monster>::iterator it;
	if (mon->size() > 0)
	{
		for (it = mon->begin(); it != mon->end(); it++)
		{
			anim->getFrame(it->getMonsterType(), it->getMonsterFrame())->draw(it->getMonsterPositionX(), it->getMonsterPositionY());
		}
	}
	//Drawing points
	fl_draw_box(FL_FLAT_BOX, 510 - (5 * (100 - play->getHP())), 10, 500 - (5 * play->getHP()), 25, FL_RED);
	fl_draw_box(FL_FLAT_BOX, 10, 10, 5 * play->getHP(), 25, FL_GREEN);
	fl_color(0, 0, 0);
	fl_font(0, 20);
	fl_draw(("HP: " + std::to_string(play->getHP()) + "/100").c_str(), 200, 31);
	fl_draw_box(FL_FLAT_BOX, 550, 10, 150, 25, FL_LIGHT1);
	fl_color(0, 0, 0);
	fl_font(0, 20);
	fl_draw(("Points: " + std::to_string(play->getPoints())).c_str(), 560, 31);
	// Going to main menu if e was pressed
	if (Fl::event_key('e'))
	{
		win->end();
		win->redraw();
		reset(*play, *mon);
		hideAll();
		men->showAll();
		return;
	}
	//Player is where mouse cursor is
	play->setPosition(Fl::event_x()-85);
	//Going for all monsters
	for (it = mon->begin(); it != mon->end(); it++)
	{
		//Erasing monster from list if attacked
		if (play->isAttack())
		{
			if ((it->getMonsterPositionY() > 500) && (it->getMonsterPositionY() < 575))
			{
				if (((play->getPosition() - 50) < it->getMonsterPositionX()) && ((play->getPosition() + 125) > it->getMonsterPositionX()))
				{
					it = mon->erase(it);
					play->addPoint();
					if (it == mon->end())break;
					continue;
				}
			}
		}
		//Monster attacked the base?
		if (it->getMonsterPositionY() > 800)
		{
			it = mon->erase(it);
			play->lowerHP();
			//Player killed?
			if (play->getHP() < 1)
			{
				GameOver = true;
			}
			break;
		}		
	}
	//Moving monsters down
	moveMonsters(mon->begin(), mon->end());
	//Creating new monster if dTime is higher than spawn time value
	if (dTime() > SPAWN_TIME)
	{
		actualizeTime();
		mon->push_back(Monster(*anim));
	}
	//Setting player attack back to false
	if (click == 0)
	{
		play->setAttack(false);
	}
	else click--;
	win->end();
	Fl::repeat_timeout(0.02, timeOut, this);
}

void DrawGameMap::moveMonsters(std::list<Monster>::iterator start, std::list<Monster>::iterator end)
{
	for (; start != end; start++)
	{
		start->moveMonster();
	}
}

double DrawGameMap::dTime()
{
	return (((double)clock() / CLOCKS_PER_SEC) - actualTime);
}

void DrawGameMap::actualizeTime()
{
	actualTime = ((double)clock() / CLOCKS_PER_SEC);
}

void DrawGameMap::reset(Player &player, std::list<Monster> &monsters)
{
	player.reset();
	monsters.clear();
	GameOver = false;
	actualTime = NULL;
}

void DrawGameMap::showAll()
{
	Fl::add_timeout(0.02,timeOut, this);
}
void DrawGameMap::hideAll()
{
	Fl::remove_timeout(timeOut);
}

void DrawGameMap::gameCallback(Fl_Widget* widget, void*p)
{
	DrawGameMap *Box = (DrawGameMap*)p;
	Box->drawMap();
}

void DrawGameMap::timeOut(void *p)
{
	DrawGameMap *T = (DrawGameMap *)p;
	T->drawMap();
}