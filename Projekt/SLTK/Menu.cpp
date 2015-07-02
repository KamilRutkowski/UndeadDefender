#include "Menu.h"

void Menu::createMenu(int &gameMode)
{	
	if (firstPass)
	{
		logo = new Fl_Box(35, 30, 646, 104, "UNDEAD DEFENDER");
		logo->labelsize(65);
		logo->labelfont(FL_BOLD);
		logo->labeltype(FL_SHADOW_LABEL);		Fl_Color bloody_red = fl_rgb_color(190, 7, 7);		logo->labelcolor(bloody_red);

		start = new Fl_Button(30, 170, 646, 100, "START");
		start->labelsize(50);
		start->labelfont(FL_BOLD);
		start->labelcolor(FL_WHITE);
		start->box(FL_UP_BOX);
		start->callback(playGame, this);

		options = new Fl_Button(30, 300, 646, 100, "OPTIONS");
		options->labelsize(50);
		options->labelfont(FL_BOLD);
		options->labelcolor(FL_WHITE);
		options->box(FL_UP_BOX);
		options->callback(showOptions, this);

		exit = new Fl_Button(30, 430, 646, 100, "EXIT");
		exit->labelsize(50);
		exit->labelfont(FL_BOLD);
		exit->labelcolor(FL_WHITE);
		exit->box(FL_UP_BOX);
		exit->callback(exitGame, this);
		gamemode = &gameMode;
	}
}

void Menu::playGame(Fl_Widget* widget, void*p)
{
	Menu* T=(Menu*)p;
	T->playGame2((Menu*)p);
}

void Menu::playGame2(Menu*p)
{
	*gamemode = 1;
	logo->hide();
	start->hide();
	options->hide();
	exit->hide();
}

void Menu::showOptions(Fl_Widget* widget, void*p)
{
	Menu* T=(Menu*)p;
	T->showOptions2((Menu*)p);
}

void Menu::showOptions2(Menu*p)
{
	*gamemode = 2;
	logo->hide();
	start->hide();
	options->hide();
	exit->hide();
}

void Menu::exitGame(Fl_Widget* widget, void*p)
{
	Menu* T=(Menu*)p;
	T->exitGame2((Menu*)p);
}

void Menu::exitGame2(Menu*p)
{
	*gamemode = 3;
}
