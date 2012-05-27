#include <vector>
#include <utility>
#include <iostream>
using namespace std;

class MixingLiquids {
public:
	double solution(double p1, double &a1, double p2, double &a2, int need) {
		double rate1to2 = 1.0*(need-p2)/(p1-need);
		double res = 0;
		if (a1 > rate1to2*a2) { res =  a2*(rate1to2+1); a1 -= rate1to2*a2; a2 = 0; }
		else { res = a1*(1+1/rate1to2); a2 -= a1/rate1to2; a1 = 0;  }
		return res;
	} 
	
	double greedyMix(vector<pair<double,double> > v1, vector<pair<double,double> > v2) {
		sort(v1.begin(), v1.end(), greater<pair<double, double> >());
		sort(v2.begin(), v2.end());

		if (v1.empty() || v2.empty()) return 0;
		int index1 = 0, index2 = 0;
		double res = 0;
		while(index1 < v1.size() && index2 < v2.size()) {
			res += solution(v1[index1].first, v1[index1].second, v2[index2].first, v2[index2].second, need);
			if (v1[index1].second <= 0) index1++; 
			if (v2[index2].second <= 0) index2++;
		}
		return res;
	}
	
	double needPercentAmount(vector<int> &percent, vector<int> &amount) {
		double res = 0;
		for(int i = 0; i < percent.size(); i++) { 
			if (percent[i] == need) res += amount[i];
		}
		return res;
	}
	
	vector<pair<double,double> > getLowerPercent(vector<int> &percent, vector<int> &amount) {
		vector<pair<double, double> > res;
		for(int i = 0; i < percent.size(); i++) { 
			if (percent[i] < need) res.push_back(make_pair(percent[i], amount[i]));
		}
		return res;
	}
	
	vector<pair<double,double> > getHigherPercent(vector<int> &percent, vector<int> &amount) {
		vector<pair<double, double> > res;
		for(int i = 0; i < percent.size(); i++) { 
			if (percent[i] > need) res.push_back(make_pair(percent[i], amount[i]));
		}
		return res;
	}
	
	double howMuch(vector <int> percent, vector <int> amount, int need_) {
		need = need_;
		vector<pair<double,double> > low = getLowerPercent(percent, amount);
		vector<pair<double,double> > high = getHigherPercent(percent, amount);
		
		return greedyMix(low, high) + needPercentAmount(percent, amount);
	}
private:
	int need;
};
