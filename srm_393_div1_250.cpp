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

class InstantRunoffVoting {
public:
	int winner(vector <string>);
	bool eliminate[10];
	int votes[10];
	
	void vote(const vector<string> &voters) {
		for (int i = 0; i < voters.size(); i++ ) {
			int candicate = 0;
			while(eliminate[voters[i][candicate]-'0']) candicate++;
			votes[voters[i][candicate]-'0']++;
		}
	}
	
	void eliminateCandicate() {
		int MIN = 10000;
		for (int i = 0; i < N; i++) if (!eliminate[i]) MIN = min(votes[i], MIN);
		for (int i = 0; i < N; i++) if (!eliminate[i] && votes[i] == MIN) eliminate[i] = true;
	}
	
	bool hasRemainCandicate() {
		for (int i = 0; i < N; i++) if (!eliminate[i]) return true;
		return false;
	}
	
	int getWinner() {
		for (int i = 0; i < N; i++) if (!eliminate[i] && votes[i]*2 > V) return i;
		return -1;
	}
	
	bool needVote() {
		int cnt = 0;
		for (int i = 0; i < N; i++) if (!eliminate[i]) cnt++;
		return cnt > 1;
	}
	
	int N;
	int V;
};

int InstantRunoffVoting::winner(vector <string> voters) {
	memset(eliminate, 0, sizeof(eliminate));
	N = voters[0].size(); V =  voters.size();
	for (int i = 0; i < N; i++) {
		memset(votes, 0, sizeof(votes));
		vote(voters);
		if (getWinner() >= 0) return getWinner(); 
		eliminateCandicate();
		if (!hasRemainCandicate()) return -1;
	}
	return -1;
}


//Powered by [KawigiEdit] 2.0!