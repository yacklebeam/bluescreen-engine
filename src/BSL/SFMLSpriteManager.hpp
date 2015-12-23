#ifndef BLUESCREEN_SPRITEMANAGER_H
#define BLUESCREEN_SPRITEMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>

struct SpriteSet
{
	char* tag;
	sf::Sprite* sprites;
	int maxSpriteIndex;
	int height;
	int width;
};

class SFMLSpriteManager
{
public:
	SFMLSpriteManager();
	~SFMLSpriteManager();
	void generateSpriteSet(char*, sf::Texture*, int, int, int, int, int, int, int);
	void generateSpriteSet(char*, sf::Texture*, int, int, int, int, int);
	sf::Sprite* getSprite(char*, int);
private:
	std::vector<SpriteSet> sprites;
};

#endif