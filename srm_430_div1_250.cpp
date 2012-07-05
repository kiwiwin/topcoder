#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

typedef long long ll;

class BitwiseEquations {
public:
	string ll2str(ll x) {
		string res = "";
		while(x) {
			res += ('0'+x%2);
			x /= 2;
		}
		reverse(res.begin(), res.end());
		return res;
	}
	
	int count0(const string &str) {
		int res = 0;
		for (int i = 0; i < str.size(); i++) if (str[i] == '0') res++;
		return res;
	}
	
	string merge(const string &s1, const string &s2) {
		int c0 = count0(s1);
		string res = string(max((int)s2.size()-c0, 0), '0') + s1;
		int offset = res.size()-1;
		for (int i = s2.size()-1; i >= 0; i--) {
			while(res[offset] != '0') offset--;
			res[offset] = s2[i];
			offset--;
		}
		
		return res;
	}
	
	ll str2ll(string s) {
		ll res = 0; ll base = 1;
		for (int i = s.size()-1; i >=0; i--) {
			res += base * (s[i]-'0');
			base *= 2;
		}
		return res;
	}

	ll kthPlusOrSolution(int x, int k) {
		return str2ll(merge(ll2str(x), ll2str(k))) - x;
	}
};
