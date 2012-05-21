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

class DivisibleByDigits {
public:
	long long getContinuation(int);
	
	bool digit[10];
	
	bool divisible(long long x) {
		for (int i = 1; i <= 9; i++) if(digit[i] && x%i != 0)  return false;
		return true;
	}
	
	long long composite(long long x, string append) {
		string s = ll2str(x);
		return str2ll(s+append);
	}
	
	long long str2ll(string s) {
		stringstream ss; ss << s; long long res; ss >> res;
		return res;
	}
	
	string ll2str(long long x) {
		stringstream ss; ss << x; string res; ss >> res;
		return res;
	}
	
	string makeString(long long x, int digit) {
		string res(digit, '0');
		string s = ll2str(x);
		for (int i = 0; i < s.size(); i++)
			res[digit-s.size()+i] = s[i];
		return res;
	}
	
	vector<string> initAppend() {
		vector<string> res;
		for (int i = 0; i < 10; i++) res.push_back(makeString(i, 1));
		for (int i = 0; i < 100; i++) res.push_back(makeString(i, 2));
		for (int i = 0; i < 1000; i++) res.push_back(makeString(i, 3));
		for (int i = 0; i < 10000; i++) res.push_back(makeString(i, 4));
		return res;
	}
	
	void setDigit(int x) {
		while(x) {
			digit[x%10] = true; x/= 10;
		}
	}
};

long long DivisibleByDigits::getContinuation(int n) {	
	long long res = n;
	vector<string> append = initAppend();
	setDigit(n);
	
	int index = 0;
	while(!divisible(res)) {
		res = composite(n, append[index++]);
	}
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!