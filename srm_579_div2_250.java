mport java.util.Arrays;

public class PrimalUnlicensedCreatures {
	public int maxWins(int init, int[] powers) {
		int result = 0;
		Arrays.sort(powers);
		int cur = init;
		for (int i = 0; i < powers.length; i++) {
			if (cur <= powers[i]) return result;
			cur += powers[i] / 2;
			result ++;
		}
		return result;
	}
}
