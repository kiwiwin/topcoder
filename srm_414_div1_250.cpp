#include <vector>
#include <algorithm>

using namespace std;

/*
	to simplify the implementation, we can assume the openTime is start from 0 clock, end at openTime clock
*/

class Embassy {
public:
	int visaApplication(vector<int> forms, int dayLength, int openTime) {
		int res = 100000000;
		for (int startTime = 0; startTime < dayLength; startTime++) {
			int now = startTime;
			for (int i = 0; i < forms.size(); i++) {
				now += forms[i];
				if (now%dayLength > openTime) now += dayLength - now%dayLength;
			}
			res = min(res, now - startTime);
		}
		return res;
	}
};
