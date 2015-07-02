#include "Animations.h"
#include "DrawGameMap.h"
#include "Monster.h"
#include "Options.h"
#include "Menu.h"

int main()
{
	Player player;
	std::list<Monster> monsters;
	Options options;
	Animations animations;
	DrawGameMap gameMap;
	Menu menu;
	int gameState = 0;
	Fl_Window window(750, 800, "UNDEAD DEFENDER");
	//Loading frames
	animations.loadFrames("img/map/bg", 3);
	animations.loadFrames("img/male_player/male", 2);
	animations.loadFrames("img/female_player/female", 2);
	animations.loadFrames("img/blob/blob",2);
	animations.loadFrames("img/ghost/ghost", 4);
	animations.loadFrames("img/red_knight/red_knight", 4);
	animations.loadFrames("img/toxic_blob/toxic_blob", 2); 
	animations.loadFrames("img/zombie/zombie", 4);
	//Main program loop
	while (1)
	{
		window.begin();
		switch (gameState)
		{
		case 0:
			menu.createMenu(gameState);
			break;
		case 1:
			gameMap.drawMap(options.whichMap(), player, monsters, animations, options, gameState);
			break;
		case 2:
			options.drawOptions(gameState);
			break;
		}
		if (menu.exit()) { break; }
		window.end();
		window.redraw();
	}
	return 0;
}
