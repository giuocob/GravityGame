#include "world/ActorContainer.h"
#include "world/Scene.h"

using namespace std;
using namespace GravityGame;

ActorContainer::ActorContainer(Scene* scene)
{
	this->scene = scene;
}

ActorContainer::~ActorContainer()
{
    //dtor
}

//Only intended to be called during scene file reading. To add actor-specific properties,
//override the method, cast the actor to subtype, and call the base method at the end.
void ActorContainer::addActorProperty(Actor* actor, std::string property, std::string value) {
	if(!property.compare("POSX")) {
		actor->setPosX(stof(value));
	} else if(!property.compare("POSY")) {
		actor->setPosY(stof(value));
	} else {
		//Property is not known; ignore
	}
}