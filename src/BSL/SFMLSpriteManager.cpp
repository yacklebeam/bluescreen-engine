#include "SFMLSpriteManager.hpp"

SFMLSpriteManager::SFMLSpriteManager()
{

}

SFMLSpriteManager::~SFMLSpriteManager()
{

}

void
SFMLSpriteManager::generateSpriteSet(char* tagIn, sf::Texture* texture, int x, int y, int width, int height, int col, int row, int max)
{
	SpriteSet set;
	set.sprites = new sf::Sprite[max];
	set.tag = tagIn;
	set.maxSpriteIndex = max;
	set.height = height;
	set.width = width;

	for(int r = 0; r < row; ++r)
	{
		for(int c = 0; c < col; ++c)
		{
			int curIndex = (r * col) + c;
			if(curIndex < max)
			{
				sf::Sprite sprite;
				sprite.setTexture(*texture);
				sprite.setTextureRect(sf::IntRect(x + (width * c), y + (height * r), width, height));
				set.sprites[curIndex] = sprite;
			}
		}
	}

	sprites.push_back(set);
}

void
SFMLSpriteManager::generateSpriteSet(char* tagIn, sf::Texture* texture, int x, int y, int width, int height, int max)
{
	generateSpriteSet(tagIn, texture, x, y, width, height, 1, 1, max);
}

sf::Sprite*
SFMLSpriteManager::getSprite(char* search, int spriteIndex)
{
	for(int i = 0; i < sprites.size(); ++i)
	{
		if(strcmp(sprites[i].tag, search) == 0)
		{
			if(spriteIndex < sprites[i].maxSpriteIndex)
			{
				return &sprites[i].sprites[spriteIndex];
			}
			else
			{
				return NULL;
			}
		}
	}
	return NULL;
}