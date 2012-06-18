#include <algorithm>
#include <string>

using namespace std;

class NextNumber {
public:
	string int2str(int N) {
		string res = "";
		while(N) {
			res = char('0'+N%2) + res;
			N>>=1;
		}
		return res;		
	}
	
	int str2int(string s) {
		int res = 0;
		for (int i = 0; i < s.size(); i++) {
			res += (s[i]-'0') * (1<<(s.size()-i-1));
		}
		return res;
	}
	 
	int getNextNumber(int N) {
		string NbitStr = int2str(N);
		if (next_permutation(NbitStr.begin(), NbitStr.end())) { return str2int(NbitStr); }
		else {
			prev_permutation(NbitStr.begin(), NbitStr.end());
			NbitStr = "0" + NbitStr;
			swap(NbitStr[0], NbitStr[1]);
			sort(NbitStr.begin()+1, NbitStr.end());
			return str2int(NbitStr);
		}
	}
};
