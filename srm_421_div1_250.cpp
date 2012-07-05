#include <vector>
#include <cmath>

using namespace std;

const double eps = 1e-12;

class EquilibriumPoints {
public:
	vector<double> X,M;
	
	double getForce(double m, double x, double pos) {
		double res = m / (x-pos) / (x-pos);
		return x < pos ? -res : res;
	}

	double getAllForce(double pos) {
		double res = 0;
		for (int i = 0; i < M.size(); i++) {
			res += getForce(M[i], X[i], pos);
		}
		return res;
	}

	double solve(double start, double end) {
		if (fabs(start - end) < eps) return start;
		double mid = (start + end) / 2;
		if (getAllForce(mid) < 0) return solve(mid, end);
		else if (getAllForce(mid) > 0) return solve(start, mid);
		else return mid;
	}

	vector<double> vi2vd(const vector<int> & x) {
		vector<double> res(x.size(), 0);
		for (int i = 0; i < x.size(); i++) res[i] = x[i];
		return res;
	}

	vector<double> getPoints(vector<int> x, vector<int> m) {
		X = vi2vd(x); M = vi2vd(m);
		vector<double> res;
		for (int i = 1; i < x.size(); i++) {
			res.push_back(solve(x[i-1], x[i]));
		}
		return res;
	}
};
