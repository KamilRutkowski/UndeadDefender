#include <FL/Fl.H>
#include "Player.h"
#include <FL/Fl_Draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <string>

class Menu
{
public:
	void createMenu(int &gameMode);
	static void playGame(Fl_Widget* widget, void*p);
	static void showOptions(Fl_Widget* widget, void* p);
	static void exitGame(Fl_Widget* widget, void* p);
	Menu();
	void playGame2(Menu*);
	void showOptions2(Menu*);
	void exitGame2(Menu*);
private:
	int gamemode;
	Fl_Button* start;
};
