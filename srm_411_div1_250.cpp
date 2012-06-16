#include <string>
#include <vector>

using namespace std;

class SentenceDecomposition {
public:
	int dp[55];
	bool vis[55];
	string S;
	vector<string> W;
	
	bool checkSameLetters(string lhs, string rhs) {
		if (lhs.size() != rhs.size()) return false;
		int cnt[26]; memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < lhs.size(); i++) cnt[lhs[i]-'a']++;
		for (int i = 0; i < rhs.size(); i++) cnt[rhs[i]-'a']--;
		for (int i = 0; i < 26; i++) if(cnt[i] != 0) return false;
		return true;
	}
	
	int translateCost(string word) {
		int res = -1;
		for (int i = 0; i < W.size(); i++) {
			if (!checkSameLetters(W[i], word)) continue;
			int tmp = 0;
			for (int j = 0; j < word.size(); j++)
				if (W[i][j] != word[j]) tmp++;
			if (res < 0) res = tmp;
			else res = min(res, tmp);
		}
		return res;
	}

	int solve(int now) {
		if (now >= S.size()) return 0;
		if (vis[now]) return dp[now];
		vis[now] = true;
		for (int len = 0; len <= S.size()-now; len++) {
			if (translateCost(S.substr(now, len)) < 0) continue;
			if (solve(now+len) < 0) continue;
			int tmp = translateCost(S.substr(now, len)) + solve(now + len);
			if (dp[now] < 0) dp[now] = tmp;
			else dp[now] = min(dp[now], tmp);
		}
		return dp[now];
	}
 
	int decompose(string sentence, vector<string> validWords) {
		for (int i = 0; i < 55; i++) { dp[i] = -1; vis[i] = false; }
		S = sentence; W = validWords;		
				
		return solve(0);
	}
};
