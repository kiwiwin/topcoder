#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class SortingGame {
public:
	set<vector<int> >VIS;
	
	bool equal(const vector<int> &lhs, const vector<int> &rhs) {
		for (int i = 0; i < lhs.size(); i++) 
			if (lhs[i] != rhs[i]) return false;
		return true;
	}
	
	vector<int> swap(vector<int> now, int index, int k) {
		reverse(now.begin()+index, now.begin()+index+k);
		return now;
	}

	int fewestMoves(vector<int> board, int k) {
		vector<int> dest;
		for (int i = 0; i < board.size(); i++) dest.push_back(i+1);
		
		queue<pair<vector<int>,int> > Q;
		Q.push(make_pair(board,0));
		VIS.insert(board);
		
		while(!Q.empty()) {
			vector<int> now = Q.front().first;
			int dis = Q.front().second;
			Q.pop();
			
			if (equal(now, dest)) return dis;
			
			for (int i = 0; i+k <= now.size(); i++) {
				vector<int> next = swap(now, i, k);
				if (VIS.find(next) != VIS.end()) continue;
				
				Q.push(make_pair(next, dis+1));
				VIS.insert(next);
			}
		}
				
		return -1;
	}
};
