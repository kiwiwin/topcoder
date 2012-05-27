#include <cmath>

class ApproximateDivision {
public:
	int smallestPower(int x) {
		int res = 1;
		while(res < x) res <<= 1;
		return res;
	}
	
	double calculateTerm(int t, int c, int term) {
		return pow(1.0*c, term-1) / pow(1.0*t, term);
	}
 
	double quotient(int a, int b, int terms) {
		double res = 0;
		int t = smallestPower(b); int c = t-b;
		for (int i = 1; i <= terms; i++) {
			res += calculateTerm(t,c,i);
		}
		return res*a;
	}
};
