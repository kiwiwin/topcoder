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

class LevelUp {
public:
	int toNextLevel(vector <int>, int);
};

int LevelUp::toNextLevel(vector <int> expNeeded, int received) {
	int leave;
	for(size_t i = 0; i < expNeeded.size(); i++){
		leave = received - expNeeded[i];
		if(leave < 0)
			return 0-leave;
		else if(received == expNeeded.back())
			return 0;
	}
}

//Powered by [KawigiEdit] 2.0!