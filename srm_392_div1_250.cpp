#include <string>

using namespace std;

class TwoStringMasks {
public:
	string filterStar(string s) {
		string res = "";
		for (int i = 0; i < s.size(); i++) if (s[i] != '*') res += s[i];
		return res;
	}

	string mergeStar(string s1, string s2) {
		if (s1 == "*") return filterStar(s2);
		if (s2 == "*") return filterStar(s1);
	
		if (s1[0] == '*') swap(s1, s2);
		s1 = s1.substr(0, s1.size()-1);
		s2 = s2.substr(1, s2.size()-1);
		
		int middle = 0;
		for (int merge = 1; merge <= min(s1.size(), s2.size()); merge++) {
			if (s1.substr(s1.size()-merge, merge) == s2.substr(0, merge)) middle = merge;
		}
		return s1 + s2.substr(middle, s2.size()-middle);
	}

	string shortestCommon(string s1, string s2) {
		string prefix = ""; string suffix = "";
		for (int i =  0; i < s1.size() && i < s2.size(); i++) {
			if (s1[i] == '*' || s2[i] == '*') break;
			if (s1[i] != s2[i]) return "impossible";
			prefix += s1[i];
		}
		
		for (int i = -1; i+(int)s1.size() >= 0 && i+(int)s2.size() >= 0; i--) {
			if (s1[i+s1.size()] == '*' || s2[i+s2.size()] == '*') break;
			if (s1[i+s1.size()] != s2[i+s2.size()]) return "impossible";
			suffix = s1[i+s1.size()] + suffix;
		}
		
		string s1_middle = s1.substr(prefix.size(), s1.size()-prefix.size()-suffix.size());
		string s2_middle = s2.substr(prefix.size(), s2.size()-prefix.size()-suffix.size());
		return prefix + mergeStar(s1_middle, s2_middle) + suffix;	
	}
};
