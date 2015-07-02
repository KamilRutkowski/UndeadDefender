#include <FL/Fl.H>
#include <FL/Fl_Draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Double_Window.H>


class Options
{
private:
	int ChooseMap;
	bool ChooseGender;
	static void wyb_cb0(Fl_Widget*, void* v);
	static void wyb_cb1(Fl_Widget*, void* v);
	static void wyb_cb2(Fl_Widget*, void* v);
	void setMap(int map);
	static void setGenderMale(Fl_Widget*, void* v);
	static void setGenderFemale(Fl_Widget*, void* v);
	void setGender(bool gender);
	static void exitToMenu(Fl_Widget* widget, void* p);
	void exitToMenu2(Options*);
	int gamemode=2;

public:
	int whichMap();
	bool whichGender();
	int drawOptions(int &gameMode, Fl_Double_Window &window);
};

