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

struct P {
	int x, y, c;
	P(int x_, int y_, int c_) : x(x_),  y(y_), c(c_) {}
	bool operator < (const struct P & obj) const {
		return y < obj.y;
	}
	
	bool canJumpTo(const struct P &dest, int v, int g) {
		if (dest.y >= y) return false;
		long long vdis = y - dest.y;
		long long hdis = abs(dest.x - x);
		
		return vdis * 2 * v * v >= hdis * hdis * g;
	}
};

class PlatformJumper {
public:
	int maxCoins(vector <string>, int, int);
};

int PlatformJumper::maxCoins(vector <string> platforms, int v, int g) {
	vector<P> vp;
	for (int i = 0; i < platforms.size(); i++) {
		int x, y, z;
		sscanf(platforms[i].c_str(), "%d %d %d", &x, &y, &z);
		P p(x,y,z);
		vp.push_back(p);
	}
	
	sort(vp.begin(), vp.end());
	
	int dp[55];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < vp.size(); i++) {
		dp[i] = vp[i].c;
		int temp = 0;
		for (int j = 0; j < i; j++) {
			if (vp[i].canJumpTo(vp[j], v, g)) {
				temp = max(temp, dp[j]);
			}
		}
		dp[i] += temp;
	}
	
	int res = 0;
	for (int i = 0; i < vp.size(); i++) res = max(res, dp[i]);
	return res;
}


//Powered by [KawigiEdit] 2.0!
