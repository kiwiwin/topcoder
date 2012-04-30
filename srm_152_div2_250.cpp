#include <vector>
using namespace std;

class FixedPointTheorem{
public:
	double run2w(double r)
	{	
		double x = 0.25;
		int i;
	 	for(i = 0; i < 200000; i++)
		{
		 	x =	x*(1-x)*r;
		}
		return x;
	}
		
	vector<double> get1knum (double R, double x)
	{
		vector<double> num;
		num.clear();
		for(int i = 0; i < 1000; i++)
		{
		 	x =	x*(1-x)*R;
			num.push_back(x);	 	
		}
		return num;
	}	
		
	double cycleRange(double R)
	{
		double max = 0;
		double min = 1;
		vector<double> num;
		num = get1knum(R, run2w(R));
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