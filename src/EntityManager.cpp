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

SpriteSet*
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
EntityManager::generateSpriteSet(char* tagIn, sf::Texture* texture, int startX, int startY, int spriteWidth, int spriteHeight, int col, int row, int max)
{
	SpriteSet set;
	set.sprites = new sf::Sprite[max];
	set.tag = tagIn;
	set.maxSpriteIndex = max;
	set.height = spriteHeight;
	set.width = spriteWidth;

	for(int r = 0; r < row; ++r)
	{
		for(int c = 0; c < col; ++c)
		{
			int curIndex = (r * col) + c;
			if(curIndex < max)
			{
				sf::Sprite sprite;
				sprite.setTexture(*texture);
				sprite.setTextureRect(sf::IntRect(startX + (spriteWidth * c), startY + (spriteHeight * r), spriteWidth, spriteHeight));
				set.sprites[curIndex] = sprite;
			}
		}
	}

	sprites.push_back(set);
	spriteCount++;
}

void
EntityManager::generateSpriteSet(char* tagIn, sf::Texture* texture, int startX, int startY, int spriteWidth, int spriteHeight, int max)
{
	SpriteSet set;
	set.sprites = new sf::Sprite[max];
	set.tag = tagIn;
	set.maxSpriteIndex = max;
	set.height = spriteHeight;
	set.width = spriteWidth;

	for(int i = 0; i < max; ++i)
	{
		sf::Sprite sprite;
		sprite.setTexture(*texture);
		sprite.setTextureRect(sf::IntRect(startX + (spriteWidth * i), startY, spriteWidth, spriteHeight));
		set.sprites[i] = sprite;
	}

	sprites.push_back(set);
	spriteCount++;
}

int
EntityManager::addEntity(char* spriteSetTag, int initialSpriteIndex, float xIn, float yIn, int tickSpeed, char* startingState)
{
	Entity e;
	e.spriteSet = getSpriteSet(spriteSetTag);
	e.position.x = xIn;
	e.position.y = yIn;
	e.currentSpriteIndex = initialSpriteIndex;
	e.dead = false;
	e.updateSpeed = tickSpeed;
	e.state = startingState;
	e.transitionState = startingState;
	e.tick = 0;
	e.velocity.x = 0;
	e.velocity.y = 0;
	e.width = e.spriteSet->width;
	e.height = e.spriteSet->height;

	int openIndex = getOpenIndex();
	if(openIndex == entityCount)
	{
		entities.push_back(e);
		entityCount++;
		return entityCount - 1;
	}
	else
	{
		entities[openIndex] = e;
		return openIndex;
	}
}

void
EntityManager::setEntityVelocity(int index, float xv, float yv)
{
	entities[index].velocity.x = xv;
	entities[index].velocity.y = yv;
}

void
EntityManager::setEntitySpriteAtIndex(int index, char* tag)
{
	char* curTag = entities[index].spriteSet->tag;
	if(strcmp(curTag, tag) != 0)
	{
		entities[index].spriteSet = getSpriteSet(tag);
		entities[index].currentSpriteIndex = 0;
	}
}

void
EntityManager::updateEntityState(int index, char* newState)
{
		entities[index].transitionState = newState;
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
	entity.spriteSet->sprites[entity.currentSpriteIndex].setPosition(entity.position.x, entity.position.y);
	return &(entity.spriteSet->sprites[entity.currentSpriteIndex]);
}

void
EntityManager::updateEntityAtIndex(int index)
{
	if(strcmp(entities[index].state, entities[index].transitionState) != 0)
	{
		entities[index].state = entities[index].transitionState;
		entities[index].spriteSet = getSpriteSet(entities[index].state);
		entities[index].currentSpriteIndex = 0;
	}
	if(entities[index].tick == entities[index].updateSpeed)
	{
		entities[index].tick = 0;
		entities[index].currentSpriteIndex++;
		if(entities[index].currentSpriteIndex >= entities[index].spriteSet->maxSpriteIndex)
		{
			entities[index].currentSpriteIndex = 0;
		}
	} else {
		entities[index].tick++;
	}

	//always do these things
	entities[index].position.x += entities[index].velocity.x;
	entities[index].position.y += entities[index].velocity.y;
	if(	entities[index].position.x < 0 - entities[index].width ||
		entities[index].position.x > 600 ||
		entities[index].position.y < 0 - entities[index].height ||
		entities[index].position.y > 600)
	{
		entities[index].dead = true;
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
		entities[index].position.x += xMove;
		entities[index].position.y += yMove;
	} else {
		for(int i = 0; i < entityCount; ++i)
		{
			entities[i].position.x += xMove;
			entities[i].position.y += yMove;		
		}
	}		
}

vec2d
EntityManager::getEntityPosition(int index)
{
	return entities[index].position;
}

int
EntityManager::getOpenIndex()
{
	for(int i = 0; i < entityCount; ++i)
	{
		if(entities[i].dead) return i;
	}
	return entityCount;
}