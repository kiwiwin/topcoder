#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class RandomSort {
public: 
	map<vector<int>, double> M;
	vector<int> dest;
	
	int countSwapPairs(const vector<int> &vi) {
		int res = 0;
		for (int i = 0; i < vi.size(); i++)
		for (int j = i+1; j < vi.size(); j++)
			if (vi[i] > vi[j]) res++;
		return res;
	}

	double solve(const vector<int> &now) {
		if (M.count(now) > 0) return M[now];
		
		int cnt = countSwapPairs(now);
		if (cnt == 0) return 0;
		
		double res = 0.0;
		for (int i = 0; i < now.size(); i++)
		for (int j = i+1; j < now.size(); j++) {
			if (now[i] < now[j]) continue;
			
			vector<int> temp = now;
			swap(temp[i], temp[j]);
			res += solve(temp) + 1;
		}
	
		M[now] = res/cnt;
		return M[now];
	}

	double getExpected(vector<int> perm) {
		for (int i = 0; i < dest.size(); i++) dest.push_back(i+1);
		M[dest] = 0.0;
		
		return solve(perm);
	}
};
