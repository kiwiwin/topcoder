import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class TypingDistance
{
	public int minDistance(String keyboard, String word)
	{
		int res = 0;
		int now = findKeyboardIndex(keyboard, word.charAt(0));
		for (int i = 1; i < word.length(); i++) {
			int next = findKeyboardIndex(keyboard, word.charAt(i));
			res += Math.abs(next - now);
			now = next;
		}
		return res;
	}

	private int findKeyboardIndex(String keyboard, char c)
	{
		return keyboard.indexOf(c);
	}	
	<%:testing-code%>
}
//Powered by [KawigiEdit] 2.0!