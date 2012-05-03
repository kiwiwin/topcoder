#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Iditarod {
public:
	int time2int(string time) {
		int hour, minute; char X; int day;
		sscanf(time.c_str(), "%d:%d %cM, DAY %d", &hour, &minute, &X, &day);
		if (hour == 12) hour -= 12;
		int res = ((day-1) * 24 + hour) * 60 + minute;
		if (X == 'P') res += 12 * 60;
		return res;
	}

	int avgMinutes(vector <string> times) {
		int start = time2int("08:00 AM, DAY 1");
		double res = 0;
		for (int i = 0; i < times.size(); i++) {
			res += time2int(times[i]) - start;
		}
		return round(res / times.size());
	}
};
