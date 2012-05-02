#include <string>
#include <vector>
using namespace std;

class CheatCode {
public:
	vector<pair<char,int> > str2vp(string str) {
		vector<pair<char,int> > res;
		char c = str[0]; int cnt = 1;
		for (int i = 1; i < str.size(); i++) {
			if (str[i] == c) cnt++;
			else {
				res.push_back(make_pair(c, cnt));
				c = str[i]; cnt = 1;
			}
		}
		res.push_back(make_pair(c, cnt));
		return res;
	}

	bool isCheat(string sub, string str) {
		vector<pair<char,int> > child = str2vp(sub);
		vector<pair<char,int> > parent = str2vp(str);		
		
		string cs = ""; for (int i = 0; i < child.size(); i++) cs += child[i].first;
		string ps = ""; for (int i = 0; i < parent.size(); i++) ps += parent[i].first;
		
		int index = 0;
		while(true) {
			index = ps.find(cs, index);
			if (index == string::npos) return false;
			bool flag = true;
			for (int i = 0; i < child.size(); i++) {
				if (child[i].second > parent[i+index].second) { flag = false; break; }
			}
			if (flag) return true;	
			index++;	
		}
	}

	vector <int> matches(string key, vector <string> codes) {
		vector<int> res;
		for (int i = 0; i < codes.size(); i++) {
			if (isCheat(codes[i], key)) res.push_back(i);
		}
		return res;
	}
};
