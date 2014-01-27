#include "world/Animation.h"

using namespace GravityGame;
using namespace std;


Animation::Animation() {
	currentFrame = 0;
}

void Animation::advanceFrame() {
	currentFrame++;
	if(currentFrame >= startupAnimation.size()+loopAnimation.size()) {
		currentFrame = startupAnimation.size();
	}
}

AnimationFrame* Animation::getFrame() {
	if(currentFrame < startupAnimation.size()) {
		//Frame is in startup animation
		return &startupAnimation[currentFrame];
	} else {
		//Frame is in loop animation or index out of bounds (probably no frames)
		unsigned int adjustedFrame = currentFrame - startupAnimation.size();
		if(adjustedFrame >= loopAnimation.size()) return NULL;
		return &loopAnimation[adjustedFrame];
	}
}

void Animation::pushStartupFrame(std::string tex, double sc, bool xR, bool yR) {
	AnimationFrame frame(tex,sc,xR,yR);
	startupAnimation.push_back(frame);
}

void Animation::pushLoopFrame(std::string tex, double sc, bool xR, bool yR) {
	AnimationFrame frame(tex,sc,xR,yR);
	loopAnimation.push_back(frame);
}