#include "DrawGameMap.h"

DrawGameMap::DrawGameMap( Player &player, std::list<Monster> &monsters, Animations &animations, Options &options)
{
	GameOver = false;
	actualTime = NULL;
	gameArea = new Fl_Box(0, 0, 750, 800);
	HP = new Fl_Box(375, 700, 100, 25);
	Points = new Fl_Box(25, 700, 100, 25);
	HP->labelcolor(FL_BLACK);
	HP->label((std::to_string(player.getHP()) + "/100").c_str());
	Points->labelcolor(FL_BLACK);
	Points->label((std::string("Points: ") + std::to_string(player.getPoints())).c_str());
	gameArea->callback(gameCallback, this);

	mon=&monsters;
	play=&player;
	anim=&animations;
	opt=&options;
	hideAll();
}

DrawGameMap::~DrawGameMap()
{
	delete gameArea;
	delete HP;
	delete Points;
}

void DrawGameMap::drawMap()
{
	gameArea->image(anim->getFrame(0, opt->whichMap()));
	gameArea->redraw_label();
	/*
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
			reset(*play, *mon);
			return;
		}
		return;
	}
	//Drawing game map
	gameArea->image(anim->getFrame(0, opt->whichMap()));
	//Drawing player
	anim->getFrame(1 + (int)opt->whichGender(), (int)play->isAttack())->draw(gameArea->x() + play->getPosition(), gameArea->y()+650);
	//Drawing monsters
	std::list<Monster>::iterator it;
	if (mon->size() > 0)
	{
		for (it = mon->begin(); it != mon->end(); it++)
		{
			anim->getFrame(it->getMonsterType(), it->getMonsterFrame())->draw(it->getMonsterPositionX(), it->getMonsterPositionY());
		}
	}
	// Going to main menu if Esc was pressed
	if (Fl::event_key(FL_Escape))
	{
		reset(*play, *mon);
		return;
	}
	//Setting player attack if left mouse button was pressed
	if (FL_LEFT_MOUSE == Fl::event_button())
	{
		play->setAttack(true);
	}
	//Player is where mouse cursor is
	play->setPosition(Fl::event_x_root());
	//Going for all monsters
	for (it = mon->begin(); it != mon->end(); it++)
	{
		//Erasing monster from list if attacked
		if (play->isAttack())
		{
			if ((it->getMonsterPositionY() > 600) && (it->getMonsterPositionX() < 650))
			{
				if (((play->getPosition() - 5) < it->getMonsterPositionX()) && ((play->getPosition() + 5) > it->getMonsterPositionX()))
				{
					it = mon->erase(it);
					play->addPoint();
					continue;
				}
			}
		}
		//Monster attacked the base?
		if (it->getMonsterPositionY() > 650)
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
	play->setAttack(false);
	gameArea->redraw();
	*/
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

void DrawGameMap::reset(Player &player, std::list<Monster> &monsters)
{
	player.reset();
	monsters.clear();
	GameOver = false;
	actualTime = NULL;
}

void DrawGameMap::showAll()
{
	gameArea->show();
	HP->show();
	Points->show();
}
void DrawGameMap::hideAll()
{
	gameArea->hide();
	HP->hide();
	Points->hide();
}

void DrawGameMap::gameCallback(Fl_Widget* widget, void*p)
{
	DrawGameMap *Box = (DrawGameMap*)p;
	Box->drawMap();
}