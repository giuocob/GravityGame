#include "scenes/TestScene.h"
#include "Game.h"

using namespace std;
using namespace GravityGame;

TestScene::TestScene()
{
    sceneActorIds = { WorldInfo::Player };
}

TestScene::~TestScene()
{
    //dtor
}
