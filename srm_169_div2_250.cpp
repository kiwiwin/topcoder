#include <vector>
using namespace std;

class Swimmers
{
public:	
	vector <int> getSwimTimes(vector <int> distances, vector <int> speeds, int current)
	{
		int ppl = speeds.size();
		vector<int> time(ppl,0);
		double add;
		double minus;
		for(int i = 0; i < ppl; i++)
		{
			minus = speeds[i] - current;
			if(distances[i] == 0)
			{
				time[i] = 0;
				continue;
			}
			if(minus <= 0)
			{
				time[i] = -1;
				continue;
			}
			add = speeds[i] + current;
			time[i]	= (distances[i] / add) + (distances[i] / minus);
		}
		return time; 
	}
};