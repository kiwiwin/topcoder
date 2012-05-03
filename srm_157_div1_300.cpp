#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Salary {
public:
	int time2int(string time) {
		int hours, minutes, seconds;
		sscanf(time.c_str(), "%d:%d:%d", &hours, &minutes, &seconds);
		return hours * 3600 + minutes * 60 + seconds;
	}

	int getMorningInterval(int atime, int dtime) {
		if (atime < 6 * 3600) {
			int end = min(dtime, 6 * 3600);
			return end - atime;
		}
		return 0;
	}
	
	int getAfternoonInterval(int atime, int dtime) {
		if (atime >= 18 * 3600) return 0;
		if (dtime < 6 * 3600) return 0;
		int start = max(atime, 6 * 3600);
		int end = min(dtime, 18 * 3600);
		return end-start;
	}
	
	int getEveningInterval(int atime, int dtime) {
		if (dtime >= 18 * 3600) {
			int start = max(atime, 18 * 3600);
			return dtime - start;
		}
		return 0;
	}

	int howMuch(vector <string> arrival, vector <string> departure, int wage) {
		double res = 0;
		for (int i = 0; i < arrival.size(); i++) {
			int dtime = time2int(departure[i]);
			int atime = time2int(arrival[i]);
			res += getMorningInterval(atime, dtime) * 1.5;
			res += getAfternoonInterval(atime, dtime);
			res += getEveningInterval(atime, dtime) * 1.5;
		}
		
		return floor(res * wage / 3600.0);
	}
};
