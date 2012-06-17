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

class ForbiddenStrings {
public:
	long long countNotForbidden(int);
	// A is 0, B is 1, C is 2
	long long dp[35][3][3];
	bool vis[35][3][3];
	
	long long solve(int L, int X, int Y) {
		if (L <= 2) return 1;
		
		if (vis[L][X][Y]) return dp[L][X][Y];
		vis[L][X][Y] = true;
		dp[L][X][Y] = 0;
		for (int Z = 0; Z < 3; Z++) {
			if (X != Y && Y != Z && Z != X) continue;
			dp[L][X][Y] += solve(L-1, Y, Z);
		}
		return dp[L][X][Y];
	}
};

long long ForbiddenStrings::countNotForbidden(int n) {
	memset(vis, false, sizeof(vis));
	if (n == 1) return 3;
	if (n == 2) return 9;
	
	long long res = 0;
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
		res += solve(n, i, j);
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!