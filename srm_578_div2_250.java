import java.math.*;

public class DeerInZooDivTwo {
	public int[] getminmax(int N, int K) {
		int[] result = {Math.max(N - K, 0), N - (K+1)/2};
		return result;
	}
}
