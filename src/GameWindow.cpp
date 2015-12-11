#include "GameWindow.h"

GameWindow::GameWindow()
{
	
}

GameWindow::GameWindow(int width, int height, char* name)
{
	create(sf::VideoMode(width, height), name);
	setVerticalSyncEnabled(true);
	//setFramerateLimit(60);
}

GameWindow::~GameWindow()
{
	
}