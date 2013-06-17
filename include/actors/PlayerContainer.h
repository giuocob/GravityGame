#ifndef PLAYERCONTAINER_H
#define PLAYERCONTAINER_H

#include "ActorContainer.h"
#include "Player.h"

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
