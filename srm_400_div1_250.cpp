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

class StrongPrimePower {
public:
	vector <int> baseAndExponent(string); 
	long long str2ll(const string &str) {
		long long res;
		sscanf(str.c_str(), "%lld", &res);
		return res;
	}
	
	long long solve(long long val, long long power) {
		return round(pow(1.0*val, 1.0/power));
	}
	
	bool isPrime(int x) {
		for (int p = 2; p*p <= x; p++)
			if (x % p == 0) return false;
		return true;
	}
	
	bool check(long long base, long long power, long long val) {
		long long temp = 1;
		for (int i = 1; i <= power; i++) temp *= base;
		return temp == val;
	}
};

vector <int> StrongPrimePower::baseAndExponent(string n) {
	long long N = str2ll(n);
		
	for (long long power = 2; power <= 62; power ++) {
		long long base = solve(N, power);
		if (!isPrime(base)) continue;
		if (!check(base, power, N)) continue;
		vector<int> res(2,0);
		res[0] = base; res[1] = power;
		return res;
	}
	
	return vector<int>();
}


//Powered by [KawigiEdit] 2.0!
