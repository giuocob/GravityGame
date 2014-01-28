#include "Game.h"

using namespace GravityGame;
using namespace std;


Game::Game(sf::RenderWindow *gameWindow)
{
    this->window = gameWindow;

    resourceManager = new ResourceManager();
    inputManager = new InputManager();
    worldManager = new WorldManager();
    drawingManager = new DrawingManager(worldManager,resourceManager,window);
}

Game::~Game()
{
    delete resourceManager;
    delete inputManager;
    delete worldManager;
    delete drawingManager;
}

bool Game::initialize()
{
    if(!resourceManager->init()) {
        error = resourceManager->getError();
        return false;
    }
    resourceManager->debug = true;
    if(!inputManager->init()) {
        error = inputManager->getError();
        return false;
    }
    inputManager->debug = true;   //DEBUG
    if(!worldManager->init()) {
        error = worldManager->getError();
        return false;
    }
    if(!drawingManager->init()) {
        error = drawingManager->getError();
        return false;
    }
    return true;
}

bool Game::run()
{

    // Start game loop
    while (window->isOpen())
    {
        // Process events
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window->close();
        }


        //Update input state
        if(!inputManager->update()) {
            error = inputManager->getError();
            return false;
        }

        //Update just about everything
        if(!worldManager->update()) {
            error = worldManager->getError();
            return false;
        }

        //Update graphical stuff and draw the scene
        if(!drawingManager->update()) {
            error = drawingManager->getError();
            return false;
        }

    }
    return true;
}

sf::RenderWindow* Game::getWindow()
{
    return this->window;
}



Game* Game::g_game = NULL;


void runGame(Game* theGame) {
    if(!theGame->initialize()) {
        cout << "FATAL ERROR IN GRAVITYGAME" << endl << theGame->getError() << endl;
        return;
    }
    if(!theGame->run()) {
        cout << "FATAL ERROR IN GRAVITYGAME" << endl << theGame->getError() << endl;
        return;
    }
}

int main()
{
    sf::RenderWindow *gameWindow = new sf::RenderWindow(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT, 32), "Gravity");
    gameWindow->setFramerateLimit(FRAMERATE);
    gameWindow->setVerticalSyncEnabled(false);

    Game::g_game = new Game(gameWindow);
    runGame(Game::g_game);
    //Game::g_game->initialize();
    //Game::g_game->run();

    delete Game::g_game;
    delete gameWindow;
    return 0;
}