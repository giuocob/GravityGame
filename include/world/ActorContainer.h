#ifndef ACTORCONTAINER_H
#define ACTORCONTAINER_H

#include <map>
#include <string>
#include "world/Actor.h"
#include "world/ActorData.h"
#include "world/WorldInfo.h"


namespace GravityGame {
    class ActorContainer
    {
        public:
            std::map<std::string,std::string> textureMap;
            std::vector<WorldInfo::ActorId> actorDependencies;
            ActorContainer();
            virtual ~ActorContainer();
            virtual Actor* createActor() =0;
            virtual void addActorProperty(Actor* actor, std::string property, std::string value);
    };
}

#endif // ACTORCONTAINER_H