import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class EllysNewNickname
{
	public int getLength(String nickname)
	{
		int result = nickname.length();
		for (int i = 1; i < nickname.length(); i++) {
			if (isVowel(nickname.charAt(i)) && isVowel(nickname.charAt(i-1))) result --; 
		}
		return result;
	}
	
	private boolean isVowel(char c) 
	{
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
	}
	
	<%:testing-code%>
}
//Powered by [KawigiEdit] 2.0!

