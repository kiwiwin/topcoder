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

class LaserShooting {
public:
	double numberOfHits(vector <int>, vector <int>, vector <int>);
	double P(int x, int y1, int y2) {
		if (y1 < y2) swap(y1, y2);
		return (atan(1.0*y1/x) - atan(1.0*y2/x)) / acos(-1);
	}
};

double LaserShooting::numberOfHits(vector <int> x, vector <int> y1, vector <int> y2) {
	double res = 0;
	for (int i = 0; i < x.size(); i++) {
		res += P(x[i], y1[i], y2[i]);
	}
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!