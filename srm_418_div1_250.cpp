#include <string.h>

class TwoLotteryGames {
public:
	double getHigherChanceGame(int n, int m, int k) {
		int C[10][10];
		memset(C, 0, sizeof(C));
		C[0][0] = 1;
		for (int i = 1; i < 10; i++) {
			C[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				C[i][j] = C[i-1][j] + C[i-1][j-1];
			}
		}
		
		int possible = C[n][m];
		double res = 0;
		for (int right = k; right <= m; right++) {
			res += C[m][right] * C[n-m][m-right];
		}
		return res/possible;
	}
};
