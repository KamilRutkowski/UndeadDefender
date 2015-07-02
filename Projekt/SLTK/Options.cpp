#include "Options.h"


int Options::whichMap()
{
	return ChooseMap;
}

bool Options::whichGender()
{
	return ChooseGender;
}

<<<<<<< HEAD
void Options::drawOptions()
=======
void Options ::drawOptions()
>>>>>>> 71c2b4d025f1ff1cb58bbdbff0c684d98bcd5d48
{
	Fl_Window options(400, 500, "Options");
	Fl_Color ooze_green = fl_rgb_color(255, 105, 105);
	options.color(ooze_green);

	Fl_Box logo(150, 50, 50, 50, "Options");
	logo.labelsize(50);
	logo.labelfont(FL_BOLD);
	Fl_Color bloody_red = fl_rgb_color(190, 7, 7);
	logo.labelcolor(bloody_red);

	Fl_Box gender(75, 120, 50, 50, "Choose Gender");
	gender.labelsize(20);
	gender.labelfont(FL_BOLD);

<<<<<<< HEAD
	c.menu(choices);
	c.callback(wyb_cb);
	c.when(FL_WHEN_RELEASE | FL_WHEN_NOT_CHANGED);
=======

	Fl_Round_Button *fbutton = new Fl_Round_Button(200, 120, 80, 50, "Female");
	Fl_Round_Button *mbutton = new Fl_Round_Button(280, 120, 80, 50, "Male");
	fbutton->type(FL_RADIO_BUTTON);
	mbutton->type(FL_RADIO_BUTTON);

	fbutton->callback(ChooseGender);
	mbutton->callback(ChooseGender);

	Fl_Choice maps(150, 220, 100, 25, "Choose map:");
	maps.labelsize(20);
	maps.labelfont(FL_BOLD);

	maps.menu(choices);
	maps.callback(wyb_cb);
	maps.when(FL_WHEN_RELEASE | FL_WHEN_NOT_CHANGED);

	options.end();
	options.show();
	return Fl::run();
>>>>>>> 71c2b4d025f1ff1cb58bbdbff0c684d98bcd5d48
}

void Options::wyb_cb(Fl_Widget*, void* v)
{
	int t = (int)v;
	ChooseMap = t - 1;
}

Fl_Menu_Item choices[] = {
	{ "&First", 0, wyb_cb, (void*)1 },
	{ "&Second", 0, wyb_cb, (void*)2 },
	{ "&Third", 0, wyb_cb, (void*)3 },
	{ 0 }
};
