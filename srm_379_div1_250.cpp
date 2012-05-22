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

class SellingProducts {
public:
	int optimalPrice(vector <int>, vector <int>);
	int benifit(int price, vector<pair<int,int> >& dest) {
		int res = 0;
		for (int i = 0; i < dest.size(); i++) {
			if (dest[i].first >= price && price >= dest[i].second) res += price - dest[i].second; 
		}
		return res;
	}
};

int SellingProducts::optimalPrice(vector <int> price, vector <int> cost) {
	vector<pair<int,int> > dest;
	for (int i = 0; i < price.size(); i++) dest.push_back(make_pair(price[i], cost[i]));
	sort(dest.begin(), dest.end(), greater<pair<int,int> >());

	int res = 0; int max_ben = 0;
	for (int i = 0; i < dest.size(); i++) {
		if (max_ben <= benifit(dest[i].first, dest)) {
			res = dest[i].first; max_ben = benifit(dest[i].first, dest); 
		}
	}
	if (max_ben <= benifit(0, dest)) res = 0;
	
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!