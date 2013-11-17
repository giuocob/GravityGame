#include "world/Scene.h"

using namespace GravityGame;
using namespace std;

Scene::Scene()
{
    actorListReady = false;
    loadErr = false;
}

Scene::~Scene()
{
    //dtor
}
