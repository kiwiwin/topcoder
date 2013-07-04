import java.util.*;

public class SemiPerfectSquare {
	public String check(int N) {
		return allSemis().contains(N) ? "Yes" : "No";
	}
	
	public Set allSemis() {
		Set semis = new HashSet<Integer>();
		for (Integer a = 1; a <= 1000; a++)
		for (Integer b = a+1; b <= 1000; b++) {
			if (a*b*b > 1000) break;
			semis.add(a*b*b);
		}
		return semis;
	}
}

