#ifndef SPRITECAN_H
#define SPRITECAN_H

#include "world/Actor.h"
#include "world/ActorContainer.h"
#include <string>

namespace GravityGame {
	class SpriteCanContainer : public ActorContainer
    {
        public:
            SpriteCanContainer();
            virtual ~SpriteCanContainer();
            Actor* createActor();
            virtual void addActorProperty(Actor* actor, std::string property, std::string value);
    };
    
    class SpriteCan : public Actor
    {
        private:
            std::string flavor;
        public:
            SpriteCan();
            virtual ~SpriteCan();
            void setFlavor(std::string flavor);
            void print();
    };
}
#endif
