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

class CandidateKeys {
public:
	vector <int> getKeys(vector <string>);
	vector<string> table;
	bool key[1<<10];
	
	bool isKey(int mask) {
		for (int i = 0; i < table.size(); i++) 
		for (int j = i+1; j < table.size(); j++) 
			if (entryEqual(table[i],table[j],mask)) return false;
		return true;
	}
	
	bool entryEqual(string lhs, string rhs, int mask) {
		for (int i = 0; i < table[0].size(); i++) {
			if ((mask&(1<<i)) && lhs[i] != rhs[i]) return false; 
		}
		return true;
	}
	
	bool isSuperKey(int mask) {
		if (!key[mask]) return false;
		for (int sub = 1; sub < mask; sub++)
			if ((sub&mask) == sub && key[sub]) return false;
		return true;
	}
	
	int maskSize(int mask) {
		return __builtin_popcount(mask);
	}
};

vector <int> CandidateKeys::getKeys(vector <string> table_) {
	table = table_; memset(key, 0, sizeof(key));
	for (int mask = 1; mask < (1<<table[0].size()); mask++) {
		key[mask] = isKey(mask);
	}
	int MIN = 100, MAX = -1;
	for (int mask = 1; mask < (1<<table[0].size()); mask++) {
		if (isSuperKey(mask)) {
			MIN = min(maskSize(mask), MIN);
			MAX = max(maskSize(mask), MAX);
		}
	}	
	
	vector<int> res;
	if (MAX < 0) return res;
	res.push_back(MIN); res.push_back(MAX);
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!