#include "Menu.h"

int Menu::createMenu(int &gameMode, Fl_Double_Window &window)
{	
	Fl_Box logo(35, 30, 646, 104, "UNDEAD DEFENDER");
	logo.labelsize( 65 );
	logo.labelfont( FL_BOLD );
	logo.labeltype( FL_SHADOW_LABEL );	Fl_Color bloody_red = fl_rgb_color(190, 7, 7);	logo.labelcolor(bloody_red);	
	
	Fl_Button start(30, 140, 646, 100, "START");
	start.labelsize(50);
	start.labelfont(FL_BOLD);
	start.labelcolor(FL_WHITE);
	start.box(FL_UP_BOX);
	start.callback(playGame, this);

	Fl_Button options(30, 360, 646, 100, "OPTIONS");
	options.labelsize(50);
	options.labelfont( FL_BOLD );
	options.labelcolor(FL_WHITE);
	options.box( FL_UP_BOX );
	options.callback(showOptions, this);
	
	Fl_Button exit(30, 470, 646, 100, "EXIT");
	exit.labelsize(50);
	exit.labelfont( FL_BOLD );
	exit.labelcolor(FL_WHITE);
	exit.box( FL_UP_BOX );
	exit.callback(exitGame, this);
	gameMode = gamemode;
	window.end();
	window.show();
	return Fl::run();
}

void Menu::playGame(Fl_Widget* widget, void*p)
{
	Menu* T=(Menu*)p;
	T->playGame2((Menu*)p);
}

void Menu::playGame2(Menu*)
{
	gamemode = 1;
}

void Menu::showOptions(Fl_Widget* widget, void*p)
{
	Menu* T=(Menu*)p;
	T->showOptions2((Menu*)p);
}

void Menu::showOptions2(Menu*)
{
	gamemode = 2;
}

void Menu::exitGame(Fl_Widget* widget, void*p)
{
	Menu* T=(Menu*)p;
	T->exitGame2((Menu*)p);
}

void Menu::exitGame2(Menu*)
{
	gamemode = 3;
}
