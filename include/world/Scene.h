#ifndef SCENE_H
#define SCENE_H

#include "world/WorldInfo.h"
#include "world/ActorContainer.h"
#include <vector>
#include <map>

namespace GravityGame {
    class Scene
    {
        public:
            bool actorListReady;
            std::vector<WorldInfo::ActorId> sceneActorIds;
            std::map<WorldInfo::ActorId,ActorContainer*> sceneActors;

            Scene();
            virtual ~Scene();
        protected:
        private:
    };
}

#endif // SCENE_H
