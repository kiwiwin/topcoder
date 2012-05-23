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

class MarblesRegroupingEasy {
public:
	int minMoves(vector <string>);
	
	int getMixedBoxNum(vector<string>& boxes) {
		int res = 0;
		for (int i = 0; i < boxes.size(); i++) {
			int cnt = 0;
			for (int j = 0; j < boxes[i].size(); j++) if (boxes[i][j] > '0') cnt++;
			if (cnt > 1) res++;
		}
		return res;
	}
	
	int getSingleColorNum(vector<string>& boxes, int color) {
		int res = 0;
		for (int i = 0; i < boxes.size(); i++) {
			if (boxes[i][color] == '0') continue;
			int cnt = 0;
			for (int j = 0; j < boxes[0].size(); j++) if (boxes[i][j] > '0') cnt++;
			if (cnt == 1) res++;
		}
		return res;
	}
};

int MarblesRegroupingEasy::minMoves(vector <string> boxes) {
	int res = 0;
	int mixedBoxNum = getMixedBoxNum(boxes);
	res += max(mixedBoxNum-1,0);
	for (int color = 0; color < boxes[0].size(); color++) {
		int singleColorNum = getSingleColorNum(boxes, color);
		res += max(singleColorNum - 1, 0);
	}
	if (mixedBoxNum == 0) res = max(res-1, 0);
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!