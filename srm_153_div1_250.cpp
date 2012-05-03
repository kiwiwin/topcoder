#include <vector>
#include <cmath>
using namespace std;

class Inventory {
public:
	double expectMonthSales(int sales, int days) {
		return 30.0 / days * sales;
	}

	int monthlyOrder(vector <int> sales, vector <int> days) {
		double res = 0; int month = 0;
		for (int i = 0; i < sales.size(); i++ ) {
			if (days[i] != 0) {
				res += expectMonthSales(sales[i], days[i]);
				month ++;
			}
		}
		return ceil(res/month);
	}
};
