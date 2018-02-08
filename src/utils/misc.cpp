
#include "misc.hpp"
#include <ctime>

namespace Utils {
	namespace Misc {
		int randU(int limit) {
			srand(time(NULL) + rand() * rand());
			return rand() % limit;
		}

		unsigned int randUI(unsigned int limit) {
			srand(time(NULL) + rand() * rand());
			unsigned int toReturn = rand() % limit;
			return toReturn;
		}

		long hash(const std::string &) {
			return 0;
		}

	} // namespace Misc
} // namespace Utils
