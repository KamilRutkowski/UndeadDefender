#include "DrawGameMap.h"
#include "Monster.h"
#include "Menu.h"

int main()
{
	Player player;
	std::list<Monster> monsters;
	Options options;
	Animations animations;
	DrawGameMap gameMap;
	Menu menu;
	bool firstPass = true;
	int gameState = 2;
	Fl_Double_Window window(750, 800, "UNDEAD DEFENDER");
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
	while (1)
	{
		window.begin();
		switch (gameState)
		{
		case 0:
			menu.createMenu(gameState,window);
			break;
		case 1:
			gameMap.drawMap(options.whichMap(), player, monsters, animations, options, gameState, window);
			break;
		case 2:
			options.drawOptions(gameState,window);
			break;
		}
		if (gameState == 3) { return 0; }
	}
}
