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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

class SpiralRoute {
public:
	vector <int> thronePosition(int, int);
	vector<int> makePosition(int x, int y) {
		vector<int> res(2,0);
		res[0] = x, res[1] = y;
		return res;
	}
	
	vector<int> addOffset(vector<int> pos, int dx, int dy) {
		pos[0] += dx, pos[1] += dy;
		return pos;
	}
};

vector <int> SpiralRoute::thronePosition(int width, int length) {
	if (length == 1) return makePosition(width-1, 0);
	if (length == 2) return makePosition(0, 1);
	if (width == 1) return makePosition(0, length-1);
	if (width == 2) return makePosition(0, 1);
	
	return addOffset(thronePosition(width-2, length-2),1,1);
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!