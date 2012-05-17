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

class ChangingSounds {
public:
	int maxFinal(vector <int>, int, int);
	bool dp[51][1001];
	int maxLevel;
	bool checkBoundary(int level) {
		return level >= 0 && level <= maxLevel;
	}
};

int ChangingSounds::maxFinal(vector <int> inter, int bl, int ml) {
	memset(dp, 0, sizeof(dp));
	maxLevel = ml;

	dp[0][bl] = true;
	for (int i = 1; i <= inter.size(); i++) {
		bool flag = false;
		for (int l = 0; l <= ml; l++) {
			if (!dp[i-1][l]) continue;
			if (checkBoundary(inter[i-1]+l)) { flag = true; dp[i][inter[i-1]+l] = true; }
			if (checkBoundary(-inter[i-1]+l)) { flag = true; dp[i][-inter[i-1]+l] = true; } 
		}
		if (!flag) return -1;
	}

	int res = 0;
	for (int l = 0; l <= ml; l++) if (dp[inter.size()][l]) res = l;
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!