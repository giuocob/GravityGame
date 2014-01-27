#ifndef ANIMATIONFRAME_H
#define ANIMATIONFRAME_H

#include <string>

namespace GravityGame {
	class AnimationFrame {
		//Data payload, public member
		public:
			std::string texture;        //The string representation of this texture
			double scale;               //Amount to scale the image by
			bool xReflect, yReflect;    //Whether to reflect the iamge

			AnimationFrame(std::string tex, double sc, bool xR, bool yR);
	};
}


#endif