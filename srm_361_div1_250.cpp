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

class WhiteHats {
public:
	int whiteNumber(vector <int>);
};

int WhiteHats::whiteNumber(vector <int> count) {
	int sum = 0; 
	for (int i = 0; i < count.size(); i++) sum += count[i];
	if (sum % (count.size()-1) != 0) return -1;
	sum /= (count.size()-1);
	
	for (int i = 0; i < count.size(); i++) 
		if (sum-count[i] != 0 && sum-count[i] != 1) return -1;
	
	return sum;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!