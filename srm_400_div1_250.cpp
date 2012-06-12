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
		sscanf(str.c_str(),"%lld", &res);
		return res;
	}
	
	bool isPrime(long long x) {
		for (long long i = 2; i*i <= x; i++)
			if (x % i == 0) return false;
		return true;
	}
	
	long long solve(long long val, long long power) {
		return subsolve(val, power, 2, 1000000000);
	}
	
	long long subsolve(long long val, long long power, long long l, long long r) {
		if (l > r) return -1;
		long long mid = (l+r)/2;
		long long tmp = power_up(mid, power);
		if (tmp == val) return mid;
		if (tmp == 0 || tmp > val) return subsolve(val, power, l, mid-1);
		else return subsolve(val, power, mid+1, r);
	}
	
	long long power_up(long long base, long long power) {
		long long res = 1;
		for (long long p = 1; p <= power; p++) {
			res *= base;
			if (res < 0) return 0;
		}
		return res;
	}
};

vector <int> StrongPrimePower::baseAndExponent(string n) {
	long long N = str2ll(n);
		
	for (long long power = 2; power <= 62; power ++) {
		long long base = solve(N, power);
		if (base < 0) continue;
		if (!isPrime(base)) continue;
		vector<int> res(2,0);
		res[0] = base; res[1] = power;
		return res;
	}
	
	return vector<int>();
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!