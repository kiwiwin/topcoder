#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class KingdomAndTrees {
public:
	int minLevel(vector <int>);
	vector<int> H;
	bool check(int x) {
		vector<int> tmp = H;
		tmp[0] = max(1, tmp[0] - x);
		for (int i = 1; i < tmp.size(); i++) {
			if (tmp[i-1]+1 > tmp[i]+x) return false;
			tmp[i] = max(tmp[i-1]+1, tmp[i]-x);
		}
		return true;
	}
	
	int solve(long long l, long long r) {
		if (l == r) return l;
		long long mid = (l+r)/2;
		if (check(mid)) {
			return solve(l, mid);
		} else {
			return solve(mid+1, r);
		}
	}
};

int KingdomAndTrees::minLevel(vector <int> heights) {
	H = heights;
	return solve(0, 1000000000);
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!