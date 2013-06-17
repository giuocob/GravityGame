#ifndef WORLDMANAGER_H
#define WORLDMANAGER_H

#include "Manager.h"
#include "Scene.h"
#include "WorldInfo.h"
#include "ActorContainer.h"

//All actor headers go here
#include "actors/PlayerContainer.h"

//All scene headers go here
#include "scenes/TestScene.h"

namespace GravityGame {
    class WorldManager : Manager
    {
        public:
            Scene *currentScene;

            WorldManager();
            virtual ~WorldManager();
            bool init();
            bool update();
            bool addSceneActorContainers();
            ActorContainer* createActorContainer(WorldInfo::ActorId id);
    };
}

#endif // WORLDMANAGER_H