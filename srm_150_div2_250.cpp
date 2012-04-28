#include <vector>
using namespace std;

class WidgetRepairs
{
public:
	int workday(int& leave, int numPerDay)
	{
	 	if( ( leave < numPerDay) && (leave > 0) )
			{
				leave = 0;
			}
		else{
		leave -= numPerDay;
		}
		return 1;
	}

	int days(vector<int> arrivals, int numPerDay)
	{
		int count = 0;
		int initial = 0;
		int& leave = initial;
		for (int i = 0; i < arrivals.size(); i++ )
		{ 
			leave += arrivals[i];
			if(leave == 0) continue;
			count += workday(leave,numPerDay);
		}
 		while(leave > 0)
 		{
			count += workday(leave,numPerDay);
 		}
		return count;
	}
	
};