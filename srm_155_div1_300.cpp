#include <vector>
#include <string>
using namespace std;

class PaternityTest {
public:
	bool checkValidMask(int n, int mask) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (mask & (1<<i)) cnt++;
		}
		return cnt * 2 == n;
	}

	string substrWithMask(string str, int mask) {
		string res = "";
		for (int i = 0; i < str.size(); i++)
			if (mask & (1 << i)) res += str[i];
		return res;
	}

	bool checkParents(string child, string mother, string men, int mask) {
		for (int i = 0; i < child.size(); i++) {
			if (mask & (1<<i)){ if (child[i] != mother[i]) return false;}
			else {if (child[i] != men[i]) return false;}			
		}
		return true;
	}

	vector <int> possibleFathers(string child, string mother, vector <string> men) {
		vector<int> res;
		bool father[10]; memset(father, 0, sizeof(father));
		for (int mask = 0; mask < (1 << child.size()); mask++) {
			if (!checkValidMask(child.size(), mask)) continue;
			for (int i = 0; i < men.size(); i++)
				if (checkParents(child, mother, men[i], mask)) father[i] = true;
		}
		for (int i = 0; i < men.size(); i++) if(father[i]) res.push_back(i);
		return res;
	}
};
