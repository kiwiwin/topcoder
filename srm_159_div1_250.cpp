#include <cmath>

class FryingHamburgers {
public:
	int howLong(int panSize, int hamburgers) {
		if (hamburgers == 0) return 0;
		if (hamburgers <= panSize) return 10;
		return ceil(hamburgers * 2.0 / panSize) * 5;
	}
};
