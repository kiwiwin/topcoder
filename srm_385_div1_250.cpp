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

class UnderscoreJustification {
public:
	string justifyLine(vector <string>, int);
	
	string buildLine(vector<string> &words, vector<int> &gaps) {
		string res = "";
		for (int i = 0 ; i < words.size()-1; i++)
			res += words[i] + buildSpace(gaps[i]);
		res += words[words.size()-1];
		return res;
	}
	
	string buildSpace(int num) {
		return string(num, '_');
	}
	
	int getRemainSpaces(vector<string> & words, int width) {
		int wordsLengthSum = 0;
		for (int i = 0; i < words.size(); i++) wordsLengthSum += words[i].size();
		return width - wordsLengthSum;
	}
	
	vector<int> buildGaps(int remain, int N) {
		vector<int> res(N, remain/N);
		for (int i = 0; i < remain%N; i++) res[i] ++;
		sort(res.begin(), res.end());
		return res;
	}
};

string UnderscoreJustification::justifyLine(vector <string> words, int width) {
	int remain = getRemainSpaces(words, width);
	vector<int> gaps = buildGaps(remain, words.size()-1);
	string res = buildLine(words, gaps);
	while(true) {
		if (!next_permutation(gaps.begin(), gaps.end())) break;
		res = min(res, buildLine(words, gaps));
	}
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!