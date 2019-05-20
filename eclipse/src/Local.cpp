#include "Local.h"

Local::Local(int id, double x, double y)
{
	this->id = id;
	this->x = x;
	this->y = y;
}

int Local::getId()
{
	return id;
}

double Local::getX()
{
	return x;
}

double Local::getY()
{
	return y;
}

void Local::setTag(string tag)
{
	this->tag = tag;
}
