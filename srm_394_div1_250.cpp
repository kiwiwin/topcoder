#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class RoughStrings {
public:
	int minRoughness(string, int);
	
	int needErase(vector<int> now, int big, int small) {
		int res = 0;
		for (int i = 0; i < now.size(); i++) {
			if (now[i] > big) res += now[i] - big;
			if (now[i] < small) res += now[i];
		}
		return res;
	}
	
	vector<int> countChar(string s) {
		vector<int> res(26,0);
		for (char c = 'a'; c < 'z'; c++) {
			for (int i = 0; i < s.size(); i++) if (s[i] == c) res[s[i]-'a']++;
		}
		return res;
	}
	
	vector<int> eliminateZero(vector<int> vi) {
		vector<int> res;
		for (int i = 0; i < vi.size(); i++) if (vi[i] > 0) res.push_back(vi[i]);
		return res;
	}
};

int RoughStrings::minRoughness(string s, int n) {
	vector<int> vi = countChar(s);
	sort(vi.begin(), vi.end(), greater<int>());
	vector<int> now = eliminateZero(vi);
	
	int res = s.size();
	for (int big = 1; big <= s.size(); big++) 
		for (int small = 1; small <= big; small++) {
			if (needErase(now, big, small) <= n) res = min(res, big-small);
		}
	return res;
}


//Powered by [KawigiEdit] 2.0!
