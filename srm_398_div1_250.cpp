#include <vector>
#include <algorithm>

using namespace std;

class CountExpressions {
public:
	int count(const vector<int> &X) {
		vector<int> tmp; tmp.push_back(X[0]);
		for (int oper = 0; oper < 3; oper++) {
			vector<int> next;
			for (int i = 0; i < tmp.size(); i++) {
				next.push_back(tmp[i]+X[oper+1]);
				next.push_back(tmp[i]-X[oper+1]);
				next.push_back(tmp[i]*X[oper+1]);
			}
			tmp = next;
		}
		int res = 0;
		for (int i = 0; i < tmp.size(); i++)
			if (tmp[i] == VAL) res++;
		return res;
	}

	int VAL;

	int calcExpressions(int x, int y, int val) {
		vector<int> X; VAL = val;
		if(x > y) swap(x,y);
		X.push_back(x);		
		X.push_back(x);		
		X.push_back(y);		
		X.push_back(y);
		int res = count(X);
		while(next_permutation(X.begin(), X.end())) {
			res += count(X);
		}
		return res;
	}
};
