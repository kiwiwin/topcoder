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

class Trainyard {
public:
	int reachableSquares(vector <string>, int);
	vector<string> layout;
	bool vis[15][15];
	pair<int,int> findSource() {
		for (int i = 0; i < layout.size(); i++)
		for (int j = 0; j < layout[i].size(); j++)
			if (layout[i][j] == 'S') return make_pair(i, j);
	}
	
	bool check(int x, int y) {
		if (x >= layout.size() || x < 0 || y >= layout[0].size() || y < 0) return false;
		if (layout[x][y] == '.') return false;
		return !vis[x][y];
	}
	
	vector<pair<int,int> > getReachable(pair<int,int> now) {
		vector<pair<int,int> > res;
		if (layout[now.first][now.second] == '|') {
			if (check(now.first-1, now.second)) if (layout[now.first-1][now.second] == '|' || layout[now.first-1][now.second] == '+') res.push_back(make_pair(now.first-1, now.second));
			if (check(now.first+1, now.second)) if (layout[now.first+1][now.second] == '|' || layout[now.first+1][now.second] == '+') res.push_back(make_pair(now.first+1, now.second));
		}else if (layout[now.first][now.second] == '-') {
			if (check(now.first, now.second-1)) if (layout[now.first][now.second-1] == '-' || layout[now.first][now.second-1] == '+') res.push_back(make_pair(now.first, now.second-1));
			if (check(now.first, now.second+1)) if (layout[now.first][now.second+1] == '-' || layout[now.first][now.second+1] == '+') res.push_back(make_pair(now.first, now.second+1));
		}else {
			if (check(now.first-1, now.second)) if (layout[now.first-1][now.second] == '|' || layout[now.first-1][now.second] == '+') res.push_back(make_pair(now.first-1, now.second));
			if (check(now.first+1, now.second)) if (layout[now.first+1][now.second] == '|' || layout[now.first+1][now.second] == '+') res.push_back(make_pair(now.first+1, now.second));
			if (check(now.first, now.second-1)) if (layout[now.first][now.second-1] == '-' || layout[now.first][now.second-1] == '+') res.push_back(make_pair(now.first, now.second-1));
			if (check(now.first, now.second+1)) if (layout[now.first][now.second+1] == '-' || layout[now.first][now.second+1] == '+') res.push_back(make_pair(now.first, now.second+1));
		}
		return res;
	}
};

int Trainyard::reachableSquares(vector <string> layout_, int fuel) {
	layout = layout_; memset(vis, 0, sizeof(vis));
	int res = 0;
	queue<pair<pair<int,int>, int> > Q;
	Q.push(make_pair(findSource(), 0));
	layout[findSource().first][findSource().second] = '+';
	while(!Q.empty()) {
		pair<pair<int,int>, int> now = Q.front(); Q.pop();
		if (vis[now.first.first][now.first.second]) continue;
		vis[now.first.first][now.first.second] =  true;
		res ++;
		if (now.second < fuel) {
			vector<pair<int,int> > reach = getReachable(now.first);
			for (int i = 0; i < reach.size(); i++) Q.push(make_pair(reach[i], now.second+1));
		}
	}
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!