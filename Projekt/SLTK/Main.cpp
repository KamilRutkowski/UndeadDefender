#include "DrawGameMap.h"
#include "Monster.h"
#include "Menu.h"

int main()
{
	Player player;
	std::list<Monster> monsters;
	Options options;
	Animations animations;
	DrawGameMap gameMap(player, monsters, animations, options);
	Menu menu;
	Fl_Double_Window window(750, 800, "UNDEAD DEFENDER");
	fl_register_images();
	//Loading frames
	animations.loadFrames("../img/map/bg", 3);
	animations.loadFrames("../img/male_player/male", 2);
	animations.loadFrames("../img/female_player/female", 2);
	animations.loadFrames("../img/blob/blob",2);
	animations.loadFrames("../img/ghost/ghost", 4);
	animations.loadFrames("../img/red_knight/red_knight", 4);
	animations.loadFrames("../img/toxic_blob/toxic_blob", 2); 
	animations.loadFrames("../img/zombie/zombie", 4);
	//Main program loop
	window.begin();
	menu.createMenu(options,gameMap);
	options.drawOptions(menu);
	options.hideAll();
	window.end();
	window.show();
	
	return Fl::run();
}

