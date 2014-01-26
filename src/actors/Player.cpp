#include "actors/Player.h"

using namespace std;
using namespace GravityGame;

PlayerContainer::PlayerContainer(Scene* scene) : ActorContainer(scene)
{
    textureMap = { {"sprite","res/sprite2.jpg"} };
}

PlayerContainer::~PlayerContainer()
{
    //dtor
}

Actor* PlayerContainer::createActor()
{
    Player *ret = new Player(scene);
    return (Actor*)ret;
}



//Player implementation
Player::Player(Scene* scene) : Actor(scene)
{
    //ctor
}

Player::~Player()
{
    //dtor
}
