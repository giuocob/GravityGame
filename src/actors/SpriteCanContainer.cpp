#include "actors/SpriteCanContainer.h"

using namespace std;
using namespace GravityGame;

SpriteCanContainer::SpriteCanContainer() : ActorContainer()
{
    textureMap = { {"sprite","res/sprite2.jpg"} };
}

SpriteCanContainer::~SpriteCanContainer()
{
    //dtor
}

Actor* SpriteCanContainer::createActor()
{
    SpriteCan *ret = new SpriteCan();
    return (Actor*)ret;
}
