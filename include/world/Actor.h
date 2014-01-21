#ifndef ACTOR_H
#define ACTOR_H

#include "SFML/Graphics.hpp"
#include "world/WorldInfo.h"

namespace GravityGame {
    class Actor : sf::Sprite
    {
    	protected:
    		double posX,posY;

        public:
            Actor();
            virtual ~Actor();

            void setPosX(double x);
            void setPosY(double y);
            void setPosition(double x, double y);

    };
}

#endif // ACTOR_H
