#include <string>
#include <vector>

using namespace std;

class OrderedSuperString {
public:
	int longestCommonStart(string lhs, string rhs, int from) {
		for (int i = from; i < lhs.size(); i++) {
			bool flag = true;
			for (int offset = 0; i+offset < lhs.size() && offset < rhs.size(); offset++) {
				if (lhs[i+offset] !=  rhs[offset]) { flag = false; break; }
			}
			if (flag) return i;
		}
		return lhs.size();
	}
	
	string mergeCommon(string base, string word, int len) {
		string res = base;
		for (int i = 0; i < word.size(); i++) {
			if (i+len >= base.size()) res += word[i];
		}
		return res;
	}

	int getLength(vector<string> words) {
		string res = ""; int from = 0;
		for (int i = 0; i < words.size(); i++) {
			int len = longestCommonStart(res, words[i], from);
			res = mergeCommon(res, words[i], len);
			from = len;
		}
		return res.size();
	}
}; 
