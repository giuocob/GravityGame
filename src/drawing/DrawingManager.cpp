#include "drawing/DrawingManager.h"

using namespace GravityGame;
using namespace std;
using namespace sf;


DrawingManager::DrawingManager(WorldManager* wm, ResourceManager* rm, RenderWindow* w) {
	worldManager = wm;
	resourceManager = rm;
	window = w;
}

bool DrawingManager::draw() {
	window->clear();
	Scene *scene = worldManager->getCurrentScene();
	if(scene == NULL) return true;
	pair<list<Actor*>::iterator,list<Actor*>::iterator> beginAndEnd = scene->getActorIterator();
	list<Actor*>::iterator iter;
	for(iter=beginAndEnd.first;iter!=beginAndEnd.second;iter++) {
		Sprite *sprite = (*iter)->prepareSprite();
		if(sprite == NULL) {
			error = (*iter)->getError();
			return false;
		}
		/*string frameName = (*iter)->getCurrentFrame()->texture;
		Texture *texture = resourceManager->getTexture(frameName);
		if(texture == NULL) {
			error = "DrawingManager: texture " + frameName + " not found in texture index";
			return false;
		}
		Sprite sprite(*texture);*/
		window->draw(*sprite);
	}

	window->display();
	return true;
}





bool DrawingManager::init() {
	//Do nothing for now
	return true;
}

bool DrawingManager::update() {
	//Just draw for now
	return draw();
}