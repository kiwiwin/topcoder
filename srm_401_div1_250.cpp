#include <string.h>

class FIELDDiagrams {
public:
	long long dp[35][35];
	
	long long countDiagrams(int fieldOrder) {
		memset(dp, 0, sizeof(dp));
		
		dp[1][1] = 1; dp[1][0] = 1;
		
		for (int level = 2; level <= fieldOrder; level++) {
			dp[level][0] = 1;
			for (int bottom = 1; bottom <= level; bottom++) {
				for (int prev = 0; prev <= bottom; prev++) {
					dp[level][bottom] += dp[level-1][prev];
				}
			}
		}
		
		long long res = 0;
		for (int bottom = 1; bottom <= fieldOrder; bottom++) {
			res += dp[fieldOrder][bottom];
		}
		return res;
	}
};
