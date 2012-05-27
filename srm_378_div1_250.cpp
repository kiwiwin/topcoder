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

class TrueStatements {
public:
	int numberTrue(vector <int>);
	int mem[51];
};

int TrueStatements::numberTrue(vector <int> statements) {
	memset(mem, 0, sizeof(mem));
	for (int i = 0; i < statements.size(); i++)
		mem[statements[i]]++;
	for (int i = 50; i >= 1; i--) 
		if (mem[i] == i) return i;
	return mem[0] == 0 ? 0 : -1;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!