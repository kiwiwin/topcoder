#include <string>
#include <vector>
using namespace std;

double log[11] = {0.0, 0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001, 0.0000001, 0.00000001, 0.000000001, 0.0000000001};

class TheLotteryBothDivs {
public:
	bool isSuffix(string lhs, string rhs) {
		int l = lhs.size()-1; int r = rhs.size()-1;
		while(true) {
			if (r < 0) return true;
			if (l < 0) return false;
			if (lhs[l] != rhs[r]) return false;
			l--; r--;
		}
	}

	vector<string> eliminateDuplicate(vector<string> vs) {
		sort(vs.begin(), vs.end());
		vector<string> res; res.push_back(vs[0]);
		for (int i = 1; i < vs.size(); i++) {
			if (vs[i] != vs[i-1]) res.push_back(vs[i]);
		}
		return res;
	}

	vector<string> mergeSuffix(vector<string> suffix) {
		vector<string> res;
		vector<string> vs = eliminateDuplicate(suffix);
		for (int i = 0; i < vs.size(); i++) {
			bool f = true;
			for (int j = 0; j < vs.size(); j++) {
				if (i == j) continue;
				if (isSuffix(vs[i], vs[j])) { f = false; break; }		
			}
			if (f) res.push_back(vs[i]);
		}
		return res;
	}

	double find(vector <string> goodSuffixes) {
		double res = 0;
		
		vector<string> suffix = mergeSuffix(goodSuffixes);
		for (int i = 0; i < suffix.size(); i++) {
			res += log[suffix[i].size()];
		}

		return res;
	}
};
