#include <string.h>

class PrimeSoccer {
public:
	double dp[19][19][19]; //interval, A, B
	//prime number: 2, 3, 5, 7, 11, 13, 17

	bool isPrime(int x) {
		return x == 2 || x == 3 || x == 5
			|| x == 7 || x == 11 || x == 13
			|| x == 17;
	}

	double getProbability(int skillA, int skillB) {
		memset(dp, 0, sizeof(dp));
		double PA = skillA/100.0;
		double PB = skillB/100.0;
		
		dp[0][0][0] = 1;
		
		for (int i = 1; i <= 18; i++) {
			for (int A = 0; A < i; A++) 
			for (int B = 0; B < i; B++) {
				dp[i][A][B] += dp[i-1][A][B] * (1-PA) * (1-PB);
				dp[i][A+1][B] += dp[i-1][A][B] * PA * (1-PB);
				dp[i][A][B+1] += dp[i-1][A][B] * (1-PA) * PB;
				dp[i][A+1][B+1] += dp[i-1][A][B] * PA * PB;
			}
		}
		
		double res = 0;
		for (int A = 0; A <= 18; A++)
		for (int B = 0; B <= 18; B++)
			if (isPrime(A) || isPrime(B)) res += dp[18][A][B];
		return res;
	}
};
