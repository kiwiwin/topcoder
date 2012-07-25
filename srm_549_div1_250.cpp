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
		//cout << top << " --> " << bot << endl;
		memset(visT, false, sizeof(visT));
		memset(visB, false, sizeof(visB));
		return tryTB(top);
	}

	bool tryTB(int top) {
		if (visT[top]) return false;
		visT[top] = true;
		//cout << "top: " << top << endl;		

		for (int next = 0; next < B; next++) {
			if (!G[top][next]) continue;
			if (M[top][next]) continue;
			
			M[top][next] = true;
			
			bool tryResult = tryBB(next);
			
			if (!tryResult) {
				M[top][next] = false;
			} else {
				return true;
			}
		}

		//visT[top] = false;
		return false;
	}
	
	bool tryBB(int bot) {
		if (visB[bot]) return false;
		visB[bot] = true;
		//cout << "bottom: " << bot << endl;
		if (isFreeB(bot)) {
			usedB[bot] = true;
			return true;
		}
		
		for (int next = 0;next < T; next++) {
			if (!G[next][bot]) continue;
			if (!M[next][bot]) continue;
			
			M[next][bot] = false;
			
			bool tryResult = tryTB(next);

			if (!tryResult) {
				M[next][bot] = true;
			} else {
				return true;
			}
		}
		//visB[bot] = false;
		return false;
	}
	 
	bool existAugment() {
		bool flag = false;
		for (int i = 0; i < T; i++) {
			if (!isFreeT(i)) continue;
			if (tryAdd(i)) {
				usedT[i] = true;
				flag = true;
			}
		}
		return flag;    
	}
};

int PointyWizardHats::getNumHats(vector <int> topH, vector <int> topR, vector <int> botH, vector <int> 
botR) {
	vector<Hat> top, bot;
	for (int i = 0; i < topH.size(); i++) top.push_back(Hat(topH[i], topR[i]));
	for (int i = 0; i < botH.size(); i++) bot.push_back(Hat(botH[i], botR[i]));
	T =  top.size(); B = bot.size();
	
	memset(G, false, sizeof(G));
	for (int i = 0; i < top.size(); i++)
	for (int j = 0; j < bot.size(); j++)
		if (top[i].canBeWizard(bot[j])) G[i][j] = true;
		
	memset(usedT, false, sizeof(usedT));
	memset(usedB, false, sizeof(usedB));
		
	memset(M, false, sizeof(M));

	for (int i = 0; i < top.size(); i++) {
	for (int j = 0; j < bot.size(); j++)
		cout << G[i][j]<< " "; 
		cout << endl;	
	}

	while(existAugment()) {
		//addAugment();
	}
	
	int result = 0;
	for (int i = 0; i < top.size(); i++)
	for (int j = 0; j < bot.size(); j++)
		if (M[i][j]) result++;

	
	return result;
}


//Powered by [KawigiEdit] 2.0!