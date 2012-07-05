#include <string.h>
#include <iostream>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

class CrazyBot {
public:
	double P[4];
	bool vis[50][50];
	int N;
	
	double solve(int x, int y, int n, double p) {
		if (n == N) return p;
		
		double res = 0;
		for (int i = 0; i < 4; i++) {
			if (!vis[x+dx[i]][y+dy[i]]) {
				vis[x+dx[i]][y+dy[i]] = true;
				res += solve(x+dx[i], y+dy[i], n+1, p*P[i]);
				vis[x+dx[i]][y+dy[i]] = false;
			}
		}
		
		return res;
	}

	double getProbability(int _N, int east, int west, int south, int north) {
		P[0] = east/100.0; P[1] = west/100.0; P[2] = north/100.0; P[3] = south/100.0;
		N = _N;
		memset(vis, false, sizeof(vis));
		vis[25][25] = true;
		return solve(25, 25, 0, 1);
	}
};
