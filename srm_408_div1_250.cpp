#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class OlympicCandles {
public:
	vector<int> C;

	bool hasMoreCandles() {
		for (int i = 0; i < C.size(); i++)
			if  (C[i] > 0) return true;
		return false;
	}
	
	bool canLight(int num) {
		if (num > C.size()) return false;
		
		for (int i = 0; i < num; i++)
			if (C[i] == 0) return false;
		return true;
	}
	
	void light(int num) {
		for (int i = 0; i < num; i++)
			C[i]--;
	}

	int numberOfNights(vector<int> candles) {
		int night = 0; C = candles;
		while(hasMoreCandles()) {
			sort(C.begin(), C.end(), greater<int>());
			if (canLight(night + 1)) { night++; light(night); }
			else break;
		}
		return night;
	}
};
