#include "world/Actor.h"
#include "world/Scene.h"

#include <iostream>

using namespace GravityGame;
using namespace std;

Actor::Actor(Scene* scene)
{
	this->scene = scene;
    posX = 0;
    posY = 0;
}

Actor::~Actor()
{
    //dtor
}

string Actor::getError() {
	return error;
}

void Actor::init() {
	//By default, no initialization
}

bool Actor::update() {
	//By default, actor does nothing
	return true;
}

void Actor::setPosX(double x) {
	posX = x;
}

void Actor::setPosY(double y) {
	posY = y;
}

void Actor::setPosition(double x, double y) {
	posX = x;
	posY = y;
}