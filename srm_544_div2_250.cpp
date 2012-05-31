#include <string>
#include <vector>
using namespace std;

class ElectionFraudDiv2{
public:
	string IsFraudulent(vector <int> percentages){
		int sum = 0;
		float num = percentages.size();
		int count = 0;
		for(size_t i = 0; i < num; i++)
		{
			sum += percentages[i];
			if(percentages[i] != 0)
				count++;
		}
		if( (sum > 100) && (sum - 100) <= (count / 2) )
			return "NO";
		if( (sum < 100) && (100 - sum) < (num /2) )
			return "NO";
		if(sum == 100)
			return "NO";
		return "YES";
	}
};