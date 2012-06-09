#include <vector>
#include <string>
#include <climits>

using namespace std;

class GreedyTravelingSalesman {
public:
	int dis[35][35];

	void addDis(vector<string> value, int base) {
		for (int i = 0; i < value.size(); i++)
		for (int j = 0; j < value[i].size(); j++)
			dis[i][j] += (value[i][j] - '0') * base;
	}
	
	void initDis(vector<string> &thousands, vector<string> &hundreds, vector<string> &tens, vector<string> &ones) {
		memset(dis, 0, sizeof(dis));
		addDis(thousands, 1000);
		addDis(hundreds, 100);
		addDis(tens, 10);
		addDis(ones, 1);
	}
	
	int nextCityWithoutReconstruct(int now) {
		int min_distance = -1, next = -1;
		for (int i = 0; i < N; i++) {
			if (vis[i]) continue;
			if (min_distance < 0) { next = i; min_distance = dis[now][next]; }
			else if (min_distance > dis[now][i]) { next = i; min_distance = dis[now][next]; }
		}
		return next;
	}

	int solve(int now, bool reconstruct) {
		vis[now] = true;
		int result = subsolve(now, reconstruct);
		vis[now] = false;
		return result;
	}
	
	int solveWithoutReconstruct(int now, int nextCity, bool reconstruct) {
		if (nextCity < 0) return 0;
		else return dis[now][nextCity] + solve(nextCity, reconstruct);
	}
	
	int solveReconstructWithItself(int now, int nextCity) {
		int min_value = 9999;
		for (int i = 0; i < nextCity; i++) {
			if (vis[i]) continue;
			min_value = min(dis[now][i]-1, min_value);
		}
		for (int i = nextCity + 1; i < N; i++) {
			if (vis[i]) continue;
			min_value = min(dis[now][i], min_value);
		}
		
		if (min_value > 0) return min_value + solve(nextCity, true);
		else return 0;
	}
	
	int solveReconstructWithOther(int now, int nextCity) {
		int cnt = 0;
		for (int i = 0; i < nextCity; i++) {
			if (vis[i]) continue;
			if (dis[now][nextCity] >= dis[now][i]) cnt++;
		}
		for (int i = nextCity + 1; i < N; i++) {
			if (vis[i]) continue;
			if (dis[now][nextCity] > dis[now][i]) cnt++;
		}
		
		if (cnt <= 1 && dis[now][nextCity] < 9999) return dis[now][nextCity] + solve(nextCity, true);
		else return 0;
	}
	
 	int subsolve(int now, bool reconstruct) {
		int result = 0;
		int nextCity = nextCityWithoutReconstruct(now);
	
		result = solveWithoutReconstruct(now, nextCity, reconstruct);
	
		if (!reconstruct) {
			for (int i = 0; i < N; i++) {
				if (vis[i]) continue;
				
				result = max(solveReconstructWithItself(now, i), result);
				result = max(solveReconstructWithOther(now, i), result);
			}
		}
		
		return result;
	}
	
	bool vis[35];
	int N;

	int worstDistance(vector<string> thousands, vector<string> hundreds, vector<string> tens, vector<string> ones) {
		initDis(thousands, hundreds, tens, ones);	
		memset(vis, false, sizeof(vis));
		N = ones.size();
		
		return solve(0, false);	
	}
};
