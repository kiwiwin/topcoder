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

class DrawingMarbles {
public:
	double sameColor(vector <int>, int);
	double singleColor(int color, int sum, int n) {
		double res = 1;
		for (int i = 0; i < n; i++) {
			res *= 1.0*(color-i)/(sum-i);
		}
		return res;
	}
};

double DrawingMarbles::sameColor(vector <int> colors, int n) {
	int sum = 0; for (int i = 0; i < colors.size(); i++) sum += colors[i];
	double res = 0;
	for (int i =0; i < colors.size(); i++) res += singleColor(colors[i], sum, n);
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!