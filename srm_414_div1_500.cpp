#include <string>
#include <vector>

using namespace std;

class StringInterspersal {
public:
	int offset[25];
	
	int chooseBetween(int lhs, int rhs) {
		for (int i = 0; ;i++) {
			if (offset[lhs] + i >= W[lhs].size()) return rhs;
			if (offset[rhs] + i >= W[rhs].size()) return lhs;
			if (W[lhs][offset[lhs]+i] < W[rhs][offset[rhs]+i]) return lhs;
			if (W[lhs][offset[lhs]+i] > W[rhs][offset[rhs]+i]) return rhs;
		}
		return -1;
	}
	
	int chooseNext() {
		int res = -1;
		for (int i = 0; i < W.size(); i++) {
			if (offset[i] >= W[i].size()) continue;
			if (res < 0) res = i;
			else res = chooseBetween(res, i);
		}
		return res;
	}
	
	vector<string> W;

	string minimum(vector<string> _W) {
		//prepare begin
		W = _W;
		memset(offset, 0, sizeof(offset));
		//prepare end
		
		string res = "";

		int totalLetterNum = 0;
		for (int i = 0; i < W.size(); i++) totalLetterNum += W[i].size();
		
		while(totalLetterNum--) {
			int index = chooseNext();
			res += W[index][offset[index]];
			offset[index]++;
		}
		
		return res;
	}
};
