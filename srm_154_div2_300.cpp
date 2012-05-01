#include <string>
#include <sstream>
#include <vector>
using namespace std;

class ProfitCalculator{
public:
	double SToD(string s) {
     double d;
     stringstream ss(s);
     ss >> d; 
     return d;
	}
	
	int percent(vector<string> items){
		double price = 0;
		double cost = 0;
		for(int i = 0; i < items.size(); i++)
		{
			price += SToD( items[i].substr(0,6));
			cost += SToD( items[i].substr(7,6));			
		}
		return (int) (price - cost)/price *100;
	
	}
};