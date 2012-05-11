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
	
	double greedyMix(vector<pair<double,double> > v1, vector<pair<double,double> > v2, int need) {
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
	
	double howMuch(vector <int> percent, vector <int> amount, int need) {
		double res = 0;
		vector<pair<double,double> > v1; vector<pair<double,double> > v2; 
		
		for(int i = 0; i < percent.size(); i++) {
			pair<double,double> pii = make_pair(percent[i], amount[i]);
			if (percent[i] < need) {v1.push_back(pii);}
			else if (percent[i] > need) {v2.push_back(pii);}
			else res += amount[i];
		}
		
		sort(v1.begin(), v1.end(), greater<pair<double, double> >());
		sort(v2.begin(), v2.end());
		
		res += greedyMix(v1, v2, need);
		return res;
	}
};
