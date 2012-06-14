#include <algorithm>
#include <cmath>

class ParallelSpeedup
{
public:
	int numProcessors(int k, int overhead)
	{
		 double num = 2;
		 int com;
		 int save;
		 int cost;
		 int each;
		 int former;
		 while(true)
		 { 	
		 	each = ceil(k / num);
		 	save = k - each;
		 	com = overhead * num * (num - 1) / 2;
		 	cost = each + com;
		 	former = ceil(k / (num - 1) ) + overhead * (num - 2) * (num - 1) / 2;
		 	if(num == 1)
		 		former = k;
		 	if(save > com && former > cost) 
		 		num++;
		 	else
		 	{ 
		 		num--;
		 		break;
		 	}
		 }
		 return num;
	}
};