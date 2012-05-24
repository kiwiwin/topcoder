class SmoothNumbers {
public:
	bool checkKSmooth(int value, int k) {
		for (int factor = 2; factor <= k; factor++) {
			while(value % factor == 0) value/=factor;
		}
		return value == 1;
	}

	int countSmoothNumbers(int N, int k) {
		int res = 1;
		for (int value = 2; value <= N; value++) {
			if (checkKSmooth(value, k)) res++;
		}
		return res;
	}
};
