import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class EllysTSP
{
	public int getMax(String places)
	{
		int countC = countFreq(places, 'C'), countV = countFreq(places, 'V');
		int MIN = Math.min(countC, countV), MAX = Math.max(countC, countV);
		if (MAX == MIN) return MIN * 2;
		return MIN * 2 + 1;
	}
	
	private int countFreq(String places, Character c) {
		int result = 0;
		for (int p : places.toCharArray()) if (p == c) result++;
		return result;
	}
}
//Powered by [KawigiEdit] 2.0!