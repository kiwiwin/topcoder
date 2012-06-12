#include <vector>
#include <iostream>
using namespace std;

class AvoidingProduct {
public:
	bool V[1052];
	int N;
	vector<int> val[2605];
	vector<int> val2[132652];
	
	vector<int> small(const vector<int> &lhs, const vector<int> &rhs) {
		for (int i = 0; i < 3; i++) {
			if (lhs[i] < rhs[i]) return lhs;
			if (lhs[i] > rhs[i]) return rhs;
		}
		return lhs;
	}
	
	vector<int> getTriple(vector<int> A, int n) {
		memset(V, true, sizeof(V));
		for (int i = 0; i < A.size(); i++) V[A[i]] = false;
		N = n;
	
		for (int x = 1; x <= 1000; x++) {
			if (!V[x]) continue;
			for (int y = x; y <= 1000; y++) {
				if (!V[y]) continue;
				if (x*y > 2601) continue;
				vector<int> tmp; tmp.push_back(x); tmp.push_back(y);
				if (val[x*y].empty()) val[x*y] = tmp;
			}
		}

		for (int v = 1; v <= 2601; v++) {
			if (val[v].empty()) continue;
			for (int z = val[v][1]; z <= 1051; z++) {
				if (!V[z]) continue;
				if (v*z > 132651) continue;
				vector<int> tmp = val[v]; tmp.push_back(z);
				if (val2[v*z].empty()) val2[v*z] = tmp;
				else {
					val2[v*z] = small(tmp, val2[v*z]);
				}
			}
		}
		
		int MIN_ABS = 132700; vector<int> res;
		for (int v = 1; v <= 132651; v++) {
			if (val2[v].empty()) continue;
			if (res.empty()) {
				res = val2[v];
				MIN_ABS = abs(n-v);
			} else if (MIN_ABS > abs(n-v)) {
				res = val2[v];
				MIN_ABS = abs(n-v);
			} else if (MIN_ABS == abs(n-v)) {
				res = small(res, val2[v]);
			}
		}
		return res;
	} 
};
