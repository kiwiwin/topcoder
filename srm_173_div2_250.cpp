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

class ProgressBar {
public:
	string showProgress(vector <int>, int);
};

string ProgressBar::showProgress(vector <int> taskTimes, int tasksCompleted) {
	int sum = 0;
	int com = 0;
	for(int i = 0; i < taskTimes.size(); i++){
		sum += taskTimes[i];
		if(i < tasksCompleted){
			com += taskTimes[i];
		}
	}
	int n = floor(20 * com / sum);
	string str(n,'#');
	str.append(20-n,'.');	
	return str;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!