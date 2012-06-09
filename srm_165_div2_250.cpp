#include <vector>
using namespace std;

class BritishCoins{
public:
	vector <int> coins(int pence){
		vector<int> num;
		num.clear();
		int pound = pence / 240;
		num.push_back(pound);
		int shilling = (pence / 12) - pound * 20;
		num.push_back(shilling);
		int penny = pence - pound * 240 - shilling * 12;
		num.push_back(penny);
		return num;
	}
};