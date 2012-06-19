#include <vector>
#include <algorithm>

using namespace std;

class RestaurantManager {
public:
	int allocateTables(vector<int> tables, vector<int> group, vector<int> arrivals, vector<int> departures) {
		int res = 0;
		sort(tables.begin(), tables.end());
		vector<int> tableLeaveTime(tables.size(), -1);
		
		for (int g = 0; g < group.size(); g++) {
			int nowTime = arrivals[g];
			for (int i = 0; i < tableLeaveTime.size(); i++)
				if (tableLeaveTime[i] <= nowTime) tableLeaveTime[i] = -1;
				
			bool flag = false;
			for (int i = 0; i < tables.size(); i++) {
				if (tableLeaveTime[i] >= 0) continue;
				if (tables[i] >= group[g]) { tableLeaveTime[i] = departures[g]; flag = true; break; }
			}
			
			if (!flag) { res += group[g]; }
		}
		return res;
	}
};
