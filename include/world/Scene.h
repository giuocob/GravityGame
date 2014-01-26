#ifndef SCENE_H
#define SCENE_H

#include "world/WorldInfo.h"
#include "world/ActorContainer.h"
#include "world/EntityManager.h"

#include <vector>
#include <map>
#include <string>

namespace GravityGame {
	class WorldManager;  //Forward for world manager
	
    class Scene
    {
        protected:
            EntityManager entityManager;

		public:
            std::string error;
            std::string sceneFile;   //Each scene should set this
            std::map<WorldInfo::ActorId,ActorContainer*> sceneActors;
            std::vector<Actor*> actorList;
            
            Scene();
            virtual ~Scene();

            bool update();
            void addActorContainer(ActorContainer* container, WorldInfo::ActorId actorId);
            Actor* createActor(WorldInfo::ActorId actorId);
            Actor* createActor(WorldInfo::ActorId actorId, ActorData* actorData);
    };
}

#endif // SCENE_H
