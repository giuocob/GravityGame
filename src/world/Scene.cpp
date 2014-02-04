#include "world/Scene.h"
#include <iostream>

using namespace GravityGame;
using namespace std;

Scene::Scene(ResourceManager* rm)
{
	this->resourceManager = rm;
}

Scene::~Scene()
{
    //dtor
}

string Scene::getSceneFile() {
	return sceneFile;
}

ResourceManager* Scene::getResourceManager() {
	return resourceManager;
}

std::pair<std::list<Actor*>::iterator,std::list<Actor*>::iterator> Scene::getActorIterator() {
	return entityManager.getActorIterator();
}



bool Scene::update() {
	if(!entityManager.update()) {
		error = entityManager.getError();
		return false;
	}
	return true;
}

void Scene::addActorContainer(ActorContainer* container, WorldInfo::ActorId actorId) {
	sceneActors[actorId] = container;
}

Actor* Scene::createActor(WorldInfo::ActorId actorId) {
	map<WorldInfo::ActorId,ActorContainer*>::iterator iter = sceneActors.find(actorId);
	if(iter == sceneActors.end()) {
		error = "Scene: requested actor container was not found for this scene";
		return NULL;
	}
	ActorContainer *container = iter->second;
	Actor *actor = container->createActor();
	if(!actor->init()) {
		error = actor->getError();
		return NULL;
	}
	return actor;
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
	actor->init();
	entityManager.addActor(actor);
	return actor;
}
