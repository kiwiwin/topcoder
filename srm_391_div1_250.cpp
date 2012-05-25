#include <string>
#include <vector>
using namespace std;

class IsomorphicWords {
public:
	bool isIsomorphic(string lhs, string rhs) {
		char buf1[260]; memset(buf1, 0, sizeof(buf1));
		char buf2[260]; memset(buf2, 0, sizeof(buf2));
		for (int i = 0; i < lhs.size(); i++) {
			if (buf1[lhs[i]] == 0) buf1[lhs[i]] = rhs[i];
			if (buf2[rhs[i]] == 0) buf2[rhs[i]] = lhs[i];
			if (buf1[lhs[i]] != rhs[i] || buf2[rhs[i]] != lhs[i]) return false;
		}
		return true;
	}

	int countPairs(vector<string> words) {
		int res = 0;
		for (int i = 0; i < words.size(); i++)
			for (int j = i+1; j < words.size(); j++)
				res += isIsomorphic(words[i], words[j]);
		return res;
	}
};
