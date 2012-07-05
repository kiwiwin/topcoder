#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class ShipLoading {
public:
	vector<int> B;
	vector<bool> V;
	
	string connectString(const vector<string> &boxes) {
		string res = "";
		for (int i = 0; i < boxes.size(); i++) res += boxes[i];
		return res;
	}
	
	vector<int> str2vi(const string &str) {
		vector<int> res;
		stringstream ss(str); int x;
		while(ss >> x) res.push_back(x);
		return res;
	}

	int minimumTime(vector<int> cranes, vector<string> boxes) {
		string boxesStr = connectString(boxes);
		B = str2vi(boxesStr);
		sort(B.begin(), B.end(), greater<int>());
		sort(cranes.begin(), cranes.end(), greater<int>());
		V = vector<bool>(B.size(), false);
		int res = 0; int count = B.size();
		while(count) {
			bool flag = false;
			int c = 0;
			for (int b = 0; b < B.size(); b++) {
				if (V[b]) continue;
				if (cranes[c] >= B[b]) { c++; V[b] = true; flag = true; count--; }
				if (c >= cranes.size()) break;
			}
			
			if (!flag) return -1;
			else res++;
		}
		return res;
	}
};
