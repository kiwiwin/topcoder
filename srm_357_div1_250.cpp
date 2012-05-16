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

class Hotel {
public:
	int marketCost(int, vector <int>, vector <int>);
};

int Hotel::marketCost(int minCustomers, vector <int> customers, vector <int> cost) {
	int dp[1105]; memset(dp, 0, sizeof(dp));
	
	for (int i = 0; i < customers.size(); i++) {
		for (int c = 0; c < minCustomers; c++) {
			if (dp[c] || c == 0) {
				if (dp[customers[i]+c]==0) dp[customers[i]+c] = dp[c]+cost[i];
				else dp[customers[i]+c] = min(dp[c]+cost[i], dp[customers[i]+c]);
			}
		}
	}
	
	int res = 100000000;
	for (int i = minCustomers; i < 1105; i++)
		if (dp[i]) res = min(dp[i],res);
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!