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

class BestView {
public:
	int numberOfBuildings(vector <int>);
	vector<long long> H;
	
	bool isObstacle(int l, int mid, int r) {
		return (H[mid]-H[l])*(r-l) >= (H[r]-H[l])*(mid-l);
	}
	
	bool visible(int l, int r) {
		if (l > r) swap(l,r);
		for (int mid = l+1; mid <= r-1; mid++) {
			if (isObstacle(l, mid, r)) return false;
		}
		return true;
	}
};

int BestView::numberOfBuildings(vector <int> _H) {
	H.resize(_H.size());
	copy(_H.begin(), _H.end(), H.begin());
	int result = 0;
	for (int i = 0; i < H.size(); i++) {
		int temp = 0;
		for (int j = 0; j < H.size(); j++) {
			if (i == j) continue;
			if (visible(i,j)) temp++;
		}	
		result = max(temp, result);
	}
	return result;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!