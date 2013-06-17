#ifndef ACTOR_H
#define ACTOR_H

#include "SFML/Graphics.hpp"
#include "WorldInfo.h"

namespace GravityGame {
    class Actor : sf::Sprite
    {
        public:
            Actor();
            virtual ~Actor();
        protected:
        private:
    };
}

#endif // ACTOR_H
