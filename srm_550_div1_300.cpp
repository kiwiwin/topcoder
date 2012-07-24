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

class RotatingBot {
public:
	int minArea(vector <int>);
	bool M[5005][5005];
};

int RotatingBot::minArea(vector <int> moves) {
	memset(M, false, sizeof(M));
	int face = 0;
	int x = 2502, y = 2502;
	M[x][y] = true;
	int SX = 2502, BX = 2502, SY = 2502, BY = 2502;
	for (int i = 0; i < moves.size(); i++) {
		for (int k = 1; k <= moves[i]; k++) {
			x += dx[face]; y += dy[face];
			if (M[x][y]) return -1;
			M[x][y] = true;
		}
		if (i == 0) BX = x;
		if (i == 1) BY = y;
		if (i == 2) {
			if (moves.size() > 3) {
				if (moves[2] < moves[0]) return -1;
			}
			SX = min(SX, x);
		}
		if (i == 3) {
			if (moves.size() > 4) {
				if (moves[2] == moves[0] && moves[3] != moves[1]-1)	return -1;
				if (moves[2] > moves[0] && moves[3] < moves[1]) return -1;
			}
			SY = min(SY, y);	
		}
		if (i == 4) {
			if (!M[x+dx[face]][y+dy[face]] && x != BX && moves.size() > 5) return -1;
			if (x > BX) return -1;
		}
		if ((i+1) < moves.size() && i > 4) {
			if (!M[x+dx[face]][y+dy[face]]) return -1;
		}
		face = (face + 1) % 4;
	}
	
	return (BX-SX+1)*(BY-SY+1);
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!