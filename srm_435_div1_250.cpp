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

class CellRemoval {
public:
	int cellsLeft(vector <int>, int);
	
	vector<int> getLeaf(const vector<int> &parents) {
		bool father[55]; memset(father, false, sizeof(father));
		for (int i = 0; i < parents.size(); i++) {
			if (parents[i] >= 0) father[parents[i]] = true;
		}
		vector<int> result;
		for (int i = 0; i < parents.size(); i++) if (!father[i]) result.push_back(i);
		return result;
	}
	
	bool isAncestor(const vector<int> &parent, int father, int child) {
		while(parent[child] != -1) {
			if (parent[child] == father) return true;
			child = parent[child];
		}
		return false;
	}
};

int CellRemoval::cellsLeft(vector <int> parent, int deletedCell) {
	vector<int> leaf = getLeaf(parent);
	int result = 0;
	for (int i = 0; i < leaf.size(); i++) {
		if (deletedCell == leaf[i]) continue;
		if (!isAncestor(parent, deletedCell, leaf[i])) result++;
	}
	return result;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!