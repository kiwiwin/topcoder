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

class Sortness {
public:
	double getSortness(vector <int>);
	
	int sortness(vector<int> a, int index) {
		int res = 0;
		for (int i = 0; i < index; i++) if (a[i] > a[index]) res++;
		for (int i = index+1; i < a.size(); i++) if (a[i] < a[index]) res++;
		return res;
	}
};

double Sortness::getSortness(vector <int> a) {
	double res = 0;
	for (int i =  0; i < a.size(); i++) 
		res += sortness(a, i);
	return res/a.size();
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!