#include "world/Scene.h"
#include <iostream>

using namespace GravityGame;
using namespace std;

Scene::Scene()
{
    actorListReady = false;
    loadErr = false;
}

Scene::~Scene()
{
    //dtor
}

void Scene::addActorContainer(ActorContainer* container, WorldInfo::ActorId actorId) {
	sceneActors[actorId] = container;
}

Actor* Scene::createActor(WorldInfo::ActorId actorId) {
	ActorContainer *container = sceneActors[actorId];
	return container->createActor();
}

Actor* Scene::createActor(WorldInfo::ActorId actorId, ActorData* actorData) {
	ActorContainer* container = sceneActors[actorId];
	Actor *actor = container->createActor();
	while(actorData->properties.size() > 0) {
		string property = actorData->properties.back();
		actorData->properties.pop_back();
		string value = actorData->values.back();
		actorData->values.pop_back();
		container->addActorProperty(actor,property,value);
	}
	return actor;
}
