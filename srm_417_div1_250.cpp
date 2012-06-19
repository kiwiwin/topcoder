#include <string>

using namespace std;

class TemplateMatching {
public:
	string suffix, prefix;
	
	int prefixScore(const string &str) {
		for (int len = min(str.size(), prefix.size()); len > 0; len--) {
			if (str.substr(0, len) == prefix.substr(prefix.size()-len)) return len;
		}
		return 0;
	}
	
	int suffixScore(const string &str) {
		for (int len = min(str.size(), suffix.size()); len > 0; len--) {
			if (str.substr(str.size()-len) == suffix.substr(0, len)) return len;
		}
		return 0;
	}
	
	string compareTwo(const string& lhs, const string &rhs) {
		int lprefix = prefixScore(lhs), rprefix = prefixScore(rhs);
		int lsuffix = suffixScore(lhs), rsuffix = suffixScore(rhs);
		if (lprefix + lsuffix < rprefix + rsuffix) return rhs;
		if (lprefix + lsuffix > rprefix + rsuffix) return lhs;
		if (lprefix < rprefix) return rhs;
		if (lprefix > rprefix) return lhs;
		return min(lhs, rhs);
	}

	string bestMatch(string text, string _prefix, string _suffix) {
		prefix = _prefix; suffix = _suffix;
		string res = ""; res += *min_element(text.begin(), text.end());
		for (int i = 0; i < text.size(); i++)
		for (int len = 1; i+len <= text.size(); len++) {
			string substr = text.substr(i, len);
			res = compareTwo(res, substr);
		}
		return res;
	}
};
