#ifndef ACTOR_H
#define ACTOR_H

#include <string>

#include "SFML/Graphics.hpp"

#include "ThrowsError.h"
#include "world/WorldInfo.h"

namespace GravityGame {
    class Scene;


    class Actor : public ThrowsError {
    	protected:
            Scene* scene;
    		double posX,posY;

        public:
            Actor(Scene* scene);   //Default values for each type of actor can be set here
            virtual ~Actor();
            virtual bool init();   //Called after specific values have been set
            virtual bool update();   //Update the actor per frame

            void setPosX(double x);
            void setPosY(double y);
            void setPosition(double x, double y);

    };
}

#endif // ACTOR_H
