#include <FL/Fl.H>
#include <FL/Fl_Draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_BMP_Image.H>

class Options: public Fl_Box
{

public:
	int ChooseMap;
	int ChooseGender;

public:
	int whichMap();
	bool whichGender();

};
