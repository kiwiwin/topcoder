#include <string.h>

class ProductOfDigits {
public: 
	int count[10];
	
	int countDigit(int N, int digit) {
		int res = 0;
		while(N>1) {
			if (N%digit==0) res++;
			else break;
			N /= digit;
		}
		return res;
	}
	
	bool checkValid(int N) {
		int P = 1;
		for (int i = 0; i < count[2]; i++) P *= 2;
		for (int i = 0; i < count[3]; i++) P *= 3;
		for (int i = 0; i < count[5]; i++) P *= 5;		
		for (int i = 0; i < count[7]; i++) P *= 7;		
		return P == N;
	}

	int smallestNumber(int N) {
		if (N == 1) return 1;
	
		memset(count, 0, sizeof(count));
		
		count[2] = countDigit(N, 2);
		count[3] = countDigit(N, 3);
		count[5] = countDigit(N, 5);
		count[7] = countDigit(N, 7);
		
		if (!checkValid(N)) return -1;
		
		int res = 0;
		res += count[2]/3; count[2] %= 3;
		if (count[2] == 2) { res ++; count[2] = 0; }
		res += count[3]/2; count[3] %= 2;
		res += (count[3] | count[2]);
		res += count[5] + count[7];
		return res;
	}
};
