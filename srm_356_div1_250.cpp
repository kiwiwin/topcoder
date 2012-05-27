#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;

class AverageProblem {
public:
	string getFloat(double d) {
		char buf[10];
		sprintf(buf,"%d", (int)floor(d));
		return string(3-strlen(buf), '0') + buf;
	}
	
	bool check(int p, string s) {
		for (int i = 0; i < p; i++) {
			if (getFloat(1000.0*i/p) == s) return true;
		}		
		return false;
	}


	bool check(int p, vector<string> score) {
		for (int i = 0 ; i < score.size(); i++) {
			if (!check(p, score[i])) return false;			
		}
		return true;
	}
	
	vector<string> split(string str) {
		vector<string> res;
		stringstream ss(str);	string s;
		while(ss >> s) res.push_back(s);
		return res;
	}
	
	string mergeString(vector<string> vs) {
		string res = "";
		for (int i = 0; i < vs.size(); i++) res += vs[i] + " ";
		return res;
	}

	vector<string> getFloat(vector<string> vs) {
		vector<string> res;
		for (int i = 0; i < vs.size(); i++)
			res.push_back(vs[i].substr(vs[i].size()-3, 3));
		return res;
	}

	int numberOfParticipants(vector <string> marks) {
		string str = mergeString(marks);
		vector<string> vs = split(str);
		vector<string> vs_float = getFloat(vs);
		
		for (int i = 1; i <= 1000; i++) {
			if (check(i, vs_float)) return i;
		}
	}
};
