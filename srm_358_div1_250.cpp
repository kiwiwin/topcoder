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
int base[6] = {1, 10, 100, 1000, 10000, 100000};
class BrokenButtons {
public:
	int minPresses(int, vector <int>);
	bool digit[10];

	int digits(int x) {
		for (int i = 5; i >= 0; i--) if (x >= base[i]) return i+1;
		if (x == 0) return 1;
		return -1;
	}
	
	bool check(int x) {
		if (x == 0) return digit[0];
		while(x) {
			if (!digit[x%10]) return false;
			x /= 10;
		}
		return true;
	}
};

int BrokenButtons::minPresses(int page, vector <int> broken) {
	for (int i = 0; i <= 9; i++) digit[i] = true;
	for (int i = 0; i < broken.size(); i++) digit[broken[i]] = false;
	int MIN = 1000000; 
	
	for (int i = 0; i < 1000000; i++) {
		if (!check(i)) continue;
		int dig = digits(i);
		MIN = min(MIN, dig + abs(i-page));
	}
	
	return min(MIN, abs(page-100));
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!