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
};

double KingdomAndDice::newFairness(vector <int> F, vector <int> S, int X) {
	int SUM = 0;
	for (int i = 0; i < F.size(); i++)
	for (int j = 0; j < S.size(); j++) 
		if (F[i] > S[j]) SUM++;
		
	int UN = 0;
	for (int i = 0; i < F.size(); i++) if (F[i] == 0) UN++;
	int AV[55]; memset(AV, 0, sizeof(AV));
	sort(S.begin(), S.end());
	
	for (int i = 1; i < S.size(); i++) {
		AV[i] = S[i] - S[i-1] -1;
		for (int j = 0; j < F.size(); j++) if (S[i-1] < F[j] && F[j] < S[i]) AV[i] --;
	}
	AV[S.size()] = X - S[S.size()-1];
	for (int j = 0; j < F.size(); j++) if (S[S.size()-1] < F[j]) AV[S.size()] --;
		
	bool DP[55][55][2505]; //index, remain, value 
	memset(DP, false, sizeof(DP));
	DP[0][UN][SUM] = true;
	
	int N = F.size();
	for (int index = 1; index <= N; index++)  {
		for (int remain = 0; remain <= UN; remain++) {
			for (int count = SUM; count <= 2500; count++) {
				if (!DP[index-1][remain][count]) continue;
				for (int use = 0; use <= min(AV[index], remain); use++) {
					//cout << index << " " << remain-use << " " << count+index*use << endl;
					DP[index][remain-use][count+index*use] = true;
				}
			}
		}
	}
	
	//max
	int CNT = -100;
	for (int i = 0; i <= 2500; i++) {
		bool flag = false;
		for (int j = 0; j <= 50; j++) { if (DP[N][j][i]) { flag = true; break;} }
		if (!flag) continue;
		if (abs(CNT*2-N*N) > abs(i*2-N*N)) {CNT = i;}
	}
	
	return 1.0*CNT/(N*N);
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!