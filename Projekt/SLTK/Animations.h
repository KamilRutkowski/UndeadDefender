#include <FL/Fl_PNG_Image.H>
#include <iostream>
#include <vector>
#include <string>
#include "Options.h"


using namespace std;

#define  FEMALE_FILE			"female.png"     
#define  MALE_FILE				"male.png"
#define  MAP1_FILE				"map1.png"
#define	 MAP2_FILE				"map2.png"
#define	 MAP3_FILE				"map3.png"


class Animations
{
public:
	vector<vector<Fl_PNG_Image>> vec;
	int frames;

public:
	Animations(void);
	~Animations(void);
	Fl_PNG_Image  getFrame(int animatedObjectType, int frame);
	int loadFrames(string name, int numberOfFrames);
	int howManyFrames();
};
