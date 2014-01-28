#include "world/EntityManager.h"
#include <iostream>

using namespace GravityGame;
using namespace std;

EntityManager::EntityManager() {
	//Nothing for now
}

EntityManager::~EntityManager() {
	//Ensure that all actors are properly disposed of
	clear();
}

std::pair<std::list<Actor*>::iterator,std::list<Actor*>::iterator> EntityManager::getActorIterator() {
	return make_pair(actorList.begin(),actorList.end());
}


void EntityManager::addPending() {
	while(!pendingActors.empty()) {
		actorList.push_front(pendingActors.front());
		pendingActors.pop_front();
	}
}

void EntityManager::clear() {
	list<list<Actor*>> listsToClear = {actorList, actorListUnloaded, pendingActors};
	list<list<Actor*>>::iterator iter;
	for(iter=listsToClear.begin();iter!=listsToClear.end();iter++) {
		while(!iter->empty()) {
			Actor* toDelete = iter->front();
			delete toDelete;
			iter->pop_front();
		}
	}
}

void EntityManager::addActor(Actor* actor) {
	pendingActors.push_front(actor);
}

bool EntityManager::update() {
	addPending();

	list<Actor*>::iterator iter;
	for(iter=actorList.begin();iter!=actorList.end();iter++) {
		Actor* actor = *iter;
		if(!actor->update()) {
			error = actor->getError();
			return false;
		}
	}
	return true;
}