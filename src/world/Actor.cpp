#include "world/Actor.h"
#include "world/Scene.h"

#include <iostream>

using namespace GravityGame;
using namespace std;
using namespace sf;

Actor::Actor(Scene* scene)
{
	this->scene = scene;
	this->resourceManager = scene->getResourceManager();
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

void Actor::setPosX(float x) {
	posX = x;
}

void Actor::setPosY(float y) {
	posY = y;
}

void Actor::setPosition(float x, float y) {
	posX = x;
	posY = y;
}

Sprite* Actor::prepareSprite() {
	string texName = getCurrentFrame()->texture;
	Texture *texture = resourceManager->getTexture(texName);
	if(texture == NULL) {
		error = "Actor: texture " + texName + " not found in texture index";
		return NULL;
	}
	sprite.setTexture(*texture);
	sprite.setPosition(posX,posY);

	return &sprite;
}