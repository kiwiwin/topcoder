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

class SquaresInsideLattice {
public:
	long long howMany(int, int);
	long long squareNum(int x, int y, int e) {
		return (long long)(x-e+1) * (y-e+1) * e;
	}
};

long long SquaresInsideLattice::howMany(int width, int height) {
	if (width > height) swap(width, height);
	long long res = 0;
	for (int edge = 1; edge <= width; edge++)
		res += squareNum(width, height, edge);
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!