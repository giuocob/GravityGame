#include "actors/PlayerContainer.h"
#include "actors/Player.h"

using namespace std;
using namespace GravityGame;

PlayerContainer::PlayerContainer() : ActorContainer()
{
    textureMap = { {string("sprite"),string("res/sprite2.jpg")} };
}

PlayerContainer::~PlayerContainer()
{
    //dtor
}

Actor* PlayerContainer::createActor()
{
    Player *ret = new Player();
    return (Actor*)ret;
}
