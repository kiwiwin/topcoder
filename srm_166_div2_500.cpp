#include <vector>
#include <algorithm>
using namespace std;

class BinaryCardinality{
public:
	int GetCard(int dec){
		int cardi = 0;
		while(dec > 0)
		{ 
			cardi += dec % 2;
			dec = dec/2;
		}
		return cardi;
	}
	
	vector <int> arrange(vector <int> numbers){
		sort(numbers.begin(),numbers.end());
		vector<int> cards;
		vector<int> out;
		for(size_t i = 0; i < numbers.size(); i++) 
		{ 
			cards.push_back(GetCard(numbers[i]));
		}
		int iter = 0;
		while(out.size() != numbers.size())
		{
			for(size_t i = 0; i < numbers.size(); i++) 
			{	 
				if(iter == cards[i])
					out.push_back(numbers[i]);
			}
			iter++;
		}
		return out;
	}
};