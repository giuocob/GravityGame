#ifndef THROWSERROR_H
#define THROWSERROR_H

#include <string>

namespace GravityGame {
	class ThrowsError {
		protected:
			std::string error;

		public:
			virtual std::string getError();
	};
}

#endif