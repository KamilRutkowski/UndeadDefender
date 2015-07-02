#include <FL/Fl.H>
#include <FL/Fl_Draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
<<<<<<< HEAD
#include <FL/Fl_Check_Button.H>
=======
#include <FL/Fl_Round_Button.H>
>>>>>>> 71c2b4d025f1ff1cb58bbdbff0c684d98bcd5d48
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

