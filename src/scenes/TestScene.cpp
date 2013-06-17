#include "scenes/TestScene.h"
#include "Game.h"

using namespace boost::assign;
using namespace std;
using namespace GravityGame;

TestScene::TestScene()
{
    sceneActorIds = list_of
                    (WorldInfo::Player)
                    ;
}

TestScene::~TestScene()
{
    //dtor
}
