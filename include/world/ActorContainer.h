#ifndef ACTORCONTAINER_H
#define ACTORCONTAINER_H

#include <map>
#include <string>
#include "world/Actor.h"


namespace GravityGame {
    class ActorContainer
    {
        public:
            std::map<std::string,std::string> textureMap;
            ActorContainer();
            virtual ~ActorContainer();
            virtual Actor* createActor() =0;
    };
}

#endif // ACTORCONTAINER_H
