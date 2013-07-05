public class ShoutterDiv2 {
	public int count(int[] s, int[] t) {
		int result = 0;
		for (int i = 0; i < s.length; i++)
		for (int j = i+1; j < s.length; j++) {
			if (isMeet(s[i], t[i], s[j], t[j])) result++;
		}
		return result;
	}
	
	private boolean isMeet(int s1, int t1, int s2, int t2) {
		return (t1 >= s2 && s2 >= s1) || (t2 >= s1 && s1 >= s2);
	}
}
