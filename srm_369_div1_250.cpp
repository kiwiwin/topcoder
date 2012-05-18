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

class BeautifulString {
public:
	int maximumLength(int, int, int, int);
};

int BeautifulString::maximumLength(int countA, int countB, int maxA, int maxB) {
	if (maxA == 0 || countA == 0) return min(countB, maxB);
	if (maxB == 0 || countB == 0) return min(countA, maxA);
	if (countA < floor(1.0*countB/maxB)) return countA + (countA+1)*maxB;
	if (countB < floor(1.0*countA/maxA)) return countB + (countB+1)*maxA;
	return countA + countB;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!