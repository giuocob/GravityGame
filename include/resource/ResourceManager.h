#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>

#include "Manager.h"
#include "world/WorldInfo.h"
#include "world/Scene.h"
#include <string>
#include <map>


namespace GravityGame {
    class ResourceManager : public Manager
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
            bool loadSceneContent(Scene* toLoad);

            sf::Texture* getTexture(std::string texName);
    };
}

#endif // RESOURCEMANAGER_H
