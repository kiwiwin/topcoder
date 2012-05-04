#include <vector>
#include <algorithm>
using namespace std;

class DiskSpace{
public:
	int minDrives(vector <int> used, vector <int> total){
		sort(total.begin(), total.end());
		int space = 0;
		for (int i = 0; i < used.size(); i++)
		{
			space += used[i];
		}
		int full = 0;
		int j = total.size() - 1;
		while(0 < space)
		{
			space -= total[j];
			full++;
			j--; 
		}
		return full;
	}
};