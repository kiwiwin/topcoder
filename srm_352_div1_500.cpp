#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

typedef long long LL;

class FibonacciKnapsack {
public:
	map<LL, LL> fib;
	vector<LL> W;
	vector<LL> P;
	LL T;	
	
	void handleInput() {
		for (int i = 0; i < items.size(); i++) {
			LL w, p;
			sscanf(items[i].c_str(), "%lld %lld", &w, &p);
			W.push_back(w); P.push_back(p);			
		}
		
		LL T; sscanf(C.c_str(), "%lld", &T);
		fib[0] = 0;
		
		for (int i = 0; i < items.size(); i++) 
			for (int j = i+1; j < items.size(); j++) {
				if (W[i] < W[j] || W[i] == W[j] && P[i] < P[j]) {
					swap(W[i], W[j]); swap(P[i], P[j]);
				}
		}
	}

	long long maximalCost(vector <string> items, string C) {
		handleInput();
	}
};

LL FibonacciKnapsack::maximalCost(vector <string> items, string C)
{
		LL sw[55], sc[55];
		memset(sw, 0, sizeof(sw));
		memset(sc, 0, sizeof(sc));
		for (int i = items.size()-1; i >= 0; i--) {
			sw[i] = sw[i+1] + W[i];
			sc[i] = sc[i+1] + P[i];
		}
		
		map<LL, LL> R;
		
		for (int i = 0; i < W.size(); i++) {
			for (map<LL, LL>::reverse_iterator itr = fib.rbegin(); itr != fib.rend(); itr++) {			
				if (itr->first + sw[i] <= T) {
					if (R.count(itr->first + sw[i]))
						R[itr->first + sw[i]] = max(R[itr->first + sw[i]], itr->second + sc[i]);
					else
					 	R[itr->first + sw[i]] = itr->second + sc[i];
					continue;
				}
			
				if (itr->first + W[i] <= T) {
					if (fib.count(itr->first + W[i])) {
						fib[itr->first + W[i]] = max(fib[itr->first + W[i]], itr->second + P[i]);
					}else {
						fib[itr->first + W[i]] = itr->second + P[i];
					}
				}
			}
			cout << fib.size() << " " << R.size() << endl;
		}
		
		LL res = 0;
		for (map<LL, LL>::iterator itr = R.begin(); itr != R.end(); itr++) {
			res = max(res, itr->second);
		}
		
		for (map<LL, LL>::iterator itr = fib.begin(); itr != fib.end(); itr++) {
			res = max(res, itr->second);
		}

		return res;
	}
