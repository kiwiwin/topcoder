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
#include <queue>

using namespace std;

struct Hat {
	Hat(int _h, int _r):h(_h), r(_r) {}
	bool canBeWizard(const Hat &bottom) {
		if (r >= bottom.r) return false;
		return bottom.h*r < h*bottom.r;
	}
	int h,r;
};

class PointyWizardHats {
public:
	int getNumHats(vector <int>, vector <int>, vector <int>, vector <int>);
	bool G[55][55];
	bool visT[55];
	int matchB[55];
	int T, B;
	
	bool isFreeB(int index) {
		return matchB[index] < 0;
	}
	
	bool tryT(int top) {
		if (visT[top]) return false;
		else visT[top] = true;

		for (int next = 0; next < B; next++) {
			if (!G[top][next]) continue;						
			if (isFreeB(next) || tryT(matchB[next])) {
				matchB[next] = top;
				return true;
			}
		}

		return false;
	}
	
	int maximumMatch() {
		int result = 0 ;
		for (int i = 0; i < T; i++) {
			memset(visT, false, sizeof(visT));
			if (tryT(i)) result++;
		}
		return result;
	}
	
	void makeGraph(const vector<int> &topH, const vector<int> &topR, const vector<int> &botH, const vector<int> &botR) {
		vector<Hat> top, bot;
		for (int i = 0; i < topH.size(); i++) top.push_back(Hat(topH[i], topR[i]));
		for (int i = 0; i < botH.size(); i++) bot.push_back(Hat(botH[i], botR[i]));
		T =  top.size(); B = bot.size();
		
		memset(G, false, sizeof(G));
		for (int i = 0; i < T; i++)
		for (int j = 0; j < B; j++)
			if (top[i].canBeWizard(bot[j])) G[i][j] = true;	
	}
};

int PointyWizardHats::getNumHats(vector <int> topH, vector <int> topR, vector <int> botH, vector <int> 
botR) {
	makeGraph(topH, topR, botH, botR);
		
	for (int i = 0; i < B; i++) matchB[i] = -1;

	return maximumMatch();
}

//Powered by [KawigiEdit] 2.0!