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

class TheDiceGame {
public:
	double expectedThrows(int);
	double dp[1000005];
};

double TheDiceGame::expectedThrows(int candies) {
	for (int i = 0; i <= candies; i++) dp[i] = 0;
	dp[1] = 1;
	for (int i =  2; i <= candies; i++) {
		for (int dice = 1; dice <= 6; dice++)
			if (dice >= i) dp[i] += 1.0/6;
			else dp[i] += 1.0/6*(dp[i-dice] + 1);
	}
	return dp[candies];
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!