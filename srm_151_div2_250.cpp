#include <string>
#include <vector>

using namespace std;

class PrefixCode {
public:
	string outputNo(int index){
		char buf[250];
		sprintf(buf, "No, %d", index);
		return buf;
	}

	bool checkPrefix(vector<string> words, int index) {
		for (int i = 0; i < words.size(); i++) {
			if (i == index) continue;
			if (words[i].find(words[index]) == 0) return false;
		}
		return true;
	}

	string isOne(vector <string> words) {
		for (int i = 0; i < words.size(); i++)
			if (!checkPrefix(words, i)) { 
				return outputNo(i);
			}
		return "Yes";
	}
};
