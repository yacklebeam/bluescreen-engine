#ifndef BLUESCREEN_ENTITY_H
#define BLUESCREEN_ENTITY_H

#include <SFML/Graphics.hpp>
#include "SpriteSet.h"
#include "Vector2d.h"

struct GameSprite
{
	vec2d offset;
	char* spriteTag;
};

struct Entity
{
	SpriteSet* spriteSet;
	char* state;
	char* transitionState;
	vec2d position;
	vec2d velocity;
	int currentSpriteIndex;
	bool dead;
	int tick;
	int updateSpeed;
	int height;
	int width;
	int hitboxIndex;
	bool dieOnComplete;
	void (*update)(int) = NULL;
};

struct Entity2
{
	std::vector<GameSprite> sprites;
	int spriteCount;
	int currentGameSprite;
	int width;
	int height;
};

#endif