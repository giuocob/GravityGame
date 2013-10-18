#ifndef SPRITECAN_H
#define SPRITECAN_H

#include "world/Actor.h"
#include "world/ActorContainer.h"

namespace GravityGame {
	class SpriteCanContainer : public ActorContainer
    {
        public:
            SpriteCanContainer();
            virtual ~SpriteCanContainer();
            Actor* createActor();
    };
    
    class SpriteCan : Actor
    {
        public:
            SpriteCan();
            virtual ~SpriteCan();
    };
}
#endif
