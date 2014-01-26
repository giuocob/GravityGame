#ifndef MANAGER_H
#define MANAGER_H

#include "ThrowsError.h"

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <string>

namespace GravityGame {
    class Manager : public ThrowsError {
        public:
            Manager();
            virtual ~Manager();
            virtual bool init() =0;
            virtual bool update() =0;
    };
}

#endif // MANAGER_H
