#include <string>
#include <vector>

using namespace std;

class CorporationSalary {
public:
	vector<string> R;
	long long S[55];
	
	long long solve(int index) {
		if (S[index] < 0) {
			S[index] = 0;
			for (int employee = 0; employee < R.size(); employee++) {
				if (R[index][employee] == 'Y') S[index] += solve(employee);
			}
			if (S[index] == 0) S[index] = 1;
		}
		return S[index];
	}

	long long totalSalary(vector<string> relations) {
		R = relations;
		for (int i = 0; i < R.size(); i++) S[i] = -1;
		long long res = 0;
		for (int i = 0; i < R.size(); i++) {
			res += solve(i);		
		}
		return res;
	}
};

