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

class RowAndManyCoins {
public:
	string getWinner(string);
};

string RowAndManyCoins::getWinner(string cells) {
	int l=cells.size();
	if (cells[0]=='A' || cells[l-1]=='A')
		return "Alice";
	else
		return "Bob";
}

