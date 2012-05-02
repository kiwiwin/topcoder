#include <iostream>
#include <algorithm>
using namespace std;

class FoxPlayingGame{
public:
	double MIN[55][55];
	double MAX[55][55];
	bool vis[55][55];
	double pa, pb;
	
	void solve(int a, int b) {
		if (vis[a][b]) return;

		solve(a-1, b);
		MIN[a][b] = MIN[a-1][b] + pa;
		MAX[a][b] = MAX[a-1][b] + pa;
		
		solve(a, b-1);
		MIN[a][b] = min(MIN[a][b], MIN[a][b-1]*pb); MIN[a][b] = min(MIN[a][b], MAX[a][b-1]*pb); 
		MAX[a][b] = max(MAX[a][b], MIN[a][b-1]*pb); MAX[a][b] = max(MAX[a][b], MAX[a][b-1]*pb); 
		
		vis[a][b] = true;
	}

	double theMax(int na, int nb, int paramA, int paramB) {
		pa = paramA / 1000.0; pb = paramB / 1000.0;
		MIN[0][0] = 0; MAX[0][0] = 0; vis[0][0] = true;
		for (int b = 1; b <= nb; b++) { MAX[0][b] = 0; MIN[0][b] = 0; vis[0][b] = true; }
		for (int a = 1; a <= na; a++) { MAX[a][0] = a*pa; MIN[a][0] = a*pa; vis[a][0] = true; }
		
		solve(na, nb);
		
		return MAX[na][nb];
	}
};
