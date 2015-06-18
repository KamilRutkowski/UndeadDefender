#include <FL/Fl_PNG_Image.H>

class Animations
{
public:
	Animations(void);
	~Animations(void);
	Fl_PNG_Image getFrame(int animatedObjectType, int frame);
};
