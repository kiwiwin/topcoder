public class GreatFairyWar {
	public int minHP(int[] dps, int[] hp) {
		int result = 0;
		int now = 0;
		for (int i = 0; i < dps.length; i++) {
			result += (now + hp[i]) * dps[i];
			now += hp[i];
		}
		return result;
	}
}
