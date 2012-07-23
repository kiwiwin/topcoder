#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Cmp {
	Cmp(vector<int> lucky) {
		L.resize(lucky.size());
		copy(lucky.begin(), lucky.end(), L.begin());
	}
			
	bool operator() (int lhs, int rhs) {
		if (unluckyInterval(lhs) != unluckyInterval(rhs))
			return unluckyInterval(lhs) < unluckyInterval(rhs);
		return lhs < rhs;
	}
			
	long long unluckyInterval(int x) {
		if (x > L[L.size()-1]) return ((long long)1) << 62;
		for (int i = 1; i < L.size(); i++) {
			if (x == L[i]) return 0;
			if (x < L[i])
				return (L[i]-x-1) * (x-L[i-1]-1) + (x-L[i-1]-1) + (L[i]-x-1);
			}
		}
			
	vector<long long> L;
};

class UnluckyIntervals {
public:
	vector<int> lucky;

	vector<int> getLuckiest(vector<int> luckySet, int n) {
		sort(luckySet.begin(), luckySet.end());
		
		lucky = vector<int>(luckySet.size()+1, 0);
		lucky[0] = 0; copy(luckySet.begin(), luckySet.end(), lucky.begin()+1); 
				
		set<int> S;
		for (int i = 0; i < lucky.size(); i++) {
			if (lucky[i] > 0) S.insert(lucky[i]);
			int cnt = 0;
			for (int x = lucky[i]-1; x > (i>0?lucky[i-1]:0); x--) {
				S.insert(x);
				cnt ++; 
				if (cnt >= n) break;
			}
			cnt = 0;
			for (int x = lucky[i]+1; x < (i<lucky.size()-1?lucky[i+1]:lucky[i]+n); x++) {
				S.insert(x);
				cnt ++;
				if (cnt >= n) break;
			}
		}
		
		vector<int> result(S.begin(), S.end());
		Cmp cmp(lucky);
		sort(result.begin(), result.end(), cmp);

		return vector<int>(result.begin(), result.begin()+n);
	}
};
