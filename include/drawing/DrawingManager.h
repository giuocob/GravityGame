#ifndef DRAWINGMANAGER_H
#define DRAWINGMANAGER_H


#include <iostream>
#include <string>
#include <list>

#include <SFML/Graphics.hpp>


#include "Manager.h"
#include "world/WorldManager.h"
#include "resource/ResourceManager.h"
#include "world/Scene.h"

namespace GravityGame {
	class DrawingManager : public Manager {
		private:
			WorldManager *worldManager;
			ResourceManager *resourceManager;
			sf::RenderWindow *window;

			bool draw();

		public:
			DrawingManager(WorldManager* wm, ResourceManager* rm, sf::RenderWindow* w);

			bool init();
			bool update();

	};
}


#endif