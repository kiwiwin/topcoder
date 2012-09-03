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

class KingdomAndDice {
public:
	double newFairness(vector <int>, vector <int>, int);
	int AV[55];
	bool DP[55][55][2505]; //index, remain, value 
	vector<int> S, F;
	int X;
	
	void countAvail() {
		memset(AV, 0, sizeof(AV));
		sort(S.begin(), S.end());
		
		for (int i = 1; i < S.size(); i++) {
			AV[i] = S[i] - S[i-1] -1;
			for (int j = 0; j < F.size(); j++) if (S[i-1] < F[j] && F[j] < S[i]) AV[i] --;
		}
		AV[S.size()] = X - S[S.size()-1];
		for (int j = 0; j < F.size(); j++) if (S[S.size()-1] < F[j]) AV[S.size()] --;
	}
	
	int already() {
		int res = 0;
		for (int i = 0; i < F.size(); i++)
		for (int j = 0; j < S.size(); j++) 
			if (F[i] > S[j]) res++;
		return res;
	}
	
	int emptyFace() {
		int res = 0;
		for (int i = 0; i < F.size(); i++) if (F[i] == 0) res++;
		return res;
	}
	
	void iterateValue(int UN, int SUM) {
		memset(DP, false, sizeof(DP));
		DP[0][UN][SUM] = true;
		
		int N = F.size();
		for (int index = 1; index <= N; index++)  {
			for (int remain = 0; remain <= UN; remain++) {
				for (int count = SUM; count <= 2500; count++) {
					if (!DP[index-1][remain][count]) continue;
					for (int use = 0; use <= min(AV[index], remain); use++) 
						DP[index][remain-use][count+index*use] = true;
				}
			}
		}
	}
};

double KingdomAndDice::newFairness(vector <int> _F, vector <int> _S, int _X) {
	F = _F; S = _S; X = _X;
	int SUM = already();
	int UN = emptyFace();
	countAvail();
	iterateValue(UN, SUM);
	
	int N = F.size();
	int CNT = -100;
	for (int i = 0; i <= 2500; i++) {
		bool flag = false;
		for (int j = 0; j <= 50; j++) { if (DP[N][j][i]) { flag = true; break;} }
		if (!flag) continue;
		if (abs(CNT*2-N*N) > abs(i*2-N*N)) CNT = i;
	}
	
	return 1.0*CNT/(N*N);
}


//Powered by [KawigiEdit] 2.0!