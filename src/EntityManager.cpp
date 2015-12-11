#include "EntityManager.h"

EntityManager::EntityManager()
{
	printf("Now handling entites...\n");
	entityCount = 0;
	spriteCount = 0;
}

EntityManager::~EntityManager()
{

}

void
EntityManager::update()
{

}

/*void
EntityManager::addEntity(sf::Texture* t, int stX, int stY, int width, int height, int cnt, int currentIn, float xIn, float yIn, float xsIn, float ysIn)
{
	Entity e;
	e.sprites = new sf::Sprite[cnt];
	for(int i = 0; i < cnt; ++i)
	{
		sf::Sprite s;
		s.setTexture(*t);
		s.setTextureRect(sf::IntRect(stX + (width * i), stY, width, height));
		e.sprites[i] = s;
	}

	e.x = xIn;
	e.y = yIn;
	e.xs = xsIn;
	e.ys = ysIn;
	e.current = currentIn;
	e.max = cnt;

	entities.push_back(e);
	entityCount++;
}*/

EntityManager::SpriteSet*
EntityManager::getSpriteSet(char* search)
{
	SpriteSet* result;
	for(int i = 0; i < spriteCount; ++i)
	{
		if(strcmp(sprites[i].tag, search) == 0)
		{
			result = &sprites[i];
		}
	}

	return result;
}

void
EntityManager::generateSpriteSet(char* tagIn, sf::Texture* texture, int startX, int startY, int width, int height, int max)
{
	SpriteSet set;
	set.sprites = new sf::Sprite[max];
	set.tag = tagIn;
	set.maxSpriteIndex = max;

	for(int i = 0; i < max; ++i)
	{
		sf::Sprite sprite;
		sprite.setTexture(*texture);
		sprite.setTextureRect(sf::IntRect(startX + (width * i), startY, width, height));
		set.sprites[i] = sprite;
	}

	sprites.push_back(set);
	spriteCount++;
}

void
EntityManager::addEntity(char* spriteSetTag, int initialSpriteIndex, float xIn, float yIn)
{
	Entity e;
	e.spriteSet = getSpriteSet(spriteSetTag);
	e.x = xIn;
	e.y = yIn;
	e.currentSpriteIndex = initialSpriteIndex;
	e.dead = false;

	entities.push_back(e);
	entityCount++;
}

int
EntityManager::getEntityCount()
{
	return entityCount;
}

sf::Sprite*
EntityManager::getSpriteAtIndex(int index)
{
	Entity entity = entities[index];
	entity.spriteSet->sprites[entity.currentSpriteIndex].setPosition(entity.x, entity.y);
	return &(entity.spriteSet->sprites[entity.currentSpriteIndex]);
}

void
EntityManager::updateEntityAtIndex(int index, int frameCount)
{
	if(frameCount %4 == 0)
	{
		entities[index].currentSpriteIndex++;
		if(entities[index].currentSpriteIndex >= entities[index].spriteSet->maxSpriteIndex)
		{
			entities[index].currentSpriteIndex = 0;
		}
	}
}

bool
EntityManager::hasEntityAtIndex(int index)
{
	return (!entities[index].dead);
}

void
EntityManager::moveEntityAtIndex(int index, int xMove, int yMove)
{
	if(index >= 0)
	{
		entities[index].x += xMove;
		entities[index].y += yMove;
	} else {
		for(int i = 0; i < entityCount; ++i)
		{
			entities[i].x += xMove;
			entities[i].y += yMove;		
		}
	}		
}
