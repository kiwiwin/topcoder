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

class HandsShaking {
public:
	long long countPerfect(int);
	long long dp[55];
	long long DP(int n) {
		if (n == 0 || n == 2) return 1;
		if (dp[n] == 0) {
			for (int i = 1; i < n; i++) {
				if ((i-1) % 2 == 1) continue;
				dp[n] += DP(i-1) * DP(n-i-1);
			}
		}
		return dp[n];
	}
};

long long HandsShaking::countPerfect(int n) {
	memset(dp, 0, sizeof(dp));
	return DP(n);
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!