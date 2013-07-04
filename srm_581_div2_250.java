public class BlackAndWhiteSolitaire {
	public int minimumTurns(String card) {
		int a = 0, b = 0;
		for (int i = 0; i < card.length(); i++) {
			if (card.charAt(i) == 'W' && i % 2 == 0) a++;
			if (card.charAt(i) == 'B' && i % 2 == 1) a++;
			if (card.charAt(i) == 'B' && i % 2 == 0) b++;
			if (card.charAt(i) == 'W' && i % 2 == 1) b++;
		}
		return Math.min(a, b);
	}
} 
