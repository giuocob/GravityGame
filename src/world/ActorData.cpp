//ActorData contains information passed from a scene file to a newly constructed actor.

#include "world/ActorData.h"

using namespace GravityGame;
using namespace std;

ActorData::ActorData() {
	//Do nothing
}

void ActorData::addData(std::string property, std::string value) {
	properties.push_back(property);
	values.push_back(value);
}