#include <stdio.h>
class ConcatenateNumber {
public:
	long long getDigits(int number) {
		long long res = 1;
		for (; res <= number; res*=10);
		return res;
	}

	int getSmallest(int number, int k) {
		long long base = getDigits(number);
		long long res = 0; long long offset = 1;
		for (int copy = 1; copy <= 100005; copy++) {
			res += offset * (number%k);
			res %= k;
			offset = (offset*base) % k;
			if (res == 0) return copy;						
		}
		return -1;
	}
};
