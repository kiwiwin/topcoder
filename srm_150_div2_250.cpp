#include <vector>
#include <cmath>
using namespace std;

class WidgetRepairs
{
public:
	int days(vector<int> arrivals, int numPerDay)
	{
		int widget = 0;
		int res = 0;
		for (int i = 0; i < arrivals.size(); i++) {
			widget += arrivals[i];
			if (widget > 0) res++;
			if (widget < numPerDay) widget = 0;
			else widget -= numPerDay;
		}
		
		return res + ceil(1.0 * widget / numPerDay);
	}
	
};
