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

class Planks {
public:
	int makeSimilar(vector <int>, int, int);
	int cutLength(int length, vector<int>& lengths, int costPerCut, int woodValue) {
		int res = 0;
		for (int i = 0; i < lengths.size(); i++) {
			if (lengths[i] >= length) {
				int cut = lengths[i]/length; if (lengths[i]%length==0) cut--;
				int sticks = lengths[i]/length;
				res += max(sticks * length * woodValue - cut * costPerCut, 0);
			}
		}
		return res;
	}
};

int Planks::makeSimilar(vector <int> lengths, int costPerCut, int woodValue) {
	int res = 0;
	for (int length = 1; length <= 10000; length++)
		res = max(res, cutLength(length, lengths, costPerCut, woodValue));
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!