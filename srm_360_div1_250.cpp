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

class SumOfSelectedCells {
public:
	string hypothesis(vector <string>);
	vector<vector<int> > table;
	
	void handleInput(vector<string> &t) {
		for (int i = 0; i < t.size(); i++) {
		vector<int> vi; int x;
		stringstream ss(t[i]);
		while(ss >> x) vi.push_back(x);
		table.push_back(vi);
		}
	}
	
	bool checkYX() {
		for (int y = 1; y < table.size(); y++)
		for (int x = 0; x < table[y].size(); x++) 
			if(table[y][x] != table[y-1][x]) return false;
		return true;
	}
	
	bool checkXY() {
		for (int x = 1; x < table[0].size(); x++)
		for (int y = 0; y < table.size(); y++)
			if (table[y][x] != table[y][x-1]) return false;
		return true;
	}
	
	bool checkSquare() {
		for (int x1 = 0; x1 < table.size(); x1++)
		for (int x2 = x1+1; x2 < table.size(); x2++) 
		for (int y1 = 0; y1 < table[0].size(); y1++)
		for (int y2 = y1+1; y2 < table[0].size(); y2++) 
			if (table[x1][y1] + table[x2][y2] != table[x1][y2] + table[x2][y1]) return false;
		return true;
	}
};

string SumOfSelectedCells::hypothesis(vector <string> t) {
	handleInput(t);
	
	bool correct = false;
	if (table.size() > table[0].size()) correct = checkYX();
	else if (table[0].size() > table.size()) correct = checkXY();
	else correct = checkSquare();
	
	return correct ? "CORRECT" : "INCORRECT";
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!