#include "scenes/TestScene.h"

using namespace std;
using namespace GravityGame;

TestScene::TestScene(ResourceManager *rm) : Scene(rm) {
    sceneFile = "testscene.grs";
}

TestScene::~TestScene()
{
    //dtor
}
