#include "actors/SpriteCan.h"
#include <iostream>

using namespace GravityGame;
using namespace std;


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



SpriteCan::SpriteCan() : Actor()
{
    cout << "SPRITE CAN OMG" << endl;
}

SpriteCan::~SpriteCan()
{
    //dtor
}
