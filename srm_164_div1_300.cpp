#include <vector>
#include <string>
using namespace std;

class UserId {
public:
	bool isValidChar(string name) {
		for (int i = 0; i < name.size(); i++) {
			if (isalpha(name[i])) continue;
			if (name[i] == '\'' || name[i] == ' ') continue;
			return false;
		}
		return true;
	}
	
	string extract(string name) {
		string res = "";
		for (int i = 0; i < name.size(); i++) {
			if (isalpha(name[i])) res += tolower(name[i]);
		}
		return res;
	}
	
	bool findInUse(vector<string> inUse, string name) {
		for (int i = 0; i < inUse.size(); i++)
			if (inUse[i] == name) return true;
		return false;
	}
	
	string int2digit(int x) {
		string res = "";
		res += x/10 + '0';
		res += x%10 + '0';
		return res;
	}
	
	string rule1Id(string first, string last) {
		string res = first[0] + last;
		if (res.size() > 8) res = res.substr(0, 8);
		return res;
	}
	
	string rule2Id(string first, string middle, string last) {
		string res = "";
		res += first[0];
		res += middle[0];
		res += last;
		if (res.size() > 8) res = res.substr(0, 8);
		return res;
	}
	
	string rule3Id(string first, string last, int index) {
		string res = "";
		res += first[0];
		res += last;
		res = res.substr(0, 6);
		return res + int2digit(index);
	}
	
	bool checkValidChar(string first, string middle, string last) {
		if (!isValidChar(first) || !isValidChar(middle) || !isValidChar(last)) return false;
		return true;
	}
	
	string id(vector <string> inUse, string first, string middle, string last) {
		if (!checkValidChar(first, middle, last)) return "BAD DATA";
		first = extract(first);  middle = extract(middle);  last = extract(last);
		if (first.size() < 2 || last.size() < 2) return "BAD DATA";
		
		//first rule
		string rule1 = rule1Id(first, last);
		if (!findInUse(inUse, rule1)) return rule1;
		
		//second rule
		if (middle.size() > 0) {
			string rule2 = rule2Id(first, middle, last);
			if (!findInUse(inUse, rule2)) return rule2;
		}
		
		//third rule
		for (int i = 1; i <= 99; i++) {
			string rule3 = rule3Id(first, last, i);
			if (!findInUse(inUse, rule3)) return rule3;
		}
	}
};
