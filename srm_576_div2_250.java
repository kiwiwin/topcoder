import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class TheExperimentDiv2
{
	private boolean[] used = new boolean[55];
	
	public int[] determineHumidity(int[] intensity, int L, int[] leftEnd)
	{
		int[] result = new int[leftEnd.length];
		for (int i = 0; i < leftEnd.length; i++)
			result[i] = countHumidity(intensity, leftEnd[i], L);
		return result;
	}
	
	private int countHumidity(int[] intensity, int start, int L) {
		int result = 0;
		for (int i = 0; i < L; i++)
			if (!used[start+i]) {
				result += intensity[start+i];
				used[start+i] = true;
			}
		return result;
	}
	
	
}
//Powered by [KawigiEdit] 2.0!

