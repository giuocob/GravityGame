#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <list>
#include <string>

#include "ThrowsError.h"
#include "world/Actor.h"
#include "world/WorldInfo.h"

namespace GravityGame {
	//EntityManager holds all actors, terrain objects, and other entities that can exist in the game world.
	//Scene is the only class that is intended to use it. It handles actor updates and deletion, and exposes
	//the iterators necessary for actors to be updated. Note that this class stores pointers to its entities,
	//and it assumes ownership of ALL entities given to it.
	//Actors are sorted by their X position for collision detection.
	class EntityManager : public ThrowsError {
		private:
			std::list<Actor*> actorList;
			std::list<Actor*> actorListUnloaded;
			std::list<Actor*> pendingActors;

			void addPending();

		public:
			EntityManager();
			~EntityManager();

			//Returns iterators to beginning and end of actor list, respectively
			std::pair<std::list<Actor*>::iterator,std::list<Actor*>::iterator> getActorIterator(); 

			void clear();
			void addActor(Actor* actor);
			void beginFrame();    //Call this before update() on each frame
			bool update();      //Call update() on all actors


	};
}


#endif