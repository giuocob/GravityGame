#include "world/ActorContainer.h"

using namespace std;
using namespace GravityGame;

ActorContainer::ActorContainer()
{

}

ActorContainer::~ActorContainer()
{
    //dtor
}

//Only intended to be called during scene file reading. To add actor-specific properties,
//override the method, cast the actor to subtype, and call the base method at the end.
void ActorContainer::addActorProperty(Actor* actor, std::string property, std::string value) {
	if(!property.compare("POSX")) {
		actor->setPosX(atof(value.c_str()));
	} else if(!property.compare("POSY")) {
		actor->setPosY(atof(value.c_str()));
	} else {
		//Property is not known; ignore
	}
}