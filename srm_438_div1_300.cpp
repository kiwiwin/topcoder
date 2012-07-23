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
	int firstN;

	vector<int> smallUnlucky() {
		vector<int> result;
		for (int i = 0; i < lucky.size(); i++) {
			int cnt = 0;
			for (int x = lucky[i]-1; x > (i>0?lucky[i-1]:0); x--) {
				result.push_back(x);
				cnt ++; 
				if (cnt >= firstN) break;
			}
		}	
			
		return result;
	}
	
	
	vector<int> bigUnlucky() {
		vector<int> result;
	
		for (int i = 0; i < lucky.size(); i++) {		
			int cnt = 0;
			for (int x = lucky[i]+1; x < (i<lucky.size()-1?lucky[i+1]:lucky[i]+firstN); x++) {
				result.push_back(x);
				cnt ++;
				if (cnt >= firstN) break;
			}
		}
	
		return result;		
	}
	
	vector<int> getAllPossibleValue() {
		set<int> S;
		S.insert(lucky.begin(), lucky.end());
		vector<int> small = smallUnlucky();
		S.insert(small.begin(), small.end());
		vector<int> big = bigUnlucky();
		S.insert(big.begin(), big.end());
		S.erase(0);
		
		return vector<int>(S.begin(), S.end());
	}

	vector<int> getLuckiest(vector<int> luckySet, int n) {
		firstN = n;
		sort(luckySet.begin(), luckySet.end());
		
		lucky = vector<int>(luckySet.size()+1, 0);
		lucky[0] = 0; copy(luckySet.begin(), luckySet.end(), lucky.begin()+1); 
				
		vector<int> result = getAllPossibleValue();
		Cmp cmp(lucky);
		sort(result.begin(), result.end(), cmp);

		return vector<int>(result.begin(), result.begin()+n);
	}
};
