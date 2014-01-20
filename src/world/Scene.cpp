#include "world/Scene.h"

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

Actor* Scene::createActor(WorldInfo::ActorId actorId, ActorData* actorData) {
	ActorContainer* container = sceneActors[actorId];
	//Begin here with parsing actorlist kthxcya

	return NULL;
}

