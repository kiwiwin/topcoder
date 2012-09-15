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

class GradingSystem {
public:
	int fairness(vector <int>, vector <int>);
};

int GradingSystem::fairness(vector <int> scores, vector <int> grades) {
	int result = 0;
	int MAX = grades[0], MIN = grades[grades.size()-1];
	for (int i = 0; i < grades.size(); i++) {
		if (grades[i] < MAX) result += MAX - grades[i];
		else MAX = grades[i];
	}
	for (int i = grades.size()-1; i >=0 ; i--) {
		if (grades[i] > MIN) result += grades[i] - MIN;
		else MIN = grades[i];
	}
	return result;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!