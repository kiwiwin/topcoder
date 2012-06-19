#include <vector>
#include <algorithm>

using namespace std;

class RestaurantManager {
public:
	vector<int> tableLeaveTime;
	vector<int> tables, group, arrivals, departures;

	void askCustomerLeave(int nowTime) {
		for (int i = 0; i < tableLeaveTime.size(); i++)
			if (tableLeaveTime[i] <= nowTime) tableLeaveTime[i] = -1;
	}
	
	bool canAcceptGroup(int groupIndex) {
		for (int i = 0; i < tables.size(); i++) {
			if (!isTableAvaiable(i)) continue;
			if (tables[i] >= group[groupIndex]) return true;
		}
		return false;
	}
	
	void acceptGroup(int groupIndex) {
		for (int i = 0; i < tables.size(); i++) {
			if (!isTableAvaiable(i)) continue;
			if (tables[i] >= group[groupIndex]) { tableLeaveTime[i] = departures[groupIndex]; return; }
		}
	}
	
	bool isTableAvaiable(int tableIndex) {
		return tableLeaveTime[tableIndex] < 0;
	}

	int allocateTables(vector<int> _tables, vector<int> _group, vector<int> _arrivals, vector<int> _departures) {
		int res = 0;
		
		tableLeaveTime = vector<int>(_tables.size(), -1);
		tables = _tables; group = _group; arrivals = _arrivals; departures = _departures;
		sort(tables.begin(), tables.end());
		
		for (int g = 0; g < group.size(); g++) {
			askCustomerLeave(arrivals[g]);
			if (canAcceptGroup(g)) acceptGroup(g);
			else res += group[g];
		}
		return res;
	}
};
