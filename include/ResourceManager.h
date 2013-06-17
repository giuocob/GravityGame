#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "Manager.h"
#include "WorldInfo.h"
#include <string>
#include <map>


namespace GravityGame {
    class ResourceManager : Manager
    {
        protected:
            std::map<std::string,sf::Texture*> textureIndex;
            std::map<std::string,sf::Sound*> soundIndex;

        public:
            bool debug;
            ResourceManager();
            virtual ~ResourceManager();
            bool init();
            bool update();
            bool loadSceneContent();
    };
}

#endif // RESOURCEMANAGER_H
