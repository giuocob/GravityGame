#include "resource/ResourceManager.h"
#include "world/WorldManager.h"

using namespace GravityGame;
using namespace std;
using namespace sf;

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

bool ResourceManager::loadSceneContent(Scene* toLoad)
{
    textureIndex.clear();
    ActorContainer *currentContainer;
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
            if(!newTexture->loadFromFile("res/images/"+imageit->second)) {
                error = "Could not load image: res/images/"+ imageit->second;
                return false;
            }
            textureIndex.insert(make_pair(imageit->first,newTexture));
            if(debug) cout << "ResourceManager: loaded " << imageit->second << endl;
        }
    }
    return true;
}

Texture* ResourceManager::getTexture(string texName) {
    map<string,Texture*>::iterator iter = textureIndex.find(texName);
    if(iter == textureIndex.end()) return NULL;
    return textureIndex[texName];
}