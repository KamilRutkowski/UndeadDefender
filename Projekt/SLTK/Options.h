#include <FL/Fl.H>
#include <FL/Fl_Draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Choice.H>



class Options
{

public:
	int ChooseMap;
	int ChooseGender;

public:
	int whichMap();
	bool whichGender();
	void drawOptions();
	void wyb_cb(Fl_Widget*, void* v);

};

