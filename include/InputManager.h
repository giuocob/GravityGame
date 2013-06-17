#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "Manager.h"
#include <vector>

namespace GravityGame {
    class InputManager : Manager
    {
        public:
            enum inputEvent {
                LEFT,
                RIGHT,
                UP,
                DOWN,
                JUMP,
                SPECIAL1,
                SPECIAL2,
                START
            };

            class KeyBinding {
                public:
                    InputManager::inputEvent event;
                    sf::Keyboard::Key key;
                    KeyBinding(inputEvent eventArg, sf::Keyboard::Key keyArg);
                    virtual ~KeyBinding();
            };

            class KeyState {
                public:
                    KeyBinding *binding;
                    bool downCurrent, downPrevious;
                    KeyState(inputEvent event, sf::Keyboard::Key keyCode);
                    KeyState(const KeyState& other);    //Copy constructor required for placement in stl::vector
                    virtual ~KeyState();
                    bool update();
                    bool down();
                    bool pressed();
            };

            std::vector<KeyState> keys;
            bool debug;

            InputManager();
            virtual ~InputManager();
            void printDebug();
            bool init();
            bool bindKey(inputEvent event, sf::Keyboard::Key keyCode);       //Create new key binding and add it to the binding list. If binding exists, replace it.
            bool update();
            KeyState* getKeyState(inputEvent event);
            bool keyPressed(inputEvent event);     //Call this from any object that wishes to receive input events
            bool keyDown(inputEvent event);        //Call this from any object that wishes to receive input events
    };
}


#endif // INPUTMANAGER_H
