#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Segments {
public:
	vector<int> sortPoints(vector<int> s) {
		if (s[0] > s[2]) swap(s[0], s[2]);
		if (s[1] > s[3]) swap(s[1], s[3]);
		return s;
	}

	string intersection(vector<int> s1, vector<int> s2) {
		s1 = sortPoints(s1); s2 = sortPoints(s2);
		int cnt = 0;
		for (int x1 = s1[0]; x1 <= s1[2]; x1++)
		for (int y1 = s1[1]; y1 <= s1[3]; y1++)
		for (int x2 = s2[0]; x2 <= s2[2]; x2++)
		for (int y2 = s2[1]; y2 <= s2[3]; y2++)
			if (x1 == x2 && y1 == y2) cnt++;
		if (cnt == 0) return "NO";
		if (cnt == 1) return "POINT";
		else return "SEGMENT";
	}
};
