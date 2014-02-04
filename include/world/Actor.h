#ifndef ACTOR_H
#define ACTOR_H

#include <string>

#include "SFML/Graphics.hpp"

#include "ThrowsError.h"
#include "world/WorldInfo.h"
#include "resource/ResourceManager.h"
#include "world/Animation.h"

namespace GravityGame {
    class Scene;


    class Actor : public ThrowsError {
    	protected:
            ResourceManager* resourceManager;
            Scene* scene;

            std::map<std::string,Animation*> animationMap;
            Animation* currentAnimation;

    		double posX,posY;
            sf::Sprite sprite;


        public:
            Actor(Scene* scene);   //Default values for each type of actor can be set here
            virtual ~Actor();

            AnimationFrame* getCurrentFrame();

            virtual bool init();   //Called after specific values have been set
            virtual bool update();   //Update the actor per frame

            void setPosX(double x);
            void setPosY(double y);
            void setPosition(double x, double y);

            //Prepare the actor's sprite for drawing. Texture comes from the DrawingManager.
            virtual sf::Sprite* prepareSprite();

    };
}

#endif // ACTOR_H
