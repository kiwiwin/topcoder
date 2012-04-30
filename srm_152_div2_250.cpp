#include <vector>
using namespace std;

class FixedPointTheorem{
public:
	
	vector<double> get1knum (double R,vector<double>& num)
	{
		num.clear();
		for(int i = 0; i < 200000; i++)
		{
		 	x = x*(1-x)*r;
		}
		for(int i = 0; i < 1000; i++)
		{
		 	x = x*(1-x)*R;
			num.push_back(x);	 	
		}
		return num;
	}	
		
	double cycleRange(double R)
	{
		double max = 0;
		double min = 1;
		vector<double> num;
		num = get1knum(R,num);
		for(int i = 0; i < 1000; i++)
		{
		 	if(num[i] > max)
		 		max = num[i];
		 	if(num[i] < min)
		 		min = num[i];
		}
		return max - min;
	}
};