#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class SolitaireSimulation {
public:
	map<vector<int>, int> M;

 	vector<int> makeNextHeap(const vector<int> &now) {
		vector<int> res;
		for (int i = 0; i < now.size(); i++)
			if (now[i] > 1) res.push_back(now[i]-1);
		res.push_back(now.size());
		sort(res.begin(), res.end());
		return res;
	}

	int periodLength(vector<int> heaps) {
		sort(heaps.begin(), heaps.end());
		M[heaps] = 0;
		int count = 0;
		while(true) {
			count ++;
			heaps = makeNextHeap(heaps);
			if (M.find(heaps) != M.end()) return count - M[heaps];
			M[heaps] = count;
		}
		return -1;
	}
}; 
