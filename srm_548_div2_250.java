import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class KingdomAndDucks
{
	private Integer[] C = new Integer[51];

	public KingdomAndDucks() {
		Arrays.fill(C, 0);
	}

	public int minDucks(int[] duckTypes)
	{
		for (int type : duckTypes) C[type]++;
		int MAX = Collections.max(Arrays.asList(C));
		int count = 0;
		for (int i = 0; i <= 50; i++) if (C[i] > 0) count++;
		return count * MAX;		
	}
	
	<%:testing-code%>
}
//Powered by [KawigiEdit] 2.0!