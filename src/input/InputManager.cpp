#include "input/InputManager.h"
#include "Game.h"
#include <iostream>

using namespace GravityGame;
using namespace sf;

InputManager::InputManager() : Manager()
{
    keys = std::vector<KeyState>();
    debug = false;
}

InputManager::~InputManager()
{
    keys.clear();
}

bool InputManager::init()
{
    //Bind default keys. This will likely be from a config file later
    bindKey(LEFT,Keyboard::Left);
    bindKey(RIGHT,Keyboard::Right);
    bindKey(UP,Keyboard::Up);
    bindKey(DOWN,Keyboard::Down);
    bindKey(JUMP,Keyboard::LShift);
    bindKey(SPECIAL1,Keyboard::Z);
    bindKey(SPECIAL2,Keyboard::X);
    bindKey(START,Keyboard::Return);
    return true;
}

void InputManager::printDebug()
{
        if(keyPressed(InputManager::LEFT))
        {
            std::cout << "LEFT" << std::endl;
        }
        if(keyPressed(InputManager::RIGHT))
        {
            std::cout << "RIGHT" << std::endl;
        }
        if(keyPressed(InputManager::UP))
        {
            std::cout << "UP" << std::endl;
        }
        if(keyPressed(InputManager::DOWN))
        {
            std::cout << "DOWN" << std::endl;
        }
        if(keyPressed(InputManager::JUMP))
        {
            std::cout << "JUMP" << std::endl;
        }
        if(keyPressed(InputManager::SPECIAL1))
        {
            std::cout << "SPECIAL1" << std::endl;
        }
        if(keyPressed(InputManager::SPECIAL2))
        {
            std::cout << "SPECIAL2" << std::endl;
        }
        if(keyPressed(InputManager::START))
        {
            std::cout << "START" << std::endl;
        }
}

bool InputManager::bindKey(inputEvent event, Keyboard::Key keyCode)
{
    //Delete KeyState for this event if it exists
    for(std::vector<KeyState>::size_type i = 0; i < keys.size(); i++)
    {
        if(keys[i].binding->event == event)
        {
            keys.erase(keys.begin()+i);
        }
    }

    //Add KeyState
    KeyState state(event,keyCode);
    keys.push_back(state);
    return true;
}

bool InputManager::update()
{
    for(std::vector<KeyState>::size_type i = 0; i < keys.size(); i++)
    {
        keys[i].update();
    }
    if(debug) printDebug();
    return true;
}

InputManager::KeyState* InputManager::getKeyState(InputManager::inputEvent event)
{
    for(std::vector<KeyState>::size_type i = 0; i < keys.size(); i++)
    {
        if(keys[i].binding->event == event)
        {
            KeyState *ret = &keys[i];
            return ret;
        }
    }
    KeyState *ret = NULL;
    return ret;
}

bool InputManager::keyPressed(InputManager::inputEvent event)
{
    KeyState *state = getKeyState(event);
    if(state == NULL) return false;
    return state->pressed();
}

bool InputManager::keyDown(InputManager::inputEvent event)
{
    KeyState *state = getKeyState(event);
    if(state == NULL) return false;
    return state->down();
}



//KeyBinding implementation
InputManager::KeyBinding::KeyBinding(inputEvent eventArg, Keyboard::Key keyArg) : event(eventArg), key(keyArg)
{

}

InputManager::KeyBinding::~KeyBinding()
{

}


//KeyState implementation
InputManager::KeyState::KeyState(inputEvent event, Keyboard::Key keyCode)
{
    binding = new KeyBinding(event,keyCode);
    downCurrent = false;
    downPrevious = false;
}

InputManager::KeyState::KeyState(const KeyState& other)
{
    downCurrent = other.downCurrent;
    downPrevious = other.downPrevious;
    const KeyBinding &otherBinding = *(other.binding);
    binding = new KeyBinding(otherBinding);
}

InputManager::KeyState::~KeyState()
{
    delete binding;
}

bool InputManager::KeyState::update()
{
    downPrevious = downCurrent;
    downCurrent = Keyboard::isKeyPressed(this->binding->key);
    return true;
}

bool InputManager::KeyState::down()
{
    return downCurrent;
}

bool InputManager::KeyState::pressed()
{
    return (downCurrent && !downPrevious);
}

