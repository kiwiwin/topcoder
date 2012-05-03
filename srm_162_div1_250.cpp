#include <vector>
#include <algorithm>
using namespace std;

class PaperFold {
public:
	int needFolds(double from, double to) {
		int res = 0;
		while(from > to) {
			res ++; from /= 2;
		}
		return res;
	}

	int numFolds(vector <int> paper, vector <int> box) {
		int res = needFolds(paper[0], box[0]) + needFolds(paper[1], box[1]);	
		res = min(res, needFolds(paper[0], box[1]) + needFolds(paper[1], box[0]));
	
		if (res > 8) return -1;
		return res;
	}
};
