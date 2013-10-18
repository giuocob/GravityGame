#include "Game.h"

using namespace GravityGame;

namespace GravityGame {

Game::Game(sf::RenderWindow *gameWindow)
{
    this->window = gameWindow;

    resourceManager = new ResourceManager();
    inputManager = new InputManager();
    worldManager = new WorldManager();
}

Game::~Game()
{
    //dtor
}

bool Game::initialize()
{
    resourceManager->init();
    resourceManager->debug = true;
    inputManager->init();
    inputManager->debug = true;   //DEBUG
    worldManager->init();
    return true;
}

bool Game::run()
{
    //Image
    sf::Texture pony;
    pony.loadFromFile("res/sprite2.jpg");
    sf::Sprite ponysprite(pony);
    
    ActorContainer *container = new SpriteCanContainer();
    Actor *sprite = container->createActor();

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

        // Clear the screen (fill it with black color)
        window->clear();

        // Display window contents on screen
        ponysprite.rotate(1);
        window->draw(ponysprite);
        window->display();

        //InputManager debug
        inputManager->update();

    }
    return true;
}

sf::RenderWindow* Game::getWindow()
{
    return this->window;
}

}


Game* Game::g_game = NULL;
int main()
{
    sf::RenderWindow *gameWindow = new sf::RenderWindow(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT, 32), "Gravity");
    gameWindow->setFramerateLimit(FRAMERATE);
    gameWindow->setVerticalSyncEnabled(false);

    Game::g_game = new Game(gameWindow);
    Game::g_game->initialize();
    Game::g_game->run();

    delete Game::g_game;
    delete gameWindow;
    return 0;
}
