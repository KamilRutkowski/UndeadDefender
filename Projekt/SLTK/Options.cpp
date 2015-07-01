#include "Options.h"



int Options::whichMap()
{
	return ChooseMap;
}

bool Options::whichGender()
{
	return ChooseGender;
}

void drawOptions()
{
	Fl_Window window(350, 400, "Options");

	Fl_Box g(100, 50, 80, 10, "Choose gender");
	g.labelsize(20);
	Fl_Check_Button f(75, 75, 80, 30, "Female");
	Fl_Check_Button m(180, 75, 80, 30, "Male");

	Fl_Choice c(100, 150, 200, 25, "Choose map:");

	c.menu(choices);
	c.callback(wyb_cb);
	c.when(FL_WHEN_RELEASE | FL_WHEN_NOT_CHANGED);

	window.end();
	window.show();

	return Fl::run();
}

void wyb_cb(Fl_Widget*, void* v)
{
	int t = (int)v;
	if (t == 1) map = new Fl_PNG_Image(MAP1_FILE);
	else if (t == 2) map = new Fl_PNG_Image(MAP2_FILE);
	else if (t == 3) map = new Fl_PNG_Image(MAP3_FILE);
}

Fl_Menu_Item choices[] = {
	{ "&First", 0, wyb_cb, (void*)1 },
	{ "&Second", 0, wyb_cb, (void*)2 },
	{ "&Third", 0, wyb_cb, (void*)3 },
	{ 0 }
};
