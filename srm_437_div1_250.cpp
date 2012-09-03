#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

class TheSwap {
public:
	string int2str(int x) {
		stringstream ss; ss << x;
		return ss.str();
	}
	
	int str2int(string s) {
		stringstream ss; ss << s;
		int x; ss >> x;
		return x;
	}
	
	int solve(const vector<string> &V, int K) {
		if (K == 0) {
			if (V.empty()) return -1;
			else return str2int(*max_element(V.begin(), V.end()));
		}

		set<string> next;

		for (int v = 0; v < V.size(); v++) 
			for (int i = 0; i < V[v].size(); i++)
			for (int j = i+1; j < V[v].size(); j++) {
				if (V[v][j] == '0' && i == 0) continue;
				string s = V[v];
				swap(s[i], s[j]);
				next.insert(s);
			}
			
		return solve(vector<string>(next.begin(),next.end()), K-1);
	}

	int findMax(int n, int K) {
		vector<string> init;	
		init.push_back(int2str(n));
		return solve(init, K);
	}
};
