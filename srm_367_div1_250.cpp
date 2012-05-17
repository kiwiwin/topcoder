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

class ObtainingDigitK {
public:
	int minNumberToAdd(string, int);
	
	string addOne(string number) {
		for (int i = number.size()-1; i >= 0; i--) {
			if (number[i] < '9') { number[i]++; return number;}
			number[i] = '0';
		}
		return "1" + number;
	}
	
	bool contain(string number, char k) {
		return number.find(k) !=  string::npos;
	}
};

int ObtainingDigitK::minNumberToAdd(string originalNumber, int k) {
	string number = originalNumber;
	int count = 0;
	while(!contain(number, k+'0')) {count++; number = addOne(number);}
	return count;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!