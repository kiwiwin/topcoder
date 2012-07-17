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

class LampsGrid {
public:
	int mostLit(vector <string>, int);
	int LitRows(string row, int count, int K) {
		int zeroCount = 0;
		for (int i = 0; i < row.size(); i++) if (row[i] == '0') zeroCount ++;
		if (zeroCount > K) return 0;
		if ((K-zeroCount) % 2 == 1) return 0;
		return count;
	}
};

int LampsGrid::mostLit(vector <string> L, int K) {
	sort(L.begin(), L.end());
	int res = 0;
	string row = L[0]; int cnt = 1;
	for (int i = 1; i < L.size(); i++) {
		if (L[i] == row) cnt ++;
		else {
			res = max(res, LitRows(row, cnt, K));
			cnt = 1; row = L[i];
		}
	}
	res = max(res, LitRows(row, cnt, K));
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!