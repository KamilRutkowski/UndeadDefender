#include "Menu.h"
#include <FL/Fl.H>
#include <FL/Fl_PNG_Image.H>

#include <string>

using namespace std;

void Menu::createMenu(int &gameMode)
{	
	
	Fl_Window menu(740, 620, "Menu");
	Fl_Color ooze_green = fl_rgb_color(255, 105, 105);
	menu.color( ooze_green );

	Fl_Box logo(35, 30, 646, 104, "UNDEAD DEFENDER");
	logo.labelsize( 65 );
	logo.labelfont( FL_BOLD );
	logo.labeltype( FL_SHADOW_LABEL );	Fl_Color bloody_red = fl_rgb_color(190, 7, 7);	logo.labelcolor(bloody_red);
	Fl_Button start(30, 140, 646, 100, "START");
	start.labelsize( 50 );
	start.labelfont( FL_BOLD );
	start.labelcolor(FL_WHITE);
	start.box( FL_UP_BOX );

	Fl_Button options(30, 360, 646, 100, "OPTIONS");
	options.labelsize(50);
	options.labelfont( FL_BOLD );
	options.labelcolor(FL_WHITE);
	options.box( FL_UP_BOX );
	
	Fl_Button exit(30, 470, 646, 100, "EXIT");
	exit.labelsize(50);
	exit.labelfont( FL_BOLD );
	exit.labelcolor(FL_WHITE);
	exit.box( FL_UP_BOX );	
	
	menu.end();
	menu.show();
	return Fl::run();;
}
