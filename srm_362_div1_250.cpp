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

class MaximizeSquares {
public:
	int squareCount(int);
	
	int getSquareNumFromRectangle(int x, int y) {
		int res = 0;
		while(x > 0 && y > 0) {
			res += x*y;
			x--; y--;
		}
		return res;
	}
	
	int getSquareNumFromEdge(int x){
		if (x < 2) return 0;
		return (x-2)*(1+x-2)/2 + x-1;
	}
};

int MaximizeSquares::squareCount(int N) {
	if (N == 0) return 0;

	int res = 0;
	for (int i = floor(sqrt(N)); i <= N; i++) {
		if (N - N/i*i > N/i) continue;
		int tmp = getSquareNumFromRectangle(i-1, N/i-1) + getSquareNumFromEdge(N - N/i*i);
		res = max(res, tmp);
	}
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!