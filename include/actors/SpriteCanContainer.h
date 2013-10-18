#ifndef SPRITECANCONTAINER_H
#define SPRITECANCONTAINER_H

#include "world/ActorContainer.h"
#include "actors/SpriteCan.h"

namespace GravityGame {
    class SpriteCanContainer : public ActorContainer
    {
        public:
            SpriteCanContainer();
            virtual ~SpriteCanContainer();
            Actor* createActor();
    };
}

#endif // SPRITECANCONTAINER_H
