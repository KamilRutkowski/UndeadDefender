#include "Options.h"


int& Options::whichMap()
{
	return ChooseMap;
}

bool& Options::whichGender()
{
	return ChooseGender;
}

void Options::drawOptions( Menu &menu)
{
	if (firstPass)
	{
		logo = new Fl_Box(350, 50, 50, 50, "Options");
		logo->labelsize(50);
		logo->labelfont(FL_BOLD);
		logo->labelcolor(fl_rgb_color(190, 7, 7));

		gender = new Fl_Box(290, 120, 50, 50, "Choose Gender:");
		gender->labelsize(20);
		gender->labelfont(FL_BOLD);

		choices[0] = { "&First", 0, wyb_cb0, (void*)this };
		choices[1] = { "&Second", 0, wyb_cb1, (void*)this };
		choices[2] = { "&Third", 0, wyb_cb2, (void*)this };
		choices[3] = { 0 };

		fbutton = new Fl_Round_Button(400, 120, 80, 50, "Female");
		mbutton = new Fl_Round_Button(480, 120, 80, 50, "Male");
		fbutton->type(FL_RADIO_BUTTON);
		mbutton->type(FL_RADIO_BUTTON);

		fbutton->callback(setGenderFemale, this);
		mbutton->callback(setGenderMale, this);

		maps = new Fl_Choice(390, 220, 100, 25, "Choose map:");
		maps->labelsize(20);
		maps->labelfont(FL_BOLD);
		maps->menu(choices);
		maps->when(FL_WHEN_RELEASE | FL_WHEN_NOT_CHANGED);

		exit = new Fl_Button(275, 300, 200, 100, "EXIT");
		exit->labelsize(20);
		exit->labelfont(FL_BOLD);
		exit->box(FL_UP_BOX);
		exit->callback(exitToMenu, this);
		men = &menu;
	}
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
	T->ChooseGender = false;
}

void Options::setGenderFemale(Fl_Widget*, void* v)
{
	Options* T = (Options*)v;
	T->ChooseGender = true;
}

void Options::exitToMenu(Fl_Widget* widget, void*p)
{
	Options* T = (Options*)p;
	T->hideAll();
	T->men->showAll();
}

void Options::showAll()
{
	logo->show();
	gender->show();
	fbutton->show();
	mbutton->show();
	maps->show();
	exit->show();
}

void Options::hideAll()
{
	logo->hide();
	gender->hide();
	fbutton->hide();
	mbutton->hide();
	maps->hide();
	exit->hide();
}