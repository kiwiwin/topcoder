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

class BlurredDartboard {
public:
	int minThrows(vector <int>, int);
};

int BlurredDartboard::minThrows(vector <int> points, int P) {
	bool p[55]; memset(p, 0, sizeof(p));
	for (int i = 0; i < points.size(); i++) p[points[i]] = true;
	
	vector<int> unknown;
	int max_dart = 1; int unknown_sum = 0;
	for (int dart = 1; dart <= points.size(); dart++) if (!p[dart]) {unknown.push_back(dart); unknown_sum += dart;}
	for (int dart = 1; dart <= points.size(); dart++) if (p[dart]) max_dart = max(max_dart, dart);

	if (unknown.empty()) return ceil(P*1.0/max_dart);
	int round_dart = max(unknown_sum, (int)unknown.size()*max_dart);
	int res = P/round_dart*unknown.size(); P = P%round_dart;
	
	if (P == 0) return res;

	int sum = 0;
	for (int i = 0; i < unknown.size(); i++) {
		if (max_dart * (i+1) >= P) return res + i + 1;
		sum += unknown[i];
		if (sum >= P) return res + i + 1;	
	}
	return -1;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!