#include "CollisionDetector.hpp"

CollisionDetector::CollisionDetector()
{
	enableAllCollisions = false;
}

CollisionDetector::~CollisionDetector()
{

}

int
CollisionDetector::registerRectHitbox(int tagIn, int typeIn, float startX, float startY, int width, int height)
{
	Hitbox h = {tagIn, typeIn, startX, startY, width, height};

	hitboxes.push_back(h);
	return hitboxes.size() - 1;
}

bool
CollisionDetector::getCollisionTarget(int typeAIn, int typeBIn)
{
	if(typeAIn == typeBIn)
	{
		return false;
	}
	for(int i = 0; i < targets.size(); ++i)
	{
		if(targets[i].typeA == typeAIn && targets[i].typeB == typeBIn)
		{
			return targets[i].canCollide;
		}

		if(targets[i].typeA == typeBIn && targets[i].typeB == typeAIn)
		{
			return targets[i].canCollide;
		}
	}
	return false;
}

void
CollisionDetector::registerTarget(int A, int B, bool canCollideIn)
{
	CollisionTarget ct = {A, B, canCollideIn};
	targets.push_back(ct);
}

bool
CollisionDetector::pointInTarget(int X, int Y, int tX, int tY, int width, int height)
{
	if(X >= tX && X <= tX + width && Y >= tY && Y <= tY + height)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool
CollisionDetector::checkCollision(int indexA, int indexB)
{
	if(indexA == -1 || indexB == -1) return false;
	if(!enableAllCollisions && !getCollisionTarget(hitboxes[indexA].type, hitboxes[indexB].type))
	{
		//use targets on, and target is false
		return false;
	}
	else //everything collides, so check it...or target was true
	{
		Hitbox A = hitboxes[indexA];
		Hitbox B = hitboxes[indexB];
		
		if(	pointInTarget(A.x, A.y, B.x, B.y, B.width, B.height) || 
			pointInTarget(A.x + A.width, A.y, B.x, B.y, B.width, B.height) || 
			pointInTarget(A.x, A.y + A.height, B.x, B.y, B.width, B.height) || 
			pointInTarget(A.x + A.width, A.y + A.height, B.x, B.y, B.width, B.height))
		{
			return true;
		}

		return false;
	}
}

void
CollisionDetector::updateHitbox(int index, int xDelta, int yDelta)
{
	hitboxes[index].x = xDelta;
	hitboxes[index].y = yDelta;
}