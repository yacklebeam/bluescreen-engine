#ifndef BLUESCREEN_SPRITESET
#define BLUESCREEN_SPRITESET

#include <SFML/Graphics.hpp>

struct SpriteSet
{
	char* tag;
	sf::Sprite* sprites;
	int maxSpriteIndex;
	int height;
	int width;
};

#endif