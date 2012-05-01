#include <vector>
#include <string>
using namespace std;

class MostProfitable{
public:
	vector<int> GetProfits(const vector<int>& costs, const vector<int>& prices, const vector<int>& sales){
		vector<int> profits;
		profits.clear();
		for(int i = 0; i < costs.size(); i++)
		{ 
			profits.push_back( sales[i]*( prices[i] - costs[i]) );
		}
		return profits;
	}	

	string bestItem(vector<int> costs, vector<int> prices, vector<int>sales ,vector<string> items){
		vector<int> profits = GetProfits(costs,prices,sales);
		int limit = 0;
		int best = 0;
		for(int i = 0; i < profits.size() ; i++)
		{
			if(limit < profits[i])
			{
				limit = profits[i];
				best = i;
			}
		}
		
		if(0 == limit) return "";		
		return items[best];
	}
};