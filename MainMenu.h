#ifndef MAINMENU_H
#define MAINMENU_H

#include <thread>
#include "JSONCardParser.h"

/*
	Handles the out-of-game menus of the game
*/
class MainMenu
{
public:
	MainMenu();
	void initiateMenus();
	void runGame();
	void runDeckBuilder();
	void runCardViewer();
	void aboutScreen();
	std::string toLowerCase(const std::string& str);

	~MainMenu();
	
private:
	std::thread* loadingThread;
	std::string userInput;
	JSONCardParser cardParser;
};
#endif
