#include <vector>

using namespace std;

class NumberofFiboCalls {
public:
	int dp0[45], dp1[45];

	vector <int> fiboCallsMade(int n) {
		memset(dp0, 0, sizeof(dp0));
		memset(dp1, 0, sizeof(dp1));
		
		dp0[0] = 1; dp1[1] = 1;
		
		for (int i = 2; i <= n; i++) {
			dp0[i] = dp0[i-1] + dp0[i-2];
			dp1[i] = dp1[i-1] + dp1[i-2];
		}
		
		vector<int> res;
		res.push_back(dp0[n]); res.push_back(dp1[n]);
		return res;
	}
};
