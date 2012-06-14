#include <vector>
#include <algorithm>

using namespace std;

class SymmetricPie {
public:
	int countDividingLines(vector<int> dogs) {
		int res = 0;
		for (int now = 0; now < dogs.size(); now++) {
			int cnt = dogs[now];
			for (int neighbor = (now+1)%dogs.size(); cnt < 50; neighbor = (neighbor+1)%dogs.size()) cnt += dogs[neighbor];
			if (cnt == 50) res++;
		}
		return res/2;
	}

	int getLines(vector<int> dogs) {
		sort(dogs.begin(), dogs.end());
		int res = countDividingLines(dogs);
		while(next_permutation(dogs.begin(), dogs.end()))
			res = max(res, countDividingLines(dogs));
		return res;
	}
};
