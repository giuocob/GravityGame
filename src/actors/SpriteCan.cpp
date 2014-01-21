#include "actors/SpriteCan.h"
#include <iostream>

using namespace GravityGame;
using namespace std;


SpriteCanContainer::SpriteCanContainer() : ActorContainer()
{
    textureMap = { {"sprite","res/sprite2.jpg"} };
}

SpriteCanContainer::~SpriteCanContainer()
{
    //dtor
}

Actor* SpriteCanContainer::createActor()
{
    SpriteCan *ret = new SpriteCan();
    return (Actor*)ret;
}

void SpriteCanContainer::addActorProperty(Actor* actor, std::string property, std::string value) {
	SpriteCan *can = (SpriteCan*)actor;
	if(!property.compare("FLAVOR")) {
		can->setFlavor(value);
	} else {
		ActorContainer::addActorProperty((Actor*)actor,property,value);
	}
}





SpriteCan::SpriteCan() : Actor()
{
    
}

SpriteCan::~SpriteCan()
{
    //dtor
}

void SpriteCan::setFlavor(std::string flavor) {
	this->flavor = flavor;
}

void SpriteCan::print() {
	cout << "Position: (" << posX << "," << posY << "); Flavor: " << flavor << endl;
}