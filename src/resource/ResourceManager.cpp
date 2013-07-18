#include "resource/ResourceManager.h"
#include "Game.h"

using namespace GravityGame;
using namespace std;

ResourceManager::ResourceManager() : Manager()
{
    debug = false;
    textureIndex = map<std::string,sf::Texture*>();
    soundIndex = map<std::string,sf::Sound*>();
}

ResourceManager::~ResourceManager()
{
    //dtor
}

bool ResourceManager::init()
{
    return true;
}

bool ResourceManager::update()
{
    return true;
}

bool ResourceManager::loadSceneContent()
{
    textureIndex.clear();
    Scene *toLoad = Game::g_game->worldManager->currentScene;
    ActorContainer *currentContainer;
    if(!toLoad->actorListReady) return false;
    //Nested loop: iterate over all images in all actorContainers in the scene
    map<WorldInfo::ActorId,ActorContainer*>::iterator actorit;
    map<string,string>::iterator imageit;
    for(actorit = toLoad->sceneActors.begin(); actorit != toLoad->sceneActors.end(); actorit++)
    {
        currentContainer = actorit->second;
        for(imageit = currentContainer->textureMap.begin(); imageit != currentContainer->textureMap.end(); imageit++)
        {
            if(textureIndex.count(imageit->first) != 0) continue;
            sf::Texture *newTexture = new sf::Texture();
            newTexture->loadFromFile(imageit->second);
            textureIndex.insert(make_pair(imageit->first,newTexture));
            if(debug) cout << "ResourceManager: loaded " << imageit->second << endl;
        }
    }
    return true;
}
