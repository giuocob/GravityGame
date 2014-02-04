#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include <iostream>

#include "resource/ResourceManager.h"
#include "input/InputManager.h"
#include "world/WorldManager.h"
#include "drawing/DrawingManager.h"

#define GAME_WIDTH 800
#define GAME_HEIGHT 600
#define FRAMERATE 60

namespace GravityGame {
    class Game : public ThrowsError
    {
        private:
            sf::RenderWindow *window;

        public:
            ResourceManager *resourceManager;
            InputManager *inputManager;
            WorldManager *worldManager;
            DrawingManager *drawingManager;

            Game(sf::RenderWindow *gameWindow);
            virtual ~Game();
            bool initialize();
            bool run();
            sf::RenderWindow* getWindow();
    };
}



#endif // GAME_H


