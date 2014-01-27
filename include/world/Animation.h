#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
#include <vector>
#include <iostream>

#include "world/AnimationFrame.h"

namespace GravityGame {
	class Animation {
		private:
			unsigned int currentFrame;
			std::vector<AnimationFrame> startupAnimation, loopAnimation;

		public:
			Animation();
			void advanceFrame();
			AnimationFrame* getFrame();
			void pushStartupFrame(std::string tex, double sc=1, bool xR=false, bool yR=false);
			void pushLoopFrame(std::string tex, double sc=1, bool xR=false, bool yR=false);
	};
}

#endif