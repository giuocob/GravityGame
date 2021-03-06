#ifndef WORLDMANAGER_H
#define WORLDMANAGER_H

#include "Manager.h"
#include "resource/ResourceManager.h"
#include "input/InputManager.h"
#include "world/Scene.h"
#include "world/WorldInfo.h"
#include "world/ActorContainer.h"

#include <map>
#include <string>

//All actor headers go here
#include "actors/Player.h"
#include "actors/SpriteCan.h"

//All scene headers go here
#include "scenes/TestScene.h"

namespace GravityGame {
    class WorldManager : public Manager
    {
		private:
            ResourceManager *resourceManager;
            InputManager *inputManager;

			std::map<std::string,WorldInfo::SceneId> sceneLookup;
			std::map<std::string,WorldInfo::ActorId> actorLookup;

            std::string SF_FIRSTLINE,SF_DELIMITER;

		
        public:
            Scene *currentScene;

            WorldManager(ResourceManager *rm, InputManager *im);
            virtual ~WorldManager();

            Scene* getCurrentScene();

            bool init();
            bool update();
            Scene* createScene(WorldInfo::SceneId id);
            Scene* loadScene(WorldInfo::SceneId id);
            ActorContainer* createActorContainer(WorldInfo::ActorId id, Scene* scene);
            ActorContainer* createActorContainer(std::string name, Scene* scene);
    };
}

#endif // WORLDMANAGER_H
