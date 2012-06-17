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

class ForbiddenStrings {
public:
	long long countNotForbidden(int);
	long long same[35];
	long long diff[35];
};

long long ForbiddenStrings::countNotForbidden(int N) {
	same[1] = 0; same[2] = 3;
	diff[1] = 3; diff[2] = 6;
	for (int n = 3; n <= N; n++) {
		same[n] = same[n-1] + diff[n-1];
		diff[n] = same[n-1] * 2 + diff[n-1];
	}
	return same[N] + diff[N];
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!