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
    //Delete animations
    map<string,Animation*>::iterator animIter;
    for(animIter=animationMap.begin();animIter!=animationMap.end();animIter++) {
    	delete animIter->second;
    }
    animationMap.clear();
}

AnimationFrame* Actor::getCurrentFrame() {
	return currentAnimation->getFrame();
}

bool Actor::init() {
	//By default, no initialization
	return true;
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