#ifndef WORLDMANAGER_H
#define WORLDMANAGER_H

#include "Manager.h"
#include "world/Scene.h"
#include "world/WorldInfo.h"
#include "world/ActorContainer.h"

//All actor headers go here
#include "actors/PlayerContainer.h"
#include "actors/SpriteCanContainer.h"

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
