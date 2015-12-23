#ifndef BLUESCREEN_GAMEWINDOW_H
#define BLUESCREEN_GAMEWINDOW_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class GameWindow: public sf::RenderWindow
{
public:
	GameWindow();
	GameWindow(int width, int height, char* name);
	~GameWindow();
	void makeFullscreen();
	void makeDefaultSize();
	bool isFullscreen();
private:
	bool isFull;
	int defaultWidth;
	int defaultHeight;
	char* titleBarName;
};

#endif