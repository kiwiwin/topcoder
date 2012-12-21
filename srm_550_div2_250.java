import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class EasyConversionMachine
{
	public String isItPossible(String originalWord, String finalWord, int k)
	{
		int diff = diff(originalWord, finalWord);
		return canConvert(diff, k) ? "POSSIBLE" : "IMPOSSIBLE";
	}
	
	private boolean canConvert(int diff, int k) {
		if (diff > k) return false;
		return (k - diff) % 2  == 0;
	}
	
	private int diff(String originWord, String finalWord) {
		int result = 0;
		for (int i = 0; i < originWord.length(); i++) {
			if (originWord.charAt(i) != finalWord.charAt(i)) result++;
		}	
		return result;
	}
	
	<%:testing-code%>
}
//Powered by [KawigiEdit] 2.0!