#ifndef PLAYERCONTAINER_H
#define PLAYERCONTAINER_H

#include "world/ActorContainer.h"
#include "actors/Player.h"

namespace GravityGame {
    class PlayerContainer : ActorContainer
    {
        public:
            PlayerContainer();
            virtual ~PlayerContainer();
            Actor* createActor();
        protected:
        private:
    };
}

#endif // PLAYERCONTAINER_H
