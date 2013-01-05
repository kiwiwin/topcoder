import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class CreateGroups
{
	public int minChanges(int[] groups, int minSize, int maxSize)
	{
		int all = sum(groups);
		if (all < minSize * groups.length || all > maxSize * groups.length)	 return -1;
		int less = 0, more = 0;
		for(int num : groups) {
			if (num < minSize) less += minSize - num;
			if (num > maxSize) more += num - maxSize;
		}
		return Math.max(less, more);
	}
	
	private int sum(int[] groups) 
	{
		int result = 0;
		for (int num : groups) result += num;
		return result;
	}
	
	<%:testing-code%>
}
//Powered by [KawigiEdit] 2.0!