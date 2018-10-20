#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::update()
{

}

void GameObject::draw()
{

}

Vec2 GameObject::getPosition()
{
	return position;
}

AABB GameObject::getBoundingBox()
{
	return box;
}

void GameObject::setPosition(Vec2 newPos)
{
	position = newPos;
}

void GameObject::setBoundingBox(AABB newBox)
{
	box = newBox;
}
