#ifndef ACTORDATA_H
#define ACTORDATA_H

#include <vector>
#include <string>

namespace GravityGame {
	class ActorData {
		public:
			std::vector<std::string> properties;
			std::vector<std::string> values;

			ActorData();
			void addData(std::string property, std::string value);
	};
}

#endif