#include "GameWindow.hpp"

GameWindow::GameWindow()
{
	
}

GameWindow::GameWindow(int width, int height, char* name)
{
	create(sf::VideoMode(width, height), name, sf::Style::Titlebar|sf::Style::Close);
	setVerticalSyncEnabled(true);
	isFull = false;
	defaultWidth = width;
	defaultHeight = height;
	titleBarName = name;
	//setFramerateLimit(60);
}

GameWindow::~GameWindow()
{
	
}

void
GameWindow::makeFullscreen()
{
	sf::VideoMode fullscreenMode = sf::VideoMode::getDesktopMode();
	create(fullscreenMode, titleBarName, sf::Style::Fullscreen);
	setVerticalSyncEnabled(true);
	isFull = true;
}

void
GameWindow::makeDefaultSize()
{
	create(sf::VideoMode(defaultWidth, defaultHeight), titleBarName, sf::Style::Titlebar|sf::Style::Close);
	setVerticalSyncEnabled(true);
	isFull = false;
}

bool
GameWindow::isFullscreen()
{
	return isFull;
}