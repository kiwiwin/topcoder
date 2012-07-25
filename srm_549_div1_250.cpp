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
	int matchT[55];
	int matchB[55];
	int T, B;

	bool isFreeT(int index) {
		return matchT[index] < 0;
	}
	
	bool isFreeB(int index) {
		return matchB[index] < 0;
	}
	
	bool tryAdd(int top) {
		memset(visT, false, sizeof(visT));
		memset(visB, false, sizeof(visB));
		return tryT(top);
	}
	
	bool tryT(int top) {
		if (visT[top]) return false;
		else visT[top] = true;

		for (int next = 0; next < B; next++) {
			if (!G[top][next] || M[top][next]) continue;
			
			M[top][next] = true;			
			if (isFreeB(next)) {
				matchT[top] = next; matchB[next] = top;
				return true;
			}
			
			int nextTop = matchB[next];
			matchT[nextTop] = -1; matchB[next] = top; matchT[top] = next;
			M[nextTop][next] = false;
			bool tryResult = tryT(nextTop);
			if (!tryResult) { 
				M[nextTop][next] = true;
				matchT[nextTop] = next; matchB[next] = nextTop; matchT[top] = -1;
				M[top][next] = false;
			} else {
				return true;
			}
		}

		return false;
	}
	 
	bool tryAugmentPath() {
		for (int i = 0; i < T; i++) {
			if (!isFreeT(i)) continue;
			if (tryAdd(i)) return true;
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
		
	for (int i = 0; i < T; i++) matchT[i] = -1;
	for (int i = 0; i < B; i++) matchB[i] = -1;
		
	memset(M, false, sizeof(M));

	while(tryAugmentPath());
	
	int result = 0;
	for (int i = 0; i < T; i++)
	for (int j = 0; j < B; j++)
		result += M[i][j];
		
	for (int i = 0; i < T; i++) cout << "T: " << matchT[i]  << endl;
	for (int i = 0; i < B; i++) cout << "B: " <<  matchB[i] << endl;	

	return result;
}


//Powered by [KawigiEdit] 2.0!