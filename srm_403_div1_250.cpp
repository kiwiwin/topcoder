class TheLuckyNumbers {
public:
	int makeValue(int mask, int digit) {
		int res = 0;
		int base = 1;
		for (int bit = 0; bit < digit; bit++) {
			if ((1<<bit) & mask) res += 7 * base;
			else res += 4 * base;
			base *= 10;
		}
		return res;
	}
	
	int luckyNumber(int x) {
		int res = 0;
		for (int digit = 1; digit <= 9; digit++) {
			for (int mask = 0; mask < (1<<digit); mask++) {
				int val = makeValue(mask, digit);
				if (val > x) return res;
				res++;
			}	
		}
		return res;
	}

	int count(int a, int b) {
		return luckyNumber(b) - luckyNumber(a-1);	
	}
};
