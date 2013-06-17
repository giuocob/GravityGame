#ifndef SCENE_H
#define SCENE_H

#include "WorldInfo.h"
#include "ActorContainer.h"
#include <vector>
#include <map>
#include <boost/assign/list_of.hpp>

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
