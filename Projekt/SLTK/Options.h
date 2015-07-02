#include <FL/Fl.H>
#include <FL/Fl_Draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Choice.H>


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

public:
	Options(void);
	~Options(void);
	int whichMap();
	bool whichGender();
	void drawOptions();
};

