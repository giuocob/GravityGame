#include "world/WorldManager.h"
#include "Game.h"

using namespace GravityGame;
using namespace std;

WorldManager::WorldManager()
{
    sceneLookup = { {"TestScene",WorldInfo::TestScene} };
    actorLookup = { {"Player",WorldInfo::Player},
					{"SpriteCan",WorldInfo::SpriteCan} };
}

WorldManager::~WorldManager()
{
    //dtor
}

bool WorldManager::init()
{
    //currentScene = (Scene*)(new TestScene());
    //addSceneActorContainers();
    //Game::g_game->resourceManager->loadSceneContent();
    return true;
}

bool WorldManager::update()
{
    return true;
}

Scene* WorldManager::createScene(WorldInfo::SceneId id) {
	switch(id) {
		case WorldInfo::TestScene :
			return (Scene*)(new TestScene());
		default:
			return NULL;
	}
}

ActorContainer* WorldManager::createActorContainer(WorldInfo::ActorId id) {
    switch(id) {
        case WorldInfo::Player :
            return (ActorContainer*)(new PlayerContainer());
        case WorldInfo::SpriteCan :
			return (ActorContainer*)(new SpriteCanContainer());
        default :
            return NULL;
    }
}

ActorContainer* WorldManager::createActorContainer(std::string name) {
	map<string,WorldInfo::ActorId>::iterator iter = actorLookup.find(name);
	if(iter == actorLookup.end()) return NULL;
	return createActorContainer(iter->second);
}
