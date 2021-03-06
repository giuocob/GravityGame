#include "world/WorldManager.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace GravityGame;
using namespace std;

WorldManager::WorldManager(ResourceManager *rm, InputManager *im)
{
    resourceManager = rm;
    inputManager = im;

    sceneLookup = { {"TestScene",WorldInfo::TestScene} };
    actorLookup = { {"Player",WorldInfo::Player},
					{"SpriteCan",WorldInfo::SpriteCan} };

    SF_FIRSTLINE = "GRSCENE";
    SF_DELIMITER = "&&&&";
}

WorldManager::~WorldManager()
{
    //dtor
}

Scene* WorldManager::getCurrentScene() {
    return currentScene;
}

bool WorldManager::init()
{
    if((currentScene = loadScene(sceneLookup["TestScene"])) == NULL) return false;
    if(!resourceManager->loadSceneContent(currentScene)) {
        error = resourceManager->getError();
        return false;
    }
    return true;
}

bool WorldManager::update()
{
    if(!currentScene->update()) {
        error = currentScene->getError();
        return false;
    }
    return true;
}

Scene* WorldManager::createScene(WorldInfo::SceneId id) {
	switch(id) {
		case WorldInfo::TestScene :
			return (Scene*)(new TestScene(resourceManager));
		default:
			return NULL;
	}
}

//Load a scene and all its contents.
Scene* WorldManager::loadScene(WorldInfo::SceneId id) {
    //Construct the scene
    Scene* scene = createScene(id);
    if(scene == NULL) {
        error = "Invalid scene ID";
        return NULL;
    }
    //Open scene file and begin parsing
    string line;
    ifstream sceneFile(std::string("scenefiles/")+scene->getSceneFile());
    if(!sceneFile.is_open()) {
        error = "Could not open scene file: " + scene->getSceneFile();
        return NULL;
    }
    getline(sceneFile,line);
    if(line.compare(SF_FIRSTLINE)) {
        error = "Supplied file is not a scene file";
        return NULL;
    }
    getline(sceneFile,line);   //Name of scene, ignore for now
    getline(sceneFile,line);   //Delimiter
    getline(sceneFile,line);   //ALIST
    //Populate actor containers in scene
    getline(sceneFile,line);
    while(line.compare(SF_DELIMITER)) {
        ActorContainer* container;
        if((container = createActorContainer(line,scene)) == NULL) return NULL;
        scene->addActorContainer(container,actorLookup[line]);
        getline(sceneFile,line);
    }
    getline(sceneFile,line);   //ACTOR
    //Create actors
    getline(sceneFile,line);
    while(line.compare(SF_DELIMITER)) {
        map<std::string,WorldInfo::ActorId>::iterator actorIter = actorLookup.find(line);
        if(actorIter == actorLookup.end()) {
            string sceneFilename = scene->getSceneFile();
            error = "WorldManager: invalid actorId in scenefile " + sceneFilename + ": " + line; 
            return NULL;
        }
        WorldInfo::ActorId actorId = actorLookup[line];
        ActorData *actorData = new ActorData();
        //Populate actorData until next delimiter
        getline(sceneFile,line);
        while(line.compare(SF_DELIMITER)) {
            //Use istringstream to split line around the '='
            std::istringstream iss(line);
            std::string segment1, segment2;
            getline(iss,segment1,'=');
            getline(iss,segment2);
            actorData->addData(segment1,segment2);
            getline(sceneFile,line);
        }
        if(scene->createActor(actorId,actorData) == NULL) {
            error = scene->getError();
            return NULL;
        }
        getline(sceneFile,line);
    }




    sceneFile.close();
    return scene;


}

ActorContainer* WorldManager::createActorContainer(WorldInfo::ActorId id, Scene* scene) {
    switch(id) {
        case WorldInfo::Player :
            return (ActorContainer*)(new PlayerContainer(scene));
        case WorldInfo::SpriteCan :
			return (ActorContainer*)(new SpriteCanContainer(scene));
        default :
            error = "WorldManager: internal unhandled actorId";
            return NULL;
    }
}

ActorContainer* WorldManager::createActorContainer(std::string name, Scene* scene) {
	map<string,WorldInfo::ActorId>::iterator iter = actorLookup.find(name);
	if(iter == actorLookup.end()) {
        error = "WorldManager: invalid actorId";
        return NULL;
    }
	return createActorContainer(iter->second,scene);
}
