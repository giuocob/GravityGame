#ifndef MANAGER_H
#define MANAGER_H

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <string>

namespace GravityGame {
    class Manager
    {
        public:
            std::string *error;

            Manager();
            virtual ~Manager();
            virtual bool init() =0;
            virtual bool update() =0;
    };
}

#endif // MANAGER_H
