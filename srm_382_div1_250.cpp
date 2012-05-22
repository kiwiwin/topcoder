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

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {-2, 2, -2, 2, -1, 1, -1, 1};

struct Rider {
	int x,y,move;
	Rider(int x_, int y_, int move_): x(x_), y(y_), move(move_) {}
};

class CollectingRiders {
public:
	int minimalMoves(vector <string>);
	vector<Rider> getRiders() {
		vector<Rider> res;
		for (int i = 0; i < board.size(); i++) 
		for (int j = 0; j < board[i].size(); j++) {
			if (isdigit(board[i][j])) res.push_back(Rider(i,j,board[i][j]-'0'));
		}
		return res;
	}
	
	int minMoves(int x, int y) {
		int res = 0;
		for (int i = 0; i < rider.size(); i++) {
			if (getMoves(rider[i], x, y) < 0) return -1;
			else res += getMoves(rider[i], x, y);
		}
		return res;
	}
	
	int getMoves(Rider r, int x, int y) {
		memset(vis, 0, sizeof(vis));
		queue<pair<pair<int,int>,int> >Q;
		Q.push(make_pair(make_pair(r.x, r.y), 0));
		while(!Q.empty()) {
			pair<pair<int,int>,int> now = Q.front(); Q.pop();
			if (now.first.first == x && now.first.second == y) return ceil(1.0*now.second/r.move);
			if (vis[now.first.first][now.first.second]) continue;
			vis[now.first.first][now.first.second] = true;
			for (int i = 0; i < 8; i++) {
				if (visible(now.first.first+dx[i], now.first.second+dy[i])) Q.push(make_pair(make_pair(now.first.first+dx[i], now.first.second+dy[i]), now.second+1));
			}
		}
		return -1;
	}
	
	bool visible(int x, int y) {
		if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return false;
		return !vis[x][y];
	}
	bool vis[15][15]; 
	vector<string> board;
	vector<Rider> rider;
};

int CollectingRiders::minimalMoves(vector <string> board_) {
	board = board_;
	rider = getRiders();
	
	int res = -1;
	for (int i = 0; i < board.size(); i++)
	for (int j = 0; j < board[i].size(); j++) {
		if (minMoves(i, j) >= 0) {
			if (res < 0) res = minMoves(i, j);
			else res = min(res, minMoves(i, j));
		}
	}
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!