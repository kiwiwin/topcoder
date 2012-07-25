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
	bool M[55][55];
	// visT , visB in each augment searching, should not be reset, because it has been proved that the vertex has
	// been searched to be without augemnt path.
	bool visT[55]; 
	bool visB[55];
	bool usedT[55];
	bool usedB[55];
	int T, B;

	bool isFreeT(int index) {
		return !usedT[index];
	}
	
	bool isFreeB(int index) {
		return !usedB[index];
	}
	
	bool tryAdd(int top) {
		memset(visT, false, sizeof(visT));
		memset(visB, false, sizeof(visB));
		return tryT(top);
	}

	//from top to bottom, choose free edge
	bool tryT(int top) {
		if (visT[top]) return false;
		visT[top] = true;

		for (int next = 0; next < B; next++) {
			if (!G[top][next]) continue;
			if (M[top][next]) continue;
			
			M[top][next] = true;			
			bool tryResult = tryB(next);
			if (tryResult) return true;
			else M[top][next] = false;
		}

		return false;
	}
	
	//from bottom to top, choose matched edge
	bool tryB(int bot) {
		if (visB[bot]) return false;
		visB[bot] = true;

		if (isFreeB(bot)) {
			usedB[bot] = true;
			return true;
		}
		
		for (int next = 0;next < T; next++) {
			if (!G[next][bot]) continue;
			if (!M[next][bot]) continue;
			
			M[next][bot] = false;
			
			bool tryResult = tryT(next);

			if (tryResult) return true;
			else M[next][bot] = true;
		}

		return false;
	}
	 
	bool tryAugmentPath() {
		for (int i = 0; i < T; i++) {
			if (!isFreeT(i)) continue;
			if (tryAdd(i)) {
				usedT[i] = true;
				return true;
			}
		}
		return false;    
	}
};

int PointyWizardHats::getNumHats(vector <int> topH, vector <int> topR, vector <int> botH, vector <int> 
botR) {
	vector<Hat> top, bot;
	for (int i = 0; i < topH.size(); i++) top.push_back(Hat(topH[i], topR[i]));
	for (int i = 0; i < botH.size(); i++) bot.push_back(Hat(botH[i], botR[i]));
	T =  top.size(); B = bot.size();
	
	memset(G, false, sizeof(G));
	for (int i = 0; i < T; i++)
	for (int j = 0; j < B; j++)
		if (top[i].canBeWizard(bot[j])) G[i][j] = true;
		
	memset(usedT, false, sizeof(usedT));
	memset(usedB, false, sizeof(usedB));
		
	memset(M, false, sizeof(M));

	while(tryAugmentPath());
	
	int result = 0;
	for (int i = 0; i < T; i++)
	for (int j = 0; j < B; j++)
		result += M[i][j];

	return result;
}


//Powered by [KawigiEdit] 2.0!