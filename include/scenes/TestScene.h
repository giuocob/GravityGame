#ifndef TESTSCENE_H
#define TESTSCENE_H


#include "world/Scene.h"

namespace GravityGame {
    class TestScene : public Scene
    {
        public:
            TestScene(ResourceManager *rm);
            virtual ~TestScene();
        protected:
        private:
    };
}

#endif // TESTSCENE_H
