#include "Local.h"

Local::Local(int id, double x, double y)
{
	this->id = id;
	this->x = x;
	this->y = y;
}

int Local::getId() const{
	return this->id;
}

double Local::getX() const{
	return this->x;
}

double Local::getY() const{
	return this->y;
}

void Local::setTag(string tag)
{
	this->tag = tag;
}

bool Local::operator == (const Local &p2) const{
	return this->id == p2.getId();
}
