import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class NumberNeighbours
{
	public int numPairs(int[] numbers)
	{
		int result = 0;
		for (int i = 0; i < numbers.length; i++)	
			for (int j = i+1; j < numbers.length; j++)
			if (isNeigh(numbers[i], numbers[j])) result++;
		return result;
	}
	
	private boolean isNeigh(int x, int y) {
		String xStr = Integer.valueOf(x).toString();
		String yStr = Integer.valueOf(y).toString();
		for (int digit = 1; digit <= 9; digit++) {
			if (countDigit(xStr, digit) != countDigit(yStr, digit)) return false;
		}
		return true;
	}
	
	private int countDigit(String s, int digit) {
		int result = 0;
		for (int i = 0; i < s.length(); i++) {
			if ((char)(digit + '0') == s.charAt(i)) result++; 
		}
		return result;
	}
	
	<%:testing-code%>
}
//Powered by [KawigiEdit] 2.0!

