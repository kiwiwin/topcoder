class CoinsExchange {
public:
	int countExchanges(int G1, int S1, int B1, int G2, int S2, int B2) {
		int res = 0;
		
		while (G1 < G2) {
			if (S1 >= 11) { S1 -= 11; G1++;	}
			else if (B1 >= 11) { B1 -= 11; S1++; }
			else return -1;
			res++;
		}
		
		while (S1 < S2) {
			if (G1 > G2) { G1--; S1 += 9; }
			else if (B1 >= 11) { B1 -= 11; S1++; }
			else return -1;
			res++;
		} 
		
		while (B1 < B2) {
			if (S1 > S2) { S1 --; B1 += 9; }
			else if (G1 > G2) { G1--; S1 += 9; }
			else return -1;
			res++;
		}
		
		return res; 
	}
};
