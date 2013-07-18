#include "world/WorldManager.h"
#include "Game.h"

using namespace GravityGame;
using namespace std;

WorldManager::WorldManager()
{
    //ctor
}

WorldManager::~WorldManager()
{
    //dtor
}

bool WorldManager::init()
{
    currentScene = (Scene*)(new TestScene());
    addSceneActorContainers();
    Game::g_game->resourceManager->loadSceneContent();
    return true;
}

bool WorldManager::update()
{
    return true;
}

bool WorldManager::addSceneActorContainers()
{
    for(vector<WorldInfo::ActorId>::size_type i = 0; i < currentScene->sceneActorIds.size(); i++)
    {
        ActorContainer *container = createActorContainer(currentScene->sceneActorIds[i]);
        currentScene->sceneActors.insert(make_pair(currentScene->sceneActorIds[i],container));
    }
    currentScene->actorListReady = true;
    return true;
}

ActorContainer* WorldManager::createActorContainer(WorldInfo::ActorId id)
{
    switch(id) {
        case WorldInfo::Player :
            return (ActorContainer*)(new PlayerContainer());
        default :
            return NULL;
    }
}
