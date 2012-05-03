#include <string>
using namespace std;

class Rochambo {
public:
	bool checkWin(char my, char opp) {
		if (my == 'R' && opp == 'S') return true;
		if (my == 'S' && opp == 'P') return true;
		if (my == 'P' && opp == 'R') return true;
		return false;
	}
	
	char predict(char first, char second) {
		if (first == second) return first;
		char gesture[] = {'P', 'S', 'R'};
		for (int i = 0; i < 3; i++) {
			if (gesture[i] != first && gesture[i] != second) return gesture[i];
		}
	}

	int firstTwoRound(string opp) {
		int res = 0;
		for (int i = 0; i < 2; i++) if (checkWin('R', opp[i])) res++;
		return res;
	}

	int predictRound(string opp) {
		int res = 0;
		for (int i = 2; i < opp.size(); i++) if (predict(opp[i-2], opp[i-1]) == opp[i]) res++;
		return res;
	}

	int wins(string opp) {
		return firstTwoRound(opp) + predictRound(opp);
	}
};
