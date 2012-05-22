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

class LameKnight {
public:
	int maxCells(int, int);
};

int LameKnight::maxCells(int height, int width) {
	if (height <= 1) return 1;
	else if (height <= 2) return min(4, (width-1)/2 + 1);
	else {
		if (width < 7) return min(4, width);
		else return width-2;
	}
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!