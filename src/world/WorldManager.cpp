#include "world/WorldManager.h"
#include "Game.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace GravityGame;
using namespace std;

WorldManager::WorldManager()
{
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

bool WorldManager::init()
{
    loadScene(sceneLookup["TestScene"]);
    cout << error << endl;
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
    ifstream sceneFile(std::string("scenefiles/")+scene->sceneFile);
    if(!sceneFile.is_open()) {
        error = "Could not open scene file: " + scene->sceneFile;
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
        ActorContainer* container = createActorContainer(actorLookup[line]);
        scene->addActorContainer(container,actorLookup[line]);
        getline(sceneFile,line);
    }
    getline(sceneFile,line);   //ACTOR
    //Create actors
    getline(sceneFile,line);
    while(line.compare(SF_DELIMITER)) {
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
        scene->createActor(actorId,actorData);
        getline(sceneFile,line);
    }




    sceneFile.close();
    return scene;


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
