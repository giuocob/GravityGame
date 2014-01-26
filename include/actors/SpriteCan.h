#ifndef SPRITECAN_H
#define SPRITECAN_H

#include "world/Actor.h"
#include "world/ActorContainer.h"
#include <string>

namespace GravityGame {
	class SpriteCanContainer : public ActorContainer
    {
        public:
            SpriteCanContainer(Scene* scene);
            virtual ~SpriteCanContainer();
            Actor* createActor();
            virtual void addActorProperty(Actor* actor, std::string property, std::string value);
    };
    
    class SpriteCan : public Actor
    {
        private:
            std::string flavor;
        public:
            SpriteCan(Scene* scene);
            virtual ~SpriteCan();
            void init();
            virtual bool update();
            void setFlavor(std::string flavor);
            void print();
    };
}
#endif
