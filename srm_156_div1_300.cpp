#include <vector>
#include <string>
using namespace std;

class BombSweeper {
public:
	vector<string> board;

	int getBombNumber() {
		int cnt = 0;
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == 'B') cnt++;
			}
		return cnt;
	}
	
	bool checkOnBoard(int r, int c) {
		if (r < 0 || r >= board.size()) return false;
		if (c < 0 || c >= board[0].size()) return false;
		return true;
	}
	
	bool hasBombNeighbor(int r, int c) {
		for (int dr = -1; dr <= 1; dr++)
		for (int dc = -1; dc <= 1; dc++){
			if( checkOnBoard(r+dr, c+dc) ){
				if(board[r+dr][c+dc] == 'B') return true;
			}
		}
		return false;
	}
	
	int getWinNumber() {
		int cnt = 0;
		for (int i = 0; i < board.size(); i++) 
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == 'B') continue;
				if (!hasBombNeighbor(i, j)) cnt++;
			}
		return cnt;
	}

	double winPercentage(vector <string> board_) {
		board = board_;
		int bomb = getBombNumber();
		int win = getWinNumber();
		return 100.0 * win / (win + bomb);
	}
};
