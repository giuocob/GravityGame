#ifndef SCENE_H
#define SCENE_H

#include "ThrowsError.h"
#include "world/WorldInfo.h"
#include "world/ActorContainer.h"
#include "world/EntityManager.h"

#include <vector>
#include <map>
#include <string>

namespace GravityGame {
    class Scene : public ThrowsError
    {
        protected:
            EntityManager entityManager;
            std::string sceneFile;   //Each scene should set this

		public:
            std::map<WorldInfo::ActorId,ActorContainer*> sceneActors;
            std::vector<Actor*> actorList;
            
            Scene();
            virtual ~Scene();
            std::string getSceneFile();
            //Returns iterators to beginning and end of actor list, respectively
            std::pair<std::list<Actor*>::iterator,std::list<Actor*>::iterator> getActorIterator();

            bool update();
            void addActorContainer(ActorContainer* container, WorldInfo::ActorId actorId);
            Actor* createActor(WorldInfo::ActorId actorId);
            Actor* createActor(WorldInfo::ActorId actorId, ActorData* actorData);
    };
}

#endif // SCENE_H
