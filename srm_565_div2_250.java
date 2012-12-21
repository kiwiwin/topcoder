import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;
import java.lang.*;

public class ValueHistogram
{
	private Integer[] M = new Integer[10];
	
	public ValueHistogram() {
		Arrays.fill(M, 0);
	}
	
	public String[] build(int[] values)
	{
		for (int i = 0; i < values.length; i++) M[values[i]] ++;
		int MAX = Collections.max(Arrays.asList(M));
		String[] result = new String[MAX+1];
		for (int i = 0; i <= MAX; i++) result[MAX-i] = buildLine(i);
		return result;
	}
	
	public String buildLine(int count) {
		StringBuilder result = new StringBuilder();
		for (int i = 0; i <= 9; i++) {
			if (M[i] > count) result.append("X");
			else result.append(".");
		}
		return result.toString();
	}	
	
	<%:testing-code%>
}
//Powered by [KawigiEdit] 2.0!