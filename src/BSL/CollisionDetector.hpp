#ifndef BLUESCREEN_COLLISION_H
#define BLUESCREEN_COLLISION_H

#include <vector>
#include "Vector2d.h"

class CollisionDetector
{
public:
	CollisionDetector();
	~CollisionDetector();
	int registerRectHitbox(int tag, int type, float startX, float startY, int width, int height);
	bool checkCollision(int, int);
	void updateHitbox(int, int, int);
	void registerTarget(int,int,bool);
	int getHBWidth(int index)
	{
		return hitboxes[index].width;
	}
	int getHBHeight(int index)
	{
		return hitboxes[index].height;
	}
	float getHBX(int index)
	{
		return hitboxes[index].x;
	}
	float getHBY(int index)
	{
		return hitboxes[index].y;
	}
private:
	bool enableAllCollisions;
	struct Hitbox
	{
		int tag;
		int type;
		float x;
		float y;
		int width;
		int height;
	};

	struct CollisionTarget
	{
		int typeA;
		int typeB;
		bool canCollide;
	};

	std::vector<CollisionTarget> targets;
	std::vector<Hitbox> hitboxes;
	bool getCollisionTarget(int,int);
	bool pointInTarget(int, int, int, int, int, int);
};

#endif