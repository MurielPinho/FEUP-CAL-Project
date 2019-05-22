#include "Local.h"

Local::Local(int id, double x, double y)
{
	this->id = id;
	this->x = x;
	this->y = y;
	this->isGarage = false;
	this->isDepo = false;
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

void Local::setGarage(){
	isGarage = true;
}
void Local::setDepo(){
	isDepo = true;
}

bool Local::getGarage(){
	return isGarage;
}
bool Local::getDepo(){
	return isDepo;
}

string Local::getTag(){
	return tag;
}
