#ifndef TROXEL_GAMEWINDOW_H
#define TROXEL_GAMEWINDOW_H

#include <SFML/Window.hpp>

class GameWindow: public sf::RenderWindow
{
public:
	GameWindow();
	GameWindow(int width, int height, char* name);
	~GameWindow();
};

#endif