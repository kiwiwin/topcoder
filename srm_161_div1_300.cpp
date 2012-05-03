#include <vector>
#include <string>

using namespace std;

class IsHomomorphism {
public:
	vector <int> mapping;
	vector <string> source;
	vector <string> target;
	
	int sourceFunction(int r, int c) {
		return mapping[source[r][c] - '0']; 
	}
	
	int targetFunction(int r, int c) {
		return target[mapping[r]][mapping[c]] - '0';
	}
	
	string pairToStr(int r, int c) {
		char buf[250];
		sprintf(buf, "(%d,%d)", r, c);
		return buf;
	}

	vector <string> numBad(vector <string> source_, vector <string> target_, vector <int> mapping_) {
		mapping = mapping_; source = source_; target = target_;
		vector<string> res;
		for (int r = 0; r < source.size(); r++)
			for (int c = 0; c < source[r].size(); c++)
				if (sourceFunction(r, c) != targetFunction(r, c)){
					res.push_back(pairToStr(r, c));
				}
		return res;
	}
};
