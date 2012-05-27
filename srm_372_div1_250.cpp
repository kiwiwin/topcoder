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

class RoadConstruction {
public:
	int getExitTime(vector <string>);
	bool yield[50][50];
	bool exit[50][50];
	vector<string> cl;
	
	pair<int,int> nextCar() {
		for (int i = 0; i < cl.size(); i++) {
			int pos = findFirstNotExitCar(i);
			if (pos == cl[i].size()) continue;
			if (needYield(i, pos)) yield[i][pos] = true;
			else return make_pair(i, pos);
		}
		return make_pair(-1,-1);
	}
	
	int findFirstNotExitCar(int x) {
		for (int i = 0; i < cl[x].size(); i++) if (!exit[x][i]) return i;
		return cl[x].size();
	}
	
	bool needYield(int x, int y) {
		if (yield[x][y]) return false;
		return hasHighNumberCar(x);
	}
	
	bool hasHighNumberCar(int x) {
		for (int i = x+1; i < cl.size(); i++) {
			for (int j = 0; j < cl[i].size(); j++) 
				if (!exit[i][j]) return true;
		}
		return false;
	}
	
	void exitOneCar(pair<int,int> car) {
		exit[car.first][car.second] = true;
	}
};

int RoadConstruction::getExitTime(vector <string> currentLanes) {
	memset(yield, 0, sizeof(yield));
	memset(exit, 0, sizeof(exit));
	cl = currentLanes;
	
	int count = 0;
	while(true) {
		pair<int,int> car = nextCar();
		if (cl[car.first][car.second] == 'D') break;
		exitOneCar(car);
		count ++;
	}
	return count;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!