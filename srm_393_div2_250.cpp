#include <vector>

using namespace std;

class VariableSpeedLimit {
public:
	double journeyTime(int journeyLength, vector<int> speedLimit) {
		double res = 0; int index = 0;
		while(journeyLength > 0) {
			if (journeyLength > speedLimit[index]) { res += 1; journeyLength -= speedLimit[index]; }
			else { res += journeyLength * 1.0 / speedLimit[index]; journeyLength = 0; }
			index = (index + 1) % speedLimit.size();
		}
		return res;
	}
};
