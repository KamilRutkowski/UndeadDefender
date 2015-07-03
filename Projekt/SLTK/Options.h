#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Double_Window.H>
#include "Menu.h"

class Menu;

class Options
{
private:
	int ChooseMap=0;
	bool ChooseGender=false;
	static void wyb_cb0(Fl_Widget*, void* v);
	static void wyb_cb1(Fl_Widget*, void* v);
	static void wyb_cb2(Fl_Widget*, void* v);
	void setMap(int map);
	static void setGenderMale(Fl_Widget*, void* v);
	static void setGenderFemale(Fl_Widget*, void* v);
	void setGender(bool gender);
	static void exitToMenu(Fl_Widget* widget, void* p);
	void exitToMenu2();
	Menu *men;
	bool firstPass = true;

	Fl_Box *logo;
	Fl_Box *gender;
	Fl_Round_Button *fbutton;
	Fl_Round_Button *mbutton;
	Fl_Choice *maps;
	Fl_Button *exit;
	Fl_Menu_Item choices[4];

public:
	int& whichMap();
	bool& whichGender();
	void drawOptions(Menu &menu);
	void showAll();
	void hideAll();
};

