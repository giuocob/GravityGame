#include "world/Actor.h"

using namespace GravityGame;

Actor::Actor() : sf::Sprite()
{
    //ctor
}

Actor::~Actor()
{
    //dtor
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