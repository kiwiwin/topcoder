#include <vector>
using namespace std;

class RemissiveSwaps {
public:
	int base;
	int dp[1000005];

	int sumDigit(int x) {
		int res = 0;
		while (x) {
			res += x%10; x/=10;
		}
		return res;
	}
	
	vector<int> getDigits(int x) {
		vector<int> res;
		while (x) {
			res.push_back(x%10); x/=10;
		}
		reverse(res.begin(), res.end());
		return res;	
	}
	
	int getValue(vector<int> &v) {
		int res = 0;
		int b = 1;
		for (int i = v.size()-1; i >= 0; i--, b *= 10) {
			res += b*v[i];
		}
		return res;
	}
	 
	vector<int> emu(int x) {
		vector<int> res;
		vector<int> digits = getDigits(x);
		for (int i = 0; i < digits.size(); i++) {
			if (digits[i] == 0) continue;
			for (int j = i+1; j < digits.size(); j++) {
				if (digits[j] == 0) continue;
				digits[i]--; digits[j]--;
				swap(digits[i], digits[j]);
				
				res.push_back(getValue(digits));
				
				swap(digits[i], digits[j]);
				digits[i]++; digits[j]++;
			}
		}
		return res;
	}
	
	bool canSwap(int x) {
		vector<int> digits = getDigits(x);
		int res = 0;
		for (int i = 0; i < digits.size(); i++) if (digits[i]) res ++;
		return res >= 2;
	}

	int DP(int x) {
		if (dp[x] == 0) {
			dp[x] = x;
			if (canSwap(x)) {
				vector<int> vi = emu(x); dp[x] = x;
				for (int i = 0; i < vi.size(); i++) {
					dp[x] =  max(dp[x], DP(vi[i]));
				}
			}
		}
		return dp[x];
	}

	int findMaximum(int N) {
		memset(dp, 0, sizeof(dp));
		return DP(N);
	}
};
