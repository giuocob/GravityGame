#include "actors/SpriteCan.h"
#include <iostream>

using namespace GravityGame;
using namespace std;


SpriteCanContainer::SpriteCanContainer(Scene* scene) : ActorContainer(scene)
{
    textureMap = { {"sprite","test/sprite2.png"},
    				{"redsprite","test/sprite2_red.png"}
    				 };
}

SpriteCanContainer::~SpriteCanContainer()
{
    //dtor
}

Actor* SpriteCanContainer::createActor()
{
    SpriteCan *ret = new SpriteCan(scene);
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





SpriteCan::SpriteCan(Scene* scene) : Actor(scene)
{

}

SpriteCan::~SpriteCan()
{
    //dtor
}

bool SpriteCan::init() {
	//Initialize animations
	Animation *spriteAnim = new Animation();
	for(int i=0;i<10;i++) {
		spriteAnim->pushLoopFrame(string("sprite"));
	}
	for(int i=0;i<10;i++) {
		spriteAnim->pushLoopFrame(string("redsprite"));
	}
	animationMap["anim"] = spriteAnim;
	currentAnimation = spriteAnim;
	return true;
}


bool SpriteCan::update() {
	currentAnimation->advanceFrame();
	std::string texture = currentAnimation->getFrame()->texture;
	return true;
}

void SpriteCan::setFlavor(std::string flavor) {
	this->flavor = flavor;
}

void SpriteCan::print() {
	cout << "Sprite can! Position: (" << posX << "," << posY << "); Flavor: " << flavor << endl;
}