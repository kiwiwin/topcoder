#include <vector>
using namespace std;

class AvoidingProduct {
public:
	bool V[1052];
	
	vector<int> getTriple(vector<int> A, int n) {
		memset(V, true, sizeof(V));
		for (int i = 0; i < A.size(); i++) V[A[i]] = false;
		int rx = 0, ry = 0, rz = 0;
		int rval = 1000000000;
		
		for (int x = 1; x <= n+51; x++) if (V[x])
			for (int y = x ; y <= n+51; y++) if (V[y])
				for (int z = y; z <= n+51; z++) if (V[z]) {
					int tmp = x*y*z;
					if (rval > abs(n-tmp)) {rx = x; ry = y; rz = z; rval = abs(n-tmp);}
					if (tmp >= n) break;
				}

		vector<int> res;
		res.push_back(rx);
		res.push_back(ry);
		res.push_back(rz);
		return res;
	} 
};
