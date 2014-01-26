#ifndef ACTOR_H
#define ACTOR_H

#include <string>

#include "SFML/Graphics.hpp"
#include "world/WorldInfo.h"

namespace GravityGame {
    class Scene;


    class Actor {
    	protected:
            std::string error;
            Scene* scene;
    		double posX,posY;

        public:
            Actor(Scene* scene);   //Default values for each type of actor can be set here
            virtual ~Actor();
            virtual std::string getError();
            virtual void init();   //Called after specific values have been set
            virtual bool update();   //Update the actor per frame

            void setPosX(double x);
            void setPosY(double y);
            void setPosition(double x, double y);

    };
}

#endif // ACTOR_H
