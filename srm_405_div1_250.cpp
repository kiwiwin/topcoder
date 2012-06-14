#include <sstream>
#include <string>
#include <vector>

using namespace std;

class RelativePath {
public:
	vector<string> getDirs(string path) {
		vector<string> res;
		for (int i = 0; i < path.size(); i++) if (path[i] == '/') path[i] = ' ';
		stringstream ss(path);
		string s;
		while(ss >> s) res.push_back(s);
		return res;
	}
	
	int commonDirNum(const vector<string> &lhs, const vector<string> &rhs) {
		int res = 0;
		for (int i = 0; i < min(lhs.size(), rhs.size()); i++) {
			if (lhs[i] == rhs[i]) res++;
			else break;
		}
		return res;
	}

	string makeRelative(string path, string currentDir) {
		vector<string> dest = getDirs(path);
		vector<string> source = getDirs(currentDir);
		
		int common = commonDirNum(dest, source);
		int father = source.size() - common;
		
		string res = "";
		for (int i = 0; i < father; i++) res += "../";
		for (int i = common; i < dest.size(); i++) {
			res += dest[i];
			if (i != dest.size() - 1) res += "/";
		}
		return res;
	}
};
