#include "world/AnimationFrame.h"

using namespace GravityGame;

AnimationFrame::AnimationFrame(std::string tex, double sc, bool xR, bool yR) {
	texture = tex;
	scale = sc;
	xReflect = xR;
	yReflect = yR;
}