#ifndef PLAYER_H
#define PLAYER_H

#include "world/ActorContainer.h"
#include "world/Actor.h"

namespace GravityGame {
	class PlayerContainer : ActorContainer
    {
        public:
            PlayerContainer(Scene* scene);
            virtual ~PlayerContainer();
            Actor* createActor();
        protected:
        private:
    };
    
    class Player : Actor
    {
        public:
            Player(Scene* scene);
            virtual ~Player();
        protected:
        private:
    };
}
#endif // PLAYER_H
