#include "Object.h"

Object::Object(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Object::update()
{

}

void Object::draw()
{
	if (sprite != NULL) { sprite->draw(x, y); }
}