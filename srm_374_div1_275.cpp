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

struct Word {
	string word;
	vector<string> syllable;

	 Word(string word_):word(word_) {
	 	split();
	 }
	 
	 bool isVowel(char c) {
	 	return c == 'a'|| c == 'e'|| c == 'i'|| c == 'o'|| c == 'u';
	 }
	 
	 void split() {
	 	string s = ""; 	bool flag = false;
	 	for (int i = 0; i < word.size(); i++) {
	 		if (!flag) {
	 			s+=word[i];
	 			if (isVowel(word[i])) flag = true;
	 		}else{
	 			if (isVowel(word[i])) s+=word[i];
	 			else { syllable.push_back(s); s=""; s+=word[i]; flag = false;}
	 		}
	 	}
	 	syllable.push_back(s);
	 }

	vector<string> getSortedSyllable() const {
		vector<string> res = syllable;
		sort(res.begin(), res.end());
		return res;
	}
	
	bool operator < (const Word & obj) const {
		vector<string> lhs = getSortedSyllable();
		vector<string> rhs = obj.getSortedSyllable();
		if (cmp(lhs, rhs) != 0) return cmp(lhs, rhs) > 0;
		return cmp(syllable, obj.syllable) > 0;	
	}
	
	int cmp(const vector<string> &lhs, const vector<string> &rhs) const {
		for (int i = 0; i < lhs.size(); i++) {
			if (i >= rhs.size()) return -1;
			if (lhs[i] != rhs[i]) return lhs[i] < rhs[i] ? 1 : -1;
		}
		if (rhs.size() > lhs.size()) return 1;
		return 0;
	}
};

class SyllableSorting {
public:
	vector <string> sortWords(vector <string>);
};

vector <string> SyllableSorting::sortWords(vector <string> words) {
	vector<Word> vw;
	for (int i = 0; i < words.size(); i++) vw.push_back(Word(words[i]));
	sort(vw.begin(), vw.end());
	vector<string> res;
	for (int i = 0; i < vw.size(); i++) res.push_back(vw[i].word);
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!