#include <string>
#include <vector>
using namespace std;

class Animation {
public:
	int SIZE;

	vector<int> getLeftChamper(string init) {
		vector<int> res;
		for (int i = 0; i < init.size(); i++)
			if (init[i] == 'L') res.push_back(i);
		return res;
	}
	
	vector<int> getRightChamper(string init) {
		vector<int> res;
		for (int i = 0; i < init.size(); i++)
			if (init[i] == 'R') res.push_back(i);
		return res;
	}

	vector<int> moveLeft(vector<int> cham, int speed) {
		vector<int> res;
		for (int i = 0; i < cham.size(); i++) 
			if (cham[i] - speed >= 0) res.push_back(cham[i] - speed);
		return res;
	}
	
	vector<int> moveRight(vector<int> cham, int speed) {
		vector<int> res;
		for (int i = 0; i < cham.size(); i++) 
			if (cham[i] + speed < SIZE) res.push_back(cham[i] + speed);
		return res;
	}

	string getOccupied(vector<int> l, vector<int> r) {
		string res(SIZE, '.');
		for (int i = 0; i < l.size(); i++) res[l[i]] = 'X';
		for (int i = 0; i < r.size(); i++) res[r[i]] = 'X';
		return res;
	}

	vector <string> animate(int speed, string init) {
		SIZE = init.size();
		vector<int> lc = getLeftChamper(init);
		vector<int> rc = getRightChamper(init);		
		
		vector<string> res;
		while(true) {
			string round = getOccupied(lc, rc);
			res.push_back(round);
			if (lc.empty() && rc.empty()) break;
			lc = moveLeft(lc, speed); rc = moveRight(rc, speed);
		}
		return res;
	}
};
