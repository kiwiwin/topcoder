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

class MagicWords {
public:
	int count(vector <string>, int);
	vector<int> PER;
	vector<string> S;
	int K;
	
	string makeWord() {
		string result = "";
		for (int i =  0; i < PER.size(); i++) result += S[PER[i]];
		return result;
	}
	
	bool checkWord(const string &word) {
		int N = word.size();
		if (N % K != 0) return false;
		int period = N/K;
		if (isPeriod(word.substr(0, period))) return false;
		for (int i = 0; i < word.size(); i++)
			if (word[i] != word[(i+period)%N]) return false;
		return true;
	}
	
	bool isPeriod(const string& str) {
		for (int period = 1; period < str.size(); period++) {
			if (str.size() % period != 0) continue;
			bool flag = true;
			for (int offset = 0; offset < period; offset++) {
				int base = str[offset]; int next = offset + period;
				while(next < str.size()) {
					if (base != str[next]) { flag = false; break; }
					next += period;
				}
			}
			if (flag) return true; 
		}
		return false;
	}
	
	bool nextWord() {
		return next_permutation(PER.begin(), PER.end());
	}
};

int MagicWords::count(vector <string> _S, int _K) {
	S = _S; K = _K;
	for (int i = 0; i < S.size(); i++) PER.push_back(i);
	
	int result = 0;
	do {
		string word = makeWord();
		if (checkWord(word)) result++;
	}while(nextWord());
	return result;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!