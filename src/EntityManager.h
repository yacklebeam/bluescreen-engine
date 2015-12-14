#ifndef BLUESCREEN_ENTITYMANAGER_H
#define BLUESCREEN_ENTITYMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "SpriteSet.h"
#include "Entity.h"
#include "Vector2d.h"

class EntityManager
{
private:
	int entityCount;
	int spriteCount;
	std::vector<Entity> entities;
	std::vector<SpriteSet> sprites;

	SpriteSet* getSpriteSet(char*);

public:
	EntityManager();
	~EntityManager();
	void update();
	int getEntityCount();
	sf::Sprite* getSpriteAtIndex(int);
	void updateEntityAtIndex(int);
	bool hasEntityAtIndex(int);
	void generateSpriteSet(char*, sf::Texture*, int, int, int, int, int, int, int);
	void generateSpriteSet(char*, sf::Texture*, int, int, int, int, int);
	int addEntity(char*, int, float, float, int, char*);
	void moveEntityAtIndex(int index, int xMove, int yMove);
	void setEntitySpriteAtIndex(int, char*);
	void updateEntityState(int, char*);
	void setEntityVelocity(int, float, float);
	vec2d getEntityPosition(int);
	int getOpenIndex();
};

#endif