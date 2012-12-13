import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class FauxPalindromes
{
	public String classifyIt(String word)
	{
		if (isPalindrome(word)) return "PALINDROME";
		if (isFaux(word)) return "FAUX";
		return "NOT EVEN FAUX";
	}
	
	private boolean isPalindrome(String word) {
		String reversed = new StringBuffer(word).reverse().toString();
		return word.equals(reversed);
	}
	
	private boolean isFaux(String word) {
		return isPalindrome(uniqConsecutive(word));
	}
	
	private String uniqConsecutive(String word) {
		StringBuffer result = new StringBuffer();
		result.append(word.charAt(0));
		for (int i = 1; i < word.length(); i++) {
			if (word.charAt(i) != word.charAt(i-1)) result.append(word.charAt(i));
		}
		return result.toString();
	}
	
	
}
//Powered by [KawigiEdit] 2.0!