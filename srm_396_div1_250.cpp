#include <string>
#include <vector>
#include <iostream>

using namespace std;

class DNAString {
public:
	string connectDNA(vector<string> dna) {
		string res = "";
		for (int i = 0; i < dna.size(); i++) res += dna[i];
		return res;
	}
	
	int needReplacement(string dna, int period) {
		int result = 0;
		for (int offset = 0; offset < period; offset++) {
			int Acount = 0, Ccount = 0, Gcount = 0, Tcount = 0;
			int totalCount = 0;
			for (int index = offset; index < dna.size(); index+=period) {
				if (dna[index] == 'A') Acount ++;
				if (dna[index] == 'C') Ccount ++;
				if (dna[index] == 'G') Gcount ++;
				if (dna[index] == 'T') Tcount ++;
				totalCount ++;
			}
			int maxCount = Acount; maxCount = max(maxCount, Ccount); maxCount = max(maxCount, Gcount); maxCount = max(maxCount, Tcount);
			result += totalCount - maxCount;
		}
		return result;
	}
	
	int minChanges(int maxPeriod, vector<string> dna) {
		string DNA = connectDNA(dna);
	
		int res = DNA.size();
		for (int period = 1; period <= maxPeriod; period++) {
			res = min(res, needReplacement(DNA, period));
		}
		
		return res;
	}
};
