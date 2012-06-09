#include <string>

using namespace std;

class StrIIRec {
public:
	int N, minInv;
	string minStr;

	int countInv(const string &str) {
		int res = 0;
		for (int i = 0; i < str.size(); i++) 
			for (int j = i+1; j < str.size(); j++)
				if (str[i] > str[j]) res++;
		return res;
	}

	string solve(const string &now) {
		if (now.size() == N) {
			if (countInv(now) >= minInv && now >= minStr) return now;
			else return "";
		}
		
		string res = "";
		for (char c = 'a'; c <= 'a'+N-1; c++) {
			if (now.find(c) != string::npos) continue;
			if (!check(now+c)) continue;
			res = solve(now+c);
			if (res != "") return res;
		}
		return res;
	}
	
	bool check(string now) {
		int cnt = countInv(now);
		cnt += maxInv(N - now.size());
		for (int i = 0; i < now.size(); i++) {
			for (char c = 'a'; c <= 'a'+N-1; c++) {
				if (now.find(c) != string::npos) continue;
				if (now[i] > c) cnt++;
			}
		}
		return cnt >= minInv;
	}
	
	int maxInv(int n) {
		return n*(n-1)/2;
	}

	string recovstr(int n, int _minInv, string _minStr) {
		N = n; minInv = _minInv; minStr = _minStr;

		string res  = "";
		for (int i = minStr.size(); i >= 0; i--) {
			res = solve(minStr.substr(0, i));
			if (res != "") return res;
		}
		return res;
	}
};
