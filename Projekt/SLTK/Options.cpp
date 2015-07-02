#include "Options.h"


int Options::whichMap()
{
	return ChooseMap;
}

bool Options::whichGender()
{
	return ChooseGender;
}

int Options::drawOptions(int &gameMode, Fl_Double_Window &window)
{
	Fl_Color ooze_green = fl_rgb_color(255, 105, 105);
	window.color(ooze_green);

	Fl_Box logo(150, 50, 50, 50, "Options");
	logo.labelsize(50);
	logo.labelfont(FL_BOLD);
	Fl_Color bloody_red = fl_rgb_color(190, 7, 7);
	logo.labelcolor(bloody_red);

	Fl_Box gender(75, 120, 50, 50, "Choose Gender");
	gender.labelsize(20);
	gender.labelfont(FL_BOLD);

	Fl_Menu_Item choices[] = {
			{ "&First", 0, wyb_cb0, (void*)this },
			{ "&Second", 0, wyb_cb1, (void*)this },
			{ "&Third", 0, wyb_cb2, (void*)this },
			{ 0 }
	};

	Fl_Round_Button fbutton(200, 120, 80, 50, "Female");
	Fl_Round_Button mbutton(280, 120, 80, 50, "Male");
	fbutton.type(FL_RADIO_BUTTON);
	mbutton.type(FL_RADIO_BUTTON);

	fbutton.callback(setGenderFemale,this);
	mbutton.callback(setGenderMale,this);

	Fl_Choice maps(150, 220, 100, 25, "Choose map:");
	maps.labelsize(20);
	maps.labelfont(FL_BOLD);
	maps.menu(choices);
	maps.when(FL_WHEN_RELEASE | FL_WHEN_NOT_CHANGED);

	Fl_Button exit(30, 470, 646, 100, "EXIT");
	exit.labelsize(50);
	exit.labelfont(FL_BOLD);
	exit.labelcolor(FL_WHITE);
	exit.box(FL_UP_BOX);
	exit.callback(exitToMenu, this);
	gameMode = gamemode;
	window.end();
	window.show();
	return Fl::run();
}

void Options::wyb_cb0(Fl_Widget*, void* v)
{
	Options* T = (Options*)v;
	T->setMap(0);
}

void Options::wyb_cb1(Fl_Widget*, void* v)
{
	Options* T = (Options*)v;
	T->setMap(1);
}

void Options::wyb_cb2(Fl_Widget*, void* v)
{
	Options* T = (Options*)v;
	T->setMap(2);
}

void Options::setMap(int map)
{
	ChooseMap = map;
}

void Options::setGenderMale(Fl_Widget*, void* v)
{
	Options* T = (Options*)v;
	T->setGender(false);
}

void Options::setGenderFemale(Fl_Widget*, void* v)
{
	Options* T = (Options*)v;
	T->setGender(true);
}

void Options::setGender(bool gender)
{
	ChooseGender = gender;
}

void Options::exitToMenu(Fl_Widget* widget, void*p)
{
	Options* T = (Options*)p;
	T->exitToMenu2((Options*)p);
}

void Options::exitToMenu2(Options*)
{
	gamemode = 0;
}
