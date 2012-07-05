#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Undo {
public:
	bool undo[55];
	vector<int> time;
 
	bool isUndo(const string &str) {
		return str.find("undo") != string::npos;
	}
	
	int getUndoTime(const string &str) {
		stringstream ss(str);
		string s; int res;
		ss >> s; ss >> res;
		return res; 
	}
	
	string getChar(const string &str) {
		stringstream ss(str);
		string oper; string res;
		ss >> oper; ss >> res;
		return res;
	}
	
	void undoOper(int startTime, int endTime) {
		for (int i = 0; i < time.size(); i++)
			if (time[i] >= startTime && time[i] <= endTime) undo[i] = true;
	}

	string getText(vector<string> commands, vector<int> _time) {
		memset(undo, false, sizeof(undo));
		time = _time;
		
		for (int i = time.size()-1; i >=0 ; i--) {
			if (undo[i]) continue;
			if (isUndo(commands[i])) {
				undoOper(time[i]-getUndoTime(commands[i]), time[i]);
			}
		}
		
		string res = "";
		for (int i = 0; i < commands.size(); i++) {
			if (undo[i]) continue;
			res += getChar(commands[i]);
		}
		return res;
	}
};
