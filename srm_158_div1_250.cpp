#include <string>
#include <vector>
#include <iostream>
using namespace std;

class BaseMystery {
public:
	bool validBase(string x, int base){
		for (int i = 0; i < x.size(); i++) {
			if (getValue(x[i]) >= base) return false;
		}
		return true;
	}

	int getValue(char c){
		if (isdigit(c)) return c - '0';
		else return c - 'A' + 10;
	}

	int base10(string value, int base) {
		int n = value.size();
		int b = 1;
		int res = 0;
		for (int i = 0; i < n; i++) {
			res += getValue(value[n-i-1]) * b;
			b *= base;
		}
		return res;
	}
	
	vector<string> getNums(string equation) {
		vector<string> res;
		int addIndex = equation.find("+");
		int eqIndex = equation.find("=");
		res.push_back(equation.substr(0, addIndex));
		res.push_back(equation.substr(addIndex+1, eqIndex-addIndex-1));
		res.push_back(equation.substr(eqIndex+1, equation.size()-eqIndex-1));
		return res;
	}

	vector <int> getBase(string equation) {
		string x,y,z;
		x = getNums(equation)[0]; y = getNums(equation)[1]; z = getNums(equation)[2];
		vector<int> res;
		for (int i = 2; i <= 20; i++) {
			if (validBase(x, i) && validBase(y, i) && validBase(z, i))
				if (base10(x, i) + base10(y, i) == base10(z, i))
					res.push_back(i);
		}
		return res;
	}
};
