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

class FoxAndGCDLCM {
public:
	long long get(long long, long long);
};

long long FoxAndGCDLCM::get(long long G, long long L) {
	if (L%G!=0)
		return -1;
	long long temp=L/G;
	long long mn=1e15;
	long long int k1,k2;
	for (k1=1;k1*k1<=temp;k1++) {
		if (temp%k1==0) {
			k2=temp/k1;
			if (__gcd(k1,k2)==1)
				mn=min(mn,k1+k2);
		}
	}
	return mn*G;
}


//Powered by [KawigiEdit] 2.0!
