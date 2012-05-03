#include <vector>
#include <algorithm>
using namespace std;

struct cmp {
	bool operator () (int lhs, int rhs) {
		if (getOnes(lhs) < getOnes(rhs)) return true;
		if (getOnes(lhs) > getOnes(rhs)) return false;
		return lhs < rhs;
	}
	int getOnes(int num) {
		int res = 0;
		for (int i = 0; i <= 30; i++)
			if (num & (1 << i)) res ++;
		return res;
	}
};

class BinaryCardinality {
public:
	vector <int> arrange(vector <int> numbers) {
		sort(numbers.begin(), numbers.end(), cmp());
		return numbers;
	}
};
