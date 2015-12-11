#ifndef TROXEL_ENTITYMANAGER_H
#define TROXEL_ENTITYMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>

class EntityManager
{
private:
	struct SpriteSet
	{
		char* tag;
		sf::Sprite* sprites;
		int maxSpriteIndex;
	};
	struct Entity
	{
		SpriteSet* spriteSet;
		int x;
		int y;
		int currentSpriteIndex;
		bool dead;
	};
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
	void updateEntityAtIndex(int, int);
	bool hasEntityAtIndex(int);
	void generateSpriteSet(char*, sf::Texture*, int, int, int, int, int);
	void addEntity(char*, int, float, float);
	void moveEntityAtIndex(int index, int xMove, int yMove);
};

#endif