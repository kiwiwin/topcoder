#include <algorithm>
using namespace std;

class FixedPointTheorem{
public:
	double Fx(double X, double R) {
		return R * X * (1-X);
	}
	
	double After2MillionIteration(double X, double R) {
		double res = X;
		for (int i = 0; i < 200000; i++) {
			res = Fx(res, R);
		}
		return res;
	}

	double rangeOf1K(double X, double R) {
		X = Fx(X, R);
		double MINX = X, MAXX = X;
		for(int i = 2; i <= 1000; i++) {
			X = Fx(X,R);
			MINX = min(MINX, X); MAXX = max(MAXX, X);
		}
		return MAXX - MINX;
	}

	double cycleRange(double R){
		double X = 0.25;
		X = After2MillionIteration(X, R);
		return rangeOf1K(X, R);
	}
};
