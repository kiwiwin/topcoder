#include <string>
#include <algorithm>

using namespace std;

class TheLuckyString {
public:
	
	bool isLuckyString(const string &str) {
		for (int i = 1; i < str.size(); i++)
			if (str[i] ==  str[i-1]) return false;
		return true;
	}

	int count(string s) {
		int res = 0;
		sort(s.begin(), s.end());
		res += isLuckyString(s);
		while(next_permutation(s.begin(), s.end())) {
			res += isLuckyString(s);
		}
		return res;	
	}
};
