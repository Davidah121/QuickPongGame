#pragma once
#include "Vec2.h"
#include "AABB.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void update();
	virtual void draw();

	Vec2 getPosition();
	AABB getBoundingBox();

	void setPosition(Vec2 newPos);
	void setBoundingBox(AABB newBox);

protected:
	Vec2 position = Vec2();
	AABB box = AABB();
};

