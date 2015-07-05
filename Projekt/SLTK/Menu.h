#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Window.H>
#include <string>
#include "Options.h"
#include "DrawGameMap.h"

class Options;
class DrawGameMap;

class Menu
{
public:
	void createMenu(Options &option, DrawGameMap &gameMap);
	static void playGame(Fl_Widget* widget, void*p);
	static void showOptions(Fl_Widget* widget, void* p);
	static void exitGame(Fl_Widget* widget, void* p);
	
	void showAll();
	void hideAll();
private:
	Options* opt;
	DrawGameMap* game;
	bool firstPass=true;
	Fl_Button* start;
	Fl_Button* options;
	Fl_Button* exit;
	Fl_Box* logo;
};
