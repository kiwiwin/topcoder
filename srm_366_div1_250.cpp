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

class ChangingSounds {
public:
	int maxFinal(vector <int>, int, int);
	int dp[50][1001];
};

int ChangingSounds::maxFinal(vector <int> inter, int bl, int ml) {
	memset(dp, 0, sizeof(dp));

	bool f = false;
	if (inter[0]+bl >= 0 && inter[0]+bl <= ml) { dp[0][inter[0]+bl] = 1; f = true;}
	if (-inter[0]+bl >= 0 && -inter[0]+bl <= ml) { dp[0][-inter[0]+bl] = 1; f = true;}
	if (!f) return -1;
	
		
	for (int i = 1; i < inter.size(); i++) {
		for (int l = 0; l <= ml; l++) {
			if (!dp[i-1][l]) continue;
			if(inter[i]+l >= 0 && inter[i]+l <= ml) dp[i][inter[i]+l] =  1;
			if(-inter[i]+l >= 0 && -inter[i]+l <= ml) dp[i][-inter[i]+l] =  1;
		}
		bool f = true;
		for (int l = 0; l <= ml; l++) if (dp[i][l]) f = false;
		if (f) return -1;
	}
	int res = 0;
	for (int l = 0; l <= ml; l++) if (dp[inter.size()-1][l]) res = l;
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!