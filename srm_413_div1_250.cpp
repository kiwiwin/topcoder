#include <vector>

using namespace std;

/*
	seq[i] + 1 is unreachable, that is to say the value region is [small, big)
*/

class ArithmeticProgression {
public:
	double minCommonDifference(int a0, vector<int> seq) {
		double MIN = 0, MAX = 10000000;
		for (int i = 0; i < seq.size(); i++) {
			double small = 1.0*(seq[i]-a0)/(i+1);
			double big = 1.0*(seq[i]+1-a0)/(i+1);
			
			MIN = max(small, MIN);
			MAX = min(big, MAX);
			if (MIN >= MAX) return -1;
		}
		
		return MIN;
	}
};
