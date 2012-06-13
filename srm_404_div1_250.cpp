#include <string>
#include <vector>

using namespace std;

class RevealTriangle {
public:
	bool hasQ(const vector<string> &Q) {
		for (int i = 0; i < Q.size(); i++)
		for (int j = 0; j < Q.size()-i; j++)
			if (Q[i][j] == '?') return true;
		return false;
	}
	
	bool hasKnowSumAndOneNum(const vector<string> &Q) {
		for (int i = 1; i < Q.size(); i++)
		for (int j = 0; j < Q.size()-i; j++) {
			if (Q[i][j] != '?') {
				if (Q[i-1][j] == '?' && Q[i-1][j+1] != '?') return true;
				if (Q[i-1][j] != '?' && Q[i-1][j+1] == '?') return true;
			}
		}
		return false;
	}
	
	void fillKnowSumAndOneNum(vector<string> &Q) {
		for (int i = 1; i < Q.size(); i++)
		for (int j = 0; j < Q.size()-i; j++) {
			if (Q[i][j] != '?') {
				if (Q[i-1][j] == '?' && Q[i-1][j+1] != '?') Q[i-1][j] = reverseSolve(Q[i][j], Q[i-1][j+1]);
				if (Q[i-1][j] != '?' && Q[i-1][j+1] == '?') Q[i-1][j+1] = reverseSolve(Q[i][j], Q[i-1][j]);
			}
		}	
	}
	
	char reverseSolve(char sum, char addend) {
		int sum_i = (sum-'0') + 10;
		int add_i = (addend - '0');
		return (sum_i - add_i) % 10 + '0';
	}

	bool hasKnowTwoNum(const vector<string> &Q) {
		for (int i = 1; i < Q.size(); i++)
		for (int j = 0; j < Q.size()-i; j++) {
			if (Q[i][j] == '?') {
				if (Q[i-1][j] != '?' && Q[i-1][j] != '?') return true;
			}
		}
		return false;
	}

	void fillKnowTwoNum(vector<string> &Q) {
		for (int i = 1; i < Q.size(); i++)
		for (int j = 0; j < Q.size()-i; j++) {
			if (Q[i][j] == '?') {
				if (Q[i-1][j] != '?' && Q[i-1][j] != '?') Q[i][j] = solve(Q[i-1][j], Q[i-1][j+1]);
			}
		}
	}
	
	char solve(char num1, char num2) {
		int num1_i = num1 - '0';
		int num2_i = num2 - '0';
		return (num1_i + num2_i) % 10 + '0';
	}

	vector<string> calcTriangle(vector<string> Q) {
		while(hasQ(Q)) {
			while (hasKnowSumAndOneNum(Q)) {
				fillKnowSumAndOneNum(Q);
			}
			while (hasKnowTwoNum(Q)) {
				fillKnowTwoNum(Q);
			}
		}
		return Q;
	}
};
