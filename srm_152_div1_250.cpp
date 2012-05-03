#include <vector>
#include <algorithm>
using namespace std;

class LeaguePicks {
public:
	int friends, picks;
	
	vector <int> halfPicks(int position) {
		vector<int> res;
		while(position <= picks) {
			res.push_back(position); position += friends * 2;
		}
		return res; 
	}
	
	vector <int> merge(vector<int> lhs, vector<int> rhs) {
		vector <int> res(lhs.size() + rhs.size(), 0);
		for (int i = 0; i < lhs.size(); i++) res[i] = lhs[i];
		for (int i = 0; i < rhs.size(); i++) res[i+lhs.size()] = rhs[i];
		sort(res.begin(), res.end());
		return res;
	}

	vector <int> returnPicks(int position, int friends_, int picks_) {
		friends = friends_; picks = picks_;
		int oddRoundPos = position, evenRoundPos = 2*friends - oddRoundPos + 1;
		return merge(halfPicks(oddRoundPos), halfPicks(evenRoundPos));
	}
};
