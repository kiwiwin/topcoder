#include <algorithm>

using namespace std;

class StreetWalking {
public:
	long long minTime(int X, int Y, int walkTime, int sneakTime) {
		if (X == Y) {
			return min(walkTime * 2, sneakTime) * ((long long)X);
		}
		else {
			if (X < Y) swap(X, Y);
			long long result = 0;
			result +=  min(walkTime * 2, sneakTime * 2) * ((long long)(X-Y)/2);
			result += walkTime * ((long long)(X-Y)%2);
			return  result + minTime(Y, Y, walkTime, sneakTime);
		}
	}
};
