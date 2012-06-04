#include <vector>
#include <string>
#include <iostream>

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

	int solve(int now, bool reconstruct) {
		if (reconstruct) {
			int res = -1, next = -1;
			for (int i = 0; i < N; i++) {
				if (vis[i]) continue;
				if (res < 0) { res = dis[now][i]; next = i;}
				else if(res > dis[now][i]) { res = dis[now][i]; next = i;}
			}
			if (next < 0) return 0;
			else {
				vis[next] = true;
				int result = res + solve(next, reconstruct);
				vis[next] = false;
				return result;
			}
		} else {
			int result = 0;
			//do not reconstruct now
			int res = -1, next = -1;
			for (int i = 0; i < N; i++) {
				if (vis[i]) continue;
				if (res < 0) { res = dis[now][i]; next = i;}
				else if(res > dis[now][i]) { res = dis[now][i]; next = i;}
			}
			if (next < 0) result = 0;
			else {
				vis[next] = true;
				result = res + solve(next, reconstruct);
				vis[next] = false;
			}
			
			//reconstruct now
			for (int i = 0; i < N; i++) {
				if (vis[i]) continue;
				//choose i as reconstrcut destination
				int cnt = 0; int min_value = 9999;
				for (int j = 0; j < i; j++) {
					if (vis[j]) continue;
					if (dis[now][j] <= dis[now][i]) cnt++; 
					min_value = min(min_value, dis[now][j]-1);
				}
				for (int j = i+1; j < N; j++) {
					if (vis[j]) continue;
					if (dis[now][j] < dis[now][i]) cnt++; 
					min_value = min(min_value, dis[now][j]); 
				}
				
				//change the [now][i]
				if (min_value > 0) {
					vis[i] = true;
					result = max(result, min_value + solve(i, true));
					vis[i] = false;
				}
				
				//change the [now][else]
				if (cnt <= 1 && dis[now][i] < 9999) {
					vis[i] = true;
					result = max(result, dis[now][i] + solve(i, true));
					vis[i] = false;
				}
			}
			
			return result;
		}
	}
	
	bool vis[35];
	int N;

	int worstDistance(vector<string> thousands, vector<string> hundreds, vector<string> tens, vector<string> ones) {
		initDis(thousands, hundreds, tens, ones);	
		for (int i = 0; i < ones.size(); i++)  {
			for (int j = 0; j < ones.size(); j++)
				cout << dis[i][j] << " ";
			cout << endl;
		}
		memset(vis, false, sizeof(vis));
		N = ones.size();
		vis[0] = true;
		return solve(0, false);	
	}
};
