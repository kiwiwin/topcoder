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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

class SpiralRoute {
public:
	vector <int> thronePosition(int, int);
	int width, length;
	int dir;
	bool vis[5000][5000];
	int x, y;
	bool shouldTurn(){
		if (x+dx[dir] < 0 || x+dx[dir] >= width) return true;
		if (y+dy[dir] < 0 || y+dy[dir] >= length) return true;	
		return vis[x+dx[dir]][y+dy[dir]];
	}
	bool end() {
		if (shouldTurn()) {
			int old_dir = dir;
			turn();
			if (shouldTurn()) return true;
			dir = old_dir;
		}
		return false;
	}
	
	void turn() {
		dir = (dir+1) % 4;
	}
	
	void move() {
		x += dx[dir]; y += dy[dir];
	}
};

vector <int> SpiralRoute::thronePosition(int width_, int length_) {
	x = 0; y = 0; dir = 0;
	width = width_; length = length_;
	memset(vis, 0, sizeof(vis));
	
	while(!end()){
		vis[x][y] = true;
		if (shouldTurn()) turn();
		move();
	}
	
	vector<int> res;
	res.push_back(x); res.push_back(y);
	
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!