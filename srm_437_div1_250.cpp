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

	int findMax(int n, int K) {
		vector<string> Old;	Old.push_back(int2str(n));
		set<string> New;
		for (int k = 1; k <= K; k++) {
			for (int o = 0; o < Old.size(); o++) {
				for (int i = 0; i < Old[o].size(); i++)
				for (int j = i+1; j < Old[o].size(); j++) {
					if (Old[o][j] == '0' && i == 0) continue;
					string s = Old[o];
					swap(s[i], s[j]);
					New.insert(s);
				}
			}
			Old.clear();
			Old = vector<string>(New.begin(), New.end());
			New.clear();
		}
		
		int result = -1;
		for (int i = 0; i < Old.size(); i++) {
			result = max(result, str2int(Old[i]));
		}
		return result;
	}
};
